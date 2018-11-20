#include "salas.h"

#define vivo 0
#define atirou 1
#define conversas 2
#define deitado 3

void imprimeConteudo(Elemento compartimento, int tamanho_hash)
{
	int tem_algo = 0;
	printf("N%s %s ha:\n", compartimento.artigos[0], compartimento.nome);
	for(int i = 0; i < tamanho_hash; i++)
    {
    	Elo* andante = compartimento.conteudo.listas[i].cabec;
        Elemento * el;
        while(andante!=NULL){
        	el = (Elemento*) andante->val;
            if(el != NULL){
				printf("%s %s\n",el->artigos[1], el->nome);
				tem_algo=1;
			}
			
            andante = andante->next;

        }
    }
	if(!tem_algo)printf("Nada\n");
}
/*
int Mover(Elemento* e1, int direcao){
	Elemento* novo = (Elemento*) e1->def.lugar.saidas;	
	if(novo->ativo){
		atual = *novo;
		return 1;
	}
	puts("Voce nao consegue ir nessa direcao!");
	return 0;

}
*/

int Examinar(Elemento* e1, Elemento* e2){
	if(e1->visivel)
		if(e1->conhecido) puts(e1->curta);
		else{
			puts(e1->longa);
			e1->conhecido = True;
		}
	return e1->visivel;
}


int Tirar(Elemento* e1, Elemento* e2){
	if(e2 == NULL) e2 = &personagem; //Por default vamos retirar do personagem se não especificado
	if(Tretira(e2->conteudo, e1->nome)){ //Se conseguiu retirar
<<<<<<< HEAD
		Tinsere(atual->conteudo, e1); //Insere na sala de volta
		printf("Você retirou %s %s e agora está na sala de origem\n", e1->artigos[0], e1->nome);
		e1->visivel = True;
		e1->ativo = True;
=======
		Tinsere(sala3.conteudo, e1->nome, e1); //Insere na sala de volta
		printf("Você retirou %s %s e agora está de volta à sala de origem", e1->artigos[0], e1->nome);
>>>>>>> 8fd2e18aff955f27728a09b320275c554e8b58bf
	}
	//Se não conseguiu retirar
	else printf("%s %s não conteúdo nenh%s %s", e1->artigos[0], e1->nome, e2->artigos[1], e2->nome);
	if(/*stringsIguais(e1->nome,"mascara")*/ e1 == &mascara) {
		pessoas.ativo = False; //Quando tira a mascara, as pessoas voltam a ficar inativas
		if(stringsIguais(atual->nome, sala3.nome)) puts("O grupo de pessoas divertidas que pareciam te acolher subitamente se fecha\n"
							    "E te isolam mais uma vez, parecendo não notar sua presenca\n");
	}
	return 1;
}

int Colocar(Elemento* e1, Elemento* e2){
	if(Tbusca(e2->conteudo, e1->nome)){ //Se o elemento ja estiver 
		printf("%s já está em %s\n", e1->nome, e2->nome);
	}
	else if(e1->visivel && e1->ativo)
	{
<<<<<<< HEAD
		printf("Você coloca %s %s em %s\n", e1->artigos[0], e1->nome, e2->nome); //"Você coloca a mascara" ou alguma outra coisa que dê pra vestir
		Tinsere(e2->conteudo, e1); //Coloca o elemento no jogador
		Tretira(atual->conteudo, e1->nome); //Tira o elemento da sala
=======
		printf("Você coloca %s %s\n", e1->artigos[0], e1->nome); //"Você coloca a mascara" ou alguma outra coisa que dê pra vestir
		Tinsere(personagem.conteudo, e1->nome, e1); //Coloca o elemento no jogador
		Tretira(atual.conteudo, e1->nome); //Tira o elemento da sala
>>>>>>> 8fd2e18aff955f27728a09b320275c554e8b58bf

		//Se vestir a mascara, as pessoas ficam ativas para interação
		if(stringsIguais(e1->nome, "mascara"))
		{
			pessoas.ativo = True;
			puts("As pessoas que estavam se divertindo sem parecer notar sua presença\n"
				 "Começam homogeneamente a virar os olhos em sua direcao..\n"
				 "Alguns deles até te convidam para interagir!\n"
				 "Parece que agora você é visto!\n");
		}
		return 1;
	}
	return 0;
}


