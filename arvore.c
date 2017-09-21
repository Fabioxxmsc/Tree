#include "function.c"

int main(){
	Tree *b;
	int n, qtd, op;
	root = b = NULL; /** Inicializa-se a raiz */


	do{
		printf("\nMenu\n");
		printf("1 - Inserir\n");
		printf("2 - Buscar\n");
		printf("3 - Mostrar tudo\n");
		printf("4 - Mostrar (Pré-Order)\n");
		printf("5 - Mostrar (In-Order)\n");
		printf("6 - Mostrar (Pos-Order)\n");
		printf("7 - Remover\n");
		printf("0 - Sair\n");
		printf("Sua opção: ");
		scanf("%d", &op);
		printf("\n");
		switch (op){
			case 1: /** Insere valores */
				printf("Informe a quantidade de valores a serem inseridos: ");
				scanf("%d", &qtd);
				for(int i = 0; i < qtd; i++){
					printf("\nInforme o valor a ser inserido: ");
					scanf("%d", &n);
					if(!root){
                        root = stree(root, root, n);
					}else{
						stree(root, root, n);
                    }
                    printf("\nValor %d foi inserido.\n", n);
				}
				break;
			case 2: /** Busca um valor específico */
				printf("\nInforme o valor a ser buscado: ");
				scanf("%d", &n);
				b = search_tree(root, n);
				if(!b)
					printf("\nValor não encontrado\n");
				else
					printf("\nValor %d encontrado\n", b->key);
				break;
			case 3: /** Mostra toda estrutura */
                if(!root)
                    printf("\nA arvore esta vazia\n", n);
                else{
                    print_tree(root, (int)NULL);
                    printf("\n");
                }
				break;
			case 4: /** Mostra todos os valores em Percurso Pre-Ordem */
                if(!root)
                    printf("\nA arvore esta vazia\n", n);
                else{
                    preorder(root);
                    printf("\n");
                }
				break;
			case 5: /** Mostra todos os valores em Percurso Em-Ordem */
                if(!root)
                    printf("\nA arvore esta vazia\n", n);
                else{
                    inorder(root);
                    printf("\n");
                }
				break;
			case 6: /** Mostra todos os valores em Percurso Pos-Ordem */
                if(!root)
                    printf("\nA arvore esta vazia\n", n);
                else{
                    posorder(root);
                    printf("\n");
				}
				break;
			case 7: /** Remove um valor específico */
                if(!root)
                    printf("\nA arvore esta vazia\n", n);
                else{
                    print_tree(root, (int)NULL);
                    printf("\nInforme o valor a ser removido: ");
                    scanf("%d", &n);
                    root = dtree(root, n);
                    printf("\nO valor %d foi removido: ", n);
                    printf("\n");
                }
				break;
			case 0: /** Exit */
				printf("Saindo...\n");
				break;
			default: /** Tratamento */
				printf("Opção incorreta\n");
		}
	}while(op != 0);

	return 0;
}
