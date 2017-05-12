#include <regex.h>
#include <stdio.h>
#include <stdbool.h>
//#include <afxres.h>

#include "../c-head/board.h"
#include "../c-head/game.h"

// Thank to http://nicolasj.developpez.com/articles/regex/ & stack overflow

bool reg_matches(const char *str, const char *pattern) {
    regex_t re;
    int ret;

    if (regcomp(&re, pattern, REG_EXTENDED) != 0)
        return false;

    ret = regexec(&re, str, (size_t) 0, NULL, 0);
    regfree(&re);

    if (ret == 0)
        return true;

    return false;
}
bool reg_find_move(const char *str, const char* pattern, int* x1, int* y1, int* x2, int* y2){
    int err;
    regex_t preg;

/* On commence par compiler notre expression sans l'option REG_NOSUB pour pouvoir récupérer les sous chaîne reconnues */
    err = regcomp(&preg, pattern, REG_EXTENDED);
    if (err == 0)
    {
        int match;
        size_t nmatch = 0;
        regmatch_t *pmatch = NULL;

        nmatch = preg.re_nsub;
        pmatch = malloc (sizeof (*pmatch) * nmatch);
        if (pmatch)
        {
/* Grâce à la structure regex_t, on connaît le nombre de sous chaîne attendue, on alloue donc un tableau de taille adéquate pour les stocker */
            match = regexec(&preg, str, nmatch, pmatch, 0);
/* On demande l'analyse de notre chaîne */
            regfree(&preg);
/* Si la chaîne est reconnue */
            if (match == 0)
            {
                // x1
                int start = pmatch[0].rm_so;
                int end = pmatch[0].rm_eo;
                size_t size = end - start;
                // If everything went right, size = 1
                if(size == 1 ){
                    *x1 = letterToNumber(str[start]);
                } else {
                    return false ;
                }

                // And this is where the fun begins
                // y1
                start = pmatch[1].rm_so;
                end = pmatch[1].rm_eo;
                size = end - start;
                char tempChar[2] ;
                // If everything went right, size = 1 or 2 (board is from A1 to O15)
                if(size == 1 ){
                    // Which means the y is in [1;9]
                    tempChar[0]='0';
                    tempChar[1]=str[start];
                    *y1 = (int) strtol(tempChar,NULL,10);
                } else if (size == 2 ){
                    tempChar[0]=str[start];
                    tempChar[1]=str[start+1];
                    *y1 = (int) strtol(tempChar,NULL,10);
                } else {
                    return false ;
                }

                // x2
                start = pmatch[2].rm_so;
                end = pmatch[2].rm_eo;
                size = end - start;
                // If everything went right, size = 1
                if(size == 1 ){
                    *x2 = letterToNumber(str[start]);
                } else {
                    return false ;
                }

                // y2
                start = pmatch[3].rm_so;
                end = pmatch[3].rm_eo;
                size = end - start;
                // If everything went right, size = 1 or 2 (board is from A1 to O15)
                if(size == 1 ){
                    // Which means the y is in [1;9]
                    tempChar[0]='0';
                    tempChar[1]=str[start];
                    *y2 = (int) strtol(tempChar,NULL,10);
                } else if (size == 2 ){
                    tempChar[0]=str[start];
                    tempChar[1]=str[start+1];
                    *y2 = (int) strtol(tempChar,NULL,10);
                } else {
                    return false ;
                }
            }
            else if (match == REG_NOMATCH)
            {
                return false ;
            }
            else
            {
                char *text;
                size_t size;

                size = regerror (err, &preg, NULL, 0);
                text = malloc (sizeof (*text) * size);
                if (text)
                {
                    regerror (err, &preg, text, size);
                    fprintf (stderr, "%s\n", text);
                    free (text);
                }
                else
                {
                    fprintf (stderr, "Memoire insuffisante\n");
                    exit (EXIT_FAILURE);
                }
            }
        }
        else
        {
            fprintf (stderr, "Memoire insuffisante\n");
            exit (EXIT_FAILURE);
        }
    }

    return false ;

}
