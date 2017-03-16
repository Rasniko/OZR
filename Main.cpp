#include <stdlib.h>
#include <stdio.h>

int binaran[32];

void ubinarno(float number) {
	float a = number, decimalno;
	int i = 1, b_Cijeli = 0, b_Decimalnih = 1;
	int broj = 0, eksponent = 0;
	int ostatak = 0, cijeli;

	if( number > 1.0 ) {
		cijeli = (int)a;
		decimalno = number - (float)cijeli;
	}
	else if (number == 1.0 ){
		cijeli = 1;
		decimalno = 0.0;
	}
	else {
		cijeli = 0;
		decimalno = number;
	}

	printf("\n Cijeli dio broja = %d \n Decimalni dio broja = %f \n", cijeli, decimalno);

	while (cijeli != 0) {

		ostatak = cijeli % 2;
		cijeli /= 2;
		broj = broj + (ostatak * i);
		i *= 10;
		b_Cijeli++;
	}

	printf("\n Cijeli dio broja u binarnom obliku = %d \n", broj);

	for (int n = 8 + b_Cijeli -1; n > 8; n--) {
		binaran[n] = broj % 10;
		broj = broj / 10;
	}

	if (number >= 1) {
		eksponent = 127 + b_Cijeli - 1;
	}

	for (int n = 8 + b_Cijeli; n < 32; n++) {
		if (decimalno != 0) {
			decimalno *= 2.0;

			if (decimalno >= 1.0) {
				binaran[n] = 1;
				decimalno = decimalno - 1.0;

				if (b_Cijeli == 0)
				{
					n = 8;
					b_Cijeli = 1;
				}
			}
			else {
				binaran[n] = 0;
			}

			if (b_Cijeli == 0) b_Decimalnih++;
		}
		else {
			binaran[n] = 0;
		}
	}

	if (number < 1) {
		eksponent = 127 - b_Decimalnih;
	}

	printf("\n\n Eksponent = %d ", eksponent);

	broj = 0;
	i = 1;

	while (eksponent != 0) {

		ostatak = eksponent % 2;
		eksponent /= 2;
		broj = broj + (ostatak * i);
		i *= 10;
	}

	printf("\n Eksponent u binarnom obliku = %d ", broj);

	for (int n = 8; n > 0; n--) {
		binaran[n] = broj % 10;
		broj /= 10;
	}
}

int main() {
	
	float number;
	char string[20];
	int exit = 1;

	while (exit == 1) {

		printf("Unesite broj: ");
		scanf("%s", &string);

		number = atof(string);

		if (number < 0) {
			binaran[0] = 1;
			number = number * (-1.0);
		}
		else {
			binaran[0] = 0;
		}

		if (number == 0) {
			for (int n = 1; n < 32; n++) {
				binaran[n] = 0;
			}
		}
		else {
			ubinarno(number);
		}

		printf("\n\n Broj %f pretvoren u IEEE 754 standard = ", number);

		for (int n = 0; n < 32; n++) {
			printf("%d", binaran[n]);

			if (n == 0) printf("  ");
			if (n == 8) printf("  ");
		}

		printf("\n\n Pritisnite 1 za ponovni unos: ");
		scanf("%d", &exit);
		printf("\n");
	}
}