int Interagir(Elemento* e1, Elemento* e2){
	if(e1->ativo)
	{
		puts("Você entra no meio da multidão, parece uma festa\n"
			 "Está se sentindo aceito, uma sensação bem acolhedora\n"
			 "Voce poderia ficar ali para sempre... Mas...\n"
			 "Quem é você mesmo?\n");
		return 1;
	}
	puts("Você tenta interagir com a multidão, mas é excluído e completamente ignorado\n"
		 "Algo não está certo..\n");
	return 0;
}

int Abrir(Elemento* e1, Elemento* e2){
	if(e1->ativo && e1->visivel){
		//Deixa visivel e ativo tudo que tem dentro do elemento (envelope)
		printf("Voce abre %s %s e\n", e1->artigos[0], e1->nome);
		imprimeConteudo((*e1), 4);
		return 1;
	}
	return 0;
}

int Desligar(Elemento* e1, Elemento* e2){
	puts("Mesmo com o gramofone desligado, a música continua tocando.\n"
		 "Isso não faz sentido nenhum...\n"
	 	 "Não importa se o disco gira ou não, a música sempre toca.\n");
	return 1;
}

int Ligar(Elemento* e1, Elemento* e2){
	puts("Como você quer ligar algo que nem sequer foi desligado?\n"
		 "Pelo menos agora o disco gira...\n");
	return 1;
}

int Estourar(Elemento* e1, Elemento* e2){
	if(e1->ativo){
		e1->ativo = False;
		printf("Ué, esquisito, o balão estourou mas não fez nenhum som.\n");
		return 1;
	}
	printf("Não dá pra estourar um balão estourado!\n");
	return 0;
}

int Tocar(Elemento* e1, Elemento* e2){
	if(Tbusca(e1->conteudo,e2->nome)==e2){
		printf("O disco já está no gramofone\n");
		return 0;
	}
	return (Tinsere(e1->conteudo, e2->nome, e2));
}

int Ler(Elemento* e1, Elemento* e2){
	if(stringsIguais(e1->nome,"carta")) {
		puts("    Amo-te tanto, meu amor... não cante\n"
			 "    O humano coração com mais verdade...\n"
			 "     Amo-te como amigo e como amante\n"
			 "      Numa sempre diversa realidade.\n\n"

			 "  Amo-te afim, de um calmo amor prestante\n"
			 "   E te amo além, presente na saudade.\n"
			 "   Amo-te, enfim, com grande liberdade\n"
			 "  Dentro da eternidade e a cada instante.\n\n"

			 "    Amo-te como um bicho, simplesmente\n"
			 "   De um amor sem mistério e sem virtude\n"
			 "    Com um desejo maciço e permanente.\n\n"

			 "     E de te amar assim, muito e amiúde\n"
			 "    É que um dia em teu corpo de repente\n"
			 "   Hei de morrer de amar mais do que pude.\n\n\n");
		puts("Essas palavras te lembram um sentimento, mas sem muito sentido\n"
			 "É apenas a remanescência da sua pouca memória.\n");
		return 1;
	}
	return 0;
}


int Atirar(Elemento* e1, Elemento* e2){
	if(!stringsIguais(e1->nome,"arma")) return 0;
	if(e2 == NULL){
		e1->def.objeto.lista[atirou].val = 0;
		return 1;
	}
	if(stringsIguais(e2->nome,"homem")){
		printf("Um barulho ensurdecedor enche a sala. O homem cai no chão, sem vida. Seu coração é tão velho que não consegue jogar seu sangue para fora de seu corpo.\n");
		e2->def.objeto.lista[vivo].val = 0;
	}
	else if(stringsIguais(e2->nome,"espelho")){
		printf("A arma acerta o espelho, mas não causa dano algum.\n");

	}
	else if(stringsIguais(e2->nome,"personagem")){
		printf("Você aperta o gatilho. Depois disso, não há mais sentidos.\n");
		//ACABA O JOGO
		return 1;
	}
	return 1;
}


