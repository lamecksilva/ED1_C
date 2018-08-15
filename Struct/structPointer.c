#include <stdio.h>
#include <string.h>

struct Person {
  char pName[15];
  int age;
};

void printPerson( struct Person *person );

void main(){
  struct Person prn;

  strcpy(prn.pName,"Jooj");
  prn.age = 13;

  printPerson( &prn );
}

void printPerson ( struct Person *person ){
  printf("Name of person: %s\n",person->pName);
  printf("Age of person: %d\n",person->age);
}