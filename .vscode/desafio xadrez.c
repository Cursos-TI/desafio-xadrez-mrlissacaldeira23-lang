#include <stdio.h>
#include <stdlib.h>

/* Imprime movimentos do bispo recursivamente (diagonais até 7 passos) */
void mover_bispo_recursivo(int movimento)
{
    if (movimento > 7)
        return;
    printf("Bispo move para a diagonal %d\n", movimento);
    mover_bispo_recursivo(movimento + 1);
}

/* Valida movimento de cavalo (não é recursiva, apenas checa o L) */
int validar_movimento_cavalo(int x_inicial, int y_inicial, int x_final, int y_final)
{
    int dx = abs(x_final - x_inicial);
    int dy = abs(y_final - y_inicial);
    if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2))
        return 1;
    return 0;
}

/* Exemplo recursivo simples para mostrar movimentos repetidos do cavalo */
void cavalo_recursivo(int horizontal, int vertical, int movimentos_restantes)
{
    if (movimentos_restantes <= 0)
        return;
    printf("Cavalo move em L: horizontal %d, vertical %d (restantes %d)\n", horizontal, vertical, movimentos_restantes);
    cavalo_recursivo(horizontal, vertical, movimentos_restantes - 1);
}

int main(void)
{
    int movimento_bispo = 0;
    int movimento_torre = 0;
    int movimento_rainha = 0;
    int movimento_cavalo = 0;

    /* Exemplos simples de movimento (1..7) */
    for (movimento_bispo = 1; movimento_bispo <= 7; movimento_bispo++)
        printf("Bispo move para a diagonal %d\n", movimento_bispo);

    for (movimento_torre = 1; movimento_torre <= 7; movimento_torre++)
        printf("Torre move para a direita %d\n", movimento_torre);

    for (movimento_rainha = 1; movimento_rainha <= 7; movimento_rainha++)
        printf("Rainha move para a esquerda %d\n", movimento_rainha);

    /* Exemplo de movimentação do cavalo em L (pequeno conjunto) */
    for (int h = 1; h <= 2; h++)
    {
        for (int v = 1; v <= 2; v++)
        {
            printf("Cavalo move em L: horizontal %d, vertical %d\n", h, v);
        }
    }

    /* Mostrar movimentos possíveis do cavalo a partir de todas as casas (8x8) */
    for (int x = 1; x <= 8; x++)
    {
        for (int y = 1; y <= 8; y++)
        {
            /* se existirem movimentos de cavalo a partir de (x,y), apenas demonstrar a verificação */
            if ((x + 2 <= 8 && y + 1 <= 8) || (x + 2 <= 8 && y - 1 >= 1) ||
                (x - 2 >= 1 && y + 1 <= 8) || (x - 2 >= 1 && y - 1 >= 1) ||
                (x + 1 <= 8 && y + 2 <= 8) || (x + 1 <= 8 && y - 2 >= 1) ||
                (x - 1 >= 1 && y + 2 <= 8) || (x - 1 >= 1 && y - 2 >= 1))
            {
                /* apenas um exemplo de saída */
                // printf("Cavalo pode mover a partir de (%d, %d)\n", x, y);
                (void)0;
            }
        }
    }

    /* Entrada do usuário para validar um movimento de cavalo */
    int pos_inicial_x = 0, pos_inicial_y = 0, pos_final_x = 0, pos_final_y = 0;
    printf("Digite a posição inicial do cavalo (x y): ");
    if (scanf("%d %d", &pos_inicial_x, &pos_inicial_y) != 2)
    {
        fprintf(stderr, "Entrada inválida.\n");
        return 1;
    }
    printf("Digite a posição final do cavalo (x y): ");
    if (scanf("%d %d", &pos_final_x, &pos_final_y) != 2)
    {
        fprintf(stderr, "Entrada inválida.\n");
        return 1;
    }

    int delta_x = pos_final_x - pos_inicial_x;
    int delta_y = pos_final_y - pos_inicial_y;
    if ((abs(delta_x) == 2 && abs(delta_y) == 1) || (abs(delta_x) == 1 && abs(delta_y) == 2))
    {
        printf("Movimento válido para o cavalo (cheque simples).\n");
    }
    else
    {
        printf("Movimento inválido para o cavalo (cheque simples).\n");
    }

    int valido = validar_movimento_cavalo(pos_inicial_x, pos_inicial_y, pos_final_x, pos_final_y);
    if (valido)
        printf("Movimento válido para o cavalo (função de validação).\n");
    else
        printf("Movimento inválido para o cavalo (função de validação).\n");

    /* Chamadas de exemplo às funções recursivas de peça */
    mover_bispo_recursivo(1);
    cavalo_recursivo(1, 2, 3); /* demonstra recursão simples do cavalo */

    /* Saída final resumida */
    printf("Resumo: bispo: %d, torre: %d, rainha: %d, cavalo: %d\n",
           movimento_bispo, movimento_torre, movimento_rainha, movimento_cavalo);
    printf("Posição final do cavalo consultada: (%d, %d)\n", pos_final_x, pos_final_y);

    return 0;
}

