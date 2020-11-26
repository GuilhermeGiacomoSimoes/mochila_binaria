#include<iostream>

int[][] zerar_primeiras_colunas_e_linhas ( int m[][], int w, int n) {
	for (int linha = 0; linha < w; linha ++) {
		m[linha][0] = 0;
	}	

	for (int coluna = 0; coluna < w; coluna ++) {
		m[0][coluna] = 0;
	}

	return m;
}

int resolver_mochila_binaria( int capacidade_mochila, int pesos[], int valores[], int numero_itens ){
	int tabela[numero_itens + 1][capacidade_mochila + 1];

	tabela = zerar_primeiras_colunas_e_linhas();

	for (int itens = 1; itens <= numero_itens; itens++) {
		for (int capacidade = 1; capacidade <= capacidade_mochila; capacidade++) {
			if (pesos[itens - 1] <= capacidade) {

				if (valores[i - 1] + tabela[i - 1][ capacidade - pesos[ itens - 1 ]] > tabela[itens - 1][capacidade]) {
					tabela[itens][capacidade] = valores[i - 1] + tabela[i - 1][ capacidade - pesos[ itens - 1 ]]	
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

int main() {
	int capacidade_mochila = 20;
	int numero_itens = 5;
	int valores[]	= {3, 5, 8, 4, 10};
	int pesos[] = {2, 4, 5, 3, 9};

	int max_valor = resolver_mochila_binaria( capacidade_mochila, pesos, valores, numero_itens );

	std::cout << ": " << max_valor << std::endl;
}
