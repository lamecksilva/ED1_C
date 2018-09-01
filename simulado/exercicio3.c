#include <stdio.h>
#include <stdlib.h>

// Definindo estrutura TSONECA
typedef struct {
    int inHora;
    int inMin;
    int outHora;
    int outMin;
}TSONECA;


TSONECA lerSoneca(){
    TSONECA aux;

    printf("\nDigite a Hora de entrada: ");
    scanf("%d",&aux.inHora);
    printf("Digite o Minuto de entrada: ");
    scanf("%d",&aux.inMin);

    printf("Digite a Hora de saida: ");
    scanf("%d",&aux.outHora);
    printf("Digite o Minuto de saida: ");
    scanf("%d",&aux.outMin);

    return aux;
}

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


float calcularValor(TSONECA aux){
    return (calcularDuracao(aux) * 0.5);
}



void imprimirSoneca(TSONECA aux){
    printf("\nHora de entrada: %d:%d\n",aux.inHora,aux.inMin);
    printf("Hora de saida: %d:%d\n", aux.outHora, aux.outMin);
    printf("A soneca durou %d minutos\n",calcularDuracao(aux));
    printf("A soneca custou um valor de R$ %.2f\n",calcularValor(aux));
}



void main(){
    
    int opt;
    float vTotal = 0;
    int nSonecas;
    
    printf("Informe o número de sonecas: ");
    scanf("%d",&nSonecas);      

    TSONECA vSoneca[nSonecas];      
    for (int i = 0; i != nSonecas; i++){
        printf("\n\n ++ %d° Soneca ++",(i+1));
        vSoneca[i] = lerSoneca();
    }

    printf("\n\n ===== RESUMO SONECAS ===== \n");

    for (int i = 0; i != nSonecas; i++){
        printf("\n ++ %d° Soneca ++",(i+1));
        imprimirSoneca(vSoneca[i]);
        vTotal = vTotal + calcularValor(vSoneca[i]);
    }
    printf("\n O valor total foi de %.2f\n",vTotal);


}