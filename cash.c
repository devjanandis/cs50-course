#include <stdio.h>
#include <math.h>
#include <cs50.h> // Adicionar a biblioteca do CS50

int get_minimo_moedas(int valor_devido, int moeda, int total_moedas);

int get_valor_devido(void);

int main(void)
{
    // recupera o valor devido
    int valor_devido = get_valor_devido();

    //busca o numero minimo de moedas
    int total_moedas = get_minimo_moedas(valor_devido, 25, 0);

    printf("%d\n", total_moedas);

    return 0;
}
// verifica a quantidade de moedas de 25, 10, 5 e 1
int get_minimo_moedas(int valor_devido, int moeda, int total_moedas)
{
    if (moeda == 25)
    {
        return get_minimo_moedas(valor_devido % 25, 10, valor_devido / 25);
    }
    else if (moeda == 10)
    {
        return total_moedas + get_minimo_moedas(valor_devido % 10, 5, valor_devido / 10);
    }
    else if (moeda == 5)
    {
        return total_moedas + get_minimo_moedas(valor_devido % 5, 1, valor_devido / 5);
    }
    else if (moeda == 1)
    {
        return total_moedas + valor_devido;
    }
    return 0;
}

int get_valor_devido(void)
{
    float f = 0.0;
    //recupera o valor devido maior que 0
    do
    {
        f = get_float("Dinheiro devido:\n");
    }
    while (f <= 0.0);

    int centavos = round(f * 100);

    return centavos;
}
Exercício da população, também fiz usando recursão (função que chama ela mesma).... #include <stdio.h>
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