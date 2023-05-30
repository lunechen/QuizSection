#include <stdio.h>


unsigned int E(unsigned int M) {
    return M ^ 3610409;
}
unsigned int getRangeBits(unsigned int A, unsigned int i, unsigned int j) {
    return ((A << (32 - j)) >> (32 - j)) >> (i - 1);
}


unsigned int concatenate(unsigned int A, unsigned int i, unsigned int j, unsigned int B, unsigned int x, unsigned int y) {
    return (getRangeBits(A, i, j) << (y - x + 1)) | getRangeBits(B, x, y);
}


int main() {
    unsigned int M, C, U, V, Vl = 520;


    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &M);
        U = E(Vl);
        C = M ^ getRangeBits(U, 1, 8);
        V = concatenate(Vl, 9, 32, C, 1, 8);
       
        Vl = V;
        printf("%u ", C);
    }
    printf("\n");
}
