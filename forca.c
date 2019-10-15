#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "forca.h"

int geraAleatorio(int maximo)
{
    time_t t;
    int n = 0;
    srand((unsigned) time(&t));
    n = (rand() % maximo) + 1;
    return n;
};

PalavraSecreta * inicializaListaSecreta()
{
    return NULL;
};

PalavraSecreta * carregaListaArquivo(PalavraSecreta *l, char nomeArq[255])
{
    const char tk[2] = ";";
    char * token;
    char palavra[31];
    char assunto[101];
    char * linha[1024];
    FILE * fWords;

    fWords = fopen(nomeArq,"r");
    if(fWords == NULL)
    {
        printf("Falha ao acessar base de dados!!!\n\n");
        exit(0);
    }

    while(fgets(linha,1024,fWords))
    {
        token = strtok(linha,tk);
        if(token!=NULL)
        {
             strcpy(palavra,token);
        }

        token=strtok(NULL,tk);
        if(token!=NULL)
        {
            strcpy(assunto,token);
        }

        l = inserePalavraSecreta(l,palavra, assunto);
    }

    fclose(fWords);
    return l;
};

void imprimeListaSecreta(PalavraSecreta *l)
{
    for(PalavraSecreta *p = l; p != NULL; p = p->prox)
    {
        printf("%d| %s\t%s\n", p->status,p->palavra,p->assunto);
    }
};

PalavraSecreta * inserePalavraSecreta(PalavraSecreta *l,char word[31],char subject[100])
{
    PalavraSecreta * novo;
    novo = (PalavraSecreta *) malloc(sizeof(PalavraSecreta));

    novo->status = 0;
    strcpy(novo->assunto,subject);
    strcpy(novo->palavra,word);
    novo->prox = l;

    return novo;
};

PalavraSecreta * sorteiaPalavra(PalavraSecreta *l)
{
    PalavraSecreta * p;

    while(temPalavraNaoUsada(l)){
        p = retornaPalavraPos(l,geraAleatorio(tamanhoListaSecreta(l)));
        if(p->status == 0){
            p->status = 1;
            return p;
        }
    }
    return NULL;
};

int temPalavraNaoUsada(PalavraSecreta *l)
{
    PalavraSecreta *p;

    for(p = l; p != NULL; p = p->prox)
    {
        if(p->status == 0)
        {
             return 1;
        }
    }

    return 0;
};

int tamanhoListaSecreta(PalavraSecreta *l)
{
    int n = 0;

    for(PalavraSecreta *p = l; p != NULL; p = p->prox)
    {
        n++;
    };

    return n;
};

PalavraSecreta * retornaPalavraPos(PalavraSecreta *l, int pos)
{
    int n = 1;
    PalavraSecreta *p;
    for(p = l; p != NULL; p = p->prox)
    {
        if(n == pos)
        {
            break;
        }

        n++;
    }
    return p;
};
