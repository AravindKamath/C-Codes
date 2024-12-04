#include<stdio.h>
#include<string.h>
void main(){
    char s[50];
    int len,flag=0;
    printf("String:");
    scanf("%s",s);
    len=strlen(s);
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1]){
            flag=1;
        }
    }
    if(flag==0)
        printf("%s is a palindrome",s);
    else
        printf("%s is not a palindrome",s);
}
