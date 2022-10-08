#include<stdio.h>
#include<stdlib.h>

void leitura_do_jogo(char *arq){
    FILE *arquivo = fopen(arq, "r");
    char linha[200];

    if(arquivo){
		printf("\nTexto lido do arquivo dos discos:\n");
		while(fscanf(arquivo, "%s", linha) != -1){
			printf("%s ", linha);
		}
		fclose(arquivo);
	}
	
	else{
		printf("\nErro ao ler do arquivo!");
	}
}

int main(){
    int i;
    char *nome_do_jogo;
    nome_do_jogo = malloc(sizeof(nome_do_jogo)*256);

    for(i = 0; i < 131; i++){
        if(i < 10){
            sprintf(nome_do_jogo, "C:/Users/estel/OneDrive/Documents/algoritmos e programação/Estrutura de Dados 1/msx1_mania/mania00%d.zip", i);
        }

        else if(i > 9 && i < 100){
            sprintf(nome_do_jogo, "C:/Users/estel/OneDrive/Documents/algoritmos e programação/Estrutura de Dados 1/msx1_mania/mania0%d.zip", i);
        }

        else{
            sprintf(nome_do_jogo, "C:/Users/estel/OneDrive/Documents/algoritmos e programação/Estrutura de Dados 1/msx1_mania/mania%d.zip", i);
        }
        leitura_do_jogo(nome_do_jogo);
    }

    free(nome_do_jogo);

    return 0;
}