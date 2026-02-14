#include <stdio.h>

// Desafio Batalha Naval - MateCheck
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HAB 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

int main() {
  
    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.
   
   
    // Matriz que representa o tabuleiro
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // ============================
    // INICIALIZA TABULEIRO
    // ============================
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ============================
    // POSICIONA NAVIOS (fixos)
    // ============================
    // Horizontal
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[1][2 + i] = NAVIO;

    // Vertical
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[4 + i][0] = NAVIO;

    // Diagonal principal
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[2 + i][5 + i] = NAVIO;

    // Diagonal secundária
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[6 + i][7 - i] = NAVIO;

    // ============================
    // MATRIZES DE HABILIDADE
    // ============================
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    // ============================
    // CONSTRUÇÃO DO CONE (↧)
    // ============================
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // ============================
    // CONSTRUÇÃO DA CRUZ
    // ============================
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // ============================
    // CONSTRUÇÃO DO OCTAEDRO (losango)
    // ============================
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // ============================
    // ORIGENS DAS HABILIDADES
    // ============================
    int origemConeLinha = 0, origemConeColuna = 4;
    int origemCruzLinha = 5, origemCruzColuna = 5;
    int origemOctLinha  = 8, origemOctColuna  = 2;

    // ============================
    // SOBREPOSIÇÃO DAS HABILIDADES
    // ============================
    int offset = TAM_HAB / 2;

    // Cone
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int l = origemConeLinha + i - offset;
            int c = origemConeColuna + j - offset;

            if (cone[i][j] == 1 &&
                l >= 0 && l < TAM_TABULEIRO &&
                c >= 0 && c < TAM_TABULEIRO &&
                tabuleiro[l][c] == AGUA) {
                tabuleiro[l][c] = HABILIDADE;
            }
        }
    }

    // Cruz
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int l = origemCruzLinha + i - offset;
            int c = origemCruzColuna + j - offset;

            if (cruz[i][j] == 1 &&
                l >= 0 && l < TAM_TABULEIRO &&
                c >= 0 && c < TAM_TABULEIRO &&
                tabuleiro[l][c] == AGUA) {
                tabuleiro[l][c] = HABILIDADE;
            }
        }
    }

    // Octaedro
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int l = origemOctLinha + i - offset;
            int c = origemOctColuna + j - offset;

            if (octaedro[i][j] == 1 &&
                l >= 0 && l < TAM_TABULEIRO &&
                c >= 0 && c < TAM_TABULEIRO &&
                tabuleiro[l][c] == AGUA) {
                tabuleiro[l][c] = HABILIDADE;
            }
        }
    }

    // ============================
    // EXIBIÇÃO DO TABULEIRO
    // ============================
    printf("\n=== TABULEIRO FINAL COM HABILIDADES ===\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

  
    return 0;
}
