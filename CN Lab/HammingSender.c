#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    char str[50];
    gets(str);
    int n = strlen(str);
    int r=0;
    while(1){
        if(pow(2,r)>=n+r+1)
            break;
        r++;
    }
    printf("No of redundant bits are: %d",r);
    int arr[50];
    for(int i=0;i<r;i++){
        int z = pow(2,i);
        arr[z]=999;
    }
    int j = 0;
    for(int i=n+r;i>=1;i--){
        if(arr[i]!=999){
            arr[i]=str[j++]-'0';
        }
    }
    int k = 0;
    for(int i=0;i<r;i++){
        int z = pow(2,i);
        int temp = 0;
        for(j=z;j<=n+r;j=z+k){
            for(k=j;k<z+j;k++){
                if(k<=n+r && arr[k]!=999)
                    temp += arr[k];
            }
        }
        arr[z]=temp%2;
    }
    printf("\nThe codeword is: ");
    for(int i=n+r;i>=1;i--){
        printf("%d",arr[i]);
    }
    return 0;
}