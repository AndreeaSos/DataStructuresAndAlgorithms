#include <stdio.h>
#include <stdlib.h>


int vec[10]={1,3,4,7,9,11,13};
int n=7;

int caut(int st,int dr,int cautat){
    int mij=(st+dr)/2;

    if(vec[mij]==cautat){
        return mij;
        //break;
    }
    else{
        if (vec[mij]>cautat){
            dr=mij-1;
            caut(st,dr,cautat);
        }
        else{
            if(vec[mij]<cautat){
                st=mij+1;
                caut(st,dr,cautat);
            }
            else{
                return -1;
                }

        }
    }

}


int cautareBinara(int nrCautat,int st, int dr){
if(st>dr){
    return -1;
}
int m=(st+dr)/2;
if(nrCautat<vec[m]){
    return cautareBinara(nrCautat,st,m-1);
}else if(nrCautat>vec[m]){
    return cautareBinara(nrCautat,m+1,dr);
}else{
return m;
}
}


int main()
{
    int nrCautat;
    scanf("%d",&nrCautat);
    //printf("%d",caut(0,n,nrCautat));
    int poz=cautareBinara(nrCautat,0,n);
    printf("%d",poz);
    return 0;
}
