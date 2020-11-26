#include<iostream>
#include<vector>
#include <assert.h>

std::vector<std::vector<int>> zerar_colunas_e_linhas ( std::vector<std::vector<int>> tabela, int capacidade_mochila, int numero_itens ) {
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

	std::vector<std::vector<int>> tabela;  
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


bool teste() {
	int capacidade_mochila 	= 20;
	int numero_itens 		= 5;
	int valores[]			= {3, 5, 8, 4, 10};
	int pesos[] 			= {2, 4, 5, 3, 9};

	int max_valor = resolver_mochila_binaria( capacidade_mochila, pesos, valores, numero_itens );

	if ( max_valor != 36) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	
	assert( teste() );


	int capacidade_mochila 	= 7;
	int numero_itens 		= 4;
	int valores[]			= {10, 7, 25, 24};
	int pesos[] 			= {2, 1, 6, 5};

	int max_valor = resolver_mochila_binaria( capacidade_mochila, pesos, valores, numero_itens );

	std::cout << "SOLUÇÃO: " << max_valor << std::endl;
}
