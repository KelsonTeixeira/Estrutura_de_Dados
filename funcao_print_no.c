int print_morse (no_morse * raiz){
	no_morse * aux;
	aux = raiz;
	int i = 0;
	while (aux != NULL){
		printf ("%d  %c\n", i, aux->dado);
		aux = aux->esq;
		i++;
	}
	aux = raiz;
	while (aux != NULL){
		printf ("%d %c\n", i, aux->dado);
		aux = aux->dir;
		i++;
	}
	return 0;
}