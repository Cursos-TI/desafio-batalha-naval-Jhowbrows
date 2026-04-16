#include <stdio.h>

#define NAVIO 3 
#define TABULEIRO 10
#define HABILIDADE 5 // Tamanho fixo das matrizes de habilidade (5x5)

int main() {
    // Definição do Tabuleiro e Rótulos
    char letras[TABULEIRO] = {'A','B','C','D','E','F','G','H','I','J'};   
    int tabuleiro[TABULEIRO][TABULEIRO] = {0}; 

    // Posicionamento dos Navios 
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[2][4 + i] = 3;         // Horizontal
        tabuleiro[5 + i][7] = 3;         // Vertical
        tabuleiro[0 + i][0 + i] = 3;     // Diagonal Principal
        tabuleiro[7 - i][1 + i] = 3;     // Diagonal Secundária
    }

    // Criação das Matrizes de Habilidade 
    int cone[HABILIDADE][HABILIDADE], cruz[HABILIDADE][HABILIDADE], octaedro[HABILIDADE][HABILIDADE];

    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            
            // Lógica do CONE (Topo no centro, expandindo para baixo)
            // Na linha 0: apenas col 2 | linha 1: col 1 a 3 | linha 2: col 0 a 4
            if (i < 3 && j >= 2 - i && j <= 2 + i) cone[i][j] = 1;
            else cone[i][j] = 0;

            // Lógica da CRUZ (Linha central ou Coluna central)
            if (i == 2 || j == 2) cruz[i][j] = 1;
            else cruz[i][j] = 0;

            // Lógica do OCTAEDRO 
            // Usamos uma variável de largura que cresce até a linha 2 e depois diminui
            int largura = (i <= 2) ? i : 4 - i; 
            if (j >= 2 - largura && j <= 2 + largura) octaedro[i][j] = 1;
            else octaedro[i][j] = 0;
        }
    }

    // Sobreposição das Habilidades no Tabuleiro
    // Definição de pontos de origem fixos (L, C)
    int origens[3][2] = {{1, 8}, {8, 2}, {5, 2}}; // Cone, Cruz, Octaedro

    for (int h = 0; h < 3; h++) { // Loop para percorrer as 3 habilidades
        for (int i = 0; i < HABILIDADE; i++) {
            for (int j = 0; j < HABILIDADE; j++) {
                
                // Calcula a posição no tabuleiro (centralizando a matriz 5x5)
                int r = origens[h][0] + (i - 2);
                int c = origens[h][1] + (j - 2);

                // Validação de limites (Garante que não saia do tabuleiro 10x10)
                if (r >= 0 && r < TABULEIRO && c >= 0 && c < TABULEIRO) {
                    int valor_hab = 0;
                    if (h == 0) valor_hab = cone[i][j];
                    else if (h == 1) valor_hab = cruz[i][j];
                    else valor_hab = octaedro[i][j];

                    // Se a habilidade marcar 1, aplicamos o valor 5 no tabuleiro
                    if (valor_hab == 1) tabuleiro[r][c] = 5;
                }
            }
        }
    }

    // Exibição do Tabuleiro Final
    printf("TABULEIRO BATALHA NAVAL \n   ");
    for(int i = 0; i < TABULEIRO; i++) printf("%c ", letras[i]);
    printf("\n");

    for(int i = 0; i < TABULEIRO; i++) {
        printf("%2d ", i + 1); 
        for(int j = 0; j < TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); 
        }
        printf("\n");
    }

    return 0;
}
