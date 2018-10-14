#include <stdio.h>
#include <stdlib.h>

#define TAM 30



typedef struct {
  int hora, minuto;
  char desc[50];
}TERRO;



typedef struct {
  TERRO erros[TAM];
  int topo;
}TPILHA;



void inicializar(TPILHA *p){
  (*p).topo = -1;
}



void empilhar(TPILHA *p, TERRO erro){
  if( !((*p).topo > TAM-1)){
    (*p).topo++;
    (*p).erros[ (*p).topo ] = erro;
  } else {
    printf("Pilha cheia não se empilha");
  }

  
}



TERRO lerErro(){
  TERRO aux;
  
  printf("Hora do erro: ");
  scanf("%d",&aux.hora);
  printf("Minuto do erro: ");
  scanf("%d",&aux.minuto);
  fflush(stdin);
  printf("Descrição do erro: ");
  scanf("%s",&aux.desc);

  return aux;
}



int menu(){
  int opt;
  printf("\n +++++++++++ MENU ++++++++++++\n");
  printf("[ 0 ] Sair\n");
  printf("[ 1 ] Registrar Erro\n");
  printf("[ 2 ] Visualizar Erros\n");
  printf("[ 3 ] Retirar ultimo erro\n");
  printf("ESCOLHA: ");
  scanf("%d",&opt);

  return opt;
}

void imprimirReg(TERRO err){
  printf("\n\nHora do erro [%d:%d]\n",err.hora,err.minuto);
  printf("Descrição: [%s]\n",err.desc);
}

void imprimir(TPILHA p){
  int i;
  for (i = p.topo; i>=0; i--){
    imprimirReg(p.erros[i]);
  }
}

TERRO desempilhar(TPILHA *p){
  TERRO aux;
  if ( !( (*p).topo == -1) ){
    aux = (*p).erros[ (*p).topo ];
    (*p).topo--;
  }else{
    printf("Não desempilha pilha vazia");
  }

  return aux;
}

void main(){
  int opt;
  TPILHA pilha;
  TERRO aux;

  inicializar(&pilha);
  do {
    opt = menu();

    switch(opt){
      case 1:
        system("clear");
        printf(" ****** Registrar erro *******\n");
        aux = lerErro();
        empilhar(&pilha, aux);
      break;

      case 2:
        system("clear");
        printf("\n =========== Visualizar erros ============\n");
        imprimir(pilha);
        printf("\n### TODO: SYSYEM PAUSE HERE!!!###\n");
      break;

      case 3:
        system("clear");
        printf("\n ----- Retirar ultimo erro ------");
        aux = desempilhar(&pilha);
        printf("\n Erro retirado: ");
        imprimirReg(aux);
        printf("\n### TODO: SYSYEM PAUSE HERE!!!###\n");
      break;

      default:
        printf("Opção inválida\n\n");
      break;
    }
  }while(opt != 0);
}