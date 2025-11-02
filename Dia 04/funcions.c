#include <stdio.h>
int calc(int a,int b);
int main()
{
int n1,n2,resp;
printf("Ingrese 2 numeros: ");
scanf("%d %d",&n1,&n2);
resp= calc(n1,n2);
printf("Resultado: %d\n",resp);
return 0;

}
int calc(int a,int b){
int res;
res = a + b;
return res;
}
