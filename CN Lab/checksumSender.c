#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    printf("Enter the dataword: ");
    char str[50];
    gets(str);
    int n = strlen(str);
    printf("Enter the segment length: ");
    int len;
    scanf("%d",&len);
    int i = 1;
    int valid = 1;
    while(1){
        int k = pow(2,i);
        if(k==len)
            break;
        else if(k>len){
            printf("Wrong seg lenth: ");
            valid = 0;
            break;
        }
        i++;
    }



    if(valid){
        int arr[50];
        int temp = n;
        i=0;
        if(n%len!=0){
            i = n%len;
            for(int j=0;j<i;j++){
                arr[j]=0;
            }
            temp+=i;
        }
        for(int j=0;j<n;j++){
            arr[i++]=str[j]-'0';
        }
        n=temp;

        int v[50];
        for(i=0;i<len;i++){
            v[i]=arr[i];
        }
        for(;i<n;i+=0){
            int carry = 0;
            int a[len];
            for(int j=0;j<len;j++){
                a[j] = arr[i++];
            }

            for(int j=len-1;j>=0;j--){
                temp = v[j]+a[j]+carry;
                v[j] = temp%2;
                carry = temp/2;
            }
            if(carry){
                for(int j=len-1;j>=0;j--){
                    temp = v[j]+carry;
                    v[j] = temp%2;
                    carry = temp/2;
                }
            }
        }
        printf("\nThe checksum is: ");
        for(int j=0;j<len;j++){
            if(v[j]==1)
                v[j]=0;
            else
                v[j]=1;
            printf("%d",v[j]);
        }
        printf("\nThe codeward is: ");
        for(int j=0;j<n;j++){
            printf("%d",arr[j]);
        }
        for(int j=0;j<len;j++){
            printf("%d",v[j]);
        }

    }
    return 0;
}