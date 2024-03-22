#include <stdio.h>
#include <stdlib.h>
int m;
int* hashMap;
int* hashMapCuadratic;
int* hashMapVerificare;

void insert_adresare_deschisa(int valDeIntrodusParam)
{
    int valDeIntrodus = valDeIntrodusParam; //value for the map
    int indice= valDeIntrodus % m; //key for the map
    if(hashMap[indice] == -1)
    {
        hashMap[indice] = valDeIntrodus;
    }
    else
    {
        int introdus=0;
        for(int j=indice +1; j<m; j++)
        {

            if(hashMap[j] == -1)
            {
                hashMap[j] = valDeIntrodus;
                introdus=1;
                break;
            }
        }
        if(introdus==0)
        {
            for(int i=0; i<indice; i++)
            {
                if(hashMap[i] == -1)
                {
                    hashMap[i] = valDeIntrodus;
                    introdus=1;
                    break;
                }
            }
        }
        if(introdus==0)
        {
            printf("Nu mai am memorie in hashmap.");
        }
    }
}


void afisare_adr_deschisa()
{
    for(int i=0; i<m; i++)
    {
        printf("%d ",hashMap[i]);
    }
    printf("\n");
}

int index_liniar(nrCautat,i)
{
    return (nrCautat+i)%m;
}
int cauta(int nrCautat)  //15
{
    for(int i=0; i<m; i++)
    {
        int indice= index_liniar(nrCautat,i);//7
        if(hashMap[indice]==nrCautat)
        {
            return indice;
        }
    }
    return -1;
}
void adresare_deschisa()
{
    m=8;//dimensiunea
    hashMap=(int *)malloc(sizeof(int)*m);
    //initializare
    for(int i=0; i<m; i++)
    {
        hashMap[i]=-1;
    }
    insert_adresare_deschisa(72);
    insert_adresare_deschisa(18);
    insert_adresare_deschisa(43);
    insert_adresare_deschisa(36);
    insert_adresare_deschisa(6);
    insert_adresare_deschisa(10);
    insert_adresare_deschisa(5);
    insert_adresare_deschisa(15);

    int index=cauta(15);
    printf("\n%d\n",index);

    //stergere
    hashMap[index]=-1;

    afisare_adr_deschisa();
}
int index_cuadratic(int c1,int c2, int nr,int i) {
    int h_prim=nr%m;
    return (h_prim + c1 *i +c2 * i * i) % m;
}
void insert_adresare_deschisa_cuadratic(int nr,int c1,int c2) {
    for(int i=0; i<m; i++)
    {
        int indice= index_cuadratic(c1,c2,nr,i);//7
        if(hashMapCuadratic[indice]==-1)
        {
            hashMapCuadratic[indice]=nr;
            break;
        }
    }
    //nu mai e loc de inserat
}
void afisare_cuadratic() {
    for(int i=0;i<m;i++) {
        printf("%d ",hashMapCuadratic[i]);
    }
    printf("\n");
}



void adresare_deschisa_cuadratic()
{
    m=7;
    hashMapCuadratic=(int *)malloc(sizeof(int)*m);
    //initializare
    for(int i=0; i<m; i++)
    {
        hashMapCuadratic[i]=-1;
    }
    int c1=1,c2=1;
    insert_adresare_deschisa_cuadratic(19,c1,c2);
    insert_adresare_deschisa_cuadratic(36,c1,c2);
    insert_adresare_deschisa_cuadratic(5,c1,c2);
    insert_adresare_deschisa_cuadratic(21,c1,c2);
    insert_adresare_deschisa_cuadratic(4,c1,c2);
    insert_adresare_deschisa_cuadratic(26,c1,c2);
    insert_adresare_deschisa_cuadratic(14,c1,c2);

    afisare_cuadratic();
}
int index_verificare( int nr,int i) {
    int h1=nr%m;
    int h2=5-(nr%5);
    return (h1+ i*h2) % m;
}
void insert_adresare_verificare_dubla(int nr) {
    for(int i=0; i<m; i++)
    {
        int indice= index_verificare(nr,i);//7
        if(hashMapVerificare[indice]==-1)
        {
            hashMapVerificare[indice]=nr;
            break;
        }
    }
    //nu mai e loc de inserat
}

void afisare_verificare_dubla() {
    for(int i=0;i<m;i++) {
        printf("%d ",hashMapVerificare[i]);
    }
    printf("\n");
}

int cauta_verificare(int nrCautat)  //15
{
    for(int i=0; i<m; i++)
    {
        int indice= index_verificare(nrCautat,i);//7
        if(hashMapVerificare[indice]==nrCautat)
        {
            return indice;
        }
    }
    return -1;
}

void adresare_verificare_dubla(){
     m=7;
    hashMapVerificare=(int *)malloc(sizeof(int)*m);
    //initializare
    for(int i=0; i<m; i++)
    {
        hashMapVerificare[i]=-1;
    }
    int c1=1,c2=1;
    insert_adresare_verificare_dubla(19);
    insert_adresare_verificare_dubla(36);
    insert_adresare_verificare_dubla(5);
    insert_adresare_verificare_dubla(21);
    insert_adresare_verificare_dubla(4);
    insert_adresare_verificare_dubla(26);
    insert_adresare_verificare_dubla(14);

     int index=cauta_verificare(21);
    printf("\n%d\n",index);

    //stergere
    hashMapVerificare[index]=-1;

    afisare_verificare_dubla();
}

void modifica_x(int *x)
{
    *x=9;
}
int main()
{
    adresare_deschisa();//h(k)= key % table_size
    adresare_deschisa_cuadratic();
    adresare_verificare_dubla();
    /*
    int x=8;
    printf("%d\n",x);
    modifica_x(&x);
    printf("%d",x);
    */
    return 0;
}
