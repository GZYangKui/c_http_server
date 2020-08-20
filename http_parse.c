//
// Created by yangkui on 2020/8/20.
//

#include "http_parse.h"

int parse_header(const char *str, struct h_header **headers) {

    return 0;
}

char *method_val(enum h_method method) {
    char *val;
    switch (method) {
        case GET:
            val = "GET";
            break;
        case POST:
            val = "POST";
            break;
        case PUT:
            val = "PUT";
            break;
        case TRACE:
            val = "TRACE";
            break;
        case OPTIONS:
            val = "OPTIONS";
            break;
        case DELETE:
            val = "DELETE";
            break;
        case CONNECT:
            val = "CONNECT";
            break;
        default:
            val = "HEAD";
    }
    return val;
}