#include<stdio.h>
void binsearch(int[],int,int);

void binsearch(int a[50],int n,int key){
    int beg,mid,end,flag;
    flag=0;
    beg=0;
    end=n-1;
    while(beg<=end){
        mid=(beg+end)/2;
        if(key==a[mid]){
            printf("%d Found in %d",key,mid+1);
            flag=1;
            break;
        }
        else if(key>a[mid])
            beg=mid+1;
        else
            end=mid-1;
    }
    if(flag==0)
        printf("%d Not Found",key);
}
void main(){
    int n,a[50],key,i;
    printf("enter size\n");
    scanf("%d",&n);
    printf("Enter Sorted Array:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("enter key to be searched\n");
    scanf("%d",&key);
    binsearch(a,n,key);

}