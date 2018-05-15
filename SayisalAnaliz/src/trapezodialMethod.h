/*
 * trapezodialIntegrationMethod.h
 *
 *  Created on: May 15, 2018
 *      Author: batuhanfaik
 */

#ifndef TRAPEZODIALMETHOD_H_
#define TRAPEZODIALMETHOD_H_

void trapezodial() {
	//Degiskenler
	double height, lowerBound, upperBound, area, sum = 0;
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
		for (int i = 0; i < (degree+1); i++) {
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
	scanf("%d", &division);

	//Height hesabi
	height = (upperBound - lowerBound) / division;

	//f(x) degerlerinin lowerBound+height'tan upperBound-height'a kadar toplanmasi
	for (int i=1; i<division; i++){
		sum = sum + f(lowerBound + i*height);
	}

	//Trapez yontemiyle integral hesabi
	area = height*((f(lowerBound)+f(upperBound))/2 + sum);

	printf("İntegralin sonucu: %lf", area);
}

#endif /* TRAPEZODIALMETHOD_H_ */
