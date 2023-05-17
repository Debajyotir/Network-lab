#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    printf("Enter the codeword: ");
    char str[50];
    gets(str);
    int n = strlen(str);
    printf("Enter the segment length: ");
    int len;
    scanf("%d",&len);
    int i = 1;
    int valid = 1;
    while(1){
        int k = pow(2,i++);
        if(k==len)
            break;
        else if(k>len){
            valid = 0;
            break;
        }
    }
    if(valid){
        int v[len];
        for(i=0;i<len;i++){
            v[i]=str[i]-'0';
        }
        for(;i<n;i+=0){
            int a[len];
            for(int j=0;j<len;j++){
                a[j] = str[i++]-'0';
            }
            int carry = 0;
            for(int j=len-1;j>=0;j--){
                int temp = v[j]+a[j]+carry;
                v[j]=temp%2;
                carry = temp/2;
            }
            if(carry){
                for(int j=len-1;j>=0;j--){
                    int temp = v[j]+carry;
                    v[j]=temp%2;
                    carry = temp/2;
                }
            }
        }
        i=1;
        for(int j=0;j<len;j++){
            if(v[j]!=1){
                printf("\nBad");
                i=0;
                break;
            }
        }
        if(i){
            printf("\nGood\n");
            for(int j=0;j<n-len;j++){
                printf("%c",str[j]);
            }
        }
    }
}