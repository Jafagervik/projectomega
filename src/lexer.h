#pragma once

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <map>
#include <memory>
#include <ostream>
#include <string_view>
#include <vector>
#include "pch.h"
#include "token.h"

const static std::map<std::string, TokenType> keywords = {
    {"if", TOKEN_IF},         {"then", TOKEN_THEN},
    {"while", TOKEN_WHILE},   {"elseif", TOKEN_ELSEIF},
    {"else", TOKEN_ELSE},     {"struct", TOKEN_STRUCT},
    {"enum", TOKEN_ENUM},     {"return", TOKEN_RETURN},
    {"end", TOKEN_END},       {"import", TOKEN_IMPORT},
    {"export", TOKEN_EXPORT}, {"null", TOKEN_NULL},
    {"in", TOKEN_IN},         {"throw", TOKEN_THROW},
    {"type", TOKEN_TYPE},     {"try", TOKEN_TRY},
    {"typeof", TOKEN_TYPEOF}, {"continue", TOKEN_CONTINUE},
    {"break", TOKEN_BREAK},   {"catch", TOKEN_CATCH},
    {"mut", TOKEN_MUT},       {"compiletime", TOKEN_COMPILETIME},
    {"atomic", TOKEN_ATOMIC},
};

[[maybe_unused]] const static std::array<std::string, 15>
    supported_number_datatypes = {"u8", "u16", "u32", "u64", "u128",
                                  "i8", "i16", "i32", "i64", "i128",
                                  "f8", "f16", "f32", "f64", "f128"};

/** Struct contains impl for what what we're trying to achieve
 *
 */
typedef struct Lexer {
        // TODO: Add more files when dealing with
        //
        std::string_view source_file;
        std::vector<char> data;
        std::vector<std::unique_ptr<Token>> token_list;

        u32 cursor;            // Where we're at in the iterator
        u32 beginning_of_line; // Set to 0 each \n
        u32 line;              // Incremented each \n
        std::vector<char>::iterator cursor_itr;

        // Construtor
        Lexer(char *source_file, std::vector<char> data)
            : source_file{source_file}, data{data}, cursor{0},
              beginning_of_line{0}, line{0} {
            // Alternative to cursor
            this->cursor_itr = this->data.begin();

            // TODO: Look into buffering of tokens.
            // eg. every amount of tokens, buffer and send to parser?
            this->token_list = std::vector<std::unique_ptr<Token>>();
            token_list.reserve(2000);
        }

        // Main function that tokenizes
        void tokenize();

        // ================
        // Helper methods
        // ================
        char peek();
        char peek_n_ahead(uint32_t n);

        bool match(char expected_char); // LOOKAHEAD

        void add_token(TokenType type);                     // For symbols
        void add_token(TokenType type, std::string lexeme); // for literals

        bool end_of_file();
        void advance(); // Advance iterator to next char

        // Lexer errors
        void throw_lexer_error(LEXER_ERROR error_code);

        // ===============================
        //  Methods for handling lexemes
        // ===============================
        void string_lexeme();
        void number_lexeme();
} Lexer;
