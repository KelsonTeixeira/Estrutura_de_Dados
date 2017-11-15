/*Kelson Teixeira
 *Estudante de Engenharia Mecatrônica na Universidade de Brasília - UnB
 *Estrutura de Dados - Turma: C
 *professor: EDUARDO ADILIO PELINSON ALCHIERI
 *TRABALHO 2								*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

typedef struct no {
	char dado;
	struct no * esq;
	struct no * dir;
} no_morse;

typedef struct lista{
	char dado;
	char code [15];
	struct lista * next;
}lista_morse;

no_morse * criarNo (void){
	no_morse * aux = (no_morse *)malloc(sizeof(no_morse));
	aux->esq = NULL;
	aux->dir = NULL;
	aux->dado = 0;
	return aux;  
}

lista_morse * criar_lista (void) {
	lista_morse * aux = (lista_morse *)malloc (sizeof (lista_morse));
	aux->dado = 0;
	memset(aux->code,0,sizeof(aux->code));
	aux->next = NULL;
	return aux;
}

void write_arvore (no_morse * raiz, FILE * arq, char code [15]){
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

void decodify_arvore (no_morse * raiz, FILE * arquivo){
	no_morse * aux;
	aux = raiz;
	char code;

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
}

void decodify_lista (FILE * arq, lista_morse * no){
	lista_morse * aux;
	aux = no;
	char read [15];

	while (fscanf (arq, "%s", read) == 1){		
		while(aux != NULL){
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
}

void read_text_arvore (FILE * arq){
	char code [15];

	while (fgets (code, 15, arq) != NULL){
		printf ("%s", code);
	}
}

void read_code_lista (FILE * arq){
	char code [15];

	while (fgets (code, 15, arq) != NULL){
		printf ("%s", code);
	}
}

void arvore_function(){
	no_morse * raiz;
	char code [15];

	FILE * arq_morse;
	FILE * arq_message;	


	raiz = criarNo();
	
	arq_morse = fopen ("morse.txt", "r");	
	write_arvore (raiz, arq_morse, code);
	fclose (arq_morse);
	
	printf ("\nMENSAGEM CODIFICADA:\n\n");
	arq_message = fopen ("mensagem.txt", "r");
	read_text_arvore (arq_message);
	printf ("\n");
	fclose (arq_message);

	arq_message = fopen ("mensagem.txt", "r");
	printf("\n\nTEXTO DECODIFICADO PELA ARVORE BINARIA: \n\n");
	clock_t tempo[2];
	tempo[0] = clock();
	decodify_arvore (raiz, arq_message);
	tempo[1] = clock();
	double tempo_arvore = (tempo[1] - tempo[0]) * 1000.0 / CLOCKS_PER_SEC;
	printf("\n\nTempo de Execussão: %lf ms.\n\n", tempo_arvore);
	printf ("Aperte ENTER para continuar.");
	getchar();
	system ("clear");
	printf ("\n\n");
	fclose (arq_message);
}

void lista_function(){
	lista_morse * no;

	FILE * arq_morse;
	FILE * arq_message;


	no = criar_lista();

	arq_morse = fopen ("morse.txt", "r");
	write_lista (no, arq_morse);
	fclose (arq_morse);

	printf ("\nMENSAGEM CODIFICADA:\n\n");
	arq_message = fopen ("mensagem.txt", "r");
	read_code_lista (arq_message);
	fclose (arq_message);

	printf("\n\nTEXTO DECODIFICADO PELA LISTA ENCADEADA: \n\n");
	arq_message = fopen ("mensagem.txt", "r");
	clock_t tempo[2];
	tempo[0] = clock();
	decodify_lista (arq_message, no);
	tempo[1] = clock();
	double tempo_lista = (tempo[1] - tempo[0]) * 1000.0 / CLOCKS_PER_SEC;
	printf("\n\nTempo de Execussão: %lf ms.\n\n", tempo_lista);
	printf ("Aperte ENTER para continuar.");
	getchar();
	system ("clear");
	fclose (arq_message);
	printf("\n\n");
}

int main (void){
	int function;
	system ("clear");
	printf ("\nBEM VINDO AO PROGRAMA DECODIFICADOR DE CODIGO MORSE\n");
	printf ("PARA DECOFICADAR, CRIE NA MESMA PASTA DESTE PROGRAMA \n");
	printf ("UM ARQUIVO NOMEADO morse.txt CONTENDO O DICIONARIO MORSE\n");
	printf ("E UM NOMEADO mensagem.txt CONTENDO A MENSAGEM A SER DECODIFICADA\n\n");
	do{
		printf ("*ESCOLHA A FORMA COMO O PROGRAMA DECODIFICARAR SUA MENSAGEM:\n\n");
		printf ("1) ARVORE BINARIA DE BUSCA\n\n");
		printf ("2) LISTA ENCADEADA\n\n");
		printf ("3) SAIR DO PROGRAMA\n\n");
		printf ("DIGITE O NUMERO DESEJADO E APERTE ENTER:");
		do{
			scanf ("%d", &function);
			getchar ();
		}while (function != 1 && function != 2 && function != 3);
		system ("clear");
		switch (function){
			case 1 : arvore_function (); break;

			case 2 : lista_function (); break;
		}
	}while(function != 3);

	return 0;
}