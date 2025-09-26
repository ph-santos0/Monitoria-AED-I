#include <stdio.h>

void somaMostra(int M, int W) {
    int C = M + W;
    printf("C = %d\n", C);
}

int main() {
    int M, W;
    printf("Digite M e W: ");
    scanf("%d %d", &M, &W);
    somaMostra(M, W);
    return 0;
}
