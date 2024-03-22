#include <stdio.h>
#include <stdlib.h>

int a[100]={1,9, 7,5, 3, 10, 50, 71, 200, 500};
int sumaCautata=154;//500+100+50+1+1+1+1
int nrTipuri=10;
int sumaMea=0;
int index=0;


int main()
{
    for(int i=0;i<nrTipuri-1;i++){
        for(int j=i+1;j<nrTipuri;j++){
            if(a[i]>a[j]){
                int aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
        }
    }
    /*while(sumaMea<sumaCautata){
        if(sumaMea+a[index]<=sumaCautata){
                sumaMea+=a[index];
        if(sumaMea<sumaCautata){
            printf("%d+",a[index]);
        }else{
            printf("%d ",a[index]);

        }

    }else{
        index++;
    }
    }*/
    for(int i=0;i<nrTipuri;i++){
        if(sumaMea+a[i]<=sumaCautata){
                sumaMea+=a[i];
        if(sumaMea<sumaCautata){
            printf("%d+",a[i]);
        }else{
            printf("%d ",a[i]);
            break;
        }

    }
    }
    return 0;
}
