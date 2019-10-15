#include <stdio.h>
#include <stdlib.h>
#include "forca.h"

int main(int argc, char *argv[])
{
    PalavraSecreta * lstSecreta = inicializaListaSecreta();
    PalavraSecreta * sorteada;
    char fNameArq[255];
    int tamanhoLista = 0;

    strcpy(fNameArq,"palavras.dat");

    if(argc>1){
      strcpy(fNameArq,argv[1]);
    }

    printf("Arquivo de dados: %s\n\n",fNameArq);

    lstSecreta = carregaListaArquivo(lstSecreta,fNameArq);
    imprimeListaSecreta(lstSecreta);

    do{
        CLEAR_SCREEN;
        imprimeListaSecreta(lstSecreta);

        sorteada = sorteiaPalavra(lstSecreta);

        if(sorteada!=NULL){
            printf("%s\n", sorteada->palavra);
        }else{
            printf("Nao tem palavra disponivel!\n\n");
            system("pause");
            break;
        }

    }while(true);

    return 0;
}
