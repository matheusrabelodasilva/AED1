//Dijkstra, exercicio do caminho e das rotas 
#include <stdio.h>
#include <stdlib.h> 
#define INFINITO 99999999
#define MAX 255
// Declarar como global limpa a memória automaticamente e evita Stack Overflow
int adj[MAX][MAX];
int dist[MAX];
int visitado[MAX];
int main() {
    int N_cidades, N_estradas, N_rotas, Conserto;
    int origem, destino, peso, i, j;
    // A leitura deve capturar os 4 valores e parar quando todos forem 0
    while (scanf("%d %d %d %d", &N_cidades, &N_estradas, &N_rotas, &Conserto) == 4 && (N_cidades != 0 || N_estradas != 0 || N_rotas != 0 || Conserto != 0)) {
        // 1. Inicializar Matriz e Vetores
        for (i = 0; i < N_cidades; i++) {
            for (j = 0; j < N_cidades; j++) {
                if (i == j) adj[i][j] = 0;
                else adj[i][j] = INFINITO;// se nossa aresta nao tiver conexao entre os vertices, colocamos infinito pois seria "infinito" o caminho para chegar de A ate B
            }
            dist[i] = INFINITO;//inicializamos desse jeito para podermos fazer a comparação no dijkstra
            visitado[i] = 0;
        }
        // 2. Construção do Grafo com as Regras de Desvio
        for (i = 0; i < N_estradas; i++) {
            scanf("%d %d %d", &origem, &destino, &peso);
            // REGRA: Se ambos estão na rota de serviço (0 até C-1)
            if (origem < N_rotas && destino < N_rotas) {
                // Só cria a aresta se forem cidades vizinhas na rota E apenas para frente (i -> i+1)
                if (origem - destino == 1) { // origem é o próximo de destino
                    adj[destino][origem] = peso;
                } else if (destino - origem == 1) { // destino é o próximo de origem
                    adj[origem][destino] = peso;
                }
            }
            // REGRA: Se origem está na rota e destino está fora, o veículo só pode ir de destino para origem (entrar na rota)
            else if (origem < N_rotas) {
                adj[destino][origem] = peso;
            }
            // REGRA: Se destino está na rota e origem está fora, o veículo só pode ir de origem para destino (entrar na rota)
            else if (destino < N_rotas) {
                adj[origem][destino] = peso;
            }
            // REGRA: Ambos fora da rota, estrada normal bidirecional
            else {
                adj[origem][destino] = peso;
                adj[destino][origem] = peso;
            }
        }
        // 3. Algoritmo de Dijkstra
        dist[Conserto] = 0; // Começa na cidade de origem Conserto
        for (i = 0; i < N_cidades; i++) {
            int atual = -1;
            int menor_dist = INFINITO;
            // Busca o vértice não visitado com a menor distância atual
            for (j = 0; j < N_cidades; j++) {
                if (!visitado[j] && dist[j] < menor_dist) {
                    menor_dist = dist[j];
                    atual = j;
                }
            }
            if (atual == -1) break; // Não há mais nós alcançáveis
            visitado[atual] = 1;
            // Relaxação das arestas
            for (j = 0; j < N_cidades; j++) {
                if (adj[atual][j] != INFINITO && !visitado[j]) {//se o vertice atual nao foi visitado e houver uma aresta entre o vertice atual e o vertice j
                    if (dist[atual] + adj[atual][j] < dist[j]) {
                        dist[j] = dist[atual] + adj[atual][j];
                    }
                }
            }
        }

        // A resposta é a distância acumulada até o final da rota (N_rotas-1)
        printf("%d\n", dist[N_rotas - 1]);
    }
    return 0;
}
