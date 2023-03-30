/* 
Faça o código estruturado para controlar uma LIFO com arranjo não 
dinâmico contendo os atributos: nome, idade e salário. Você deverá 
implementar as seguintes sub rotinas obrigatŕias:
*/
/*
A. push() para empilhar o registro
B. pop() para remover registros
C. int mostrar() para mostrar os registros da LIFO
D. bool cheia() verificar se a LIFO está cheia
E. bool vazia() verificar se a LIFO está vazia
F. int tela () exibe a tela e armazena a opção de escolha do menu 
G. void Controle() controla o menu de controle da LIFO 
*/

#include "iostream" // usar o cout e o cin
#include "iomanip" // biblioteca de decimas e que possibilita a usar o fixed << setprecision(2)
#define max 3 
// #define max 3 é a definição do quanto vai ser armazenado na estrutura(lista, pilha, topo)

using namespace std;

typedef struct dados lifo; // dados será a minha variável da estrutura

int topo = -1;

struct dados{ // estrutura de dados
string dado[max];
int idade;
float salario;
char nome;
};
lifo tb; // o lifo ele vai ser a estrutura e vai ser usado como tb(variavel para usar as outras variáveis dentro do struct.

int vazio() // Mostrar a lista vazia
{
	if(topo == -1) 
		return 1;
	else
		return 0;
}

int cheia() // Mostrar a lista cheia
{
	if(topo == max - 1)
		return 1;
	else
		return 0;
}
string lerNome(){ // Armazenar variaveis do tipo string(qualquer)
	setlocale(LC_ALL, "pt-br");
	string nome;
	cout << "\nDigite o seu nome: ";
  cin.ignore();
	getline(cin, nome); // Quando usar uma variável tipo string use o getline(cin, nome da variável); e antes cin.ignore();
return nome;
}
int lerIdade(){ // Armazenar idade
	int idade;
	cout << "Digite sua idade: ";
	cin >> idade;
return idade;
}
float lerSalario(){ // Armazenar salário 
	setlocale(LC_ALL, "pt-br");
	float salario;
	cout << "Seu salário: " << fixed << setprecision(2); // antes de usar o fixed << setprecision(2) você tem que declarar a biblioteca "iomanip" ou <iomanip>
	cin >> salario;
return salario;
}

void push(){
	if(cheia() == 1)
		return;
topo ++; // Valor vai ser posto sempre acima
	tb.dado[topo] = lerNome();
	tb.idade = lerIdade();
	tb.salario = lerSalario();
	cout << "\nValor empilhado foi: \n"; // irá puxar os valores na sua escolha e armazená-las 
  cout << "\n" << tb.dado[tb.nome];
	cout << "\n" << tb.idade;
	cout << "\n" << tb.salario << "\n";
	system("sleep 3");
}
void pop(){
	if(vazio() == 1) // Caso for escolhido a opção de limpar ele vai apagar todos os registros
		return;
	tb.dado[topo] = '\0';
	topo --;
	cout << "\nValor desempilhado com sucesso!\n\n";
	system("sleep 3");
}
void exibir(){

	for(int i = topo; i >= 0; i--) // Um for para exibir os valores dentro da pilha/lista no topo
		{
			setlocale(LC_ALL, "pt-br");
			cout << "\n";
			cout << "Nome: " <<  tb.dado[i] << endl;
			cout << "Idade: " <<  tb.idade << endl;
			cout << "Salário: " << tb.salario << endl; 
			cout << "\n-----------------\n";
		}
	system("sleep 4");
}
int tela(){
system("clear");
	int option;
		cout << "\n1 - Puxar valor \n2 - Limpar pilha \n3 - Exibir \n4 - Sair";
		cout << "\n\nSelecione: ";
		cin >> option;
return option;
}
void controle(){

	do{
		switch(tela()){

			case 1:
				push(); // puxando o valor e armazenando
			break;
			case 2:
				pop(); // excluir ou desempilhar
			break;
			case 3:
				exibir(); // Exibir os valores armazenados
			break;
			case 4:
				exit(0); // Vazou
			break;
			default: 
			cout << "Erro"; // caso for introduzido algo errado.
		} 
  }while (true); // se isso for verdadeiro ele vai de acordo com a escolha da opção 
}
int main(){
	setlocale(LC_ALL, "pt-br"); // Chamar a acentuação brasileira
	controle(); // função onde está a escolha e as outras funções e estrutura 
	return 0;
}
