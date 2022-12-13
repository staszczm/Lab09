#include <stdio.h>
#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    if(mat->r > mat->c || b->c != 1 || x->c != 1){
        fprintf(stderr, "Nieprawidlowe rozmiary macierzy!\n");
        return 2;
    }    
    
    int size = mat->r, row, col;
    
    for( row = size-1; row >=0; row--){
        double tmp = 0;
        for(col = row+1; col<size; col++)
            tmp += mat->data[row][col] * x->data[col][0];
        if( mat->data[row][row] == 0){
            return 1;
            fprintf(stderr, "Dzielenie na diagonali!\n");
        }
        x->data[row][0] = (b->data[row][0] - tmp) / mat->data[row][row];
    }

    return 0;
}


