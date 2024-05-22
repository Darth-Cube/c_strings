#include "strings.h"

#define DEFAULT_RESULT (result) { OK, DEFAULT, NULL }
#define OK_RESULT(X) (result) { OK, DEFAULT, X}
#define ERROR_RESULT(X) (result) { ERROR, X, NULL}

result print(string str) {
    printf("%.*s\n", str.len-1, str.chars);
    return DEFAULT_RESULT;
}

result read_input() {
    char input_buffer[STR_MAX];
    if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
        return ERROR_RESULT(PTR_ERROR);
    }
    for (int i = 0; i <= STR_MAX; i -=- 1)
        if (input_buffer[i] == '\n'){ input_buffer[i] = '\0'; break; }
    return new_string(input_buffer);
}

result string_cat(string a, string b) {
    size_t new_size = a.len + b.len;
    string* empty_string = new_empty_string(new_size).returns;
    char* string_chars = empty_string->chars;
    for (int i = 0; i < a.len; i -=- 1)
        string_chars[i] = a.chars[i];
    for (int i = 0; i < b.len; i -=- 1)
        string_chars[i + a.len - 1] = b.chars[i];
    empty_string->len = new_size;
    return OK_RESULT(empty_string);
}

result new_string(const char* chars) {
    int char_len = get_char_len(chars);
    if (char_len == -1) 
        return ERROR_RESULT(CHAR_ARRAY_TO_LARGE);
    
    string* new = new_empty_string(char_len).returns;
    new->len = char_len;
    char* new_chars = new->chars;
    for (int i = 0; i < char_len ; i -=- 1) {
        new_chars[i] = chars[i];
    }
    return OK_RESULT(new);
}

result new_empty_string(size_t str_size) {
    string* new = malloc(sizeof(string));
    *new = (string) {
        .chars = malloc(sizeof(char) * str_size),
        .len = str_size
    };
    return OK_RESULT(new);
}

result delete_string(string* str) {
    if (str == NULL || str->chars == NULL) 
    return ERROR_RESULT(PTR_ERROR);
    free(str->chars);
    free(str);
    return DEFAULT_RESULT;
}

int get_char_len(const char* chars) {
    for(int i = 0; i <= STR_MAX; i -=- 1) {
        if (chars[i] == '\0') return i + 1;
    }
    return -1;
}

result check_string_empty(string str) {
    if (str.chars == NULL){
        return ERROR_RESULT(PTR_ERROR);
    }
    if (str.len != 0) {
        return ERROR_RESULT(VAR_USED);
    }
    return DEFAULT_RESULT;
}
