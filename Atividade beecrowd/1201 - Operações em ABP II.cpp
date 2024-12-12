#include <stdio.h>
#include <string.h>

struct Node {
    int value;
    Node *left, *right;
    Node() {
        left = NULL;
        right = NULL;
    }
    Node(int _value) {
        value = _value;
        left = NULL;
        right = NULL;
    }
    int g() {
        int g = 0;
        if (left != NULL) g++;
        if (right != NULL) g++;
        return g;
    }
};

struct Tree {
    Node *root;
    Tree() {
        root = NULL;
    }
    
    bool empty() {
        return root == NULL;
    }

    void insert(int value) {
        if (empty()) {
            root = new Node(value);
            return;
        }
        insert(root, value);
    }

    void insert(Node *aux, int value) {
        if (value < aux->value) {
            if (aux->left == NULL) {
                aux->left = new Node(value);
                return;
            }
            insert(aux->left, value);
        } else if (value > aux->value) {
            if (aux->right == NULL) {
                aux->right = new Node(value);
                return;
            }
            insert(aux->right, value);
        }
    }

    void inOrder() {
        inOrder(root);
    }

    void inOrder(Node *aux) {
        if (aux == NULL) return;
        
        int first = 1;
        innerInOrder(aux, first);
    }

    void innerInOrder(Node *aux, int &first) {
        if (aux == NULL) return;
        
        innerInOrder(aux->left, first);
        
        if (!first) printf(" ");
        else first = 0;
        
        printf("%d", aux->value);
        
        innerInOrder(aux->right, first);
    }

    void preOrder() {
        preOrder(root);
    }

    void preOrder(Node *aux) {
        if (aux == NULL) return;
        
        int first = 1;
        innerPreOrder(aux, first);
    }

    void innerPreOrder(Node *aux, int &first) {
        if (aux == NULL) return;
        
        if (!first) printf(" ");
        else first = 0;
        
        printf("%d", aux->value);
        
        innerPreOrder(aux->left, first);
        innerPreOrder(aux->right, first);
    }

    void postOrder() {
        postOrder(root);
    }

    void postOrder(Node *aux) {
        if (aux == NULL) return;
        
        int first = 1;
        innerPostOrder(aux, first);
    }

    void innerPostOrder(Node *aux, int &first) {
        if (aux == NULL) return;
        
        innerPostOrder(aux->left, first);
        innerPostOrder(aux->right, first);
        
        if (!first) printf(" ");
        else first = 0;
        
        printf("%d", aux->value);
    }

    bool search(int value) {
        return search(root, value);
    }

    bool search(Node *aux, int value) {
        if (aux == NULL) return false;
        if (value == aux->value) return true;
        if (value < aux->value) return search(aux->left, value);
        return search(aux->right, value);
    }

    void remove(int value) {
        if (!empty()) {
            root = removeNode(root, value);
        }
    }

    Node* removeNode(Node* node, int value) {
        if (node == NULL) return NULL;

        if (value < node->value) {
            node->left = removeNode(node->left, value);
        } 
        else if (value > node->value) {
            node->right = removeNode(node->right, value);
        } 
        else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } 
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMax(node->left);
            node->value = temp->value;
            node->left = removeNode(node->left, temp->value);
        }
        return node;
    }

    Node* findMax(Node* node) {
        Node* current = node;
        while (current->right != NULL) {
            current = current->right;
        }
        return current;
    }
};

int main() {
    Tree tree;
    char op[10];
    int value;

    // Primeira inserção
    scanf("I %d", &value);
    tree.insert(value);

    // Processamento dos comandos subsequentes
    while (scanf("%s", op) != EOF) {
        if (strcmp(op, "I") == 0) {
            scanf("%d", &value);
            tree.insert(value);
        }
        else if (strcmp(op, "INFIXA") == 0) {
            tree.inOrder();
            printf("\n");
        }
        else if (strcmp(op, "PREFIXA") == 0) {
            tree.preOrder();
            printf("\n");
        }
        else if (strcmp(op, "POSFIXA") == 0) {
            tree.postOrder();
            printf("\n");
        }
        else if (strcmp(op, "P") == 0) {
            scanf("%d", &value);
            if (tree.search(value)) {
                printf("%d existe\n", value);
            } else {
                printf("%d nao existe\n", value);
            }
        }
        else if (strcmp(op, "R") == 0) {
            scanf("%d", &value);
            tree.remove(value);
        }
    }

    return 0;
}