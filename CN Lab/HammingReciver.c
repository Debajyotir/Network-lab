#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    char str[50];
    gets(str);
    int n = strlen(str);
    int r=0;
    while(1){
        if(pow(2,r)>=n+1)
            break;
        r++;
    }
    printf("No of redundant bits are: %d",r);
    int arr[50];
    int j = 0;
    for(int i=n;i>0;i--){
        arr[i]=str[j++]-'0';
    }
    int cnt = 0;
    int l = 1;
    int k = 0;
    int arr2[50];
    for(int i=0;i<r;i++){
        int temp = 0;
        int z = pow(2,i);
        for(j=z;j<=n;j=z+k){
            for(k=j;k<j+z;k++){
                if(k<=n)
                    temp+=arr[k];
            }
        }
        arr2[l++]=temp%2;
        cnt+=temp%2;
    }
    
    if(cnt==0){
        printf("\nAccepted");
    }
    else{
        cnt = 0;
        for(int i=r;i>0;i--){
            if(arr2[i]==1)
                cnt+=pow(2,(i-1));
        }
        printf("\nThe error at pos %d\n",cnt);
        if(arr[cnt]==0)
            arr[cnt]=1;
        else 
            arr[cnt]=0;
        for(int i=n;i>0;i--){
            printf("%d",arr[i]);
        }
    }

    return 0;
}