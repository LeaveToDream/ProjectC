//
// Created by John-i5m on 18/04/2017.
//

#include <stdbool.h>
#include <mem.h>
#include <stdlib.h>
#include <stdio.h>

#include "../c-head/board.h"
#include "../c-head/game.h"
#include "../c-head/find.h"


// Possible length : A1 to B1, A11 to B11

bool isAMove (char* string){
    if(strlen(string)>=8 && strlen(string)<=10){
        const char toFind[5] = " to ";
        return (strstr(string, toFind)!=NULL);
    } else {
        return false ;
    }
}
bool processMove(char* string, int* x1, int* y1, int* x2, int* y2){
    if(!isAMove(string)){
        return false ;
    }

    const char toFind[5] = " to ";
    char* tempChar ;
    int anchor, tempInt ;
    anchor = strstr(string, toFind) - string; // This var stores a pointer to the " " that precede "to" in the

    // x1
    if(string[0]>='a' && string[0]<='z'){
        tempInt = letterToNumber(string[0]);
        *x1 = tempInt ;
    } else {
        return false ;
    }

    // y1
    tempChar = str_sub(string, 1, anchor);
    tempInt = strtol(tempChar,NULL,10);
    free(tempChar);
    if(tempInt>=0 && tempInt<= 18){
        *y1 = tempInt ;
    } else {
        return false ;
    }

    // x2
    if(string[anchor+4]>='a' && string[anchor+4]<='z'){
        tempInt = letterToNumber(string[anchor+4]);
        *x2 = tempInt ;
    } else {
        return false ;
    }

    // y2
    tempChar = str_sub(string, anchor+5, strlen(string));
    tempInt = (int) strtol(tempChar,NULL,10);
    free(tempChar);
    if(tempInt>=0 && tempInt<= 18){
        *y2 = tempInt ;
    } else {
        return false ;
    }

}

char *str_sub (const char *s, unsigned int start, unsigned int end) {
    /* See http://nicolasj.developpez.com/articles/libc/string/ for more example. Thank you ! */
    char *new_s = NULL;

    if (s != NULL && start < end) {
        /* On calcule la taille de la sous-chaîne*/
        new_s = malloc (sizeof (*new_s) * (end - start + 2));
        if (new_s != NULL){
            int i;
            /* On parcourt s entre les deux indices */
            for (i = start; i <= end; i++) {
                /* On copie chaque caractère dans la sous-chaîne */
                new_s[i-start] = s[i];
            }
            new_s[i-start] = '\0';
        } else {
            fprintf (stderr, "Memoire insuffisante\n");
            exit (EXIT_FAILURE);
        }
    }
    return new_s;
}

void lower (char *str) {
    for (int i = 0; i < strlen(str) ; ++i) {
        if(str[i]>= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 'a' - 'A' ;
        }
    }
}