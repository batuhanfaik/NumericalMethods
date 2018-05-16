/*
 * inverseOfMatrix.h
 *
 *  Created on: May 15, 2018
 *      Author: batuhanfaik
 */

#ifndef INVERSEOFMATRIX_H_
#define INVERSEOFMATRIX_H_

void inverseOfMatrix() {
	//Matris okuma degiskenleri
	int i = 0, j = 0, n = 0;

	printf("Kare matrisin satır sayısını giriniz: ");
	scanf("%d", &n);

	//Matris tanimlamalari ve okumasi
	double matrix[n][n];
	double inverse[n][n];

	printf("Elemanlar arasına boşluk bırakarak %d elemanı da giriniz: \n",
			n * n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%lf", &matrix[i][j]);
		}
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
	i = j = 0;

	//Ana matrisi ust ucgen formatina getirme
	for (int step = 0; step < n; step++) {
		tempVal = matrix[step][step];
		for (j = 0; j < n; j++) {
			matrix[step][j] /= tempVal;
			inverse[step][j] /= tempVal;
		}
		for (i = step+1; i < n; i++) {
			tempVal = matrix[i][step];
			for (j = 0; j < n; j++) {
				matrix[i][j] -= matrix[step][j] * tempVal;
				inverse[i][j] -= inverse[step][j] * tempVal;
			}
		}
	}

	//Ust ucgen matrisi birim matris formatina getirme
	for (int step = 0; step < n; step++) {
		for (i = step+1; i < n; i++) {
			tempVal = matrix[step][i];
			for (j = 0; j < n; j++) {
				matrix[step][j] -= matrix[i][j] * tempVal;
				inverse[step][j] -= inverse[i][j] * tempVal;
			}
		}
	}

	/*printf("\n\nMatrisin kendisi:\n");

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("\t");
            printf("%.4f  ", matrix[i][j]);
		}
		printf("\n");
	}*/

	printf("\n\nMatrisin tersi:\n");

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("\t");
            printf("%.4f  ", inverse[i][j]);
		}
		printf("\n");
	}

}

#endif /* INVERSEOFMATRIX_H_ */
