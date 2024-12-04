#include<stdio.h>
#include<math.h>
void main(){
    int a[50],size,i,sum=0,var=0;
    float mean,std,variance;
    printf("size");
    scanf("%d",&size);
    printf("Array");
    for(i=0;i<size;i++)
        scanf("%d",&a[i]);
    for(i=0;i<size;i++)
        sum+=a[i];
    mean=sum/size;
    for(i=0;i<size;i++)
        var+=pow(a[i]-mean,2);
    variance=var/size;
    std=sqrt(variance);
    printf("Mean=%f",mean);
    printf("Variance=%f",variance);
    printf("Standard deviation=%f",std);
}