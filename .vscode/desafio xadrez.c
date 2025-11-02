#include <stdio.h>
#include <stdlib.h>

/* Funções auxiliares bem formadas e declaradas antes do main */

// Recursão simples para imprimir movimentos do bispo
void mover_bispo_recursivo(int movimento) {
    if (movimento > 7) return;
    printf("Bispo move para a diagonal %d\n", movimento);
    mover_bispo_recursivo(movimento + 1);
}

void torre_recursivo(int movimento) {
    if (movimento > 7) return;
    printf("Torre move para a direita %d\n", movimento);
    torre_recursivo(movimento + 1);
}

void rainha_recursivo(int movimento) {
    if (movimento > 7) return;
    printf("Rainha move para a esquerda %d\n", movimento);
    rainha_recursivo(movimento + 1);
}

void cavalo_recursivo(int horizontal, int vertical, int movimentos_restantes) {
    if (movimentos_restantes == 0) return;
    printf("Cavalo move em L: horizontal %d, vertical %d\n", horizontal, vertical);
    cavalo_recursivo(horizontal, vertical, movimentos_restantes - 1);
}

// Valida movimento do cavalo (não é recursiva, apenas valida)
int validar_movimento_cavalo(int x_inicial, int y_inicial, int x_final, int y_final) {
    int dx = abs(x_final - x_inicial);
    int dy = abs(y_final - y_inicial);
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

// Imprime todos os possíveis destinos do cavalo no tabuleiro (para demonstração)
void imprimir_possiveis_movimentos_cavalo_tabuleiro(void) {
    for (int x = 1; x <= 8; x++) {
        for (int y = 1; y <= 8; y++) {
            if ((x + 2 <= 8 && y + 1 <= 8) || (x + 2 <= 8 && y - 1 >= 1) ||
                (x - 2 >= 1 && y + 1 <= 8) || (x - 2 >= 1 && y - 1 >= 1) ||
                (x + 1 <= 8 && y + 2 <= 8) || (x + 1 <= 8 && y - 2 >= 1) ||
                (x - 1 >= 1 && y + 2 <= 8) || (x - 1 >= 1 && y - 2 >= 1)) {
                printf("Cavalo pode mover para (%d, %d)\n", x, y);
            }
        }
    }
}

int main(void) {
    // Contadores de exemplo para movimentos
    int movimento_bispo = 0;
    int movimento_torre = 0;
    int movimento_rainha = 0;
    int movimento_cavalo = 0;

    // Exemplos simples com loops
    for (movimento_bispo = 1; movimento_bispo <= 7; movimento_bispo++) {
        printf("Bispo move para a diagonal %d\n", movimento_bispo);
    }

    for (movimento_torre = 1; movimento_torre <= 7; movimento_torre++) {
        printf("Torre move para a direita %d\n", movimento_torre);
    }

    for (movimento_rainha = 1; movimento_rainha <= 7; movimento_rainha++) {
        printf("Rainha move para a esquerda %d\n", movimento_rainha);
    }

    // Exemplo simples do cavalo
    imprimir_possiveis_movimentos_cavalo_tabuleiro();
    for (int h = 1; h <= 2; h++) {
        for (int v = 1; v <= 2; v++) {
            printf("Cavalo move em L: horizontal %d, vertical %d\n", h, v);
            movimento_cavalo++;
        }
    }

    // Entrada de posições para validar um movimento de cavalo
    int pos_inicial_x = 0, pos_inicial_y = 0, pos_final_x = 0, pos_final_y = 0;
    printf("Digite a posição inicial do cavalo (x y): ");
    if (scanf("%d %d", &pos_inicial_x, &pos_inicial_y) != 2) {
        fprintf(stderr, "Entrada inválida.\n");
        return 1;
    }
    printf("Digite a posição final do cavalo (x y): ");
    if (scanf("%d %d", &pos_final_x, &pos_final_y) != 2) {
        fprintf(stderr, "Entrada inválida.\n");
        return 1;
    }

    if (validar_movimento_cavalo(pos_inicial_x, pos_inicial_y, pos_final_x, pos_final_y)) {
        printf("Movimento válido para o cavalo.\n");
    } else {
        printf("Movimento inválido para o cavalo.\n");
    }

    // Demonstrações recursivas (nível mestre)
    mover_bispo_recursivo(1);
    torre_recursivo(1);
    rainha_recursivo(1);
    cavalo_recursivo(1, 1, 4);

    // Saída final resumida
    printf("bispo: %d, torre: %d, rainha: %d, cavalo: %d\n",
           movimento_bispo, movimento_torre, movimento_rainha, movimento_cavalo);
    printf("diagonal %d\n", movimento_bispo);
    printf("direita %d\n", movimento_torre);
    printf("esquerda %d\n", movimento_rainha);
    printf("horizontal %d, vertical %d\n", movimento_cavalo, movimento_cavalo);
    printf("Cavalo pode mover para (%d, %d)\n", pos_final_x, pos_final_y);

    return 0;
}

    

