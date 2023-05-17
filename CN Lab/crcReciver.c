#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    printf("Enter the dataword: ");
    char str[50];
    gets(str);
    int n = strlen(str);
    printf("Enter the polynomial: ");
    char div[50];
    gets(div);
    int m = strlen(div);
    char s[50];
    for(int i=0;i<n-m+1;i++){
        s[i]=str[i];
    }
    int i = 0;
    while(n>i){
        if(i+m-1>=n)
            break;
        int k = 0;
        int f = 1;
        for(int j=0;j<m;j++){
            if((str[i]=='1'&& div[j]=='0') || (str[i]=='0'&& div[j]=='1')){
                str[i]='1';
                if(f==1){
                    f=0;
                    k=i;
                }
            }
            else
                str[i]='0';
            i++;
        }
        if(k!=0)
            i=k;
        else{
            for(;i<n;i++){
                if(str[i]=='1')
                    break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(str[i]=='1'){
            printf("Wrong Data");
            break;
        }
        if(i+1==n){
            printf("Correct Data");
            printf("\nOriginal codeword is: %s",s);
        }
    }
    return 0;
}