/*
Lexical Analyzer

Author: Guilherme Arruda

Created in: 28/06/23
Last updated: 04/07/23

*/

//#pragma once

//=================================== HEADERS ===================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>

//=============================== MACROS =======================================

#define IDENTIFIER_MAX_LENGTH 256
#define LINE_MAX_LENGTH 300
#define KEYWORD_COUNT 4
#define SYMBOL_DELIMITER_COUNT 2
#define MATH_OPERATOR_COUNT 4
#define ATRIBUTION_CHAR_COUNT (1)
//#define DEBUG_FLAG 1

//============================= CONVENTIONS ==================================

enum columns{
    COUNTER = 0,
    TOKENS,
    TYPE,
    VALUE,
    L_POS,
    C_POS

};

enum TYPES{
    KEYWORD = C_POS + 1,
    IDENTIFIER,
    SYMBOL_DELIMITER,
    MATH_OPERATOR,
    ATRIBUTION,
    LITERAL,
    CONSTANT
};

char* KEYWORDS[] = {
    "let",
    "var",
    "if",
    "else"
};

char* SYMBOLS_DELIMITERS[] = {
    "(",
    ")"
};

char* MATH_OPERATORS[] = {
    "+",
    "-",
    "/",
    "*"
};

char* ATRIBUTION_CHAR[] = {
    "="
};

int DEBUG_FLAG = 1;

//=================================== FUNCTIONS =======================================

void add_token(char* token_string, uint32_t token_counter, uint32_t colum_counter, uint32_t line_counter, uint8_t type, bool DEBUG_FLAG){
    char** table_line = (char**)calloc(6, sizeof(char*));
    for(uint8_t i = 0; i < 6; i++){
        table_line[i] = (char*)calloc(IDENTIFIER_MAX_LENGTH, sizeof(char));
    }

    if(DEBUG_FLAG) printf("\n");

    sprintf(table_line[COUNTER], "%d", token_counter);

    if(DEBUG_FLAG){
        printf("%d - counter: %s ",token_counter, table_line[COUNTER]);
        system("pause");
    }

    sprintf(table_line[TOKENS], "%s", token_string);

    if(DEBUG_FLAG){
       printf("%d - token: %s ",token_counter, table_line[TOKENS]);
        system("pause");
    }

    switch (type){

        case KEYWORD:
        {
            sprintf(table_line[TYPE], "KEYWORD");
            sprintf(table_line[VALUE], "KEYWORD");

            if(DEBUG_FLAG){
                printf("%d - type: %s ",token_counter, table_line[TYPE]);
                system("pause");
                printf("%d - value: %s ",token_counter, table_line[VALUE]);
                system("pause");
            }

            break;
        }
        case IDENTIFIER:
        {
            sprintf(table_line[TYPE], "IDENTIFIER");
            sprintf(table_line[VALUE], "%s", token_string);

            if(DEBUG_FLAG){
                printf("%d - type: %s ",token_counter, table_line[TYPE]);
                system("pause");
                printf("%d - value: %s ",token_counter, table_line[VALUE]);
                system("pause");
            }

            break;
        }
        case SYMBOL_DELIMITER:
        {
            sprintf(table_line[TYPE], "SYMBOL_DELIMITER");
            sprintf(table_line[VALUE], "SYMBOL_DELIMITER_%s", token_string);

            if(DEBUG_FLAG){
                printf("%d - type: %s ",token_counter, table_line[TYPE]);
                system("pause");
                printf("%d - value: %s ",token_counter, table_line[VALUE]);
                system("pause");
            }

            break;
        }
        case MATH_OPERATOR:
        {
            sprintf(table_line[TYPE], "MATH_OPERATOR");
            sprintf(table_line[VALUE], "MATH_OPERATOR_%s", token_string);

            if(DEBUG_FLAG){
                printf("%d - type: %s ",token_counter, table_line[TYPE]);
                system("pause");
                printf("%d - value: %s ",token_counter, table_line[VALUE]);
                system("pause");
            }

            break;
        }
        case ATRIBUTION:
        {
            sprintf(table_line[TYPE], "ATTRIBUTOR");
            sprintf(table_line[VALUE], "ATTRIBUTOR_%s", token_string);

            if(DEBUG_FLAG){
                printf("%d - type: %s ",token_counter, table_line[TYPE]);
                system("pause");
                printf("%d - value: %s ",token_counter, table_line[VALUE]);
                system("pause");
            }

            break;
        }
        case LITERAL:
        {
            sprintf(table_line[TYPE], "LITERAL");
            sprintf(table_line[VALUE], "%s", token_string);

            if(DEBUG_FLAG){
                printf("%d - type: %s ",token_counter, table_line[TYPE]);
                system("pause");
                printf("%d - value: %s ",token_counter, table_line[VALUE]);
                system("pause");
            }

            break;
        }
        case CONSTANT:
        {
            sprintf(table_line[TYPE], "CONSTANT");
            sprintf(table_line[VALUE], "%s", token_string);

            if(DEBUG_FLAG){
                printf("%d - type: %s ",token_counter, table_line[TYPE]);
                system("pause");
                printf("%d - value: %s ",token_counter, table_line[VALUE]);
                system("pause");
            }

            break;
        }

        default:

            fprintf(stderr, "TYPE not match.");

    }

    sprintf(table_line[L_POS], "%d", line_counter);

    if(DEBUG_FLAG){
        printf("%d - LPOS: %s ",token_counter, table_line[L_POS]);
        system("pause");
    }

    sprintf(table_line[C_POS], "%d", colum_counter - strlen(token_string)+1);

    if(DEBUG_FLAG){
        printf("%d - CPOS: %s ",token_counter, table_line[C_POS]);
        system("pause");
    }

    //return table_line;

}//end add token function

