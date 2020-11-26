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
	
}
