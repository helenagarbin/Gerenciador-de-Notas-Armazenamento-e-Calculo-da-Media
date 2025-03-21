#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Aluna: Helena Tubino Garbin

1) Escreva um programa que receba do usuário 10 notas finais de alunos de uma disciplina (não inteiros) e o nome do arquivo no qual eles devem ser armazenados.
Em seguida, ler do arquivo estes valores armazenados,calculando a média aritmética dessas notas finais e  imprimindo na tela o valor.
*/

int main()
{
    setlocale(LC_ALL,"Portuguese");

    FILE *arquivo;
    char nome_arquivo[50];
    float notas[10];
    float soma_notas = 0.0;
    float media_aritmetica;
    int i;

    printf("Digite as 10 notas finais dos alunos:\n");
    for(i=0; i<10; i++)
    {
        printf("\n A nota %d: ", i+1);
        scanf("%f", &notas[i]);
    }

    printf("\nDigite o nome do arquivo para ser armazenado as notas finais: ");
    scanf("%s", &nome_arquivo);

    arquivo = fopen(nome_arquivo, "w");

    if(arquivo==NULL)
    {
        printf("Erro\n");
        return 1;
    }

    for(i=0; i<10; i++)
    {
        fprintf(arquivo, "%f\n", notas[i]);
    }


    fclose(arquivo);

    arquivo=fopen(nome_arquivo, "r");
    if(arquivo ==  NULL)
    {
        printf("Erro\n");
        return 1;
    }

    for(i=0; i<10; i++)
    {
        fscanf(arquivo, "%f", &notas[i]);
        soma_notas += notas[i];
    }

    media_aritmetica = soma_notas / 10;

    fclose(arquivo);


    printf("A média artimética das notas é: %.2f\n", media_aritmetica);

    return 0;
}

