#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    printf("Enter the codeward: ");
    char str[50];
    gets(str);
    char c;
    printf("Enter the type of Parity\ne for even parity\nAnything else for odd parity : ");
    scanf("%c",&c);
    int n = strlen(str);
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(str[i]=='1')
            cnt++;
    }
    printf("The codeword %s is: ",str);
    if(c=='e'){
        if(cnt%2==0)
            printf("Good");
        else
            printf("Bad");

    }
    else{
        if(cnt%2==0)
            printf("Bad");
        else
            printf("Good");
    }
    return 0;
}