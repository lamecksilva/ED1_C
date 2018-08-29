#include <stdio.h>

void main()
{
    int var = 20;
    int *ip;

    ip = &var;

    printf("Endereço da var: %x\n", &var);

    printf("Endereço na ip: %x\n", ip);

    printf("Valor de *ip: %x\n", *ip);
}
