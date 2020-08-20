//
// Created by yangkui on 2020/8/18.
//

#ifndef C_HTTP_SERVER_UTILS_H
#define C_HTTP_SERVER_UTILS_H
#define EMPTY_STRING ""
typedef unsigned long size_t;

/*Global request memory from operating system.*/
void *s_malloc(size_t size);

/*Global request to the operating system to change the memory size.*/
void *s_realloc(void *pt,size_t size);

/*Global error handler.*/
void error(int, int, const char *, ...);

/*Split string according by fix format*/
extern char **s_split(char *des, char *format);

/*Get substring base malloc realization so need manual free memory.*/
extern char *sub_str(char *desc, int s, int e);

#endif //C_HTTP_SERVER_UTILS_H
