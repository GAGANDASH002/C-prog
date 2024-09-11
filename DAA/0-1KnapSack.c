#include <stdio.h>


int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int P[], int W[], int n, int C) {
    int M[n + 1][C + 1];

 
    for (int o = 0; o <= n; o++) {
        for (int c = 0; c <= C; c++) {
            if (o == 0 || c == 0)
                M[o][c] = 0;
            else if (W[o - 1] < c)
                M[o][c] = max(M[o - 1][c], P[o - 1] + M[o - 1][c - W[o - 1]]);
            else
                M[o][c] = M[o - 1][c];
        }
    }

   
    return M[n][C];
}

int main() {
    int P[] = {60, 100, 120};  
    int W[] = {10, 20, 30};   
    int C = 50;                
    int n = sizeof(P) / sizeof(P[0]); 

    int maxValue = knapsack(P, W, n, C);
    printf("The maximum value that can be accommodated in the knapsack is %d\n", maxValue);

    return 0;
}