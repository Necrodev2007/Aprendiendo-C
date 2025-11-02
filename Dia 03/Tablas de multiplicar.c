#include <stdio.h>
int main()
{
int a, b;
int tablas;
int max = 10;
printf("\nGenerador de tablas\n\n");
printf("Numero de tablas:");
scanf("%d", &tablas);
if(tablas > 0){
for(a = 1;a <= tablas; ++a){
    for(b = 0; b <= max; ++b){
printf("%d x %d = %d\n",a,b,a*b);


}
printf("\n");
}
}
return 0;
}
