/*  
 * Beschreibung : p06b Trigonometrie / Funktionen / Numerik
 */ 

#include <stdio.h> 
#include <math.h>
#define _USE_MATH_DEFINES

/* calculate phi */
double phi(double alpha, double beta){
	return beta-alpha;
}

/* calculate length u */
double u(double length, double alpha, double beta){
	return length*sin((M_PI/180)*alpha)/sin((M_PI/180)*phi(alpha, beta));
}

/* calculate height of pyramid */
double hoehe(double length, double alpha, double beta){
	return u(length, alpha, beta)*sin((M_PI/180)*beta);
}

/* calculate volume of pyramid */
double pvolumen(double height){
	return 2*height*height*height/3;
}

int main(){
	double length;
	double alpha;
	double beta;
	double height;

	/* get values from console */
	printf("Werte eingeben:\n\nLänge s:\n");
	scanf("%lf", &length);
	printf("Winkel alpha:\n");
	scanf("%lf", &alpha);
	printf("Winkel beta:\n");
	scanf("%lf", &beta);

	/* calculate and print stuff */
	if(alpha<beta){
		height = hoehe(length, alpha, beta);
		printf("Die Pyramide hat eine Höhe von: %.02lf Metern.\nDie Pyramide hat ein Volumen von: %.02lf Kubikmeter.\nDie Strecke s beträgt: %.02lf Meter.\nDer Winkel alpha beträgt: %.02lf Grad.\nDer Winkel beta beträgt: %.02lf Grad.\nDer Winkel phi beträgt: %.02lf Grad.\n", height, pvolumen(height), length, alpha, beta, phi(alpha, beta));
	} else
		printf("Winkel alpha darf nicht größer als/oder gleich Winkel beta sein.\n");
	return 0;
} 
