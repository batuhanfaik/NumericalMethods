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
	double xVal, delta, epsilon;
	int degree, divergence = 0, testCounter = 0;
	char devam = 'e';

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
	scanf("%lf", &xVal);

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

	//Kok hesabi
	while ((fabs(f(xVal + delta) - f(xVal)) > epsilon) && (devam == 'e')){
		while ((f(xVal)*f(xVal + delta) > 0) && (devam == 'e')){
			xVal += delta;
			testCounter++;
			if (testCounter % 1000 == 0){
				printf("Verilen değerler sonucu %d iterasyondur kök bulunamadı.\n"
		   "X değeri şu anda \"%.4lf\"\n"
		   "Devam etmek istiyor musunuz (e/h)? ", testCounter, xVal);
				scanf(" %c", &devam);

				//devam karakter kontrolu
				while(devam != 'e' && devam != 'h'){
					printf("\"%c\" geçerli değildir.\n"
						   "Lütfen geçerli karakter giriniz (e/h): ", devam);
					scanf(" %c", &devam);
				}
			}
		}
		xVal -= delta;
		delta /= 2;
		testCounter = 0;
	}

	//Cikti
	if (devam != 'e'){
		printf("Kök bulunamadı :(");
	} else {
		printf("Fonksiyonun kökü: %lf", xVal + delta);
	}

}

#endif /* GRAPHICALMETHOD_H_ */
