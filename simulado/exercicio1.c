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


//Menu
int menu(){
    int opt;

    printf("\n\n\n ------  Aluguel de cabines - Menu  ------\n");
    printf("[ 1 ] - Novo cadastro\n");
    printf("[ 2 ] - Mostrar cadastros\n");
    printf("[ 8 ] - Sair\n");
    printf("Opcao: ");
    scanf("%d",&opt);

    return opt;
}



// Main
void main(){
    int opt;
    TSONECA t1;

    do{
        opt = menu();

        switch(opt){
            case 1:
                t1 = lerSoneca();
            break;

            case 2:
                printf("\n***** Cadastro 1 *****");
                imprimirSoneca(t1);
            break;
            default:
                printf("\nA implementar\n");
            break;
        }
    }while(opt != 8);
}