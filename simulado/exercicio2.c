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


// Calculando duração da soneca
int calcularDuracao(TSONECA aux){
    int t1, t2, duracao;

    t1 = ((aux.inHora * 60) + aux.inMin);
    t2 = ((aux.outHora * 60) + aux.outMin);
    duracao = (t2 - t1);

    if (duracao == 0){
        printf(" Error Error Error");
    } else {
        return duracao;
    }
}


// Calcular valor da sonecaCore i5-5200U @ 4x 2.7GHz [63.
float calcularValor(TSONECA aux){
    return (calcularDuracao(aux) * 0.5);
}



// Main
void main(){
    int opt;
    TSONECA t1;

    t1 = lerSoneca();
    imprimirSoneca(t1);
    printf("A soneca durou %d minutos\n",calcularDuracao(t1));
    printf("A soneca custou um valor de R$ %.2f\n",calcularValor(t1));

}