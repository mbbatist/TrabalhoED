#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//Estrutura da caixinha de uma fila estatica
typedef struct
{
    int inicio,fim;
    int dados[MAX];

}FILAESTATICA;

//Função de criação de uma fila estatica
FILAESTATICA* fila_create()
{
    FILAESTATICA *n=(FILAESTATICA*) malloc(sizeof(FILAESTATICA));
    if(n)
    {
        n->inicio=-1;
        n->fim=-1;
    }
    return n;
}
/* **************************************************************
                Lógica do estado da Fila
Inserção: fim+1
Remoção:inicio+1
Cheio: fim+1==inicio
Vazia:remover inicio==fim /volta para estado inicial /fim e inicio//

            Fórmula para inserção em uma fila

       |fim+1| /MAX ->resto será a casa a inserir
************************************************************** */
int fila_insert(FILAESTATICA* Fi, int v)
{
    if(Fi->inicio==-1)
      {
        Fi->inicio=0;
        Fi->fim=0;
        Fi->dados[0]=v;
      }
    else
    {
        int next=(Fi->fim+1)%MAX;

        if(next==Fi->inicio)
        {
            return 0;
        }
        else
        {
            Fi->dados[next]=v;
            Fi->fim=next;
        }
    }
    return 1;
}

int fila_remove(FILAESTATICA* Fi,int *value)
{
    if(Fi->inicio>=0)
    {
        *value=Fi->dados[Fi->inicio];
        if(Fi->inicio==Fi->fim)
        {
            Fi->inicio=-1;
            Fi->fim=-1;
        }
        else

            Fi->inicio=(Fi->inicio+1)%MAX;
            return 1;

    }return 0;
}

void fila_print(FILAESTATICA* Fi)
{
  if(Fi->inicio!=-1)
  {
    int i;
    printf("Imprimindo a fila... \n");
    for(i=Fi->inicio; i!=Fi->fim+1; i=(i+1)%MAX)
    {
        printf("%d \n",Fi->dados[i]);
        if(i==Fi->fim)
        {
            break;
        }
    }
  }
}
/* 
        CODIGO DO PROFESSOR

void fila_print(FILAESTATICA* Fi)
{
  if(Fi->inicio!=-1)
    do{
        printf("%d \n,F->dados[i]");
        i=((i+1)%MAX);
      }while(i!=(Fi->fim+1)%MAX);
*/

int main()
{
    int num,i;
    FILAESTATICA* fila1;

    fila1=fila_create();

    for(i=0;i<=9;i++){
        printf("Informe o valor à inserir na fila:");
        scanf("%d",&num);
        fila_insert(fila1,num);
        }

        fila_print(fila1);

        printf("\n Removendo da fila... \n ");
        while(fila_remove(fila1,&num))
        {
            printf("%d ",num);
        }
        return 0;

    }