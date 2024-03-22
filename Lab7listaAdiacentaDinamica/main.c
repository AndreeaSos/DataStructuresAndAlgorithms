#include <stdio.h>
#include <stdlib.h>
typedef struct nodetype
{
    int key;
    struct nodetype *next;

} NodeT;

typedef struct node_type2
{
    int key;
    struct node_type2 *next;
    struct node_type2 *prev;
} NodeDL;

NodeDL *coadaHead=NULL,*coadaTail=NULL;

NodeT *firsts[100];
int nrVarfuri,nrArce;
int vizitat[100]= {0};

void my_push(int givenkey)  //insert_first  => enqueue
{
    NodeDL* p=(NodeDL*)malloc(sizeof(NodeDL));
    p->key=givenkey;
    p->prev=NULL;
    p->next=NULL;

    if(coadaHead==NULL)  //inserare primul el
    {
        coadaHead=p;
        coadaTail=p;
    }
    else
    {
        coadaTail->prev=p;
        p->next=coadaTail;
        coadaTail=p;
    }
}
void my_pop()   //delete_last() => dequeue
{
    if(coadaHead!=NULL)
    {
        if(coadaHead==coadaTail)   //un singur el in coada
        {
            free(coadaHead);
            coadaHead=NULL;
            coadaTail=NULL;
        }
        else   // mai multe el in coada
        {
            NodeDL *nodDeSters=coadaHead;
            coadaHead=coadaHead->prev;
            free(nodDeSters);
            coadaHead->next=NULL;
        }
    }
}
int my_top()  //vad elementul din head
{
    if(coadaHead==NULL)
    {
        return -1;
    }
    else
    {
        return coadaHead->key;
    }
}


void insertFirst(int indexFirsts,int givenKey)
{
    NodeT* p=(NodeT*)malloc(sizeof(NodeT));
    p->key=givenKey;
    p->next=NULL;

    if(firsts[indexFirsts]==NULL)
    {
        firsts[indexFirsts]=p;
    }
    else
    {
        p->next=firsts[indexFirsts];
        firsts[indexFirsts]=p;
    }
}

int perechi()
{
    int contor=0;
    for(int i=0; i<nrArce; i++)
    {
        if(firsts[i]!=NULL)
        {
            //return 0;
            printf("Nodul curent %d\n",i);
            NodeT* p=firsts[i];
            while(p!=NULL)
            {
                int  j=p->key;
                printf("    cauta in lista lui %d--\n",j);
                if(firsts[j]!=NULL)
                {
                    NodeT* q=firsts[j];
                    while(q!=NULL)
                    {
                        printf("        verifica %d cu %d\n",i,q->key);
                        if(q->key==i&&j>i)
                        {
                            contor++;
                            printf("---------- Success: (%d, %d)-----------\n",i, j);
                        }
                        q=q->next;
                    }
                }
                p=p->next;
            }
        }
    }
    return contor;
}


//graf liste de adiacenta dinamice
void citire()
{
    FILE* fisier=fopen("grafListaAdiacenta.in","r");
    fscanf(fisier,"%d %d",&nrVarfuri,&nrArce);
    for(int i=0; i<nrArce; i++)
    {
        int a,b;
        fscanf(fisier,"%d %d",&a,&b);
        insertFirst(a,b);
    }
}

void afisare()
{
    for(int i=0; i<nrVarfuri; i++)
    {
        NodeT* par=firsts[i];
        while(par!=NULL)
        {
            printf("%d ",par->key);
            par=par->next;
        }
        printf("\n");
    }
}
void bfs()
{
    //coada
    int nodStart=1;
    my_push(nodStart);
    vizitat[nodStart]=1;
    while(coadaHead !=NULL)
    {
        int nodParcurgere = my_top();
        my_pop();
        printf("%d ",nodParcurgere);
        //modificare
        NodeT* par=firsts[nodParcurgere];
        while(par!=NULL)
        {
            int vecin=par->key;
            if(vizitat[vecin]==0)
            {
                my_push(vecin);
                vizitat[vecin]=1;
            }
            par=par->next;
        }
    }

}

int main()
{
    citire();
    afisare();
    printf("\n");
    printf("%d ",perechi());
    //bfs();
    return 0;
}
