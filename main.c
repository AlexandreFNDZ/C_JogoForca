#include <stdio.h>
#include <stdlib.h>
#include "forca.h"

int main(int argc, char *argv[])
{
    PalavraSecreta * lstSecreta = inicializaListaSecreta();
    char fNameArq[255];
    int tamanhoLista=0;

    strcpy(fNameArq,"palavras.dat");

    if(argc>1){
      strcpy(fNameArq,argv[1]);
    }

    printf("Arquivo de dados: %s\n\n",fNameArq);

    lstSecreta = carregaListaArquivo(lstSecreta,fNameArq);
    imprimeListaSecreta(lstSecreta);


    return 0;
}
