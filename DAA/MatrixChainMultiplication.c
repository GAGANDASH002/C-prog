#include<stdio.h>
int min(int d0, int d1, int d2, int d3) {
    int c11 =0;
    int c23 = d1 * d2 * d3;
    int c12= d0 * d1 * d2;
    int c33 =0;

    int min_mult1 = c12 + c33+(d0*d2*d3);
    int min_mult2 = c11 + c23+(d0*d1*d3);

    return (min_mult1 < min_mult2) ? min_mult1 : min_mult2;
}

int main(){
    int  d0,d1,d2,d3;
    printf("Enter the dimenstions d0 d1 d2 d3 :");
    scanf("%d %d %d %d", &d0, &d1, &d2, &d3);
    int min_mult = min(d0, d1, d2, d3);
    printf("Minimum number of multiplication required : %d",min_mult);
}