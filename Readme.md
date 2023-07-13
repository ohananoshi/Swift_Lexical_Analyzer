### Swift Lexical Analyzer
- ### Headers
    - stdio.h
    - string.h
    - stdlib.h
    - ctype.h
    - stdint.h
    - stdbool.h
- ### Table Conventions
    - ### Columns
        - COUNTER
        - TOKENS
        - TYPE
        - VALUE
        - L_POS
        - C_POS
    - ### Types
        - KEYWORD
        - IDENTIFIER
        - SYMBOL_DELIMITER
        - MATH_OPERATOR
        - ATRIBUTION
        - LITERAL
        - CONSTANT
- ### Functions
    - add_token
    - file_to_string

- ### Functions Description

    - #### file_to_string

    ```C
    void file_to_string(FILE* file_pointer, char* absolute_path)
    ```

    It reads the file one character at a time, and concatenates them to form a string, which is tested for the types delarated by "Table Conventions".

    - ### add_token

    ```C
    void add_token(char* token_string, uint32_t token_counter, uint32_t colum_counter, uint32_t line_counter, uint8_t type, bool DEBUG_FLAG)
    ```

    Adds the token to the table by filling in the columns shown in "Table Conventions".