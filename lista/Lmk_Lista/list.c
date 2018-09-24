#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
  int     conteudo;
  struct reg *prox; 
} celula;


void imprime(celula *le){
  celula *p;
  for(p = le->prox; p != NULL; p = p->prox)
    printf("%d\n",p->conteudo);
};

int menu(){
  int opt;

  printf(" === MENU ===\n");
  printf("0 - Sair\n");
  printf("1 - Visualizar Lista\n");
  printf("2 - Adicionar no final\n");
  printf("3 - Adicionar no inicio\n");
  printf("4 - Pesquisar elemento\n");
  printf("5 - Apagar celula\n");

  printf("Opcao: ");
  scanf("%d",&opt);
}

void main(void){
  celula *le;
  le = malloc (sizeof (celula));
  le->prox = NULL;


}
