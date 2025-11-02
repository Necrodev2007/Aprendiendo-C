#include <stdio.h>

int main()
{

char * name = "Luis";

printf("\nDireccion en memoria: %p - Valor: %s\n", name, name);

long long n[5] ;

printf("Tamano en bytes: %lld", sizeof(n));



return 0;

}