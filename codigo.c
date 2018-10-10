/*Kelson Teixeira
*Estudante de Engenharia Mecatrônica - UnB (Universidade de Brasília)
*Trabalho desenvolvido para a Disciplina ED (Estrutura de Dados)*/
 *												*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
	char dado;
	struct no * esq;
	struct no * dir;
} no_morse;

no_morse * criarNo (void){
	no_morse * aux = (no_morse *)malloc(sizeof(no_morse));
	aux->esq = NULL;
	aux->dir = NULL;
	aux->dado = 0;
	return aux;  
}

int write_arvore (no_morse * raiz, FILE * arq, char code [15]){
	no_morse * aux;
	aux = raiz;
	char dado;
	int i;
	memset(code,0,sizeof(*code));
	while (fgets (code, 15, arq) != NULL){
		dado = code [0];
		i = 2;
		while (code [i] != '\0'){
			if (code [i] == '.'){
				if (aux->esq == NULL){
					aux->esq = criarNo();
					aux = aux->esq;
				}else{
					aux = aux->esq;
				}
			}
			if (code [i] == '-'){
				if (aux->dir == NULL){
					aux->dir = criarNo();
					aux = aux->dir;
				}else{
					aux = aux->dir;
				}
			}	
			i++;
		}
		aux->dado = dado;
		aux = raiz;
	}
	return 0;
}

int decodify_arvore (no_morse * raiz, FILE * arquivo){
	no_morse * aux;
	aux = raiz;
	char code;
	int i;
	while (!feof (arquivo)){
		fscanf (arquivo, "%c", &code);
		if (code == '.'){
			aux = aux->esq;
		}
		if (code == '-'){
			aux = aux->dir;
		}
		if (code == ' '){
			printf ("%c", aux->dado);
			aux = raiz;
		}
		if (code == '/'){
			printf (" ");
		}
	}
	printf ("%c", aux->dado);
	return 0;
}

int read_text_arvore (FILE * arq){
	char code [15];
	while (fgets (code, 15, arq) != NULL){
		printf ("%s", code);
	}
	return 0;
}

int main (){
	FILE * arq_morse;
	FILE * arq_message;
	no_morse * raiz;
	char code [15];

	arq_morse = fopen ("morse.txt", "r");
	arq_message = fopen ("mensagem.txt", "r");

	raiz = criarNo();
	write_arvore (raiz, arq_morse, code);
	printf ("\nMENSAGEM CODIFICADA:\n");
	read_text_arvore (arq_message);
	printf ("\n");
	fclose (arq_message);
	arq_message = fopen ("mensagem.txt", "r");
	printf("TEXTO DECODIFICADO: \n\n");
	decodify_arvore (raiz, arq_message);
	printf ("\n");

	fclose (arq_morse);
	fclose (arq_message);

	return 0;
}
