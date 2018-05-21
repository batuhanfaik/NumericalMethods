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
	int i = 0, j = 0, n = 0, determinant = 1;

	printf("Kare matrisin satır sayısını giriniz: ");
	scanf("%d", &n);

	//Matris tanimlamalari ve okumasi
	double matrix[n][n];
	double inverse[n][n];

	printf("Elemanlar arasına boşluk bırakarak satırları teker teker giriniz: \n",
			n * n);
	for (i = 0; i < n; i++) {
		printf("%d. Satır: ", i+1);
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
	int diagLocZero = 0, diagLocNonZero = 0, diagZero = 0, found = 0;

	//Kosegendeki 0'larin tespiti
	while(diagZero == 0){
		if (matrix[diagLocZero][diagLocZero] == 0){ //Kosegendeki 0i tespit
			diagLocNonZero = 0;
			for(j = 0; j < n; j++){
				while(matrix[diagLocNonZero][diagLocZero] == 0 && found == 0) { //Kosegeni 0 olmayan satiri tespit
					diagLocNonZero++;
				}
				//Hem matrixte hem de inverste yer degistirme
				tempVal = matrix[diagLocZero][j];
				matrix[diagLocZero][j] = matrix[diagLocNonZero][j];
				matrix[diagLocNonZero][j] = tempVal;
				tempVal = inverse[diagLocZero][j];
				inverse[diagLocZero][j] = inverse[diagLocNonZero][j];
				inverse[diagLocNonZero][j] = tempVal;
				found = 1; //Kosegeni 0 olmayan satirin indisi artmamasi icin konulan degisken
			}
		}
		//0 tespiti icin kosegeni arttirma found'i 0lama
		diagLocZero++;
		found = 0;
		if (diagLocZero == n){
			diagZero = 1;
		}
	}

	//Ana matrisi ust ucgen formatina getirme
	for (int step = 0; step < n; step++) {
		tempVal = matrix[step][step];
		for (j = 0; j < n; j++) {
			matrix[step][j] /= tempVal;
			inverse[step][j] /= tempVal;
		}
		for (i = step + 1; i < n; i++) {
			tempVal = matrix[i][step];
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

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (inverse[i][j] != inverse[i][j]){
				determinant = 0;
			}
		}
	}

	if (determinant == 0) {
		printf("Determinantı 0 olan matrisin inversi yoktur.");
	} else {
		printf("\n\nMatrisin tersi:\n");

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				printf("\t");
				printf("%.4f  ", inverse[i][j]);
			}
			printf("\n");
		}
	}

}

#endif /* INVERSEOFMATRIX_H_ */
