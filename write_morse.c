/*Kelson Teixeira
 *Estudante de Engenharia Mecatrônica na Universidade de Brasília - UnB
 *Estrutura de Dados - Turma: C
 *professor: EDUARDO ADILIO PELINSON ALCHIERI
 *												*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void write_lista (lista_morse * no, FILE * arq){
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
}



void newMessage (lista_morse * no, FILE * arq){
	char read [1000];
	lista_morse * aux = no;
	int i;
	scanf ("%999[^\n]", read);
	printf("read: %s\n", read);
	i = 0;
	while (read[i] != '\0'){
		while (aux != NULL){
			if (read [i] == aux->dado){
				fprintf (arq, "%s ", aux->code);
				aux = NULL;
			}else if (read [i] == ' '){
				fprintf(arq, "/");
				aux = NULL;
			}else{
				aux = aux->next;
			}
		}
		aux = no;
		i++;
	}
}


int main (){
	lista_morse * no;
	no = criar_lista(); 
	/*char read [15];*/
	FILE * arq_morse;
	FILE * message;
	message = fopen ("mensagem.txt", "w");
	arq_morse = fopen ("morse.txt", "r");
	write_lista (no, arq_morse);
	newMessage (no, message);


	
	return 0;
}