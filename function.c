#include "lib.h"

Tree *stree(Tree *root, Tree *r, int key){
	if(!r) {
		r = (Tree *) malloc(sizeof(Tree));
		if(!r){
			printf("Erro em alocação\nSem memória\n");
			exit(0);
		}
		r->left = NULL;
		r->right = NULL;
		r->key = key;
		if(!root)
			return r; /** primeira entrada */
		if(key < root->key)
			root->left = r;
		else
			root->right = r;
		return r;
	}
	if(key < r->key)
		stree(r, r->left, key);
	else
		stree(r, r->right, key);
}

void print_tree(Tree *r, int l){
	int i;
	if(!r)
		return;
	print_tree(r->right, l + 1);
	for(i = 0; i < l; ++i)
		printf(" ");
	printf("%d\n", r->key);
	print_tree(r->left, l + 1);
}

void inorder(Tree *root){
	if(!root)
		return;
	inorder(root->left);
	if(root->key)
		printf("%d ", root->key);
	inorder(root->right);
}

void preorder(Tree *root){
	if(!root)
		return;
	if(root->key)
		printf("%d ", root->key);
	preorder(root->left);
	preorder(root->right);
}

void posorder(Tree *root){
	if(!root)
		return;
	posorder(root->left);
	posorder(root->right);
	if(root->key)
		printf("%d ", root->key);
}

Tree *search_tree(Tree *root, int key){
	if(!root)
		return root; /** not found */
	if(!root)
		return root; /** arvore vazia */
	while(root->key != key){
		if(key < root->key)
			root = root->left;
		else
			root = root->right;
		if(!root)
			break;
	}
	return root;
}

Tree *dtree(Tree *root, int key){
	Tree *p, *p2;

	if(!root)
		return root;                     /** não enconntrado */

	if(root->key == key){               /** apagar a raiz */
		if(root->left == root->right){ /** isso significa uma árvore vazia */
			free(root);
			return NULL;
		}else if (!root->left){      /** ou se uma sub árvore é nula */
			p = root->right;
			free(root);
			return p;
		}else if(!root->right){
			p = root->left;
			free(root);
			return p;
		}else {                  /** ou as duas subárvores estão presentes */
			p2 = root->right;
			p = root->right;
			while(p->left)
				p = p->left;
			p->left = root->left;
			free(root);
			return p2;
		}
	}
	if(root->key < key)
		root->right = dtree(root->right, key);
	else
		root->left = dtree(root->left, key);
	return root;
}
