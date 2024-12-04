#include<stdio.h>
void main(){
    int a,b,temp1,temp2,rem;
    printf("2 numbers:");
    scanf("%d%d",&a,&b);
    temp1=a;
    temp2=b;
    while(b!=0){
        rem=a%b;
        a=b;
        b=rem;
    }
    printf("GCD=%d",a);
    printf("LCM=%d",(temp1*temp2)/a);
}