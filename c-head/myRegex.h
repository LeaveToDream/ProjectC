//
// Created by John-i5m on 17/04/2017.
//

#ifndef __REGEX__
#define __REGEX__

#include <stdbool.h>

bool reg_matches(const char *str, const char *pattern);
bool reg_find_move(const char *str, const char *pattern, int* x1, int* y1, int* x2, int* y2 );

#endif //PROJECTC_REGEX_H
