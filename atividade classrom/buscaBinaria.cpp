#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string toLowerCase(const string& str) {
    string result = str;
    for (char& ch : result) {
        ch = tolower(ch);
    }
    return result;
}

void buscaBinariaPrefixo(const vector<string>& nomes, const string& prefixo) {
    string prefixoLower = toLowerCase(prefixo);
    int s = 0, e = nomes.size() - 1;

    while (s <= e) {
        int m = (s + e) / 2;
        string nomeLower = toLowerCase(nomes[m]);

        if (nomeLower.compare(0, prefixoLower.size(), prefixoLower) == 0) {
            cout << "Resultado da busca: " << nomes[m] << "\n";

            int esquerda = m - 1;
            while (esquerda >= 0 && toLowerCase(nomes[esquerda]).compare(0, prefixoLower.size(), prefixoLower) == 0) {
                cout << "Resultado da busca: " << nomes[esquerda] << "\n";
                --esquerda;
            }

            int direita = m + 1;
            while (direita < nomes.size() && toLowerCase(nomes[direita]).compare(0, prefixoLower.size(), prefixoLower) == 0) {
                cout << "Resultado da busca: " << nomes[direita] << "\n";
                ++direita;
            }
            return; 
        } else if (nomeLower > prefixoLower) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }

    cout << "Nenhum resultado encontrado para o prefixo: " << prefixo << "\n";
}

int main() {
    ifstream file("C:/Users/natsa/OneDrive/Documentos/nomes.txt");
    if (!file) {
        cerr << "Erro ao abrir o arquivo 'nomes.txt'.\n";
        return 1;
    }

    vector<string> nomes;
    string nome;

    while (getline(file, nome)) {
        nomes.push_back(nome);
    }
    file.close();

    sort(nomes.begin(), nomes.end());

    string prefixo;
    cout << "Digite o prefixo para busca: ";
    ncin >> prefixo;

    buscaBinariaPrefixo(nomes, prefixo);

    return 0;
}


/*Ler o arquivo nomes.txt em anexo.

Utilizando a busca binária, ler um nome e retornar todos os nomes que se encaixam com a busca no início da palavra.

Por exemplo:

Adalberto Estevez
Adelia Rosmaninho
Adelina Paredes
Adelio Clementino
Afonso Cantanhede
Afonso Herrera
Bruna Adenisia

Se buscar pelas iniciais Ade, sua busca deve trazer "Adelia Rosmaninho", "Adelina Paredes", "Adelio Clementino".


Ignorar letras maiúsculas e minúsculas na hora de ler.

Funções úteis:

https://cplusplus.com/reference/cstring/strstr/

https://cplusplus.com/reference/cctype/toupper/

https://cplusplus.com/reference/cctype/tolower
*/