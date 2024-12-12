#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int value;
    Node *left, *right;
    Node(int _value) : value(_value), left(NULL), right(NULL) {}
};

struct Tree {
    Node *root;
    Tree() : root(NULL) {}

    bool empty() {
        return root == NULL;
    }

    void insert(int value) {
        if (empty()) {
            root = new Node(value);
        } else {
            insert(root, value);
        }
    }

    void insert(Node *aux, int value) {
        if (value < aux->value) {
            if (aux->left == NULL) {
                aux->left = new Node(value);
            } else {
                insert(aux->left, value);
            }
        } else if (value > aux->value) {
            if (aux->right == NULL) {
                aux->right = new Node(value);
            } else {
                insert(aux->right, value);
            }
        }
    }

    void levelOrder(Node *aux) {
        if (aux == NULL) return;
        queue<Node*> q;
        q.push(aux);
        bool first = true;
        while (!q.empty()) {
            Node *current = q.front();
            q.pop();
            if (!first) cout << " ";
            cout << current->value;
            first = false;
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }
};

int main() {
    int C;
    cin >> C;

    for (int caseNum = 1; caseNum <= C; ++caseNum) {
        int N;
        cin >> N;

        Tree t;
        for (int i = 0; i < N; ++i) {
            int value;
            cin >> value;
            t.insert(value);
        }

        cout << "Case " << caseNum << ":\n";
        t.levelOrder(t.root);
        cout << "\n\n";
    }

    return 0;
}