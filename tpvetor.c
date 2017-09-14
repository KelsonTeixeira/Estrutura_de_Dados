/*Kelson Teixeira
 *Estudante de Engenharia Mecatrônica na Universidade de Brasília - UnB
 *Estrutura de Dados - Turma: C
 *professor: EDUARDO ADILIO PELINSON ALCHIERI
 *												*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max = 101;

int validacao (char pilha [max], char user [max]){
	int i, j = 0;
	for (i = 0; i < 100; i++){
		if (user [i] == '('){
			pilha [j] = '(';
			j++;			
		}
		if (user [i] == ')'){
			if (j == 0){
				return 0;
			
			}else{
				pilha [j-1] = 0;
				j--;		
			}
		}
	}
	for (i = 0; i < 100; i++){
		if (pilha [i] != 0){
			return 0;
		}
	}
	return 1;
}

int pos (char user [max], char pilha [max]){
	memset (pilha,0,sizeof(pilha));
	for (i = 0; i < 100; i++){
		if (user [i] != '+'&& user [i] != '-'&& user [i] != '*' && user [i] != '/' && user [i] != '(' && user [i] != ')'){
			printf ("%c ", user [i]);
		}
	}
	return 0;
}

int main (){

	char pilha [max];
	char user [max];
	memset(pilha,0,sizeof(pilha));
	memset(user,0,sizeof(user));
	
	printf ("Escreva uma expressão infixa de no máximo 100 caractéres:\n");
	scanf ("%100[^\n]", user);


	
	int a = validacao (pilha, user);
	if (a == 0){
		printf ("Inválida\n");
	}else{
		if (a == 1){
			pos (user, pilha);
		}
	}
	 




	
	return 0;
}