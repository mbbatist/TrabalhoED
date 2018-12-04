#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    unsigned char info;
    struct no *prox;
}Tno;

typedef struct{
    Tno *incio;
}Tlista;

Tlista* Tlista_create(){
    Tlista *novo = (Tlista*)malloc(sizeof(Tlista));
    if(novo){
        novo->incio = NULL;
    }
    return novo;
}

void TLista_create_no(Tlista *L, int info){
    Tno *aux;
    Tno *novo = (Tno*)malloc(sizeof(Tno));
    if(novo){
        novo->info = info;
        novo->prox = NULL;
    }
    if(L->incio == NULL)
        L->incio = novo;
    else{
        aux = L->incio;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;

    }
    //return novo;
}

int main()
{
    Tlista * L1,*L2,*L3;
    L1 = Tlista_create();
    L2 = Tlista_create();
    L3 = Tlista_create();

    unsigned char texto[5] = "abcd";
    unsigned char texto2[100] = "Thiago Silva Pereira e Caleb Hugo do Nascimento Pereira";
    unsigned char texto3[100];
    strcpy(texto3,texto2);

    int i,j;
    unsigned char aux;
    for(i=0;i<strlen(texto);i++)
        TLista_create_no(L1,texto[i]);
    for(i=0;i<strlen(texto);i++){
        
        for(j=0;j<=6;j+=2){
            aux = texto[i]>>(j);
            aux = aux<<6;
            aux = aux>>6;
            TLista_create_no(L2,aux);
        }

    }

    Tno *aux1;
    aux1 = L2->incio;
    i = 0;
    while(aux1 != NULL){
        unsigned char aux;
        aux = texto2[i]>>2;
        aux = aux<<2;
        aux = aux1->info | aux;
        TLista_create_no(L3,aux);
        i++;
        aux1 = aux1->prox;
    }
    FILE *dados;
    dados = fopen("Criptografia.txt","w");

    aux1 = L3->incio;

    i=0;
    while(aux1 != NULL){
        texto3[i] = aux1->info;
        aux1 = aux1->prox;
        i++;
    }
    printf("Texto a ser Ocultado:\n%s\n\n",texto);
    printf("Texto Normal:\n%s\n\n",texto2);
    printf("Texto Modificado com os Bits:\n%s",texto3);
    fprintf(dados,texto3);
    fclose(dados);

    return 0;
}
