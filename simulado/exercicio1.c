#include <stdio.h>
#include <stdlib.h>

// Definindo estrutura TSONECA
typedef struct {
    int inHora;
    int inMin;
    int outHora;
    int outMin;
}TSONECA;


// Lendo atributos de uma estrutura TSONECA
TSONECA lerSoneca(){
    TSONECA aux;

    printf("Digite a Hora de entrada: ");
    scanf("%d",&aux.inHora);
    printf("Digite o Minuto de entrada: ");
    scanf("%d",&aux.inMin);

    printf("Digite a Hora de saida: ");
    scanf("%d",&aux.outHora);
    printf("Digite o Minuto de saida: ");
    scanf("%d",&aux.outMin);

    return aux;
}


// Imprimindo dados
void imprimirSoneca(TSONECA aux){
    printf("\nHora de entrada: %d : %d\n",aux.inHora,aux.inMin);
    printf("Hora de saida: %d : %d\n", aux.outHora, aux.outMin);
}



// Main
void main(){
    TSONECA t1;


    t1 = lerSoneca();
    imprimirSoneca(t1);

}