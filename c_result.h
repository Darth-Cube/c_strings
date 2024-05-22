#ifndef c_result
#define c_result

/**
 * @brief status code if error was set or not
 * 
 */
typedef enum status {
    OK,
    ERROR
} status;

/**
 * @brief enum for error types
 * 
 */
typedef enum ERROR_TYPE {
    PTR_ERROR=0,
    VAR_USED,
    CHAR_ARRAY_TO_LARGE,
    INPUT_ERROR,
    DEFAULT=99
} ERROR_TYPE;

/**
 * @brief structure to wrap status code, potential error type and data return
 * returns may be NULL dependant on function implementation
 */
typedef struct result {
    status status;
    ERROR_TYPE type;
    void* returns;
} result;

#endif