/*
 * numericalDerivation.h
 *
 *  Created on: May 16, 2018
 *      Author: batuhanfaik
 */

#ifndef NUMERICALDERIVATION_H_
#define NUMERICALDERIVATION_H_

void numericalDerivation(){
	//Degiskenler
		double xVal, delta, backDiff, forwDiff, centDiff;
		int degree;

		//Girdiler
		printf("Kaçıncı dereceden polinomun türevini arıyorsunuz?: ");
		scanf("%d", &degree);

		//Katsayilar dizisi
		double coefficient[degree + 1];
		for (int i = degree; i >= 0; i--) {
			printf("%d. derecenin katsayısı: ", i);
			scanf("%lf", &coefficient[i]);
		}

		//Analitik turevin katsayiar dizisi
		double dcoefficient[degree];
		for (int i = (degree - 1); i >= 0; i--) {
			dcoefficient[i] = coefficient[i + 1] * (i + 1);
		}

		//Girdiler
		printf("Sırasıyla, aralarında boşluk bırakarak\n"
				"X ve Delta değerleri: ");
		scanf("%lf %lf", &xVal, &delta);

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

			//Fonksiyonun analitik turevinin hesaplandigi dongu
			for (int i = 0; i < degree; i++) {
				value = dcoefficient[i] * thisx + value;
				thisx = thisx * xval;
			}

			return value;
		}

		//Turev hesaplamalari
		forwDiff = (f(xVal + delta) - f(xVal))/delta;
		backDiff = (f(xVal) - f(xVal - delta))/delta;
		centDiff = (forwDiff + backDiff)/2;

		//Sonuclar
		printf("X= %.2lf noktasında\nAnalitik türev değeri= %.4lf\n", xVal, df(xVal));
		printf("İleri fark türev değeri= %.4lf\n", forwDiff);
		printf("Geri fark türev değeri= %.4lf\n", backDiff);
		printf("Merkezi fark türev değeri= %.4lf", centDiff);
}

#endif /* NUMERICALDERIVATION_H_ */
