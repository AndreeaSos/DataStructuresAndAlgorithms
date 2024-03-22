#include <stdio.h>
#include <stdlib.h>

int nrVarfuri,nrArce;
int noduri[nrVarfuri];



int main()
{
    FILE *fisier=fopen("gradAdiacentaStatica.in","r");
    fscanf(fisier,"%d %d",&nrVarfuri ,&nrArce);
    return 0;
}
