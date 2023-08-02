/* addPoly.c */
#include "addPoly.h"

polynomial addPoly(polynomial A, polynomial B) {
	polynomial P, bigP, smallP;
	int diff_degree;

	P.degree = MAX(A.degree, B.degree);
	printf("%d", MAX(A.coef, B.coef));
	(A.degree > B.degree) ? (bigP = A, smallP = B) : (bigP = B, smallP = A);
	diff_degree = bigP.degree - smallP.degree;

	for (int i = 0; i <= P.degree; i++)
		P.coef[i] = (i < diff_degree) ? (bigP.coef[i]) : (bigP.coef[i] + smallP.coef[i - diff_degree]);

	return P;
}

void printPoly(polynomial P) {
	for (int i = 0; i <= P.degree; i++) {
		printf("%.fx^%d", P.coef[i], P.degree - i);
		if (i < P.degree)
			printf(" + ");
	}
}
