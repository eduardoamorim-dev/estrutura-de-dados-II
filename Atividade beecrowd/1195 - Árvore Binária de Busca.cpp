#include <iostream>

using namespace std;

struct No {
    int valor;
    No *esquerdo, *direito;
    No(int v) : valor(v), esquerdo(NULL), direito(NULL) {}
};

class ArvoreBinaria {
private:
    No* raiz;

    void preOrdem(No* no) {
        if (no == NULL) return;
        cout << " " << no->valor;
        preOrdem(no->esquerdo);
        preOrdem(no->direito);
    }

    void emOrdem(No* no) {
        if (no == NULL) return;
        emOrdem(no->esquerdo);
        cout << " " << no->valor;
        emOrdem(no->direito);
    }

    void posOrdem(No* no) {
        if (no == NULL) return;
        posOrdem(no->esquerdo);
        posOrdem(no->direito);
        cout << " " << no->valor;
    }

public:
    ArvoreBinaria() : raiz(NULL) {}

    void insere(int valor) {
        No* novo = new No(valor);
        if (raiz == NULL) {
            raiz = novo;
            return;
        }

        No* atual = raiz;
        No* pai = NULL;

        while (atual != NULL) {
            pai = atual;
            if (valor < atual->valor)
                atual = atual->esquerdo;
            else
                atual = atual->direito;
        }

        if (valor < pai->valor)
            pai->esquerdo = novo;
        else
            pai->direito = novo;
    }

    void preOrdem() {
        preOrdem(raiz);
        cout << "\n";
    }

    void emOrdem() {
        emOrdem(raiz);
        cout << "\n";
    }

    void posOrdem() {
        posOrdem(raiz);
        cout << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    int c, t = 1, n, q;
    cin >> c;

    while (c--) {
        cout << "Case " << t++ << ":\n";
        cin >> q;

        ArvoreBinaria AB;
        for (int i = 0; i < q; ++i) {
            cin >> n;
            AB.insere(n);
        }

        cout << "Pre.:";
        AB.preOrdem();

        cout << "In..:";
        AB.emOrdem();

        cout << "Post:";
        AB.posOrdem();
        cout << "\n";
    }
    return 0;
}
