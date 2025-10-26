#include <stdio.h>
const int ciudad = 2, semana = 7;
int main(){
int covid[ciudad][semana];
for (int i = 0; i < ciudad; i++)
{
for (int j = 0; j < semana; j++)
{
    printf("ciudad %d, dia %d: ", i+1,j+1);
    scanf("%d", &covid[i][j]);
}
}
printf("\nDatos: \n\n");


for(int i = 0; i < ciudad; i++)
{
   for (int j = 0; j < semana; j++)
   {
    printf("ciudad %d, dia %d: = %d\n ", i+1,j+1, covid[i][j]);
   }
  
}
return 0;
}