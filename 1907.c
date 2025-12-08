#include <stdio.h>

#define MAX 1025

char grid[MAX][MAX];
int N, M;

typedef struct {
    int x, y;
} Ponto;

Ponto fila[MAX * MAX];

void bfs(int i, int j) {
    int inicio = 0, fim = 0;
    
    fila[fim].x = i;
    fila[fim].y = j;
    fim++;
    
    grid[i][j] = 'o'; 

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (inicio < fim) {
        Ponto atual = fila[inicio];
        inicio++;

        for (int k = 0; k < 4; k++) {
            int nx = atual.x + dx[k];
            int ny = atual.y + dy[k];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == '.') {
                grid[nx][ny] = 'o';
                fila[fim].x = nx;
                fila[fim].y = ny;
                fim++;
            }
        }
    }
}

int main() {
    // O problema no Beecrowd geralmente pode ter multiplos casos de teste ou apenas um
    // O padrao com EOF cobre ambos os cenarios
    while (scanf("%d %d", &N, &M) != EOF) {
        for (int i = 0; i < N; i++) {
            scanf("%s", grid[i]);
        }

        int clicks = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '.') {
                    clicks++;
                    bfs(i, j);
                }
            }
        }

        printf("%d\n", clicks);
    }

    return 0;
}
