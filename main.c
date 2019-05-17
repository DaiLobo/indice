#include <stdio.h>
#include <string.h>

int main()
{
    char linha[2048];
    char nis_chave[14];
    int n = 0;
    int coluna = 0;
    char* campo;

    FILE *f = fopen("bolsa.csv", "r");
    FILE *indice = fopen("indice.txt", "w"); /*cria o arquivo indice*/

    fgets(linha, 2048, f); /*abrir arquivo f e armazenar 2048 bytes no linha*/
    long posicao_chave = ftell(f); /*posicao absoluta da cabeça de leitura*/
    fgets(linha, 2048, f);

    while(!feof(f)) /*enquanto não termina arquivo f*/
    {
        printf("%d", n);
        coluna = 0;
        campo = strtok(linha,"\t"); /* equivalente ao split*/
        while(campo)
        {
            if(coluna == 7)
            {
                strncpy(nis_chave, campo, 14); /*define o tamanho da variavel*/
                fprintf(indice, "%.14s %010ld\n", nis_chave, posicao_chave);
               /* printf("NIS => %s esta em %ld\n", nis_chave, posicao_chave);*/
            }
            coluna++;
            campo = strtok(NULL,"\t");
        }
        printf("%d", n);
        printf("---------------------------------------\n");
        posicao_chave = ftell(f);
        fgets(linha, 2048, f);
        n++;
        printf("%d", n);
    }
}
