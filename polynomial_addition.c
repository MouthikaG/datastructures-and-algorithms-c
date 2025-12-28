#include <stdio.h>

typedef struct {
    int coefficient;
    int exponent;
} Term;


void addPolynomials(Term poly1[], int size1, Term poly2[], int size2) {
    int i = 0, j = 0;
    printf("Resultant Polynomial: ");
    
    while (i < size1 && j < size2) {
        if (poly1[i].exponent == poly2[j].exponent) {
            printf("%d^%d + ", poly1[i].coefficient + poly2[j].coefficient, poly1[i].exponent);
            i++; j++;
        } else if (poly1[i].exponent > poly2[j].exponent) {
            printf("%d^%d + ", poly1[i].coefficient, poly1[i].exponent);
            i++;
        } else {
            printf("%d^%d + ", poly2[j].coefficient, poly2[j].exponent);
            j++;
        }
    }
    while (i < size1) {
        printf("%d^%d + ", poly1[i].coefficient, poly1[i].exponent);
        i++;
    }
    while (j < size2) {
        printf("%d^%d + ", poly2[j].coefficient, poly2[j].exponent);
        j++;
    }
    printf("\b\b \n");
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

    printf("Input Polynomial 1:\nEnter the number of terms: ");
    scanf("%d", &size1);
    inputPolynomial(poly1, size1);

    printf("Input Polynomial 2:\nEnter the number of terms: ");
    scanf("%d", &size2);
    inputPolynomial(poly2, size2);

    addPolynomials(poly1, size1, poly2, size2);

    return 0;
}

