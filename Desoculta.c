#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    unsigned char texto[100];
    unsigned char texto2[5];
    unsigned char aux;
    int i,j,h;

    FILE *dados;
    dados = fopen("Criptografia.txt","r");
    if(dados){
        fgets(texto,100,dados);

        j = 0;
        h = 6;
        for(i=0;i<4;i++){
        h = 6;
        while(h>=0){
            if(h==6){
                aux = texto[j]<<6;
                aux = aux>>h;
                texto2[i] = aux;
                j++;
                h-=2;
            }else {
                aux = texto[j]<<6;
                aux = aux>>h;
                texto2[i] = texto2[i] | aux;
                j++;
                h-=2;
            }
            }
        }
    printf("Mensagem Oculta = %s",texto2);

        fclose(dados);
    }
    else
        printf("Arquivo Nao Encontrado\n");

    return 0;
}
