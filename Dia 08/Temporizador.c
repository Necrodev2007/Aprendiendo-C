#include <stdio.h>
#include <unistd.h>
int main()
{
int time, i;
printf("//////Temporizador//////\n\n");
printf("Ingresa el tiempo en segundos: ");
scanf("%d", &time);
printf("\n");
for(i = time; i >= 0; i--)
{
printf("%d\n", i);
fflush(stdout);
sleep(1);
}
printf("¡Se acabo el tiempo!");
return 0;
}