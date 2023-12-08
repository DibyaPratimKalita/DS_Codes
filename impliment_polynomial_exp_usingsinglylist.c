/*Write a program to implement polynomial expression using a singly linked list.*/

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

// Function to display the polynomial with brackets around negative terms
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
    struct Term* polynomial = NULL;

    // Insert terms into the polynomial
    insertTerm(&polynomial, 3, 2);
    insertTerm(&polynomial, -2, 1);
    insertTerm(&polynomial, 5, 0);

    // Display the polynomial
    printf("Polynomial: ");
    displayPolynomial(polynomial);

    // Free the memory used by the polynomial
    freePolynomial(&polynomial);

    return 0;
}