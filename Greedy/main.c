#include <stdio.h>
#include <stdlib.h>

int a[100]={1, 5, 10, 50, 100, 200, 500};
int sumaCautata=14;//500+100+50+1+1+1+1
int nrTipuri=7;
int sumaMea=0;
int index=0;

int main()
{
    while(sumaMea<sumaCautata){
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
    }
    return 0;
}
