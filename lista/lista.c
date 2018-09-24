#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
  int chave;
  char nome[30];
  int musicas;
}TREGISTRO;

// Lista encadeada
struct TNO        // Tipo nó 
{
  TREGISTRO reg;
  struct TNO *prox;
};

typedef struct TNO *TLISTA;


TREGISTRO LerRegistro()
{
  TREGISTRO aux;

  printf(" Digite a chave : ");
  scanf("%d", &aux.chave);

  printf(" Digite o nome : ");
  scanf("%s", &aux.nome);

  printf(" Digite as musicas : ");
  scanf("%d", &aux.musicas);

  return aux;
}




void ImprimirRegistro(TREGISTRO pReg)
{
  printf("\n Chave \t\t : %d \n", pReg.chave);
  printf(" Nome \t\t : %s \n", pReg.nome);
  printf(" Musicas \t : %d \n", pReg.musicas);
}



void Inicializar( TLISTA *pLista )
{
  (*pLista) = NULL;
}




void InserirInicio(TLISTA *pLista, TREGISTRO pReg)
{
  // 1 - Alocar novo
  struct TNO *novo;
  novo = (struct TNO *)malloc( sizeof(struct TNO) );

  // 2 - Seta registro
  novo->reg = pReg;

  // 3 Redirecionar proximo
  novo->prox = (*pLista);

  // 4 - Novo assumir como lista
  (*pLista) = novo;
}




void InserirFinal(TLISTA *pLista, TREGISTRO pReg)
{ 
  struct TNO *novo, *aux;       // Cria um node novo e um auxiliar

  novo = (struct TNO *) malloc( sizeof (struct TNO));     // Aloca o espaço do novo na memoria ram
  novo->reg = pReg;     // coloca o registo passado por parametro, no novo node
  novo->prox = NULL;      // define o novo node como final, pois o proximo é null

  if ( (*pLista) == NULL)       // Se o node passado por parametro for null(ultimo da lista)
  {  
    (*pLista) = novo;           // O node passado se torna o novo node
  }
  else
  {
    aux = (*pLista);            // 
    while (aux->prox != NULL)
    {
      aux = aux->prox;
    }

    aux->prox = novo;
  }
}





void Imprimir(TLISTA pLista)
{
     struct TNO *aux;
     
     aux = pLista;  
     
     while (aux != NULL)
     {
           ImprimirRegistro(aux->reg);      
           aux = aux->prox;
     }  
}






void main()
{
    TREGISTRO r;
    TLISTA    l; // LinkedList l;
    Inicializar(&l);

    Imprimir(l);

}
