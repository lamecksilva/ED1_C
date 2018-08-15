#include <stdio.h>
#include <string.h>

struct Person {
  char pName[15];
  int age;
};

void main(){
  struct Person prn;

  strcpy(prn.pName,"Jooj");
  prn.age = 13;

  printf("%s\n%d\n",prn.pName,prn.age);
}