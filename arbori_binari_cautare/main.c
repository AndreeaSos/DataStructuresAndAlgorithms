#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
} NodeT;

NodeT *root;

NodeT *insertNode( NodeT *root, int keyParam )
{
    if(root==NULL)
    {
        NodeT* p=(NodeT*)malloc(sizeof(NodeT));
        p->key=keyParam;
        p->left=NULL;
        p->right=NULL;
        return p;
    }
    else if(root->key>keyParam)
    {
        root->left=insertNode(root->left,keyParam);
    }
    else
    {
        root->right=insertNode(root->right,keyParam);
    }
    return root;
}

void preorder(NodeT* par)
{
    if(par!=NULL)
    {
        printf("%d ",par->key);
        preorder(par->left);
        preorder(par->right);
    }
}

NodeT *searchKey( NodeT *root, int keyParam )
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->key==keyParam)
    {
        return root;
    }
    else if(root->key>keyParam)
    {
        return searchKey(root->left,keyParam);
    }
    else
    {
        return searchKey(root->right,keyParam);
    }
}


void inorder(NodeT* par)
{
    if(par!=NULL)
    {
        inorder(par->left);
        printf("%d ",par->key);
        inorder(par->right);
    }
}


void postorder(NodeT* par)
{
    if(par!=NULL)
    {
        postorder(par->left);
        postorder(par->right);
        printf("%d ",par->key);
    }
}

NodeT* findMin(NodeT* node)
{
    if(node==NULL)
    {
        return NULL;
    }
    else if(node->left==NULL)
    {
        return node;
    }
    else return findMin(node->left);
}

NodeT* findMax(NodeT* node)
{
    if(node==NULL)
    {
        return NULL;
    }
    else if(node->right==NULL)
    {
        return node;
    }
    else return findMax(node->right);
}

NodeT* succesor(NodeT *node)
{
    if(node==NULL)
    {
        return node;
    }
    else return findMin(node->right);
}

NodeT* predecesor(NodeT *node)
{
    if(node==NULL)
    {
        return node;
    }
    else return findMax(node->left);
}

NodeT* delNode(NodeT* root, int key)
{
    NodeT *p;
    /* arbore vid */
    if (root == NULL) return root;
    /* Daca cheia key este mai mica decat cheia radacinii, cautarea nodului key
    se face in subarborele stang */
    if (key < root->key)
        root->left = delNode(root->left, key);
    /* Daca cheia key este mai mare decat cheia radacinii, cautarea nodului key
    se face in subarborele drept */
    else if (key > root->key)
        root->right = delNode(root->right, key);
    /* cheia radacinii este egala cu key, acesta este nodul ce trebuie sters */
    else
    {
        /* Nodul are un singur fiu */
        if (root->left == NULL)
        {
            p = root->right;
            free(root);
            return p;
        }
        else if (root->right == NULL)
        {
            p = root->left;
            free(root);
            return p;
        }
        /* Nodul are 2 fii */
        p = findMin(root->right);
        root->key = p->key;
        root->right = delNode(root->right, p->key);
    }
    return root;
}


int main()
{
    root=insertNode(root,31);
    root=insertNode(root,16);
    root=insertNode(root,45);
    root=insertNode(root,24);
    root=insertNode(root,7);
    root=insertNode(root,19);
    root=insertNode(root,29);
    inorder(root);
    printf("\n");
    /* printf("\n %d",searchKey(root,19)->key);
     printf("\n %d",findMin(root)->key);
     printf("\n %d",findMax(root)->key);
     printf("\n %d",succesor(root)->key);
     printf("\n %d",predecesor(root)->key);*/
    root=delNode(root,16);
    inorder(root);
    printf("\n");
    postorder(root);
    return 0;
}
