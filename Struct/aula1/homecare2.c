#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float pmax, pmin;
}TLEITURA;

void main(){
  TLEITURA lt;

  printf("Digite a pressao maxima: ");
  scanf("%f",&lt.pmax);
  printf("Digite a pressao minima: ");
  scanf("%f",&lt.pmin);

  if (lt.pmax >= 15){
    printf("pressao alta\n");
  } else {
    if (lt.pmin <= 7){
      printf("pressao baixa\n");
    } else {
      printf("pressao normal\n");
    }
  }
}