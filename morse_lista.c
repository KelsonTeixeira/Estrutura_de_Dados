/*Kelson Teixeira
*Estudante de Engenharia Mecatrônica - UnB (Universidade de Brasília)
*Trabalho desenvolvido para a Disciplina ED (Estrutura de Dados)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct lista{
	char dado;
	char code [15];
	struct lista * next;
}lista_morse;

lista_morse * criar_lista (void) {
	lista_morse * aux = (lista_morse *)malloc (sizeof (lista_morse));
	aux->dado = 0;
	memset(aux->code,0,sizeof(aux->code));
	aux->next = NULL;
	return aux;
}

int write_lista (lista_morse * no, FILE * arq){
	char read [15];
	char dado;	
	int i, j = 0;
	lista_morse * aux;
	aux = no;
	while (fgets (read, 15, arq) != NULL){
		dado = read [0];
		i = 2;		
		if (j==0){
			aux->dado = dado;
			while (read [i] != '\0' &&	read [i] != '\n'){
				aux->code [i - 2] = read [i];
				i++;
			}
			j++;
		}else{
			aux->next = criar_lista();
			aux = aux->next;
			aux->dado = dado;
			while (read [i] != '\0' && read[i] != '\n'){
				aux->code [i - 2] = read [i];
				i++;
			}			
		}
	}
	return 0;
}

void print_lista (lista_morse * no){
	lista_morse * aux;
	aux = no;
	while (aux != NULL){
		printf ("1 %c  %s\n", aux->dado, aux->code);
		aux = aux->next;		
	}
}

int decodify_lista (FILE * arq, lista_morse * no){
	lista_morse * aux;
	aux = no;
	char read [15];	
	int j;
	while (fscanf (arq, "%s", read) == 1){
		j = 0;
		while(aux != NULL && j == 0){
			if (strcmp (read, aux->code) == 0){
				printf ("%c", aux->dado);
				aux = NULL;
			}else if(read [0] == '/'){
				printf (" ");
				aux = NULL;
			}else{
				aux = aux->next;
			}
		}
		aux = no;	
	}

	return 0;
}

int read_code_lista (FILE * arq){
	char code [15];
	while (fgets (code, 15, arq) != NULL){
		printf ("%s", code);
	}
	return 0;
}


int main (){
	lista_morse * no;

	FILE * arq_morse;
	FILE * arq_message;

	arq_morse = fopen ("morse.txt", "r");
	arq_message = fopen ("mensagem.txt", "r");

	no = criar_lista();
	write_lista (no, arq_morse);	
	printf ("\nMENSAGEM CODIFICADA:\n");
	read_code_lista (arq_message);
	fclose (arq_message);
	arq_message = fopen ("mensagem.txt", "r");
	printf("\nTEXTO DECODIFICADO: \n\n");
	decodify_lista (arq_message, no);


	/*print_lista (no);*/
	printf("\n");
	
	return 0;
}
