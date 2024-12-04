#include<stdio.h>
void main(){
    int n,d,count,sum,rem;
    printf("Number:");
    scanf("%d",&n);
    printf("Digit:");
    scanf("%d",&d);
    sum=0;
    count=0;
    while(n!=0){
        rem=n%10;
        if(d==rem)
            count++;
        sum+=rem;
        n/=10;
    }
    printf("sum=%d,occurance=%d",sum,count);
}
