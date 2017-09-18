/*Kelson Teixeira
 *Estudante de Engenharia Mecatrônica na Universidade de Brasília - UnB
 *Estrutura de Dados - Turma: C
 *professor: EDUARDO ADILIO PELINSON ALCHIERI
 *												*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max = 101;

int esvaziar (char pilha [max]){
	int i;
	for (i = 100; i >= 0; i--){
		pilha [i] = 0;
	}
	return 0;
}
int esvaziar2 (int pilhable [max]){
	int i;
	for (i = 100; i >= 0; i--){
		pilhable [i] = 0;
	}
	return 0;
}

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
				t++;
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
	}


	return 0;
}

int convert(char posfixa [max], int j){
	if (posfixa [j] == '0'){
		return 0;
	}
	if (posfixa [j] == '1'){
		return  1;
	}
	if (posfixa [j] == '2' ){
		return  2;
	}
	if (posfixa [j] == '3'){
		return  3;
	}
	if (posfixa [j] == '4'){
		return  4;
	}
	if (posfixa [j] == '5'){
		return  5;
	}
	if (posfixa [j] == '6'){
		return  6;
	}
	if (posfixa [j] == '7'){
		return  7;
	}
	if (posfixa [j] == '8'){
		return  8;
	}
	if (posfixa [j] == '9'){
		return  9;
	}

}

int avaliacao (char user [max], int pilhable [max], char posfixa [max]){
	int j = 0, t = 0;
	int valor, operacao;
	esvaziar2 (pilhable);
	while (posfixa [j] != 0){
		if (posfixa [j] != '+'&& posfixa [j] != '-'&& posfixa [j] != '*' && posfixa [j] != '/' && posfixa [j] != '(' && posfixa [j] != ')'&& posfixa [j] != ' '){
			valor = convert (posfixa, j);
			pilhable [t] = valor;
			t++;
		}
		if (posfixa [j] == '+'){
			t--;
			operacao = pilhable [t];
			pilhable [t] = 0;
			t--;
			operacao = pilhable [t] + operacao;
			pilhable [t] = operacao;
			t++;
		}
		if (posfixa [j] == '-'){
			t--;
			operacao = pilhable [t];
			pilhable [t] = 0;
			t--;
			operacao = pilhable [t] - operacao;
			pilhable [t] = operacao;
			t++;
		}
		if (posfixa [j] == '*'){
			t--;
			operacao = pilhable [t];
			pilhable [t] = 0;
			t--;
			operacao = pilhable [t] * operacao;
			pilhable [t] = operacao;
			t++;
		}
		if (posfixa [j] == '/'){
			t--;
			operacao = pilhable [t];
			pilhable [t] = 0;
			t--;
			operacao = pilhable [t] / operacao;
			pilhable [t] = operacao;
			t++;
		}

		j++;
	}
	while (t != 0){
		t--;
	}	
	printf ("\n%d\n", pilhable [t]);
	return 0;
}


int main (){
	int pilhable [max];
	char pilha [max];
	char user [max];
	char posfixa [max];
	/*esvaziar (pilha);*/
	memset(user,0,sizeof(user));
	memset(pilha,0,sizeof(pilha));
	memset(posfixa,0,sizeof(posfixa));

	
	printf ("Escreva uma expressão infixa de no máximo 100 caractéres:\n\n");
	scanf ("%100[^\n]", user);


	
	int a = validacao (pilha, user);
	if (a == 0){
		printf ("Inválida\n");
	}else{
		if (a == 1){
			pos (user, pilha, posfixa);			
			printf ("\n%s\n", posfixa);
			avaliacao (user, pilhable, posfixa);
		}
	}
	 
	
	return 0;
}