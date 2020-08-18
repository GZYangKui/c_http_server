//
// Created by yangkui on 2020/8/17.
//

#include <stdio.h>
#include "http_server.h"
#include "utils.h"

int main(int argc, char *args[]) {
    char **ss = s_split("abcdef测试dabc", "测试");
    for (int i = 0; i < sizeof(ss); ++i) {
        printf("%s\n", ss[i]);
    }
    printf("Hello,world!");
    return 0;
}