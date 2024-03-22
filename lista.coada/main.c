#include <stdio.h>
#include <stdlib.h>

typedef struct node_type
{
    int key;
    struct node_type *next;
    struct node_type *prev;
} NodeDL;

NodeDL *enqueued=NULL;//ca un last
NodeDL *dequeued=NULL;//ca un first


void my_push(int givenkey) { //insert_last = push
    NodeDL* p=(NodeDL*)malloc(sizeof(NodeDL));
    p->key=givenkey;
    p->prev=NULL;
    p->next=NULL;

    if(enqueued==NULL) {
        enqueued=p;
        dequeued=p;
    } else
        enqueued->next=p;
        p->prev=enqueued;
        enqueued=p;
    }
}
int my_top() { //view top element =top

    if(stiva==NULL) {
        return -1;
    } else {
        return stiva->key;
    }
}
void my_pop() { //sterge un element =pop
    if(stiva!=NULL) {
        NodeDL *nodDeSters=stiva;
        stiva=stiva->prev;
        free(nodDeSters);
        stiva->next=NULL;
    }
}


void afisare() {
    while(stiva!=NULL) {
        printf("%d ",my_top());
        my_pop();
    }
    printf("\n");
}

int main()
{
    my_push(8);
    my_push(9);
    my_push(10);
    afisare();
    return 0;
}
