#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    //Variaveis de linha do cabeçalho e do tabuleiro
    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};   
    int tabuleiro[10][10] = {0};

    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    
    //variaveis dos navios
    int navio[3] = {3,3,3};
    int navio2[3] = {3,3,3};

    //Lógica da exibição dos navios no tabuleiro
    //exibição do navio1 na horizontal
    for (int i = 0; i < 3; i++) {
        tabuleiro[2][3 + i] = navio[i]; //navio horizontal
    }

    //Exibição do navio na Vertical
    for(int i = 0; i < 3; i++) {
        tabuleiro[5 + i][7] = navio2[i]; //navio vertical
    }
    
    //Exibição do tabuleiro e Criação da lógica de exbição do mesmo
    printf("Tabuleiro Batalha Naval\n");
    
    //Adição de espaço para melhor posicionamento do cabeçalho em relação ao tabuleiro
    printf("   ");

    //Loop exibindo cordenadas pelo cabeçalho (colunas) atraves das letras A-J
    for(int i = 0; i < 10; i++) {
        printf("%c ", linha[i]);
    }

    //Quebra de linha após o Cabeçalho
    printf("\n");

    //Loop exibindo o tabuleiro
    for(int i = 0; i < 10; i++) {
        printf("%2d ", i + 1); //Exibição das cordenadas de linha com a numeração
        for(int j = 0;j < 10; j++){
            printf("%d ", tabuleiro[i][j]); //Loop de exibição do tabuleiro com colunas repetindo 10x a cada linha
        };
        printf("\n"); //Quebra de linha a cada coluna feita 10x por loop
    }

    

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    
    return 0;
}
