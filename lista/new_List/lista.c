#include <stdio.h>
#include <stdlib.h>

// Registro -- -------------------------------------------
typedef struct 
{
        int   chave;
        char  nome[30];
        int   musicas;      
}TREGISTRO;

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

// Lista encadeada
struct TNO
{
       TREGISTRO   reg;
       struct TNO  *prox;
};

typedef struct TNO *TLISTA;

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
     struct TNO *novo, *aux;
     
     novo = (struct TNO *) malloc( sizeof (struct TNO));    
     novo->reg = pReg;
     novo->prox = NULL;

     if ( (*pLista) == NULL)
     {  
          (*pLista) = novo;
     }
     else
     {
         aux = (*pLista);
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


void InserirPosicao(TLISTA *pLista, TREGISTRO pReg, int pPos)
{
	struct TNO *novo, *aux;
	int p;
    // 1 - Criar o no
	novo 		= (struct TNO *) malloc(sizeof (struct TNO));	
	novo->reg 	= pReg;
	novo->prox  = NULL;	
	// 2 - Encontrar a posicao
	aux = (*pLista);
	p   = 0;
	while (p < pPos-1)
	{
		aux = aux->prox;		
		p++;
	}
	// 3 - Insercao em si
	novo->prox = aux->prox;
	aux->prox = novo;
}




void main(void)
{
    TREGISTRO r;
    TLISTA    l; // LinkedList l;

    Inicializar(&l);
    
    r = LerRegistro();
    InserirFinal(&l, r);

    r.musicas = 100;
    InserirFinal(&l, r);

    r.musicas = 200;
    InserirFinal(&l, r);

	printf(" -- Impressao 1 --\n ");
    Imprimir(l);

	printf(" -- Impressao 2 --\n ");
    r.musicas = 150;
    InserirPosicao(&l, r, 2);
    r.musicas = 130;
    InserirPosicao(&l, r, 2);
	Imprimir(l);

    system("pause");
}