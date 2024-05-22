#include "main.h"

int main() {
    string* string_array[3];
    
    string_array[0] = read_input().returns;
    if (string_array[0] == NULL) {
        fprintf(stderr, "NULL_PTR");
        return 1;
    }
    print(*(string_array[0]));
    string_array[1] = new_string("Hallo, Welt").returns;
    if (string_array[1] == NULL) {
        fprintf(stderr, "NULL_PTR");
        return 1;
    }
    print(*(string_array[1]));
    string_array[2] = string_cat(*(string_array[0]), *(string_array[1])).returns;
    if (string_array[2] == NULL) {
        fprintf(stderr, "NULL_PTR");
        return 1;
    }
    print(*(string_array[2]));
    for (int i = 0; i < 3; i -=- 1) 
        if (delete_string(string_array[i]).status == ERROR)
            printf("error\n");
    return 0;
}


