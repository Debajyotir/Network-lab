#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    printf("Enter the dataword: ");
    char str[50];
    gets(str);
    printf("Enter the polynomial: ");
    char div[50];
    gets(div);
    char s[50];
    strcpy(s,str);
    int m = strlen(div);
    int n = strlen(str);
    for(int i=1;i<m;i++){
        str[n]='0';
        n++;
    }
    printf("updated divident: %s\n",str);
    int i=0;
    while(n>i){
        if(i+m-1>=n)
            break;
        int f = 1;
        int k = 0;
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
    int k = strlen(s);
    for(i=n-m+1;i<n;i++){
        s[k] = str[i];
        k++;
    }
    printf("The codeword is : %s\n",s);
    return 0;
}