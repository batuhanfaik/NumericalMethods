/*
 * main.c
 *
 *  Created on: Apr 17, 2018
 *      Author: batuhanfaik
 */

//Tumlesik kutuphaneler
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//Yazilan kutuphaneler
#include "graphicalMethod.h"
#include "bisectionMethod.h"
#include "regulaFalsiMethod.h"
#include "newtonRaphsonMethod.h"
#include "inverseOfMatrix.h"
#include "gaussJordanMethod.h"
#include "trapezodialMethod.h"
#include "simpsonMethod.h"
#include "numericalDerivation.h"

int main() {
	//Turkcelestirme
	setlocale(LC_ALL, "Turkish");

	//Onemli Uyarilar
	printf("Kullanılacak fonksiyonları lütfen polinom olarak veriniz.\n\n");

	//Degisken tanimlari
	int islem = 0;
	char tekrar = 'e';

	while (tekrar == 'e') {
		//Islem secimi
		printf("1-Grafik metoduyla kök bulma\n"
				"2-Bisection metoduyla kök bulma\n"
				"3-Regula Falsi metoduyla kök bulma\n"
				"4-Newton Raphson metoduyla kök bulma\n"
				"5-Nümerik yolla matrisin inversinin alınması\n"
				"6-Gauss Jordan metoduyla denklem takımı çözümü\n"
				"7-Trapez metoduyla integrasyon\n"
				"8-Simpson metoduyla integrasyon\n"
				"9-Nümerik türev hesaplama\n"
				"\nYapmak istediginiz işlemin numarasini giriniz: ");
		scanf("%d", &islem);

		switch (islem) {
		case (1):
			graphical();
			break;
		case (2):
			bisection();
			break;
		case (3):
			regulaFalsi();
			break;
		case (4):
			newtonRaphson();
			break;
		case (5):
			inverseOfMatrix();
			break;
		case (6):
			gaussJordan();
			break;
		case (7):
			trapezodial();
			break;
		case (8):
			simpson();
			break;
		case (9):
			numericalDerivation();
			break;
		default:
			printf("İşlem seçilmedi.");
		}

		//Tekrarlayim mi?
		tekrar = 'h';
		printf("\n\nTekrar işlem yapmak istiyor musunuz (e/h)? ");
		scanf(" %c", &tekrar);

		//tekrar karakter kontrolu
		while(tekrar != 'e' && tekrar != 'h'){
			printf("\"%c\" geçerli değildir.\n"
		  "Lütfen geçerli karakter giriniz (e/h): ", tekrar);
			scanf(" %c", &tekrar);
		}

		printf("\n");
	}

	return 0;
}
