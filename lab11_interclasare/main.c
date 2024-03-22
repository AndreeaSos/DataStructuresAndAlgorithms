#include <stdio.h>
#include <stdlib.h>

int v1[10]={27,38};
int n=2;
int v2[10]={43,3};
int m=2;
int z[20]={0};

int inter(int v1[10],int v2[10],int z[20]){
    int poz=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v1[i]=v2[j]){
                poz++;
                z[poz]=v1[i];
                i++;
                j++;
            }else if(v1[i]<v2[j]){
                poz++;
                z[poz]=v1[i];
                i++;
            }else {
                poz++;
                z[poz]=v2[j];
                j++;
            }
        }
    }
    if(n>m){
        for(int i=m;i<n;i++){
                poz++;
            z[i]=v1[i];
        }
    }else if(n<m){
        for(int j=n;j<m;j++){
                poz++;
            z[j]=v2[j];
        }
    }
    //return z;
    return poz;
}

int sortare_interclasare(int v[],int st, int dr){
    if(st=dr){
        return v[st];
    }

    int m=(st+dr)/2;
    int rezStanga[10];
    int nRSt;
    int nrStanga=sortare_interclasare(v,st,m);
    int nrDreapta=sortare_interclasare(v,m+1,dr);
}

int main()
{
    int p=inter(v1,v2,z);
    for(int i=0;i<p;i++){
        printf("%d ",z[i]);
    }
    return 0;
}
