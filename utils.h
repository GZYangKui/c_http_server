//
// Created by yangkui on 2020/8/18.
//

#ifndef C_HTTP_SERVER_UTILS_H
#define C_HTTP_SERVER_UTILS_H
#define EMPTY_STRING ""

/*Split string according by fix format*/
extern char **s_split(char *des, char *format);

/*Get substring base malloc realization so need manual free memory.*/
extern char *sub_str(char *desc, int s, int e);

#endif //C_HTTP_SERVER_UTILS_H
