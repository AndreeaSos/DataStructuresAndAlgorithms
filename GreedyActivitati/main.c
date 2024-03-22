#include <stdio.h>
#include <stdlib.h>

typedef struct activitate
{
    int inceput,finalizat;
    char nume[100];
} Activitate;

Activitate a[100];
Activitate aGasite[10];
int nrActivitati;

void afisareActivitati(int n, Activitate aux[])
{
    for(int i=0; i<n; i++)
    {
        printf("%d %d %s\n",aux[i].inceput,aux[i].finalizat,aux[i].nume);
    }
}

void sortareActivitati()
{
    for(int i=0; i<nrActivitati-1; i++)
    {
        for(int j=i+1; j<nrActivitati; j++)
        {
            if(a[i].finalizat < a[j].finalizat)
            {
                Activitate aux =a[i];
                a[i]=a[j];
                a[j]=aux;
            }
        }
    }
}
int main()
{
    FILE *f=fopen("activitati.in","r");
    fscanf(f,"%d ",&nrActivitati);
    for(int i=0; i<nrActivitati; i++)
    {
        fscanf(f,"%d %d %s",&a[i].inceput,&a[i].finalizat,&a[i].nume);
    }
    sortareActivitati();
    //afisareActivitati();
    int indice=0;
    aGasite[indice]=a[0];
    for(int i=0;i<nrActivitati;i++) {
        int out=0;
        while(aGasite[indice].inceput < a[i].finalizat) {
            i++;
            if(i>=nrActivitati) {
                out=1;
                break;
            }
        }
        if(out==1) {
            break;
        }
        indice++;
        aGasite[indice]=a[i];
    }
    afisareActivitati(indice+1,aGasite);
    return 0;
}
