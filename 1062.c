#include <stdio.h>
#define MAX_COACHES 1001
int main() {
    int n;
    int target_order[MAX_COACHES];
    int station_stack[MAX_COACHES];
    int first_coach;
    while (scanf("%d", &n) == 1 && n != 0) {
        while (1) {
            scanf("%d", &first_coach);
            if (first_coach == 0) {
                printf("\n");
                break;
            }
            target_order[0] = first_coach;
            for (int i = 1; i < n; i++) {
                scanf("%d", &target_order[i]);
            }
            int top = -1;
            int target_idx = 0;
            for (int coach_from_a = 1; coach_from_a <= n; coach_from_a++) {
                station_stack[++top] = coach_from_a;
                while (top != -1 && station_stack[top] == target_order[target_idx]) {
                    top--;
                    target_idx++;
                }
            }
            if (top == -1) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}
