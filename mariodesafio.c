#include <stdio.h>
#include <cs50.h> // Adicionar a biblioteca do CS50

void imprime(char c, int n);

int get_positive(void);

int main(void)
{
    // recupera um positivo entre 1 e 8
    int tamanho = get_positive();

    char espaco = ' ';
    char hash = '#';
    // imprime os degraus
    for (int i = 1; i < tamanho + 1; i++)
    {
        imprime(espaco, tamanho - i);
        imprime(hash, i);
        imprime(espaco, 2);
        imprime(hash, i);
        imprime('\n', 1);
    }
    return 0;
}

void imprime(char c, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", c);
    }
}

int get_positive(void)
{
    int n;
    //recupera um inteiro entre 1 e 8
    do
    {
        n = get_int("Tamanho entre 1 e 8\n");
    }
    while (n < 1 || n > 8);

    return n;
}