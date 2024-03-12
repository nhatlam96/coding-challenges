/*
 * Bietet String-Funktionen,
 * die bei fehlendem 0 Byte eine
 * maximale Ueberpruefungslaenge haben.
 *
 * 15.11.18 -- Robin Eschbach
 *
 */

#include <stdio.h>

int xstrnlen(char *s, int n) {
	int length = 0;
	while(s[length] != '\0' && length < n ) {
		length++;
	}
	return length;
}

char * xstrncpy(char *nach, char *von, int n) {
	int i = 0;
	for(; von[i] != '\0' && i < n - 1; i++) {
		nach[i] = von[i];
	}
	nach[i + 1] = '\0';
	return nach;
}

char * xstrncat(char *nach, char *von, int n) {
	int i = xstrnlen(nach, sizeof(nach));
	for(int j = 0; von[j] != '\0' && j < n; i++, j++) {
		nach[i] = von[j];
	}
	nach[i + 1] = '\0';
	return nach;
}

int xstrncmp(char *a, char *b, int n) {
	int ret = 0;
	for(int i = 0; i < n; i++) {
		ret = a[i] - b[i];
		if(ret != 0 || a[i] == '\0' || b[i] == '\0') {
			break;
		}
	}
	return ret;
}


int main() {
	char wort1[20] = {'T', 'e', 's', 't', '\0'};
	char wort2[40] = {'T', 'E', 's', 'T', ' ', ' ', ' ', '\0'};

	printf("wort1: \"%s\"\nwort2: \"%s\"\n\n", wort1, wort2);

	/* xstrncmp ohne Überlaufverhinderung */
	printf("xstrncmp(\"%s\", \"%s\", 8): %i\n", wort1, wort2, xstrncmp(wort1, wort2, 8));
	/* xstrncmp mit Überlaufverhinderung */
	printf("xstrncmp(\"%s\", \"%s\", 1): %i\n\n", wort1, wort2, xstrncmp(wort1, wort2, 1));

	/* xstrnlen ohne Überlaufverhinderung */
	printf("xstrnlen(\"%s\", 20): %i\n", wort1, xstrnlen(wort1, 20));
	/* xstrnlen mit Überlaufverhinderung */
	printf("xstrnlen(\"%s\", 2): %i\n\n", wort1, xstrnlen(wort1, 2));


	/* xstrncat ohne Überlaufverhinderung */
	printf("xstrncat(\"%s\", \"%s\", 20): ", wort1, wort2);
	printf("\"%s\"\n", xstrncat(wort1, wort2, 20));
	/* xstrncat mit Überlaufverhinderung */
	printf("xstrncat(\"%s\", \"%s\", 2): ", wort2, wort1);
	printf("\"%s\"\n\n", xstrncat(wort2, wort1, 2));

	/* xstrncpy ohne Überlaufverhinderung */
	printf("xstrncpy(\"%s\", \"%s\", 20): ", wort1, wort2);
	printf("\"%s\"\n", xstrncpy(wort1, wort2, 20));
	/* xstrncat mit Überlaufverhinderung */
	printf("xstrncpy(\"%s\", \"%s\", 2): ", wort2, wort1);
	printf("\"%s\"\n", xstrncpy(wort2, wort1, 2));

	return 0;
}
