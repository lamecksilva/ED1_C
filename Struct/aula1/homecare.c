#include <stdio.h>
#include <stdlib.h>

void main(){
  float pmax, pmin;

  printf("Digite a pressao maxima: ");
  scanf("%f",&pmax);
  printf("Digite a pressao minima: ");
  scanf("%f",&pmin);

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