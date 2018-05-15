/*
 * newtonRaphsonMethod.h
 *
 *  Created on: May 15, 2018
 *      Author: batuhanfaik
 */

#ifndef NEWTONRAPHSONMETHOD_H_
#define NEWTONRAPHSONMETHOD_H_

void newtonRaphsonMethod() {
	//Degiskenler
	double xVal, xValTemp, epsilon;
	int degree;

	//Girdiler
	printf("Kacinci dereceden fonksiyonun kokunu ariyorsunuz?: ");
	scanf("%d", &degree);

	//Katsayilar dizisi
	double coefficient[degree + 1];
	for (int i = degree; i >= 0; i--) {
		printf("%d. derecenin katsayisi: ", i);
		scanf("%lf", &coefficient[i]);
	}

	//Turevin katsayiar dizisi
	double dcoefficient[degree];
	for (int i = (degree - 1); i >= 0; i--) {
		dcoefficient[i] = coefficient[i+1]*(i+1);
	}

	//Girdiler
	printf(
			"Sirasiyla aralarinda bosluk birakarak\nBaslangic X ve Epsilon degerleri: ");
	scanf("%lf %lf", &xVal, &epsilon);

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

	double df(double xval) {
		double value = 0;
		double thisx = 1;

		//Fonksiyonun turevinin hesaplandigi dongu
		for (int i = 0; i < degree; i++) {
			value = dcoefficient[i] * thisx + value;
			thisx = thisx * xval;
		}

		return value;
	}

	do {
		//X(k) tutmak icin
		xValTemp = xVal;

		///X(k+1) hesabi
		xVal = xVal - (f(xVal)/df(xVal));

	} while (fabs(xVal - xValTemp) > epsilon);

	printf("Fonksiyonun koku: %lf", xVal);
}

#endif /* NEWTONRAPHSONMETHOD_H_ */