int Falar(Elemento* e1, Elemento* e2){
	int* instance = &(e1->def.objeto.lista[conversas].val); //ARRUMAR
	if((*instance)%4 == 0){
		printf("Há muito tempo eu estou aqui. Tanto que a própria palavra já perdeu o significado. O único jeito que eu sei que ele passa é por que vejo as marcas em meu corpo.\n");
		(*instance)++;
		return 1;
	}
	else if ((*instance)%4 == 1){
		printf("Às vezes eu me questiono das escolhas que fiz. Nada parece ter sido suficiente.\n");
		(*instance)++;
	}
	else if ((*instance)%4 == 2){
		printf("Não aguento mais isto tudo. Não tem nada que eu posso fazer neste ponto. Não há mais esperança para mim.\n");
		(*instance)++;
	}
	else if ((*instance)%4 == 3){
		printf("Sozinho. Tanto tempo, sozinho. Me fez perceber as mentiras que sempre ouvi. Eu estou sozinho. Não há ninguém comigo.\n");
		(*instance)++;
	}
	return 1;
}

int Beber(Elemento* e1, Elemento* e2){
	if(stringsIguais(e1->nome,"garrafa")) return 0;
	printf("O líquido desce por você aquecendo todo seu corpo. Você se sente bem, confiante, feliz. 'Tô um BURRP pouco feliz', você diz. Não há uma coisa ruim em seu corpo neste momento.\n");
	return 1;
}

int Comer(Elemento* e1, Elemento* e2){
	if(stringsIguais(e1->nome, "cogumelo")){
		printf("Repentinamente, todas as cores das salas se misturam e espalham como uma grande explosão. Os padrões aumentam, e sua mente transcende o plano físico. Tudo se enche de energia."
			"É a sensação mais bonita que você já teve.\n");
		return 1;
	}
	return 0;
}

int Deitar(Elemento* e1, Elemento* e2){
	if(stringsIguais(e1->nome, "cama") && e1->def.objeto.lista[deitado].val == 1){
		printf("Você já está deitado.\n");
		return 0;
	}
	else if(stringsIguais(e1->nome, "cama")){
		printf("Você se deita na cama e sente como se seu corpo tivesse sido transportado aos céus. Todos seus músculos relaxam, e sua mente fica leve. 'Poderia ficar aqui para sempre', pensa.\n");
		e1->def.objeto.lista[deitado].val = 1;
		return 1;
	}
	return 0;
}

int Levantar(Elemento* e1, Elemento* e2){
	if(stringsIguais(e1->nome, "cama") && e1->def.objeto.lista[deitado].val == 1){
		printf("Com muito esforço, você cria a determinação para levantar da cama. Seu corpo se sente pesado.\n");
		e1->def.objeto.lista[deitado].val = 0;
		return 1;
	}
	else if(stringsIguais(e1->nome, "cama") && e1->def.objeto.lista[deitado].val == 0){
		printf("Você já está levantado.\n");
		return 0;
	}
	return 0;
}


int Pegar(Elemento* e1, Elemento* e2){
	if(stringsIguais(e1->nome, "cogumelo"))
		printf("Ao tocar no cogumelo, você sente todo seu corpo vibrar de animação, mesmo sem entender de onde vem o sentimento. Mas algo sobre suas cores o fazem sentir em outro mundo.\n");
	else
		printf("Agora você tem %s na sua mão.\n",e1->nome);
	return(Tinsere(e2->conteudo, e1->nome, e1));
}

int Soltar(Elemento* e1, Elemento* e2){
	if(Tretira(e2->conteudo, e1->nome)){
		printf("%s não está mais na sua mão.\n",e1->nome);
		return 1;
	}
	printf("Não dá pra soltar um objeto que nem está na sua mão...\n");
	return 0;
}

