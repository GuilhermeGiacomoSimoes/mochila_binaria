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

int main() {
	int capacidade_mochila = 20;
	int numero_itens = 5;
	int beneficios[]	= {3, 5, 8, 4, 10};
	int pesos = {2, 4, 5, 3, 9};

	int max_valor = resolver_mochila_binaria();

	std::cout << ": " << max_valor << std::endl;
}
