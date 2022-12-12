#include <stdio.h>
#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 * Zwraca 2 - wiecej niewiadomych niz rownan, a wiec brak jednoznacznej odpowiedzi
 * Zwraca 3 - macierz wyrazow wolnych ma zbyt wiele kolumn
 */

int eliminate(Matrix *mat, Matrix *b) {
    if(mat->row > mat->column) {
        fprintf(stderr, "Podano wiecej niewiadomych niz rownan,\n"
                        "nie mozna ustalic jednoznacznej odpowiedzi.\n");
        return 2;
    }
    if(b->column != 1) {
        fprintf(stderr, "Nieprawidlowa liczba kolumn macierzy wyrazow wolnych.\n");
        return 3;
    }

    int size = mat->row;
    int column, row;

    /// przeksztalcenie macierzy A w macierz gorna-trojkatna
    for (column = 0; column < size - 1; column++) {
        for (row = column + 1; row < size; row++) {
            if (mat->data[column][column] == 0) {
                fprintf(stderr, "Podana macierz jest osobliwa!\n");
                return 1;
            }
            double temp = mat->data[row][column] / mat->data[column][column];
            int i;
            for (i = column; i < size; i++)
                mat->data[row][i] -= temp * mat->data[column][i];
            b->data[row][0] -= temp * b->data[column][0];
        }
    }
    return 0;
}