#include<stdio.h>
void linsearch(int a[50],int size,int key){
    int i,flag=0;
    for(i=0;i<size;i++){
        if(key==a[i]){
            flag=1;
            printf("\nSUCCESS\n%d found in %d",key,i+1);
            break;
        }
    }
    if (flag==0)
        printf("\nFAILURE\n%d not found",key);
}

void main(){
    int a[50],size,key;
    printf("Size");
    scanf("%d",&size);
    printf("Elements");
    for(int i=0;i<size;i++)
        scanf("%d",&a[i]);
    printf("Key");
    scanf("%d",&key);
    linsearch(a,size,key);

}