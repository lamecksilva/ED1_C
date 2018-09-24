#include <stdio.h>
#include <stdlib.h>

// Inicia a lista, que armazena um numero inteiro e o valor do proximo item da lista
struct Node{
  int num;
  struct Node *prox;
};

// Define o tipo Lista como um Node
typedef struct Node *LISTA;

// Recebe a lista por parametro e declara o proximo valor dela como null
void inicia(LISTA *pLista){
  (*pLista) = NULL;
};

// Insere um novo node no final
void insereFinal(LISTA *pLista, int n){
  // Cria dois nodes novos 
  struct LISTA *novo, *aux;

  novo = (struct LISTA *) malloc( sizeof(struct Node));
  novo->num = n;
  novo->prox = NULL;

  if ((*pLista) == NULL)
  {
    (*pLista) = novo;       // Se o node for o ultimo, seu 'prox' vira o novo node
  }

  else
  {
    aux = (*pLista);
    while(aux->prox != NULL){       // Enquanto não chegar ao final da lista
      aux = aux->prox;            // O auxiliar vai ficar passando de node até chegar ao ultimo
    }

    // Ai então o proximo node se torna o ultimo
    aux->prox = novo;
  }
}


void imprimir(LISTA *pLista){        // O método imprimir recebe um node lista por parametro
  struct LISTA *aux;          //  Um node auxiliar é criado

  aux = pLista;         // O node auxiliar recebe a lista passada por parametro

  while(aux != NULL){         // Enquanto aux não for o ultimo da lista
    printf("[%d]  ",aux->num);     // vai printar o valor na tela
    aux = aux->prox;             // e o auxiliar vai se tornar o proximo a cada loop
  }

}


// Onde a mágica acontece
void main(void){
  int num;
  LISTA l;

  inicia(&l);
  printf("digite o primeiro numero");
  scanf("%d",&num);

  insereFinal(&l,num);

  imprimir(&l);
}