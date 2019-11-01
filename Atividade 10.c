#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void QuickSort(int a[], int p, int r){
    int x,y;
    int i=p;
    int j=r;
    x = a[(p + r) / 2];

    while(i <= j) {
        while(a[i] < x && i < r) {
            i++;
        }
        while(a[j] > x && j > p) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > p) {
        QuickSort(a, p, j);
    }
    if(i < r) {
        QuickSort(a, i, r);
    }
}

int main(void){

int i=10;
int v[10]={30,12,3,5,6,9,10,25,10,40};

printf("Vetor desordenado: [ ");
for(i=0;i<10;i++){
printf("%d ", v[i]);}
printf("]\n");

QuickSort(v, 0, i-1);

printf("Vetor ordenado: [ ");
for(i=0;i<10;i++){
printf("%d ", v[i]);}
printf("]\n");

printf("Insira um numero a ser buscado na array:  ");
int b;
scanf("%d", &b);

for(i=0;i<10;i++){
 if(v[i]==b){
     printf("Numero encontrado.\n");
     return true;
 }
}
printf("Numero nao encontrado.\n");
return false;
}
