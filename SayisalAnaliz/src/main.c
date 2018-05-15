/*
 * main.c
 *
 *  Created on: Apr 17, 2018
 *      Author: batuhanfaik
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graphicalMethod.h"
#include "bisectionMethod.h"
#include "regulaFalsiMethod.h"

int main() {
	//Degisken tanimlari
	int islem = 0;
	char tekrar = 'e';

	while (tekrar == 'e') {
		//Islem secimi
		printf("1-Grafik metoduyla kök bulma\n"
				"2-Bisection metoduyla kök bulma\n"
				"3-Regula Falsi metoduyla kök bulma\n"
				"Yapmak istediginiz islemin numarasini giriniz: ");
		scanf("%d", &islem);


		switch (islem) {
			case (1):
			graphicalMethod();
			break;
			case (2):
			bisectionMethod();
			break;
			case (3):
			regulaFalsiMethod();
			break;
			default:
			printf("Islem secilmedi.");
		}

		//Tekrarlayim mi?
		tekrar = 'h';
		printf("\n\nTekrar islem yapmak istiyor musunuz? (e/h) ");
		scanf(" %c", &tekrar);
		printf("\n");
	}

	return 0;
}
