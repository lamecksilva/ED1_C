#include <stdio.h>
#include <stdlib.h>


#define TAM 3

// Definindo estrutura TSONECA
typedef struct {
    int inHora;
    int inMin;
    int outHora;
    int outMin;
}TSONECA;

typedef struct {
    TSONECA sonecas[TAM];
    int topo;
}TPILHA;


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

void inicializar(TPILHA *pilha){
    (*pilha).topo = -1;
}

void armazenar(TPILHA *pilha, TSONECA soneca){
    (*pilha).topo++;
    (*pilha).sonecas[ (*pilha).topo ] = soneca;
}

int menu(){
    int opt;
    
    printf("\n ====== Gerenciamento de sonecas =====\n");
    printf(" [ 1 ] - Registrar nova SONECA\n");
    printf(" [ 2 ] - Visualizar e totalizar SONECAS\n");
    printf(" [ 3 ] - Sair\n");
    printf("OPÇÃO: ");
    scanf("%d",&opt);

    return opt;
}

void main(){
    int opt;
    float vTotal = 0;
    TSONECA aux;
    TPILHA sPilha;

    inicializar(&sPilha);

    do{
        opt = menu();
        
        switch(opt){
            case 1:
                printf(" +++ NOVA SONECA +++ \n");
                aux = lerSoneca();
                armazenar(&sPilha, aux);
                vTotal = vTotal + calcularValor(aux);
            break;
            case 2:
                printf("\n\n ===== RESUMO SONECAS ===== \n");

                for (int i = sPilha.topo; i >= 0; i--)
                {
                    printf("\n ++ %d° Soneca ++",(i+1));
                    imprimirSoneca(sPilha.sonecas[i]);
                }

                printf("\n O valor total foi de %.2f\n",vTotal);

            break;

            default:{
                printf("Saindo...\n");
            }
        }
    }while(opt != 3);

    
}