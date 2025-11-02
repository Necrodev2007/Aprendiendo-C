#include <stdio.h>
int main(){


int numero;
char texto[20];

scanf("%d", &numero);
while (getchar() != '\n');  // 🧹 Limpia el [ENTER] sobrante
scanf("%s", texto);         // ✅ Ahora sí funciona

return 0;
}