#ifdef defined(__WIN32) || defined(WIN32)
	#define OS_Windows
#endif

#include<iostream>
#include<vector>
#include <assert.h>

std::vector< std::vector<int> > zerar_colunas_e_linhas ( std::vector< std::vector<int> > tabela, int capacidade_mochila, int numero_itens ) {
	for (int item = 0; item <= numero_itens; item++) {
		
		std::vector<int> capacidades;

		for (int capacidade = 0; capacidade < capacidade_mochila; capacidade++) {
			capacidades.push_back(0);		 
		}

		tabela.push_back( capacidades );	
	}	

	return tabela;
}

int resolver_mochila_binaria( int capacidade_mochila, int pesos[], int valores[], int numero_itens ){

	std::vector< std::vector<int> > tabela;  
	tabela = zerar_colunas_e_linhas( tabela, capacidade_mochila, numero_itens );

	for (int itens = 1; itens <= numero_itens; itens++) {
		for (int capacidade = 1; capacidade <= capacidade_mochila; capacidade++) {
			if (pesos[itens - 1] <= capacidade) {

				int max = valores[itens - 1] + tabela[itens - 1][capacidade - pesos[itens - 1]];
				
				if (max > tabela[itens - 1][capacidade]) {
					tabela[itens][capacidade] = max;	
				}
				else {
					tabela[itens][capacidade] = tabela[itens - 1][capacidade];
				}
			}	
			else {
				tabela[itens][capacidade] = tabela[itens - 1][capacidade];
			}
		}
	}

	return tabela[numero_itens][capacidade_mochila];
}


void imprimir_resposta(int solucao) {

	#ifdef OS_Windows
		system("cls");
	#else
		system("clear");
	#endif

	std::cout << "Solucao otima: " << solucao << std::endl;	
}


bool teste() {
	int capacidade_mochila 	= 7;              
	int numero_itens 		= 4;              
	int valores[]			= {10, 7, 25, 24};
	int pesos[] 			= {2, 1, 6, 5};   

	int max_valor = resolver_mochila_binaria( capacidade_mochila, pesos, valores, numero_itens );

	if ( max_valor == 34) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	
	assert( teste() );

	int capacidade_mochila;
	int numero_itens;
	
	std::cout << "capacidade da mochila: ";
	std::cin  >> capacidade_mochila;	
	if (std::cin.fail()) {
		std::cout << "Favor informar um numero valido" << std::endl;;	
		return 1;
	}

	std::cout << "numero de itens: ";
	std::cin  >> numero_itens;
	if (std::cin.fail()) {
		std::cout << "Favor informar um numero valido" << std::endl;;	
		return 1;
	}
	
	int valores  [ numero_itens ];
	int pesos    [ numero_itens ]; 

	for ( int index = 0; index < numero_itens; index ++) {
		std::cout << "Informar o valor do " << index + 1 << "* item: ";
		std::cin  >> valores[index];
		if (std::cin.fail()) {
			std::cout << "Favor informar um numero valido" << std::endl;;	
			return 1;
		}

		std::cout << "Informar o peso do " << index + 1 << "* item: ";
		std::cin  >> pesos[index];	
		if (std::cin.fail()) {
			std::cout << "Favor informar um numero valido" << std::endl;;	
			return 1;
		}

		
	}

	int solucao = resolver_mochila_binaria( capacidade_mochila, pesos, valores, numero_itens );
	imprimir_resposta(solucao);
}
