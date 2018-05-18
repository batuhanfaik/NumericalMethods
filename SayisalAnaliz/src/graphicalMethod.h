/*
 * graphicalMethod.h
 *
 *  Created on: Apr 17, 2018
 *      Author: batuhanfaik
 */

#ifndef GRAPHICALMETHOD_H_
#define GRAPHICALMETHOD_H_

void graphical() {
	//Degiskenler
	double xval, delta, deltaTest, epsilon;
	int degree, divergence = 0;

	//Girdiler
	printf("Kaçıncı dereceden polinomun kökünü arıyorsunuz?: ");
	scanf("%d", &degree);

	//Katsayilar dizisi
	double coefficient[degree];
	for (int i = degree; i >= 0; i--) {
		printf("%d. derecenin katsayısı: ", i);
		scanf("%lf", &coefficient[i]);
	}

	//Girdiler
	printf("Başlangıç X değeri: ");
	scanf("%lf", &xval);

	printf("Sırasıyla, aralarında boşluk bırakarak\n"
			"Delta ve Epsilon değerleri: ");
	scanf("%lf %lf", &delta, &epsilon);

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

	while ((((f(xval + delta) - f(xval)) > epsilon)
			|| ((f(xval) - f(xval + delta)) > epsilon)) && (f(xval) != 0)) {
		while (((f(xval) * f(xval + delta) > 0)) && (f(xval + delta) != 0) && (divergence == 0)){
			xval += delta;
			deltaTest = deltaTest/2;
			if (deltaTest < epsilon){
				divergence = 1;
			}
		}
		xval -= delta;
		delta /= 2;
		deltaTest = delta;
	}

	//Cikti
	if (divergence == 1){
		printf("Kök bulunamadı :(");
	} else {
		printf("Fonksiyonun kökü: %lf", xval + delta);
	}
}

#endif /* GRAPHICALMETHOD_H_ */