void file_to_string(FILE* file_pointer, char* absolute_path){
    file_pointer = fopen(absolute_path, "r");

    char** table[15];
    char* str_buffer = (char*)calloc(1, sizeof(char));

    char atual_char, last_char;
    uint32_t token_counter = 0, line_counter = 1, c_counter = 1, aspa_counter = 0;

    bool keyword_flag = 0, symb_delim_flag = 0, math_op_flag = 0, atribution_flag = 0;

    while((atual_char = fgetc(file_pointer)) != EOF){
        c_counter = 1;
        //last_char = atual_char;

        for(uint32_t i = 0; atual_char != '\n'; c_counter++){

            if(atual_char == '"') aspa_counter++;
            last_char = atual_char;
            atual_char = fgetc(file_pointer);

            printf("last char: %c   atual char: %c\n", last_char, atual_char);

            //if(last_char != ' '){
            //    str_buffer[i] = last_char;
            //    i++;
            //    str_buffer[i] = '\0';
            //}
            if(aspa_counter == 0){
                if(last_char != ' '){
                    str_buffer[i] = last_char;
                    i++;
                    str_buffer[i] = '\0';
                }
            }else{
                str_buffer[i] = last_char;
                i++;
                str_buffer[i] = '\0';
            }

            printf("-> %s \n", str_buffer);
            system("pause");
            if(aspa_counter == 0){

                for(uint8_t j = 0; j < KEYWORD_COUNT; j++){
                    if(strcmp(str_buffer, KEYWORDS[j]) == 0){
                        keyword_flag = 1;
                        printf("KEY : %s ", KEYWORDS[j]);
                        system("pause");
                    }
                }
                for(uint8_t j = 0; j < SYMBOL_DELIMITER_COUNT; j++){
                    if(strcmp(str_buffer, SYMBOLS_DELIMITERS[j]) == 0){
                        symb_delim_flag = 1;
                        printf("SYMBOL : %s ", SYMBOLS_DELIMITERS[j]);
                        system("pause");
                    }
                }
                for(uint8_t j = 0; j < MATH_OPERATOR_COUNT; j++){
                    if(strcmp(str_buffer, MATH_OPERATORS[j]) == 0){
                        math_op_flag = 1;
                        printf("OPERATOR : %s ", MATH_OPERATORS[j]);
                        system("pause");
                    }
                }
                for(uint8_t j = 0; j < ATRIBUTION_CHAR_COUNT; j++){
                    if(strcmp(str_buffer, ATRIBUTION_CHAR[j]) == 0){
                        atribution_flag = 1;
                        printf("ATTRIBUTOR : %s ", ATRIBUTION_CHAR[j]);
                        system("pause");
                    }
                }
                //identifier
                if((keyword_flag == 0 && symb_delim_flag == 0 && math_op_flag == 0 && atribution_flag == 0) && (atual_char == '(' || atual_char == ' ' || atual_char == '\n')){
                    if(isdigit(last_char)){
                        token_counter++;
                        i = 0;
                        add_token(str_buffer, token_counter, c_counter, line_counter, CONSTANT, DEBUG_FLAG);
                        str_buffer[i] = '\0';
                   }else{
                        token_counter++;
                        i = 0;
                        add_token(str_buffer, token_counter, c_counter, line_counter, IDENTIFIER, DEBUG_FLAG);
                        str_buffer[i] = '\0';
                        }
                }
                //keyword
                if(keyword_flag == 1 && atual_char == ' '){
                    keyword_flag = 0;
                    token_counter++;
                    i = 0;
                    add_token(str_buffer, token_counter, c_counter, line_counter, KEYWORD, DEBUG_FLAG);
                    str_buffer[i] = '\0';
                }
                //symbol
                if(symb_delim_flag == 1){
                    symb_delim_flag = 0;
                    token_counter++;
                    i = 0;
                    add_token(str_buffer, token_counter, c_counter, line_counter, SYMBOL_DELIMITER, DEBUG_FLAG);
                    str_buffer[i] = '\0';
                }
                //math operator
                if(math_op_flag == 1){
                    math_op_flag = 0;
                    token_counter++;
                    i = 0;
                    add_token(str_buffer, token_counter, c_counter, line_counter, MATH_OPERATOR, DEBUG_FLAG);
                    str_buffer[i] = '\0';
                }
                //atribution
                if(atribution_flag == 1){
                    atribution_flag = 0;
                    token_counter++;
                    i = 0;
                    add_token(str_buffer, token_counter, c_counter, line_counter, ATRIBUTION, DEBUG_FLAG);
                    str_buffer[i] = '\0';
                }
            }    ///*
            //literal
            if(aspa_counter == 2){
                aspa_counter = 0;
                token_counter++;
                add_token(str_buffer, token_counter, c_counter, line_counter, LITERAL, DEBUG_FLAG);
                str_buffer[i] = '\0';
            }

        }//end for
    }//end while

}//end function


//exemplos de alvos


//let nome = "John"
//print("Hello, \(nome)! Welcome to Swift!")

/*

counter  |    tokens     |    type     |    value    |  L. POS  |  C. POS
1             let           KEYWORD       KEYWORD          1          1
2             nome         identifier       nome           1          5
3              =            Symbol         Symbol          1         10
4            "John"         Literal        "John"          1         12

*/

