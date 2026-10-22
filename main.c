
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Limpa os caracteres restantes da linha digitada */
void limparLinha(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Descarta o restante da linha
    }
}

/* Le e valida os nomes dos estudantes */
void lerNomes(int quantidade, char nomes[10][50])
{
    for (int i = 0; i < quantidade; i++)
    {
        do
        {
            printf("Digite o nome do estudante %d: ", i + 1);

            if (fgets(nomes[i], sizeof(nomes[i]), stdin) == NULL)
            {
                printf("Erro ao ler o nome.\n");
                exit(EXIT_FAILURE);
            }

            /* Verifica se o nome coube no vetor */
            if (strchr(nomes[i], '\n') == NULL && !feof(stdin))
            {
                limparLinha();
                nomes[i][0] = '\0';
                printf("Nome muito longo! Digite novamente.\n");
                continue;
            }

            /* Remove o Enter do final do nome */
            nomes[i][strcspn(nomes[i], "\n")] = '\0';

            if (strlen(nomes[i]) == 0)
            {
                printf("O nome nao pode ficar vazio!\n");
            }

        } while (strlen(nomes[i]) == 0);
    }
}

/* Le e valida as tres notas de cada estudante */
void lerNotas(int quantidade, float notas[10][3],
              char nomes[10][50])
{
    for (int i = 0; i < quantidade; i++)
    {
        printf("\nNotas de %s:\n", nomes[i]);

        for (int j = 0; j < 3; j++)
        {
            int valido = 0;

            do
            {
                printf("Digite a nota %d (0 a 10): ", j + 1);

                if (scanf("%f", &notas[i][j]) != 1)
                {
                    printf("Entrada invalida! Digite um numero.\n");
                    limparLinha();
                }
                else
                {
                    limparLinha();

                    if (!(notas[i][j] >= 0.0f &&
                          notas[i][j] <= 10.0f))
                    {
                        printf("A nota deve estar entre 0 e 10!\n");
                    }
                    else
                    {
                        valido = 1;
                    }
                }

            } while (valido == 0);
        }
    }
}

/* Calcula as medias e grava os resultados no vetor recebido */
void calcularMedias(int quantidade, float notas[10][3],
                    float *medias)
{
    for (int i = 0; i < quantidade; i++)
    {
        medias[i] = (notas[i][0] +
                     notas[i][1] +
                     notas[i][2]) / 3.0f;
    }
}

/* Exibe a tabela com notas, medias e situacoes */
void exibirBoletim(int quantidade, char nomes[10][50],
                   float notas[10][3], float medias[10])
{
    printf("\n================ BOLETIM DA TURMA ================\n");

    printf("%-20s %7s %7s %7s %8s  %s\n",
           "Estudante", "Nota 1", "Nota 2", "Nota 3",
           "Media", "Situacao");

    for (int i = 0; i < quantidade; i++)
    {
        const char *situacao;

        if (medias[i] >= 6.0f)
        {
            situacao = "Atingiu a meta";
        }
        else
        {
            situacao = "Abaixo da meta";
        }

        printf("%-20s %7.2f %7.2f %7.2f %8.2f  %s\n",
               nomes[i],
               notas[i][0],
               notas[i][1],
               notas[i][2],
               medias[i],
               situacao);
    }
}

/* Calcula e retorna a media geral da turma */
float calcularMediaGeral(int quantidade, float medias[10])
{
    float soma = 0.0f;

    for (int i = 0; i < quantidade; i++)
    {
        soma += medias[i];
    }

    return soma / quantidade;
}

/* Mostra a maior media e todos os estudantes empatados */
void mostrarMaiorMedia(int quantidade, char nomes[10][50],
                       float medias[10])
{
    float maiorMedia = medias[0];

    for (int i = 1; i < quantidade; i++)
    {
        if (medias[i] > maiorMedia)
        {
            maiorMedia = medias[i];
        }
    }

    printf("\nMaior media: %.2f\n", maiorMedia);
    printf("Estudante(s) com a maior media:\n");

    for (int i = 0; i < quantidade; i++)
    {
        if (medias[i] == maiorMedia)
        {
            printf("- %s\n", nomes[i]);
        }
    }
}

int main(void)
{
    int quantidade;
    char nomes[10][50];
    float notas[10][3];

    printf("=== BOLETIM DA TURMA ===\n");
    printf("Quantos estudantes deseja cadastrar (1 a 10)? ");

    if (scanf("%d", &quantidade) != 1 ||
        quantidade < 1 || quantidade > 10)
    {
        printf("Quantidade invalida!\n");
        return 1;
    }

    limparLinha();

    printf("Quantidade de estudantes: %d\n", quantidade);

    lerNomes(quantidade, nomes);
    lerNotas(quantidade, notas, nomes);

    /* Reserva memoria para uma media por estudante */
    float *medias = malloc(quantidade * sizeof(float));

    if (medias == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    /* Inicializa o vetor antes de calcular os resultados */
    for (int i = 0; i < quantidade; i++)
    {
        medias[i] = 0.0f;
    }

    calcularMedias(quantidade, notas, medias);
    exibirBoletim(quantidade, nomes, notas, medias);

    float mediaGeral = calcularMediaGeral(quantidade, medias);

    printf("\nMedia geral da turma: %.2f\n", mediaGeral);

    mostrarMaiorMedia(quantidade, nomes, medias);

    /* Libera a memoria reservada */
    free(medias);

    return 0;
}
