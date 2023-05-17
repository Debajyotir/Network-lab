#include <stdio.h>  
#include <math.h> 
#include <string.h>
int main(){
    printf("Enter the codeward: ");
    char str[50];
    gets(str);
    int n = strlen(str);
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(str[i]=='1')
            cnt++;
    }
    str[n+1]='\0';
    if(cnt%2==0){
        printf("\nThe even Parity bit is: 0");
        str[n] = '0';
        printf("\nThe even Parity codeword is: %s",str);
        printf("\nThe odd Parity bit is: 1");
        str[n] = '1';
        printf("\nThe odd Parity codeword is: %s",str);
    }
    else{
        printf("\nThe even Parity bit is: 1");
        str[n] = '1';
        printf("\nThe even Parity codeword is: %s",str);
        printf("\nThe odd Parity bit is: 0");
        str[n] = '0';
        printf("\nThe odd Parity codeword is: %s",str);
    }
    return 0;
}