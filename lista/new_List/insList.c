#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char nome[20];
  int idade;
}TREGISTRO;









TREGISTRO ler(){
  TREGISTRO aux;

  printf("Digite seu nome: ");
  scanf("%s", &aux.nome);
  printf("Digite sua idade: ");
  scanf("%d", &aux.idade);

  return aux;
}









typedef struct NODE {
  TREGISTRO reg;
  struct NODE *prox;
};

typedef struct NODE *lista;



void iniciar(lista *pLista){
  (*pLista) = NULL;
}












int menu(){
  int opt;

  printf(" ==== Menu ====\n");
  printf("0 - Sair\n");
  printf("1 - Mostrar\n");
  printf("2 - Inserir no Final\n");
  printf("3 - Inserir no Inicio\n");
  printf("4 - Inserir na posição\n");
  printf("Opcao: ");
  scanf("%d",&opt);

  return opt;
}







void imprimirReg(TREGISTRO reg){
  printf("\nNome: %s\n",reg.nome);
  printf("Idade: %d\n",reg.idade);
}







void imprimir(lista pLista){
  struct NODE *aux;

  aux = pLista;

  while(aux != NULL){
    imprimirReg(aux->reg);
    aux = aux->prox;
  }
}








void inserirFinal(lista *pLista, TREGISTRO reg){
  struct NODE *novo, *aux;

  novo = (struct NODE *) malloc( sizeof (struct NODE));
  novo->reg = reg;
  novo->prox = NULL;

  if ( (*pLista) == NULL ){
    (*pLista) = novo;
  }else{
    aux = (*pLista);
    while(aux->prox != NULL){
      aux = aux->prox;
    }

    aux->prox = novo;
  }
}









void main(void){
  TREGISTRO  reg;
  lista  l;
  int  opt;

  iniciar(&l);

  do{
    opt = menu();
    switch(opt){
      case 1:
        imprimir(&l);
        break;

      case 2:
        reg = ler();
        inserirFinal(&l,reg);
        break;
    }

  }while(opt != 0);
}