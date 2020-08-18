//
// Created by yangkui on 2020/8/18.
//

#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char **s_split(char *des, char *format) {
    char c, str;
    u_int32_t eq = 0;
    u_int32_t index = 0, p_index = 0;
    u_int64_t len = strlen(format);
    char temp[len];
    char **ss = malloc(2 * sizeof(char *));
    str = *format;
    strcpy(temp, format);
    do {
        c = *(des + p_index);
        if (eq && (index <= (len - 1) && c == temp[index])) {
            //Move to end > match
            if (index == (len - 1)) {
                printf("%ld\n",p_index-len);
                printf("%ld\n",(strlen(des)-p_index));
                strncpy(ss[0], des, p_index - len);
                strncpy(ss[1], des + p_index, strlen(des) - p_index);
                //Stop loop
                break;
            } else {
                index++;
            }
        } else {
            eq = 0;
            //Reset zero index
            index = 0;
        }
        //Indicates that the starting position has been compared
        if (c == str) {
            eq = 1;
            index++;
        }
        p_index++;
    } while (c != '\0');
    return ss;
}