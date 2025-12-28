#include <stdio.h>

typedef struct {
    int coefficient;
    int exponent;
} Term;


void multiplyPolynomials(Term poly1[], int size1, Term poly2[], int size2) {
    Term result[100]; 
    int k = 0;

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            result[k].coefficient = poly1[i].coefficient * poly2[j].coefficient;
            result[k].exponent = poly1[i].exponent + poly2[j].exponent;
            k++;
        }
    }

    printf("Resultant Polynomial: ");
    for (int i = 0; i < k; i++) {
        printf("%d^%d ", result[i].coefficient, result[i].exponent);
        if (i < k - 1) printf("+ ");
    }
    printf("\n");
}


void inputPolynomial(Term poly[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &poly[i].coefficient, &poly[i].exponent);
    }
}

int main() {
    Term poly1[10], poly2[10];
    int size1, size2;

    printf("Enter first polynomial:\nEnter the number of terms: ");
    scanf("%d", &size1);
    inputPolynomial(poly1, size1);

    printf("Enter second polynomial:\nEnter the number of terms: ");
    scanf("%d", &size2);
    inputPolynomial(poly2, size2);

    multiplyPolynomials(poly1, size1, poly2, size2);

    return 0;
}

