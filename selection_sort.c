#include<stdio.h>
void sort(int a[50],int n){
    int i,j,pos,temp;
    for(i=0;i<n-1;i++){
        pos=i;
        for(j=i+1;j<n;j++){
            if(a[pos]>a[j])
                pos=j;
        }
        temp=a[i];
        a[i]=a[pos];
        a[pos]=temp;
    }

}

void main(){
    int a[100],n,i,j,temp;
    printf("Enter size of array\n");
    scanf("%d",&n);
    printf("enter unsorted array elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nUnsorted Array:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    sort(a,n);
    printf("\nSorted Array:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}