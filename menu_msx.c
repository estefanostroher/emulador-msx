#include <stdio.h>
#include <stdlib.h>

/*
    O desafio é criar um programa em C (no PC) para carregar o DSK na
memória e encontrar automaticamente os nomes dos jogos no bloco que contém
o menuzinho e o programa que ele chama (provavelmente .LDR ou .BAS).
*/

typedef struct
{
    char linha[400];
    struct no* prox;
}no;

void Conteudo(char nome[255])
{
    FILE* arq = fopen(nome,"rt");
    if(arq==NULL){printf("Nao carregou %s\n", nome); return;}
    char linha[600];
    fscanf(arq, "%s ", &linha);
    printf("%s \n", linha);
    fclose(arq);
}

int main()
{
    char* nome;
    nome = (char*) malloc(255);
    
    int i;
    for(i=1; i<131; i++)
    {
        if(i<10) sprintf(nome,"arquivo/mania00%d.dsk", i);
        else if(i>=10 && i<100)sprintf(nome,"arquivo/mania0%d.dsk", i);
        else sprintf(nome,"arquivo/mania%d.dsk", i);

        Conteudo(nome);
    }
    nome = NULL;
    free(nome);
}
