/*  Comentei os 'system pause, cls' pois o shell bash não roda eles, mas para funcionar no devc++ basta
    remover os //
*/

#include <stdio.h>
#include <stdlib.h>


#define tam 3


// Define um tipo estrutura chamado TREGISTRO
typedef struct{             
       int id;
       char Desc[30];
       int  Qtde;
}TREGISTRO;



// Função que retorna uma estrutura do tipo TREGISTRO
TREGISTRO LerRegistro ()        
{
     TREGISTRO aux;
     
     printf(" Digite o id : ");
     scanf("%d", &aux.id);
     printf(" Digite a descricao : ");
     scanf("%s", &aux.Desc);
     printf(" Digite a quantidade : ");
     scanf("%d", &aux.Qtde);
     
     return aux;
}



// Recebe uma estrutura como argumento, e 'printa' seus atributos 
void ImprimirRegistro(TREGISTRO pReg)              
{
     printf(" Id: %d Desc:  %s - Qtde - %d \n", pReg.id, pReg.Desc, pReg.Qtde);    
}


// Define uma estrutura que guarda um vetor do tipo TREGISTRO
typedef struct {
       TREGISTRO Itens[tam];
       int Topo;      
}TPILHA;


// Recebe uma estrutura TPILHA e define seu topo como -1
void Inicializar(TPILHA *pPilha)
{
     (*pPilha).Topo = -1;    
}

// Recebe uma TPILHA e retorna se a pilha está vazia ou não
int PilhaVazia(TPILHA pPilha)
{
    return (pPilha.Topo == -1);   
}

// Recebe uma TPILHA e retorna se a pilha está no seu 'topo' maximo [2]
int PilhaCheia(TPILHA pPilha)
{
    return (pPilha.Topo == (tam-1));   
}


// Se a pilha NÃO estiver vazia, coloca um registro a mais na pilha
void Empilhar(TPILHA *pPilha, TREGISTRO pReg)
{
     if ( ! PilhaCheia(*pPilha) )
     {
          (*pPilha).Topo++;
          (*pPilha).Itens[ (*pPilha).Topo ] = pReg;
     }
     else
     {
         printf(" Nao eh possivel empilhar em pilha cheia.");
     }
}


// Se a pilha NÃO estiver vazia, tira o registro que está no topo
TREGISTRO Desempilhar(TPILHA *pPilha)
{
    TREGISTRO aux;
    if ( ! PilhaVazia(*pPilha) )
    {
        aux = (*pPilha).Itens[ (*pPilha).Topo ];
        (*pPilha).Topo--;
    }
    else
    {
         aux.Qtde = -1;
         printf(" Nao eh possivel desempilhar em pilha vazia.");
    }

    return aux;
}


// Recebe a pilha e 'printa' seus dados
void Imprimir(TPILHA pPilha)
{
      printf("-- Pilha -- \n");
      int i;
      for (i= pPilha.Topo; i>=0; i--)
      {
          ImprimirRegistro(pPilha.Itens[i]); 
          printf("\n");
      }
}


// Menu que retorna a opção desejada
int Menu()
{
    int op; 
    printf(" \n\n -- Menu -- \n");   
    printf("   (1) Empilhar p1 \n");   
    printf("   (2) Empilhar p2 \n");   
    printf("   (3) Passar P1 para P2 \n");   
    printf("   (4) Passar P2 para P1 \n");   
    printf("   (5) Desempilhar P1 \n");   
    printf("   (6) Desempilhar P2 \n");   
    printf("   (7) Visaulizar estoque \n");   
    printf("   (9) Sair \n");   
    printf(" Opcao : ");
    scanf("%d", &op);
    return op;    
}



// Main
void main()
{
      int opcao;
      TPILHA p1, p2;
      TREGISTRO raux;      

      Inicializar(&p1);
      Inicializar(&p2);
      
      do{
          
          opcao = Menu();

          printf("\n\n");          
          // Processar opcao de menu          
          switch(opcao)
          {
             case 1: {
                  raux = LerRegistro();
                  Empilhar(&p1, raux);                  
             } break;             

             case 2: {
                  raux = LerRegistro();
                  Empilhar(&p2, raux);                  
             } break;             

             case 3: {
                  raux = Desempilhar(&p1);                  
                  Empilhar(&p2, raux);
             } break;             

             case 4: {
                  raux = Desempilhar(&p2);                  
                  Empilhar(&p1, raux);
             } break;             


             case 5: {
                  raux = Desempilhar(&p1);
                  printf(" Registro desempilhado (p1): ");
                  ImprimirRegistro(raux);                  
                  } break;             

             case 6: {
                  raux = Desempilhar(&p2);
                  printf(" Registro desempilhado (p2): ");
                  ImprimirRegistro(raux);                  
                  } break;             

             case 7: {
                  printf("\n Pilha 1: \n");
                  Imprimir(p1);
                  printf("\n Pilha 2: \n");
                  Imprimir(p2);
                  } break;             


             default: {
                printf(" A implementar ");
            }                                   
        }
          
        printf("\n\n");          
        //system("pause");
        //system("cls");
    } while(opcao != 9);   
    //system("pause");  
}


//Fim
//Comentários: Clovis Filho