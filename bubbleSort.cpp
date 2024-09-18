#include <iostream>

void troca(int v[], int a, int b){
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void bubbleSort(int v[], int n){

    for (int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++){
            if(v[j] > v[j + 1]){
                troca(v, j, j+1);
            }
        }
    }
}

void imprimirVetor(int v[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

using namespace std;

int main (){

    int v[] = { 4 , 1, 3, 2 };
    bubbleSort(v, 4);
    imprimirVetor(v, 4);

    return 0;
}
