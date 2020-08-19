//
// Created by yangkui on 2020/8/18.
//

#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char **s_split(char *des, char *format) {
    char c;
    char **s = NULL;
    int i = 0, p = 0, eq = 0;
    do {
        c = *(des + p);
        if (c == *format || (eq && c == *(format + (++i)))) {
            if (eq == 0) {
                eq = 1;
            }
            //end loop
            if (i == strlen(format) - 1) {
                s = malloc(2 * sizeof(char *));
                int si = p - i, ei = p;
                printf("Matcher format string start %d end %d", si, ei);
                //todo Generate string array
                break;
            }
        } else {
            i = eq = 0;
        }
        ++p;
    } while (c != '\0');
    return s;
}

char *sub_str(char *desc, int s, int e) {
    char *sub_s = (char *) malloc(sizeof(char *));
    unsigned long len = strlen(desc);
    if (s > len || !(e - s)) {
        strcpy(sub_s, EMPTY_STRING);
    } else {
        char c;
        int index = 0;
        int s_len = e - s;
        char ss[s_len + 1];
        memset(ss, 0, sizeof(ss));
        do {
            c = *(desc + s + index);
            ss[index] = c;
            if (s + index == e - 1) break;
            index++;
        } while (c != '\0');
        strcpy(sub_s, ss);
    }
    return sub_s;
}