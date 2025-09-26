#include <stdio.h>

int somaRetorna(int M, int W) {
    return M + W;
}

int main() {
    int M, W, C;
    printf("Digite M e W: ");
    scanf("%d %d", &M, &W);
    C = somaRetorna(M, W);
    printf("C = %d\n", C);
    return 0;
}
