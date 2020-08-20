//
// Created by yangkui on 2020/8/18.
//

#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>

void *s_malloc(size_t size) {
    void *pt;
    if (!(pt = malloc(size)))
        error(EXIT_FAILURE, errno, "malloc");
    return pt;
}

void *s_realloc(void *pt, size_t size) {
    if (!(pt = realloc(pt, size)))
        error(EXIT_FAILURE, errno, "realloc");
    return pt;
}

void error(int status, int err_num, const char *format, ...) {
    va_list args;

    fprintf(stderr, "%s: error: ", "c_http_server");
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    if (err_num)
        fprintf(stderr, ": %s", strerror(err_num));
    fprintf(stderr, "\n");

    exit(status);
}

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
                printf("Matcher format string start %d end %d\n", si, ei);
                s[0] = sub_str(des, 0, si);
                s[1] = sub_str(des, ei + 1, (int) strlen(des));
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
    if (s > len || (e - s) <= 0) {
        printf("sub_str:substring index error[start:%d end:%d]\n", s, e);
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