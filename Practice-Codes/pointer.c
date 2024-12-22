#include<stdio.h>
void add(int a[50],int size,int *p){
    int sum=0;
    p=a;
    for(int i=0;i<size;i++){
        *p=a[i];
        sum+=*p;
        p+=1;
    }
    printf("sum=%d",sum);
}

void main(){
    int a[50],size,i,*p,sum;
    printf("size");
    scanf("%d",&size);
    printf("Array");
    for(i=0;i<size;i++)
        scanf("%d",&a[i]);
    add(a,size,p);
}