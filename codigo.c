/*Kelson Teixeira
 *Estudante de Engenharia Mecatrônica na Universidade de Brasília - UnB
 *Estrutura de Dados - Turma: C
 *professor: EDUARDO ADILIO PELINSON ALCHIERI
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

int write_morse (no_morse * raiz, FILE * arq, char code [15]){
	no_morse * aux;
	aux = raiz;
	char dado;
	int i;
	memset(code,0,sizeof(*code));
	while (fgets (code, 15, arq) != NULL){
		dado = code [0];
		i = 0;
		while (code [i] != '.' && code [i] != '-'){
			i++;
		}
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

int print_morse (no_morse * raiz){
	no_morse * aux;
	aux = raiz;
	while (aux != NULL){
		printf ("%c\n", aux->dado);
		aux = aux->esq;
	}
	aux = raiz;
	while (aux != NULL){
		printf ("%c\n", aux->dado);
		aux = aux->dir;
	}
	return 0;
}
int read_morse (no_morse * raiz, FILE * arquivo){
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
	return 0;
}

int main (){
	FILE * arq_morse;
	FILE * arquivo;
	no_morse * raiz;
	char code [15];

	arq_morse = fopen ("morse.txt", "r");
	arquivo = fopen ("mensagem.txt", "r");

	raiz = criarNo();
	write_morse (raiz, arq_morse, code);
	getchar ();
	
	read_morse (raiz, arquivo);

	//print_morse(raiz);


	
	return 0;
}