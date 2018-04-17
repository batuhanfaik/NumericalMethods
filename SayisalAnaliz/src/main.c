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


int main() {
	//Degisken tanimlari
	int islem = 0;

	//Islem secimi
	printf("1-Grafik metoduyla kök bulma\n"
			"Yapmak istediginiz islemin numarasini giriniz: ");
	scanf("%d", &islem);

	switch (islem) {
	case (1):
		graphicalMethod();
		break;
	case (2):
		bisectionMethod();
		break;
	default:
		printf("Islem secilmedi.");
	}

	return 0;
}
