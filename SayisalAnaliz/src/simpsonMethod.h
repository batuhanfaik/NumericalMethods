/*
 * simpsonMethod.h
 *
 *  Created on: May 15, 2018
 *      Author: batuhanfaik
 */

#ifndef SIMPSONMETHOD_H_
#define SIMPSONMETHOD_H_

void simpson() {
	//Degiskenler
	double height, lowerBound, upperBound, area, sumOfOdds = 0, sumOfEvens = 0;
	int degree, division;

	//Girdiler
	printf("Kaçıncı dereceden polinomun integralini alacaksınız?: ");
	scanf("%d", &degree);

	//Katsayilar dizisi
	double coefficient[degree];
	for (int i = degree; i >= 0; i--) {
		printf("%d. derecenin katsayisi: ", i);
		scanf("%lf", &coefficient[i]);
	}

	//Fonksiyon
	double f(double xval) {
		double value = 0;
		double thisx = 1;

		//Fonksiyonun hesaplandigi dongu
		for (int i = 0; i < (degree + 1); i++) {
			value = coefficient[i] * thisx + value;
			thisx = thisx * xval;
		}
		return value;
	}

	//Upper ve lower boundary alma
	printf("Sırasıyla, aralarında boşluk bırakarak\n"
			"İntegralin Alt ve Üst limitleri: ");
	scanf("%lf %lf", &lowerBound, &upperBound);

	//n degeri alma
	printf("Ayrılacak olan bölge sayısı (n değeri): ");
	do {
		scanf("%d", &division);
		if (division % 2 == 1){
			printf("\nn değeri çift olmalıdır!\nLütfen tekrar giriniz: ");
		}
	} while (division % 2 == 1);

	//Height hesabi
	height = (upperBound - lowerBound) / division;

	//f(x)'in tek degerlerinin lowerBound+height'tan upperBound-height'a kadar toplanmasi
	for (int i = 1; i < division; i+=2) {
		sumOfOdds = sumOfOdds + f(lowerBound + i * height);
	}

	//f(x)'in cift degerlerinin lowerBound+2*height'tan upperBound-2*height'a kadar toplanmasi
	for (int i = 2; i < division-1; i+=2) {
		sumOfEvens = sumOfEvens + f(lowerBound + i * height);
	}

	//Simpson yontemiyle integral hesabi
	area = (height/3)*(f(lowerBound) + f(upperBound) + 4*sumOfOdds + 2*sumOfEvens);

	printf("İntegralin sonucu: %lf", area);
}

#endif /* SIMPSONMETHOD_H_ */
