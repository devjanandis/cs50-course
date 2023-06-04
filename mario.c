#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Pede por um número de 1 a 8
    int size;
    do
    {
        size = get_int("tamanho (de 1 a 8): ");
    }
    while (size < 1 || size > 8);

    int spaces;

    // i = quantos blocos imprimir
    for (int i = 1; i <= size; i++)
    {
        // spaces = quantos "blocos de ar" imprimir
        spaces = size - i;
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < (size - spaces); j++)
        {
            printf("#");
        }
        printf("\n");
    }
}