#include<stdio.h>
#include<math.h>
void roots(int a,int b,int c){
    float d,r1,r2;
    d=b*b-(4*a*c);
    if (d==0){
        printf("Equal\n");
        r1=(-b+sqrt(d))/(2*a);
        printf("%f",r1);
    }
    else if(d>0){
        printf("Real\n");
        r1=(-b+sqrt(d))/(2*a);
        r2=(-b-sqrt(d))/(2*a);
        printf("%f\n",r1);
        printf("%f",r2);
    }
    else
        printf("Imaginary");

}

void main(){
    int a,b,c;
    printf("a,b,c");
    scanf("%d%d%d",&a,&b,&c);
    roots(a,b,c);
}