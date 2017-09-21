#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int key;
	struct tree *left;
	struct tree *right;
}Tree;

/** Criando a enumeração: */
enum boolean{
    true = 1, false = 0
};
/** Permitindo a sua declaração como um tipo qualquer: */
typedef enum boolean bool;

/** Primeiro no da arvore */
Tree *root;


/** Protótipo das Funções */
Tree *stree(Tree *root, Tree *r, int key);  // inserção
void inorder(Tree *root);                   // print in-order
void preorder(Tree *root);                  // print pre-order
void posorder(Tree *root);                  // print pos-order
void print_tree(Tree *root, int l);         // mostra toda estrutura
Tree *search_tree(Tree *root, int key);     // busca um valor
Tree *dtree(Tree *root, int key);           // remove um valor
