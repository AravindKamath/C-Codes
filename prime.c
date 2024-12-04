#include<stdio.h>
void main(){
    int a,b,flag,count;
    printf("enter starting & ending");
    scanf("%d%d",&a,&b);
    count=0;
    for(int i=a;i<=b;i++){
        flag=0;
        for(int j=2;j<=(i/2);j++){
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if (flag==0){
            count+=1;
            printf("%d\t",i);
        }
    }
    if(count>0)
        printf("\n%d within range",count);
    else
        printf("No prime");
}