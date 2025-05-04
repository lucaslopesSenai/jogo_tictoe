#include <stdio.h>

char tabuleiro[3][3];

// Inicializa o tabuleiro com espaços
void inicializarTabuleiro() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tabuleiro[i][j] = ' ';
}

// Mostra o tabuleiro no terminal
void exibirTabuleiro() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i < 2) printf("\n-----------\n");
    }
    printf("\n");
}

// Verifica se houve vitória
char verificarVencedor() {
    for (int i = 0; i < 3; i++) {
        // Linhas
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
            return tabuleiro[i][0];
        // Colunas
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
            return tabuleiro[0][i];
    }

    // Diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
        return tabuleiro[0][0];
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
        return tabuleiro[0][2];

    return ' '; // Ninguém venceu ainda
}

// Verifica se o tabuleiro está cheio (empate)
int tabuleiroCheio() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tabuleiro[i][j] == ' ')
                return 0;
    return 1;
}

int main() {
    int linha, coluna;
    char jogadorAtual = 'X';
    char vencedor = ' ';

    inicializarTabuleiro();

    while (1) {
        exibirTabuleiro();
        printf("Jogador %c, digite a linha (0-2) e a coluna (0-2): ", jogadorAtual);
        scanf("%d %d", &linha, &coluna);

        // Validação da jogada
        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
            printf("Jogada inválida! Tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogadorAtual;

        vencedor = verificarVencedor();
        if (vencedor != ' ' || tabuleiroCheio())
            break;

        // Alterna jogador
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }

    exibirTabuleiro();
    if (vencedor != ' ')
        printf("Parabéns! O jogador %c venceu!\n", vencedor);
    else
        printf("Empate! Ninguém venceu.\n");

    return 0;
}
