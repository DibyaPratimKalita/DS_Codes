/*Write a program to add two polynomial expressions that are represented using a singly linked list.*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new term
struct Term* createTerm(int coeff, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newTerm->coefficient = coeff;
    newTerm->exponent = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into the polynomial
void insertTerm(struct Term** poly, int coeff, int exp) {
    struct Term* newTerm = createTerm(coeff, exp);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct Term* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to display the polynomial
void displayPolynomial(struct Term* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    while (poly != NULL) {
        if (poly->coefficient < 0) {
            printf("(%dx^%d)", poly->coefficient, poly->exponent);
        } else {
            printf("%dx^%d", poly->coefficient, poly->exponent);
        }

        poly = poly->next;

        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        int coeff1 = (poly1 != NULL) ? poly1->coefficient : 0;
        int exp1 = (poly1 != NULL) ? poly1->exponent : 0;

        int coeff2 = (poly2 != NULL) ? poly2->coefficient : 0;
        int exp2 = (poly2 != NULL) ? poly2->exponent : 0;

        int sumCoeff = coeff1 + coeff2;

        insertTerm(&result, sumCoeff, exp1); // Assuming the exponents are the same

        if (poly1 != NULL) {
            poly1 = poly1->next;
        }

        if (poly2 != NULL) {
            poly2 = poly2->next;
        }
    }

    return result;
}

// Function to free the memory used by the polynomial
void freePolynomial(struct Term** poly) {
    struct Term* current = *poly;
    struct Term* nextTerm;

    while (current != NULL) {
        nextTerm = current->next;
        free(current);
        current = nextTerm;
    }

    *poly = NULL;
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;

    // Insert terms into the first polynomial
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, -2, 1);
    insertTerm(&poly1, 5, 0);

    // Insert terms into the second polynomial
    insertTerm(&poly2, 2, 1);
    insertTerm(&poly2, 1, 0);

    // Display the first polynomial
    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    // Display the second polynomial
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    // Add the polynomials
    struct Term* result = addPolynomials(poly1, poly2);

    // Display the result polynomial
    printf("Result: ");
    displayPolynomial(result);

    // Free the memory used by the polynomials
    freePolynomial(&poly1);
    freePolynomial(&poly2);
    freePolynomial(&result);

    return 0;
}