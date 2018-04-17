/*
 * bisectionMethod.h
 *
 *  Created on: Apr 17, 2018
 *      Author: batuhanfaik
 */

#ifndef BISECTIONMETHOD_H_
#define BISECTIONMETHOD_H_

void bisectionMethod(){
	//Degiskenler
	double xVal1, xVal2, epsilon;
	int degree;

	//Girdiler
	printf("Kacinci dereceden fonksiyonun kokunu ariyorsunuz?: ");
	scanf("%d", &degree);

	//Katsayilar dizisi
	double coefficient[degree+1];
	for (int i = degree; i >= 0; i--) {
		printf("%d. derecenin katsayisi: ", i);
		scanf("%lf", &coefficient[i]);
	}

	//Girdiler
	printf("Baslangic X1 ve X2 degerleri: ");
	scanf("%lf %lf", &xVal1, &xVal2);

	printf("Epsilon degeri: ");
	scanf("%lf", &epsilon);

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

	//Ilk ortanca deger atamasi
	double xValMid = (xVal1 + xVal2) / 2;

	//Hesaplama Dongusu
	while (fabs(f(xValMid)) > epsilon) {

		//Eger kok birinci ve ortanca deger arasindaysa yeni ortanca ikinci deger
		if (f(xVal1) * f(xValMid) < 0) {
			xVal2 = xValMid;
		}
		//Eger kok birinci ve ortanca deger arasinda degilse yeni ortanca birinci deger
		else {
			xVal1 = xValMid;
		}

		//Yeni ortanca hesabi
		xValMid = (xVal1 + xVal2)/2;
	}

	//Cikti
	printf("Fonksiyonun koku: %lf", xValMid);
}

#endif /* BISECTIONMETHOD_H_ */
