/*
 * gaussJordanMethod.h
 *
 *  Created on: May 16, 2018
 *      Author: batuhanfaik
 */

#ifndef GAUSSJORDANMETHOD_H_
#define GAUSSJORDANMETHOD_H_

void gaussJordan() {
	//Matris okuma degiskenleri
	int i = 0, j = 0, n = 0;

	printf("Matrisler AX=C formatında olmak üzere\n"
			"A kare matrisinin satır sayısını giriniz: ");
	scanf("%d", &n);

	//Matris tanimlamalari ve okumasi
	double matrix[n][n];
	double inverse[n][n];
	double constants[n][1];

	printf("Elemanlar arasına boşluk bırakarak\n"
			"A matrisinin %d elemanını da giriniz: \n", n * n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%lf", &matrix[i][j]);
		}
	}

	printf("Elemanlar arasına boşluk bırakarak\n"
			"C matrisinin %d elemanını da giriniz: \n", n);
	for (i = 0; i < n; i++) {
		scanf("%lf", &constants[i][0]);
	}

	//nxn birim matris
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j) {
				inverse[i][j] = 1;
			} else {
				inverse[i][j] = 0;
			}
		}
	}

	//Degisken tanimlama
	double tempVal;

	//Ana matrisi ust ucgen formatina getirme
	for (int step = 0; step < n; step++) {
		tempVal = matrix[step][step];
		constants[step][0] /= tempVal;
		for (j = 0; j < n; j++) {
			matrix[step][j] /= tempVal;
			inverse[step][j] /= tempVal;
		}
		for (i = step + 1; i < n; i++) {
			tempVal = matrix[i][step];
			constants[i][0] -= constants[step][0] * tempVal;
			for (j = 0; j < n; j++) {
				matrix[i][j] -= matrix[step][j] * tempVal;
				inverse[i][j] -= inverse[step][j] * tempVal;
			}
		}
	}

	//Ust ucgen matrisi birim matris formatina getirme
	for (int step = 0; step < n; step++) {
		for (i = step + 1; i < n; i++) {
			tempVal = matrix[step][i];
			constants[step][0] -= constants[i][0] * matrix[step][i];
			for (j = 0; j < n; j++) {
				matrix[step][j] -= matrix[i][j] * tempVal;
				inverse[step][j] -= inverse[i][j] * tempVal;
			}
		}
	}

	printf("\nX değerleri:\n");

	for (i = 0; i < n; i++) {
		printf("X(%d)= %.4f\n", i + 1, constants[i][0]);
	}
}

#endif /* GAUSSJORDANMETHOD_H_ */
