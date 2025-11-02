#include <stdio.h>
int main(void)
{
/*Un puntero apunta a una direccion en memoria,
no al valor directamente*/
    int valor = 10;
    int *pointer = &valor; //Puntero a variable int
    int **pointer_to_pointer = &pointer; // puntero a puntero que apunta a variable

printf("Memory Address: %p\n", pointer_to_pointer);

 return 0;   
}