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
    // Matriz que representa o tabuleiro
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicialização do tabuleiro com água (0)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ===============================
    // NAVIO 1 - HORIZONTAL
    // ===============================
    int linhaH = 1, colunaH = 2;

    if (colunaH + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio horizontal fora dos limites.\n");
        return 1;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaH][colunaH + i] != AGUA) {
            printf("Erro: Sobreposição no navio horizontal.\n");
            return 1;
        }
        tabuleiro[linhaH][colunaH + i] = NAVIO;
    }

    // ===============================
    // NAVIO 2 - VERTICAL
    // ===============================
    int linhaV = 4, colunaV = 0;

    if (linhaV + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio vertical fora dos limites.\n");
        return 1;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaV + i][colunaV] != AGUA) {
            printf("Erro: Sobreposição no navio vertical.\n");
            return 1;
        }
        tabuleiro[linhaV + i][colunaV] = NAVIO;
    }

    // ===============================
    // NAVIO 3 - DIAGONAL PRINCIPAL (↘)
    // linha e coluna aumentam juntas
    // ===============================
    int linhaD1 = 2, colunaD1 = 5;

    if (linhaD1 + TAM_NAVIO > TAM_TABULEIRO ||
        colunaD1 + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio diagonal principal fora dos limites.\n");
        return 1;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaD1 + i][colunaD1 + i] != AGUA) {
            printf("Erro: Sobreposição no navio diagonal principal.\n");
            return 1;
        }
        tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
    }

    // ===============================
    // NAVIO 4 - DIAGONAL SECUNDÁRIA (↙)
    // linha aumenta, coluna diminui
    // ===============================
    int linhaD2 = 6, colunaD2 = 7;

    if (linhaD2 + TAM_NAVIO > TAM_TABULEIRO ||
        colunaD2 - (TAM_NAVIO - 1) < 0) {
        printf("Erro: Navio diagonal secundaria fora dos limites.\n");
        return 1;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaD2 + i][colunaD2 - i] != AGUA) {
            printf("Erro: Sobreposição no navio diagonal secundaria.\n");
            return 1;
        }
        tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
    }

    // ===============================
    // EXIBIÇÃO DO TABULEIRO
    // ===============================
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

  
    return 0;
}
