#include <iostream>
#include <locale>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Time {
    string nome;
    int pontos = 0;
    int vitorias = 0;
    int empates = 0;
    int derrotas = 0;
    int saldoGols = 0;
    int golsPro = 0;
    int golsContra = 0;
};

void calculaEstatisticas(Time &time1, Time &time2, int g1, int g2) {
    if (g1 > g2) {
        time1.pontos += 3;
        time1.vitorias++;
        time2.derrotas++;
    } else if (g1 < g2) {
        time2.pontos += 3;
        time2.vitorias++;
        time1.derrotas++;
    } else {
        time1.pontos++;
        time2.pontos++;
        time1.empates++;
        time2.empates++;
    }

    time1.golsPro += g1;
    time1.golsContra += g2;
    time2.golsPro += g2;
    time2.golsContra += g1;

    time1.saldoGols = time1.golsPro - time1.golsContra;
    time2.saldoGols = time2.golsPro - time2.golsContra;
}

int encontraTime(Time times[], int n, const string &nome) {
    for (int i = 0; i < n; i++) {
        if (times[i].nome == nome) return i;
    }
    return -1;
}

void imprimeTabela(const Time times[], int n) {
    cout << left << setw(10) << "Time"
         << setw(7) << "Pontos"
         << setw(9) << "Vitórias"
         << setw(8) << "Empates"
         << setw(9) << "Derrotas"
         << setw(12) << "Saldo Gols"
         << setw(9) << "Gols Pró"
         << setw(12) << "Gols Contra" << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << times[i].nome
             << setw(7) << times[i].pontos
             << setw(9) << times[i].vitorias
             << setw(9) << times[i].empates
             << setw(8) << times[i].derrotas
             << setw(12) << times[i].saldoGols
             << setw(9) << times[i].golsPro
             << setw(12) << times[i].golsContra << endl;
    }
}

int main() {
    const int MAX_TIMES = 12;
    Time times[MAX_TIMES] = {{"CAM"}, {"CAL"}, {"ATH"}, {"DGV"}, {"AME"}, {"CRU"},
                             {"TOM"}, {"VNO"}, {"URT"}, {"POU"}, {"CAP"}, {"UBE"}};

    ifstream arquivo("C:/Users/eduardoamorim/documents/times.txt");
    string linha;

    while (getline(arquivo, linha)) {
        string time1 = linha.substr(0, 3);
        string time2 = linha.substr(linha.length() - 3, 3);
        int g1 = linha[4] - '0';
        int g2 = linha[6] - '0';

        int indice1 = encontraTime(times, MAX_TIMES, time1);
        int indice2 = encontraTime(times, MAX_TIMES, time2);
        calculaEstatisticas(times[indice1], times[indice2], g1, g2);
    }

    setlocale(LC_ALL, "");
    int opcao;

    do {
        cout << "-------- Menu ---------\n";
        cout << "Escolha o método de ordenação:\n";
        cout << "1. Algoritmo BubbleSort\n";
        cout << "2. Algoritmo SelectionSort\n";
        cout << "3. Algoritmo InsertionSort\n";
        cout << "4. Algoritmo MergeSort\n";
        cout << "5. Sair\n";
        cout << "Digite sua opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                bubbleSort(times, MAX_TIMES);
                imprimeTabela(times, MAX_TIMES);
                break;
            case 2:
                selectionSort(times, MAX_TIMES);
                imprimeTabela(times, MAX_TIMES);
                break;
            case 3:
                insertionSort(times, MAX_TIMES);
                imprimeTabela(times, MAX_TIMES);
                break;
            case 4:
                mergeSort(times, 0, MAX_TIMES - 1);
                imprimeTabela(times, MAX_TIMES);
                break;
            case 5:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }
    } while (opcao != 5);

    return 0;
}
