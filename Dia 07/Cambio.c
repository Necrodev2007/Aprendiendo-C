#include <stdio.h>
int main()
{

float precio = 15.60, dineroc = 20,cambio;
cambio = dineroc - precio;

printf("====Factura====\n\nPrecio del producto: %.2f$\nDinero del cliente: %.0f$\n\nSu cambio es: %.2f$\n",precio, dineroc, cambio);

}