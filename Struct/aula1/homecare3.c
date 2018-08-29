#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float pmax, pmin;
}TLEITURA;

void VerificarPressao(float pmax, float pmin){
  if (pmax >= 15){
    printf("pressao alta\n");
  } else {
    if (pmin <= 7){
      printf("pressao baixa\n");
    } else {
      printf("pressao normal\n");
    }
  }
}


void main(){
  TLEITURA lt;
  
  printf("Digite a pressao maxima: ");
  scanf("%f",&lt.pmax);
  printf("Digite a pressao minima: ");
  scanf("%f",&lt.pmin);

  VerificarPressao(lt.pmax, lt.pmin);
}

