#include <stdio.h>
int main() {
    double n1, n2; // Usamos double para suportar números gigantes de forma simples
    while (scanf("%lf %lf", &n1, &n2) != EOF) {
        if (n1 > n2) {
            printf("%.0f\n", n1 - n2);
        } else {
            printf("%.0f\n", n2 - n1);
        }
    }
    return 0;
}
