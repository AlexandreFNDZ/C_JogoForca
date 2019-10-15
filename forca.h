#ifndef FORCA_H_INCLUDED
#define FORCA_H_INCLUDED

struct palavraSecreta{
    int status;
    char palavra[31];
    char assunto[101];
    struct palavraSecreta * prox;
};

typedef struct palavraSecreta PalavraSecreta;


PalavraSecreta * inicializaListaSecreta();
PalavraSecreta * carregaListaArquivo(PalavraSecreta *l, char nomeArq[255]);
void imprimeListaSecreta(PalavraSecreta *l);
PalavraSecreta * inserePalavraSecreta(PalavraSecreta *l,char word[31],char subject[100]);



#endif // FORCA_H_INCLUDED
