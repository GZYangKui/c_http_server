/**
 *
 *<p>
 * The current project supports HTTP 1.1.
 * For more HTTP 1.1, please visit the following link:<a href='https://www.w3.org/Protocols/rfc2616/rfc2616.html'></a>
 * </p>
 */
#ifndef C_HTTP_SERVER_HTTP_PARSE_H
#define C_HTTP_SERVER_HTTP_PARSE_H

//<a href='https://www.w3.org/Protocols/rfc2616/rfc2616-sec9.html#sec9'></a>
enum h_method {
    PUT,
    GET,
    POST,
    HEAD,
    TRACE,
    OPTIONS,
    DELETE,
    CONNECT
};

struct h_body {
    int type;
    void *data;
};

struct h_header {
    char *key;
    char *value;
};

struct h_request {
    int port;
    char *url;
    char *host;
    struct h_body body;
    enum h_method method;
    struct h_header **header;
};

struct h_response {
    int port;
    char *url;
    char *host;
    struct h_body body;
    enum h_method method;
    struct h_header **header;
};

//Parse the HTTP request header information from the specified string and return the number of parsed request headers.
extern int parse_header(const char *str, struct h_header **headers);

/*Get every enum value*/
extern char *method_val(enum h_method);

#endif //C_HTTP_SERVER_HTTP_PARSE_H
