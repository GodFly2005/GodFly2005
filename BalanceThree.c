#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int n;
int main(void){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char ter[81]="";
        bool flag=true,is_minus=true;
        scanf("%s",ter);
        int len=strlen(ter);
        for(int j=0;j<len;j++){
            if(ter[j]=='Z'){
                printf("Radix Error\n");
                flag=false;
                break;
            }}
        if(!flag)
        continue;
        int dec=atoi(ter);
        if(dec>=0){
            is_minus=false;
        }
        dec=abs(dec);
        char thr[81]="";
        int k=0;
        do{
            k++;
            thr[k]=dec%3+'0';
            dec/=3;
        }while(dec>0);
        thr[k+1]='0';
        for(int j=1;j<=k;j++){
            switch(thr[j]){
                case '2':thr[j]='Z';break;
                case '3':thr[j]='0';break;
                case '0':case '1':continue;
            }
            thr[j+1]++;
        }
        if(is_minus){
            if(thr[k+1]=='0'){
                for(int j=1;j<=k;j++){
                switch(thr[j]){
                    case '1':thr[j]='Z';break;
                    case 'Z':thr[j]='1';break;
                }
                }
                for(int j=k;j>=1;j--){
                    printf("%c",thr[j]);
                }
            }
            else{
                for(int j=1;j<=k+1;j++){
                switch(thr[j]){
                    case '1':thr[j]='Z';break;
                    case 'Z':thr[j]='1';break;
                }
                }
                for(int j=k+1;j>=1;j--){
                    printf("%c",thr[j]);
                }
            }
        }
        else{
            if(thr[k+1]=='0'){
                for(int j=k;j>=1;j--){
                    printf("%c",thr[j]);
                }
            }
            else{
                for(int j=k+1;j>=1;j--){
                    printf("%c",thr[j]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}