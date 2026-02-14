#include <stdio.h>

// Desafio Batalha Naval - MateCheck
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
  
    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.
    // Declaração do tabuleiro 10x10
    
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Declaração dos navios (vetores unidimensionais)
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO]   = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais dos navios (definidas no código)
    int linhaH = 2, colunaH = 3; // Navio horizontal
    int linhaV = 5, colunaV = 6; // Navio vertical

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Validação do navio horizontal (limites)
    if (colunaH + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Posiciona o navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // Validação do navio vertical (limites)
    if (linhaV + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Verifica sobreposição antes de posicionar o navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaV + i][colunaV] == NAVIO) {
            printf("Erro: Sobreposição de navios detectada.\n");
            return 1;
        }
    }

    // Posiciona o navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // Exibe o tabuleiro
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

  
    return 0;
}