int Quebrar(Elemento* e1, Elemento* e2){
	if(e1->ativo){
		e1->ativo = False;
		printf("%s quebrado com sucesso\n", e1->nome);
		return 1;
	}
	printf("Não dá pra quebrar o que já está quebrado...\n");
	return 0;
}

int Gritar(Elemento* e1, Elemento* e2){
	printf("AAAAA! Ninguém parece ouvir seus gritos desesperados.\n");
	return 1;
}

int Chorar(Elemento* e1, Elemento* e2){
	puts("Eu sei, isso é muito triste.\n"
		"Mas suas lágrimas definitivamente não vão resolver o problema.\n");
	return 1;
}

int Sentar(Elemento* e1, Elemento* e2){
	puts("Agora você está sentado no chão. Vai chorar?");
	return 1;
}

int Correr(Elemento* e1, Elemento* e2){
	printf("Não tem para onde correr, nem se esconder.");
	return 1;
}

void insereAcoes()
{
	personagem.acoes = malloc(5*sizeof(fptr));
	personagem.acoes[0] = Gritar;
	personagem.acoes[1] = Chorar;
	personagem.acoes[2] = Sentar;
	personagem.acoes[3] = Correr;
	personagem.acoes[4] = Examinar;

	quadro.acoes = malloc(sizeof(fptr));
	quadro.acoes[0] = Examinar;

	disco.acoes = malloc(6*sizeof(fptr));
	disco.acoes[0] = Pegar;
	disco.acoes[1] = Soltar;
	disco.acoes[2] = Quebrar;
	disco.acoes[3] = Tocar; //colocar no gramofone
	disco.acoes[4] = Examinar;

	gramo.acoes = malloc(3*sizeof(fptr));
	gramo.acoes[0] = Desligar;
	gramo.acoes[1] = Ligar;
	gramo.acoes[2] = Examinar;

	balao.acoes = malloc(5*sizeof(fptr));
	balao.acoes[0] = Examinar;
	balao.acoes[1] = Estourar;
	balao.acoes[2] = Comer;
	balao.acoes[3] = Pegar;
	balao.acoes[4] = Soltar;

	envelope.acoes = malloc(4*sizeof(fptr));
	envelope.acoes[0] = Abrir;
	envelope.acoes[1] = Colocar;
	envelope.acoes[2] = Tirar;
	envelope.acoes[3] = Examinar;

	carta.acoes = malloc(2*sizeof(fptr));
	carta.acoes[0] = Ler;
	carta.acoes[1] = Examinar;

	mascara.acoes = malloc(3*sizeof(fptr));
	mascara.acoes[0] = Colocar;
	mascara.acoes[1] = Tirar;
	mascara.acoes[2] = Examinar;

	pessoas.acoes = malloc(2*sizeof(fptr));
	pessoas.acoes[0] = Interagir;
	pessoas.acoes[1] = Examinar;

	arma.acoes = malloc(2*sizeof(fptr));
	arma.acoes[0] = Atirar;
	arma.acoes[1] = Examinar;

	espelho.acoes = malloc(sizeof(fptr));
	espelho.acoes[0] = Examinar;

	homem.acoes = malloc(2*sizeof(fptr));
	homem.acoes[0] = Examinar;
	homem.acoes[1] = Falar;

	garrafa.acoes = malloc(2*sizeof(fptr));
	garrafa.acoes[0] = Examinar;
	garrafa.acoes[1] = Beber;
	garrafa.acoes[2] = Quebrar;

	cama.acoes = malloc(3*sizeof(fptr));
	cama.acoes[0] = Examinar;
	cama.acoes[1] = Deitar;
	cama.acoes[2] = Levantar;

	cogumelos.acoes = malloc(3*sizeof(fptr));
	cogumelos.acoes[0] = Examinar;
	cogumelos.acoes[1] = Comer;
	cogumelos.acoes[2] = Pegar;
}
