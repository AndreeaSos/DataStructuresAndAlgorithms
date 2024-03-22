#include <stdio.h>
#include <stdlib.h>
 typedef struct node_type
 {
 int id; /* node name */
 struct node_type *left, *right;
 } NodeT;

  NodeT *createBinTreeFromFile(FILE* f)
 {
 NodeT *p;
 int c;
 /* se citeste id-ul nodului */
 fscanf(f, "%d", &c);
  if ( c == 0 )
 return NULL; /* arbore vid, nu facem nimic */
 else /* else inclus pentru claritate */
 { /* construim nodul la care pointeaza p */
 p = ( NodeT *) malloc( sizeof( NodeT ));
 //if ( p == NULL )
// fatalError( "Nu mai avem memorie in createBinTree" );
 /* se populeaza nodul */
 p->id = c;
 p->left = createBinTreeFromFile(f);
 p->right = createBinTreeFromFile(f);
 }
 return p;
 }

 void preorder(NodeT *p){
    if(p!=NULL){
        printf("%d ",p->id);
        preorder(p->left);
        preorder(p->right);
    }
 }

 void inorder(NodeT *p){
    if(p!=NULL){
        preorder(p->left);
        printf("%d ",p->id);
        preorder(p->right);
    }
 }

  void postorder(NodeT *p){
    if(p!=NULL){
        preorder(p->left);
        preorder(p->right);
        printf("%d ",p->id);

    }
 }

 int leaf_node(NodeT *node){
    if (node==NULL) return 0;
    if(node->left==NULL&&node->right==NULL){
        return 1;
    }
    return leaf_node(node->left)+leaf_node(node->right);

 }

 int afisare_frunze(NodeT *node){
    if (node==NULL) return 0;
    if(node->left==NULL&&node->right==NULL){
        printf("%d ",node->id);
    }else{
        afisare_frunze(node->left);
        afisare_frunze(node->right);
    }
 }

 int nr_noduri_interne(NodeT *node){
      if (node==NULL) return 0;
    if(node->left!=NULL || node->right!=NULL){
        return 1+nr_noduri_interne(node->right)+nr_noduri_interne(node->left);
    }
 }

int maxim(int a, int b){
    //return a>b?a:b
    if(a>b)return a;
    return b;
}

 int inaltime_arbore(NodeT *node){
    if(node==NULL) return -1;
    return 1+maxim(inaltime_arbore(node->left),inaltime_arbore(node->right));
 }

NodeT* search_node(NodeT *node, int searchkey){
      if(node!=NULL){
        if(node->id==searchkey){
            return node;
        }
        NodeT* lefti=search_node(node->left,searchkey);
        if(lefti!=NULL){
            return lefti;
        }
        return search_node(node->right,searchkey);
    }
    return NULL;
}

 int main(){
 NodeT *root;
 FILE *f = fopen("arbore.in", "r");
 if (!f){
 printf("Nu se poate deschide fisierul ArboreBinar.txt\n");
 return-1;
 }
 root = createBinTreeFromFile(f);
 preorder(root);
 printf("\n");
 inorder(root);
 printf("\n");
 postorder(root);
 printf("\n");
 printf("numarul de frunze este ");
 printf("%d \n",leaf_node(root));
 printf("frunzele sunt: ");
 afisare_frunze(root);
 printf("\n nr_noduri_interne: %d",nr_noduri_interne(root));
    printf("\n nr noduri total: 8");
    printf("\n inaltime_arbore: %d",inaltime_arbore(root));
    NodeT* cauta4=search_node(root,5);
    if(cauta4!=NULL) {
        printf("\n gasit 4, si inaltimea lui este: %d",inaltime_arbore(cauta4));
    }

 fclose(f);
 return 0;
 }
