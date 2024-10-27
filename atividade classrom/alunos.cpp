#include <iostream>
#include <locale>
#include <fstream>
#include <string>

using namespace std;

const int MAX_LINHAS = 1000;

void troca(string* linhas, int a, int b) {
    string aux = linhas[a];
    linhas[a] = linhas[b];
    linhas[b] = aux;
}

void bubbleSort(string* linhas, int n) {
    for (int i = 0; i < n - 1; i++) {
        bool houveTroca = false;
        for (int j = 0; j < (n - 1) - i; j++) {
            if (linhas[j] > linhas[j + 1]) {
                troca(linhas, j, j + 1);
                houveTroca = true;
            }
        }
        if (!houveTroca) return;
    }
}

void selectionSort(string* linhas, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (linhas[i] > linhas[j]) {
                troca(linhas, i, j);
            }
        }
    }
}

void insertionSort(string* linhas, int n) {
    for (int i = 1; i < n; i++) {
        string aux = linhas[i];
        int j = i - 1;
        while (j >= 0 && aux < linhas[j]) {
            linhas[j + 1] = linhas[j];
            j--;
        }
        linhas[j + 1] = aux;
    }
}

void merge(string* linhas, int s, int m, int e) {
    string tmp[(e - s) + 1];
    int i = s, j = m + 1, k = 0;
    while (i <= m && j <= e) {
        tmp[k++] = (linhas[i] < linhas[j]) ? linhas[i++] : linhas[j++];
    }
    while (i <= m) {
        tmp[k++] = linhas[i++];
    }
    while (j <= e) {
        tmp[k++] = linhas[j++];
    }
    for (i = s, k = 0; i <= e; i++, k++) {
        linhas[i] = tmp[k];
    }
}

void mergeSort(string* linhas, int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(linhas, s, m);
        mergeSort(linhas, m + 1, e);
        merge(linhas, s, m, e);
    }
}

void imprimirVetor(string* linhas, int n) {
    for (int i = 0; i < n; i++) {
        cout << linhas[i] << endl;
    }
}

int carregarArquivo(string* linhas) {
    ifstream arquivo("C:/Users/eduardoamorim/Documents/alunos.txt");

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 0;
    }

    string linha;
    int contador = 0;
    while (getline(arquivo, linha) && contador < MAX_LINHAS) {
        linhas[contador++] = linha;
    }
    arquivo.close();
    return contador;
}

void exibirMenu() {
    cout << "-------- Menu ---------\n";
    cout << "Escolha uma opção:\n";
    cout << "1. Algoritmo BubbleSort\n";
    cout << "2. Algoritmo SelectionSort\n";
    cout << "3. Algoritmo InsertionSort\n";
    cout << "4. Algoritmo MergeSort\n";
    cout << "5. Sair\n";
}

int main() {
    setlocale(LC_ALL, "");

    string* linhas = new string[MAX_LINHAS];
    int totalLinhas = carregarArquivo(linhas);
    if (totalLinhas == 0) {
        delete[] linhas;
        return 1;
    }

    int opcao;
    do {
        exibirMenu();
        cin >> opcao;

        switch (opcao) {
            case 1:
                bubbleSort(linhas, totalLinhas);
                imprimirVetor(linhas, totalLinhas);
                break;
            case 2:
                selectionSort(linhas, totalLinhas);
                imprimirVetor(linhas, totalLinhas);
                break;
            case 3:
                insertionSort(linhas, totalLinhas);
                imprimirVetor(linhas, totalLinhas);
                break;
            case 4:
                mergeSort(linhas, 0, totalLinhas - 1);
                imprimirVetor(linhas, totalLinhas);
                break;
            case 5:
                cout << "Você saiu do programa!\n";
                break;
            default:
                cout << "Opção inválida!\n";
                break;
        }
    } while (opcao != 5);

    delete[] linhas;
    return 0;
}
