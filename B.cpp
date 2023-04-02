/*
b) Ler o valor correspondente ao salário mensal (variável SM) de um trabalhador e também o valor do 
percentual de reajuste (variável PR) a ser atribuído. Apresentar o valor do novo salário (variável NS).
*/

/* Formas 

1. Salário base + 6% do salário base = nova remuneração.

2. Salário do funcionário atualizado + porcentagem de reajuste x 3 (meses de atraso) = remuneração do mês.

3. Salário base + 6% do salário base/2 = nova remuneração.
*/


#include <iostream> // usar cout e cin
#include <math.h> // biblioteca de matemática 
#include <iomanip> // biblioteca para ler o fixed << setprecision(2) onde vai botar duas casas após a vírgula 

using namespace std;

typedef struct dado lifo; // minha variável para a struct é dado

float pr = (100.00/30.00) * 0.06; // float com cálculo de juros diários 

struct dado{ // Struct - Estrutura
float ns;
float sm;
int dias;
int mes;
};
lifo tb;

float salariomensal(){ // funções para armazenar valores
setlocale(LC_ALL, "pt-br");
	float sm;
	cout << "\nDigite o seu salário: ";
  cin >> sm;
return sm;
}
int dia(){
	int dias;
	cout << "Digite os dias de atraso ou acrescentar: ";
	cin >> dias;
return dias;
}
int month(){
	int mes;
	cout << "Digite os meses de atraso: ";
	cin >> mes;
return mes;
}// finalizado
void mostrar(){ // mostrar e armazenar 
	tb.sm = salariomensal();
	tb.mes = month();
	tb.dias = dia();
	system("sleep 3");
}
float calc(){ // função para calcular com escolha
system("clear");
setlocale(LC_ALL, "pt-br");
int select;

cout << "\nNota: valores postos vão ser calculados de acordo com a escolha.\n\n\n";
cout << "\n1 - Novo Salário com reajuste de 6%";
cout << "\n2 - Reajuste de Meses de atraso";
cout << "\n3 - Remuneração acrescentada";
cout << "\n\nDigite a opção que deseja: ";
cin >> select;
	
	if(select == 1)
{
  tb.ns = tb.sm * pr;
}
	if(select == 2)
	{
		tb.ns = tb.sm + pr * tb.mes;
	}
	if(select == 3)
	{
		tb.ns = tb.sm + (tb.sm + (pr / 2));
	}
return select;
}
void excluir(){ // função para excluir ou zerar valor
system("clear");
	tb.sm = '\0';
  tb.dias = '\0';
	tb.mes = '\0';
	tb.ns = '\0';
	cout << "Valor excluido com sucesso!\n\n";
system("sleep 3");
}
void exibir(){ // função para exibir valor
system("clear");
	cout << "\rNovo salário reajustado: " << fixed << setprecision(2) << tb.ns << "\n\n\n";
system("sleep 3");
}
int menu(){ // Menu de opções 
system("clear");
	int option;
		cout << "\n1 - Armazenar valor \n2 - Calcular \n3 - Exibir \n4 - Excluir \n5 - Sair";
		cout << "\n\nSelecione: ";
		cin >> option;
return option;
}
void selection(){ // função para a estrutura de casos

	do{
		switch(menu()){

			case 1:
				mostrar();
			break;
			case 2:
		    calc();
			break;
			case 3:
			  exibir();
			break;
			case 4:
			  excluir();
			break;
			case 5:
				exit(0);
			break;
			default: 
			cout << "Erro";
		} 
  }while (true);
}
int main(){ iniciar o código 
system("clear");
selection(); // chamar a minha estrutura de casos
return 0;
}
