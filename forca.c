#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "forca.h"



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


