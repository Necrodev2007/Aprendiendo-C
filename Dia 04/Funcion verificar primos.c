#include <stdio.h>
int nprimo(int n);
int main(){

    int n, flag = 0;
    
printf("ingrese un numero: ");
    scanf("%d", &n);
flag = nprimo(n);
    
if(flag == 1){

printf("%d no es primo\n", n);
}
else{
printf("%d es primo\n", n);
}
return 0;
}
int nprimo(int n){

int i;

    for(i = 2; i <= n/2; i++)
    {
if(n % i == 0)
{
return 1;

}
}
}