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
	double xval, delta, epsilon;
	int degree;

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

	printf("Sırasıyla, aralarında boşluk bırakarak\"
			"nDelta ve Epsilon değerleri: ");
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
			|| ((f(xval) - f(xval + delta)) > epsilon)) && (f(xval) != 0)
			&& (delta >= epsilon)) {
		while (((f(xval) * f(xval + delta) > 0)) && f(xval + delta) != 0) {
			xval += delta;
		}
		xval -= delta;
		delta /= 2;
	}

	//Cikti
	printf("Fonksiyonun kökü: %lf", xval + delta);
}

#endif /* GRAPHICALMETHOD_H_ */
