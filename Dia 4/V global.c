#include<stdio.h>
void display();
int n = 12; //Variable global

int main(){


++n;

display();
return 0;
}
void display(){

++n;
printf("n = %d\n", n);
}