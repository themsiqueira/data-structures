#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

struct node *inicio = NULL;
struct node *fim_fila = NULL;

int tamanho=0;

struct node{
	int dado;
	struct node *prox;
};

void insere(int valor) {
	struct node *aux;
	aux = new(struct node);
	aux->dado = valor;

	if(tamanho==0) {
		inicio = aux;
		fim_fila = aux;
	}

	fim_fila->prox = aux;
	fim_fila = aux;
	aux->prox = NULL;

	tamanho++;
	printf("\n\n\nElemento inserido com sucesso");
}

void exibir_fila() {
	struct node *aux;

	if(inicio==NULL) {
		printf("\tERRO: Fila vazia");
		return;
	}

	aux=inicio;

	while(aux!=NULL) {
		printf(" %d |", aux -> dado);
		aux = aux->prox;
	}
}

void remover() {
	struct node *aux;

	if(inicio==NULL) {
		printf("\tERRO: Fila vazia");
		return;
	}
	aux = inicio;
	inicio = inicio->prox;
	delete(aux);
	tamanho--;
	printf("\n\nElemento removido com sucesso\n");
}

void menu() {
	printf("\n##############################################");
	printf("\n#               MENU - FILA                  #");
	printf("\n#                                            #");
	printf("\n#	  Digite a operacao desejada            #");
	printf("\n#                                            #");
	printf("\n#	 1 = Inserir elemento                #");
	printf("\n#	 2 = Remover elemento                #");
	printf("\n#	 3 = Exibir fila                     #");
	printf("\n#	 4 = Mostrar primeiro elemento       #");
	printf("\n#	 5 = Sair                            #");
	printf("\n#                                            #");
	printf("\n##############################################");
	printf("\n\n");
}

void mostrar_primeiro() {
	if(inicio==NULL) {
		printf("\tERRO: Fila vazia");
		return;
	}
	printf("\nO primeiro elemento da fila = %d", inicio->dado);
}

main() {

	int opcao,valor;
	bool i=true;

	menu();

	do {
		opcao = getche()-'0';

		switch(opcao) {
			case 1:
				system ("cls");
				menu();
				printf("\nDigite o valor a ser inserido ");
				scanf("%d", &valor);
				insere(valor);
				printf("\n\n\n\nEscolha outra operacao para continuar...\n\n");
				break;
			case 2:
				system ("cls");
				menu();
				remover();
				printf("\n\n\n\nEscolha outra operacao para continuar...\n\n");
				break;
			case 3:
				system ("cls");
				menu();
				exibir_fila();
				printf("\n\n\n\nEscolha outra operacao para continuar...\n\n");
				break;
			case 4:
				system ("cls");
				menu();
				mostrar_primeiro();
				printf("\n\n\n\nEscolha outra operacao para continuar...\n\n");
				break;
			case 5:
				system ("cls");
				printf("\n\n\t\tAte logo !!\n\n\n\n\n\n\n\n\n\n");
				i=false;
				break;
		}
	}
	while(i==true);

	system ("pause");
}