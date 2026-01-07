#include <stdio.h>
int main() {
    int N, K, P, i, total;
    int frequencia[105];
    while (scanf("%d %d", &N, &K) == 2 && (N != 0 || K != 0)) {
        for (i = 0; i < 105; i++) {
            frequencia[i] = 0;
        }
        for (i = 0; i < N; i++) {
            scanf("%d", &P);
            frequencia[P]++;
        }
        total = 0;
        for (i = 1; i <= 100; i++) {
            if (frequencia[i] >= K) {
                total++;
            }
        }
        printf("%d\n", total);
    }
    return 0;
}
