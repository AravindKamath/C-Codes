#include<stdio.h>
void read(int m[10][10],int r,int c){
    for(int i=0;i<r;i++){
        printf("\n");
        for(int j=0;j<c;j++)
            printf("%d",m[i][j]);
    }
}

void transpose(int m[10][10],int t[10][10],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            t[j][i]=m[i][j];
    }
}

void trace(int t[10][10],int r){
    int sum=0;
    for(int i=0;i<r;i++)
        sum+=t[i][i];
    printf("%d",sum);
}

void main(){
    int m[10][10],t[10][10],r,c,i,j;
    printf("Enter rows and columns\n");
    scanf("%d%d",&r,&c);
    printf("Enter Array\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            scanf("%d",&m[i][j]);
    }
    printf("Matrix:\n");
    read(m,r,c);
    printf("\nTranspose:\n");
    transpose(m,t,r,c);
    read(t,r,c);
    printf("\nTrace:\n");
    trace(t,r);
}