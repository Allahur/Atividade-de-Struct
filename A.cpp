/*
a) Elaborar um programa de computador que efetue a leitura de quatro valores inteiros (variáveis A, B, C e 
D). Ao final o programa deve apresentar o resultado do produto (variável P) do primeiro com o terceiro 
valor, e o resultado do produto (variável P) do primeiro com o terceiro valor, e o resultado da soma 
(variável S) do segundo com o quarto valor.
*/ 

#include <iostream>
#include <math.h>
#define max 3
// Definindo 3 como a quantidade que eu desejo que armazena em meu struct

using namespace std;

typedef struct dado lifo; // A variável que vou usar na lifo é dado


int topo = -1; // Valor que vai sempre ser acrecentado em cima do anterior

struct dado{ // minha estrutura
int dados[max];
int primeiro;
int segundo;
int terceiro;
int quarto;
};
lifo tb;

int vazio() // Se for vazia não haverá nada
{
	if(topo == -1) 
		return 1;
	else
		return 0;
}

int cheia() // Caso for cheia vai mostrar valor
{
	if(topo == max - 1)
		return 1;
	else
		return 0;
}
int lerp(){
	int primeiro;
	cout << "\nDigite o primeiro valor: ";
  cin >> primeiro;
return primeiro;
}
int lers(){
	int segundo;
	cout << "Digite o segundo valor: ";
	cin >> segundo;
return segundo;
}
int lert(){ 
	int terceiro;
	cout << "Digite o terceiro valor: ";
	cin >> terceiro;
return terceiro;
}
int lerq(){
	int quarto;
	cout << "Digite o quarto valor: ";
	cin >> quarto;
return quarto;
} // Funções para armazenar valores(antes do void)
void mostrar(){
	if(cheia() == 1)
  topo ++;
	tb.dados[topo] = lerp();
	tb.primeiro = tb.dados[topo];
	tb.segundo = lers();
	tb.terceiro = lert();
  tb.quarto = lerq();
	system("sleep 3");
}
int first(){
	return (tb.primeiro + tb.terceiro); // Uma função para Cálculo
}
int second(){
	return (tb.segundo + tb.quarto); // Outra função para Cálculo 
}
void excluir(){ // Aqui será onde irei excluir ou zerar valores 
	if(vazio() == 1)
	tb.dados[topo] = '\0'; 
  tb.primeiro = '\0';
	tb.segundo = '\0';
	tb.terceiro = '\0';
	tb.quarto = '\0';
	topo --;
	cout << "\nValor excluido com sucesso!\n\n";
	system("sleep 3");
}
void exibir(){ // Exibir meu resultado
			cout << "\nResultado\n";
			cout << "\n1°: " << first();
	    cout << "\n2°: " << second();
			cout << "\n-----------------\n";
	system("sleep 4");
}
int tela(){ // Menu
system("clear");
	int option;
		cout << "\n1 - Armazenar valor \n2 - Resultado \n3 - Excluir \n4 - Sair";
		cout << "\n\nSelecione: ";
		cin >> option;
return option;
}
void selection(){ // Estrutura de casos

	do{
		switch(tela()){

			case 1:
				mostrar();
			break;
			case 2:
				exibir();
			break;
			case 3:
				excluir();
			break;
			case 4:
				exit(0);
			break;
			default: 
			cout << "Erro";
		} 
  }while (true);
}
int main(){
selection(); // Chamar o void que contém a estrutura de casos
return 0;
}
