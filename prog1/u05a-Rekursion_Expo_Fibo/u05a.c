/* u05a.c
 * Name: Eric Finger
 * Datum: 09.11.22
 * Beschreibung: Berchnet mit rekursiven Funktionen:
 *               - Die Fakultaet einer Zahl n
 *               - Die Potenz zweier Zahlen x^y
 *               - Die ersten 10 Fibonacci-Zahlen
*/

#include <stdio.h>

// Berechnet n!
int fakul(int n) {
    if (n <= 1) {
        return 1;
    }

    // n! = n * (n - 1)! = n * n * (n - 2)!
    return n * fakul(n - 1);
}

// Berechnet x^y
int power(int x, int y) {
    // x^0 = 1
    if (y == 0) {
        return 1;
    }

    // x^1 = x
    if (y <= 1) {
        return x;
    }

    // x^y = x * x^(y - 1) = x * x * x^(y - 2)
    return x * power(x, y - 1);
}

// Berchnet die n-te Stelle der Fibonacci-Folge
int fibo(int n) {
    // Per definition sind die ersten beiden Fibonacci-Zahlen 1:
    if (n <= 2) {
        return 1;
    }

    // Die Fibonacci-Zahl X ist die Summe der beiden Zahlen davor:
    return fibo(n - 1) + fibo(n - 2);
}

int main() {
    int userInput;
    printf("Geben Sie eine Zahl zur Fakultaetsberechnung ein: ");
    scanf("%d", &userInput);
    printf("%d! = %d\n", userInput, fakul(userInput));


    int userInputX;
    int userInputY;
    printf("Geben Sie Zahlen fuer die Berechnung von x^y ein:\n");
    printf("x: ");
    scanf("%d", &userInputX);
    printf("y: ");
    scanf("%d", &userInputY);
    printf("%d^%d = %d\n", userInputX, userInputY, power(userInputX, userInputY));

    printf("Die ersten 10 Zahlen der Fibonacci-Folge:\n");
    for (int i = 1; i <= 10; i++) {
        printf("%d ", fibo(i));
    }
    printf("\n");

    return 0;
}

