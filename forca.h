#ifndef FORCA_H_INCLUDED
#define FORCA_H_INCLUDED

/* definição de uma Macro para limpeza do console */
#ifdef _WIN32
# define CLEAR_SCREEN system("cls")
#else
# define CLEAR_SCREEN puts("\x1b[H\x1b[2J")
#endif

struct palavraSecreta{
    int status;
    char palavra[31];
    char assunto[101];
    struct palavraSecreta * prox;
};

typedef struct palavraSecreta PalavraSecreta;

int geraAleatorio(int maximo);
PalavraSecreta * inicializaListaSecreta();
PalavraSecreta * carregaListaArquivo(PalavraSecreta *l, char nomeArq[255]);
void imprimeListaSecreta(PalavraSecreta *l);
PalavraSecreta * inserePalavraSecreta(PalavraSecreta *l,char word[31],char subject[100]);
PalavraSecreta * sorteiaPalavra(PalavraSecreta *l);
int temPalavraNaoUsada(PalavraSecreta *l);
int tamanhoListaSecreta(PalavraSecreta *l);
PalavraSecreta * retornaPalavraPos(PalavraSecreta *l, int pos);


#endif // FORCA_H_INCLUDED
