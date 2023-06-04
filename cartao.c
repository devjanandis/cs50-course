// #include <stdio.h>
// #include <cs50.h> // Adicionar a biblioteca do CS50

int conta_digitos(long numero_cartao);

int recupera_tipo_cartao_valido(long numero_cartao, int digitos);

int main(void)
{
    // recupera o numero do cartao de credito
    long numero_cartao = get_long("Número: ");

    int digitos = conta_digitos(numero_cartao);

    if ((digitos == 13) || (digitos == 15) || (digitos == 16))
    {
        // recupera o tipo do cartao
        int tipo_cartao = recupera_tipo_cartao_valido(numero_cartao, digitos);

        if (tipo_cartao == 1)
        {
            printf("MASTERCARD\n");
        }
        else if (tipo_cartao == 2)
        {
            printf("VISA\n");
        }
        else if (tipo_cartao == 3)
        {
            printf("AMEX\n");
        }
        else {
            printf("INVALID\n");
        }
    } else
    {
      printf("INVALID\n");
    }

    return 0;
}

// conta o numero de digitos de um cartao
int conta_digitos(long numero_cartao)
{
    int i = 0;
    while (numero_cartao > 0)
    {
        numero_cartao = numero_cartao /10;
        i++;
    }
    return i;
}
// devolve 1 para Master, 2 VISA e 3 AMEX ou - 1 para inválido
int recupera_tipo_cartao_valido(long numero_cartao, int digitos)
{
    int soma = 0;
    int produto = 0;
    int digito = 0;
    int segundo_digito = 0;
    int tipo_cartao = -1;

    for (int i = 0; i < digitos; i++)
    {
        // recupera o primeiro digito
        digito = numero_cartao % 10;

        // verifica a posicao do digito
        if (i % 2 == 0)
        {
            soma += digito;
        }
        else
        {
            int x = digito * 2;

            if (x > 9)
            {
                int y = x % 10;
                x /= 10;

                produto += (x + y);
            }
            else
            {
                produto += x;
            }
        }

        // se estao nas primeiras posicoes da esquerda para a direita
        if ((digitos - 2) == i)
        {
            int primeiro_digito = numero_cartao / 10;

            //cartao Amex
            if ((numero_cartao == 34 || numero_cartao == 37) && digitos == 15)
            {
                tipo_cartao = 3;
            }
            // cartao Visa
            else if (primeiro_digito == 4 && (digitos == 13 || digitos == 16))
            {
                tipo_cartao = 2;
            }
            // cartao master
            else if (digitos == 16 && (numero_cartao == 51 || numero_cartao == 52 || numero_cartao ==  53 || numero_cartao ==  54 || numero_cartao == 55))
            {
                tipo_cartao = 1;
            }
        }
        numero_cartao = numero_cartao / 10;
    }

    if ((produto + soma) % 10 != 0)
    {
        tipo_cartao = -1;
    }

    return tipo_cartao;

}