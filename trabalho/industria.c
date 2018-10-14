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

  printf("Descrição do erro: ");
  scanf("%s",&aux.desc);
  printf("Hora do erro: ");
  scanf("%d",&aux.hora);
  printf("Minuto do erro: ");
  scanf("%d",&aux.minuto);
  fflush(stdin);

  return aux;
}



int menu(){
  int opt;

  printf("[ 0 ] Sair\n");
  printf("[ 1 ] Registrar Erro\n");
  printf("[ 2 ] Visualizar Erros\n");
  printf("ESCOLHA: ");
  scanf("%d",&opt);

  return opt;
}

void imprimirReg(TERRO err){
  printf("Hora do erro [%d:%d]\n",err.hora,err.minuto);
  printf("Descrição: [%s]",err.desc);
}

void imprimir(TPILHA p){
  int i;
  for (i = p.topo; i>=0; i--){
    imprimirReg(p.erros[i]);
  }
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
        printf("Registrar erro\n");
        aux = lerErro();
        empilhar(&pilha, aux);
      break;

      case 2:
        printf("Visualizar erros\n");
        imprimir(pilha);
      break;

      default:
        printf("Opção inválida\n\n");
      break;
    }
  }while(opt != 0);
}