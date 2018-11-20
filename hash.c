#include "lista.h"
/*
typedef struct TabSim{
	int size;
	Lista* listas;
}TabSim;
*/
int hash(char* s, int mod){
	//Definindo como será o hash das palavras
	long long int out = 0;
	for(int i = 0; s[i] != '\0'; i++){
		out = out*257 + (int) s[i];
		out %= mod;
	}
	return out;
}

TabSim Tcria(int tam){
	//Criando uma tabela com tam listas
	TabSim tabela;
	tabela.listas = malloc(tam*sizeof(Lista));
	tabela.size = tam;
	for(int i = 0; i < tam; i++){
		tabela.listas[i] = Lcria();
	}
	return tabela;
}

void Tdestroi(TabSim t){
	//Percorre a tabela destruindo as listas dela
	for(int i = 0; i < t.size; i++){
		Ldestroi(t.listas[i]);
	}
	free(t.listas);
	return;
}

int Tinsere(TabSim t, Elemento* val){
	//Calcula o hash do elemento, que é em qual lista ele será inserido
	int hash_val = hash(val->nome, t.size);
	return Linsere(t.listas[hash_val], val)==NULL?0:1;
}

Elemento* Tbusca(TabSim t, char *n){
	int hash_val = hash(n, t.size);
	return Lbusca(t.listas[hash_val], n);
}

int Tretira(TabSim t, char *n){
	int hash_val = hash(n, t.size);
	Elo* crawler = t.listas[hash_val].cabec; //Elemento* out = NULL;
	Elemento* ee;
	while(crawler != NULL){
		ee = (Elemento* ) crawler->val;
		if(crawler->val != NULL && stringsIguais(ee->nome, n)){
			crawler->val = NULL;
			return 1;
		}
		crawler = crawler->next;
	}
	return 0;
}
