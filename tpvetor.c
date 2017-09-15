/*Kelson Teixeira
 *Estudante de Engenharia Mecatrônica na Universidade de Brasília - UnB
 *Estrutura de Dados - Turma: C
 *professor: EDUARDO ADILIO PELINSON ALCHIERI
 *												*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max = 101;

<<<<<<< HEAD
int esvaziar (char pilha [max]){
	int i;
	for (i = 0; i < 101; i++){
		pilha [i] = 0;
	}
	return 0;
}

=======
>>>>>>> dd5adc3d55aa999c1ad62bf77b70d413ff60d260
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

<<<<<<< HEAD
int pos (char user [max], char pilha [max], char posfixa [max]){
	int i = 0, j =0, t = 0;
	esvaziar (pilha);
	while (user [i] != 0){
		if (user [i] != '+'&& user [i] != '-'&& user [i] != '*' && user [i] != '/' && user [i] != '(' && user [i] != ')'&& user [i] != ' '){
			posfixa [j] = user [i];
			j++;
		}
		if (user [i] == '+'|| user [i] == '-'|| user [i] == '*' || user [i] == '/'){
			if (pilha [t] == 0){
				pilha [t] = user [i];
			}else{
				if (user [i] == '*' || user [i] == '/'){
					if (pilha [t] == '*' || pilha [t] == '/'){
						posfixa [j] = pilha [t];
						pilha [t] = user [i];
						j++;
					}
					if (pilha [t] == '+' || pilha [t] == '-'){
						posfixa [j] = user [i];
						j++;
					}
					if (pilha [t] == '('){
						t++;
						pilha [t] = user [i];
					}

				}
				if (user [i] == '+' || user [i] == '-'){
					if (pilha [t] == '('){
						t++;
						pilha [t] = user [i];
					}else{
						posfixa [j] = pilha [t];
						pilha [t] = user [i];
						j++;
					}
				}				
			}
		}
		if (user [i] == '('){			
			if (pilha [t] == 0){
				pilha [t] = user [i];
				i++;
			}else{
				t++;
				pilha[t] = user[i];
			}
		}
		if (user [i] == ')'){
			while (pilha [t] != '('){
				posfixa [j] = pilha [t];
				pilha [t] = 0;
				if (t != 0){
					t--;
				}
				j++;
			}
			if (pilha [t] == '('){
				pilha [t] = 0;
				if (t != 0){
					t--;
				}
			}
		}
		i++;
	}	
	if (pilha [0] != 0){
		posfixa[j] = pilha [0];
=======
int pos (char user [max], char pilha [max]){
	memset (pilha,0,sizeof(pilha));
	for (i = 0; i < 100; i++){
		if (user [i] != '+'&& user [i] != '-'&& user [i] != '*' && user [i] != '/' && user [i] != '(' && user [i] != ')'){
			printf ("%c ", user [i]);
		}
>>>>>>> dd5adc3d55aa999c1ad62bf77b70d413ff60d260
	}
	return 0;
}

<<<<<<< HEAD
int avaliacao (char user [max], char pilha [max], char posfixa [max]){

	return 0;
}

=======
>>>>>>> dd5adc3d55aa999c1ad62bf77b70d413ff60d260
int main (){

	char pilha [max];
	char user [max];
<<<<<<< HEAD
	char posfixa [max];
	/*esvaziar (pilha);*/
	memset(user,0,sizeof(user));
	memset(pilha,0,sizeof(pilha));

=======
	memset(pilha,0,sizeof(pilha));
	memset(user,0,sizeof(user));
	
>>>>>>> dd5adc3d55aa999c1ad62bf77b70d413ff60d260
	printf ("Escreva uma expressão infixa de no máximo 100 caractéres:\n");
	scanf ("%100[^\n]", user);


	
	int a = validacao (pilha, user);
	if (a == 0){
		printf ("Inválida\n");
	}else{
		if (a == 1){
<<<<<<< HEAD
			pos (user, pilha, posfixa);
			printf ("\n%s\n", posfixa);
		}
	}
=======
			pos (user, pilha);
		}
	}
	 




>>>>>>> dd5adc3d55aa999c1ad62bf77b70d413ff60d260
	
	return 0;
}