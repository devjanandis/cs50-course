#include <stdio.h>
#include <cs50.h> // Adicionar a biblioteca do CS50

int calcula_anos_crescimento(int populacao_inicial, int populacao_final);

int get_populacao(int is_inicio, int minimo);

int main(void)
{
    // recupera o tamanho inicial da populacao
    int populacao_inicial = get_populacao(1, 9);

    // recupera o tamanho final da populacao
    int populacao_final = get_populacao(2, populacao_inicial);

    // recupera a quantidade de anos do crescimento de uma populacao inicial ate o final
    int anos = calcula_anos_crescimento(populacao_inicial, populacao_final);

    printf("Years: %d\n", anos);

    return 0;
}

// calcula os anos de crescimento de uma populacao
int calcula_anos_crescimento(int populacao_inicial, int populacao_final)
{
    if (populacao_inicial < populacao_final)
    {
        int nascidos = populacao_inicial / 3;
        int mortos = populacao_inicial / 4;
        populacao_inicial = populacao_inicial + nascidos - mortos;
        return 1 + calcula_anos_crescimento(populacao_inicial, populacao_final);
    }

    return 0;
}

int get_populacao(int is_inicio, int minimo)
{
    int n;

    //recupera um inteiro maior ou igual ao minimo
    if (is_inicio == 1)
    {
        do
        {
            n = get_int("Tamanho inicial:\n");
        }
        while (n < minimo);
    }
    else
    {
        do
        {
            n = get_int("Tamanho final:\n");
        }
        while (n < minimo);
    }
    return n;
}