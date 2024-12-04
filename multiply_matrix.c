#include<stdio.h>
void read(int m[10][10],int r,int c){
    printf("Enter elements\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            scanf("%d",&m[i][j]);
    }
}

void display(int m[10][10],int r,int c){
    for(int i=0;i<r;i++){
        printf("\n");
        for(int j=0;j<c;j++)
            printf("%d\t",m[i][j]);
    }
}

void multiply(int m1[10][10],int m2[10][10],int m3[10][10],int r1,int c1,int r2,int c2){
    int i,j,k;
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            m3[i][j]=0;
            for(k=0;k<c1;k++)
                m3[i][j]=m3[i][j]+(m1[i][k]*m2[k][j]);
        }
    }
}

void main(){
    int m1[10][10],r1,c1,m2[10][10],r2,c2,m3[10][10];
    printf("Rows & Columns M1");
    scanf("%d%d",&r1,&c1);
    printf("Rows & Columns M2");
    scanf("%d%d",&r2,&c2);
    if(c1==r2){
        printf("M1:\n");
        read(m1,r1,c1);
        printf("M2:\n");
        read(m2,r2,c2);
        printf("\nM1:\n");
        display(m1,r1,c1);
        printf("\nM2:\n");
        display(m2,r2,c2);
        printf("\nProduct:\n");
        multiply(m1,m2,m3,r1,c1,r2,c2);
        display(m3,r1,c2);
    }
    else
        printf("Matrix Not Computable");

}