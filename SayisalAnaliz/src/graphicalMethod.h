/*
 * graphicalMethod.h
 *
 *  Created on: Apr 17, 2018
 *      Author: batuhanfaik
 */

#ifndef GRAPHICALMETHOD_H_
#define GRAPHICALMETHOD_H_

void graphicalMethod() {
	//Degiskenler
		double xval, delta, epsilon;
		int degree;

		//Girdiler
		printf("Kacinci dereceden fonksiyonun kokunu ariyorsunuz?: ");
		scanf("%d", &degree);

		//Katsayilar dizisi
		double coefficient[degree];
		for (int i = degree; i >= 0; i--) {
			printf("%d. derecenin katsayisi: ", i);
			scanf("%lf", &coefficient[i]);
		}

		//Girdiler
		printf("Baslangic X degeri: ");
		scanf("%lf", &xval);

		printf("Sirasiyla aralarinda bosluk birakarak\nDelta ve Epsilon degerleri: ");
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
				|| ((f(xval) - f(xval + delta)) > epsilon)) && (f(xval) != 0) && (delta >= epsilon)) {
			while (((f(xval) * f(xval + delta) > 0)) && f(xval + delta) != 0) {
				xval += delta;
			}
			xval -= delta;
			delta /= 2;
		}

		//Cikti
		printf("Fonksiyonun koku: %lf", xval + delta);
}

#endif /* GRAPHICALMETHOD_H_ */
