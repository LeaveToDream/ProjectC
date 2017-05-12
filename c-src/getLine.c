#include <stdio.h>
#include <string.h>

#include "../c-head/getLine.h"

char *My_gets(char * str) {
    char buffer[My_gets_N];
    char *retval = fgets(buffer, My_gets_N, stdin);
    if (retval) {
        int l = strlen(buffer);
        /* fgets() saves '\n', but gets() does not */
        if ((l > 0) && (buffer[l-1] == '\n')) {
            l--;
        }
        memcpy(str, buffer, l);
        str[l] = '\0';
        return str;
    }
    else {
        return 0;
    }
}
