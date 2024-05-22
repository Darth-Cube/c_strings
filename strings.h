#ifndef strings
#define strings

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "c_result.h"

#define STR_MAX 2000

/**
 * @brief string structure with pointer to char array and length
 * 
 */
typedef struct string {
    char* chars;
    size_t len;
} string;

/**
 * @brief print given string to stdout with newline at the end
 * 
 * @param str string parameter
 * @return result status if printing was succsessful
 */
result print(string str);

/**
 * @brief read input from stdin and save to string
 * 
 * @return result status code and string pointer
 */
result read_input();

/**
 * @brief concat two strings and return a new string
 *  new string equals to a = "foo", b = "bar" -> "foobar"
 * @param a first string
 * @param b second string
 * @return result status code and new string
 */
result string_cat(string a, string b);

/**
 * @brief delete string type
 * 
 * @param str string pointer
 * @return result status code if str got deleted
 */
result delete_string(string* str);

/**
 * @brief checks if there are chars in the string
 * 
 * @param str string parameter
 * @return result if string was empty or not
 */
result check_string_empty(string str);

/**
 * @brief create new string from char array
 * char array needs '/0' terminator
 * @param chars pointer to char array
 * @return result new string with char array
 */
result new_string(const char* chars);

/**
 * @brief create new empty string with allocated memory for given size
 * 
 * @param str_size size parameter for malloc
 * @return result status code and new string
 */
result new_empty_string(size_t str_size);

/**
 * @brief calculate the length of given char array
 * 
 * @param chars char array
 * @return int length of char array, -1 if char array too long or faulty
 */
int get_char_len(const char* chars);

#endif