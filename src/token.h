#pragma once

#include "pch.h"
#include <iostream>

/** TokenType contains all tokens that will be used
 *
 * in this project
 */
typedef enum {
    TOKEN_INTEGER = 0,        // 4
    TOKEN_FLOAT,              // 3.23
    TOKEN_STRING,             // "sfdg"
    TOKEN_CHAR,               // 'c'
    TOKEN_IDENTIFIER,         // name of function or variable _abcDEF123
    TOKEN_BOOL,               // true
    TOKEN_POINTER,            // Pointer[]
    TOKEN_ARROW,              // -> For starting the block
    TOKEN_COLON,              // : for return values
    TOKEN_EQUAL,              // =
    TOKEN_PLUSEQUAL,          // +=
    TOKEN_MINUSEQUAL,         // -=
    TOKEN_ASTERISKEQUAL,      // *=
    TOKEN_DIVIDEEQUAL,        // /=
    TOKEN_MODEQUAL,           // %=
    TOKEN_BITANDEQUAL,        // &=
    TOKEN_BITNOTEQUAL,        // ~=
    TOKEN_BITOREQUAL,         // |=
    TOKEN_BITXOREQUAL,        // ^
    TOKEN_BITSHIFTLEFTEQUAL,  // <<=
    TOKEN_BITSHIFTRIGHTEQUAL, // >>=
    TOKEN_ASSIGNMENTEND,      // Possibly nothing, since we don't allow this
    TOKEN_CONCATEQUAL,        // ++=
    TOKEN_PARENTOPEN,         // (
    TOKEN_PARENTCLOSE,        // )
    TOKEN_BRACEOPEN,          // [
    TOKEN_BRACECLOSE,         // ]
    TOKEN_BRACKETOPEN,        // {
    TOKEN_BRACKETCLOSE,       // }
    TOKEN_END,  // end     End is both a keyword and a assignment for somethings
    TOKEN_PLUS, // +
    TOKEN_MINUS,         // -
    TOKEN_ASTERISK,      // *  multiply or dereferencing
    TOKEN_DIVIDE,        // /
    TOKEN_MODULO,        // %
    TOKEN_POW,           // ** ,  FIXME: Could be tricky with pointers
    TOKEN_BITAND,        // &
    TOKEN_BITNOT,        // ~
    TOKEN_BITOR,         // |
    TOKEN_BITXOR,        // ^
    TOKEN_BITSHIFTLEFT,  // <<
    TOKEN_BITSHIFTRIGHT, // >>
    TOKEN_AND,           // and, or, not is operators here
    TOKEN_OR,            // or
    TOKEN_NOT,           // not
    TOKEN_GREATER,       // >
    TOKEN_LESS,          // <
    TOKEN_NOTEQUAL,      // !=
    TOKEN_GREATEREQUAL,  // >=
    TOKEN_LESSEQUAL,     // <=
    TOKEN_QUOTE,         // '
    TOKEN_DOUBLEQUOTE,   // "
    TOKEN_PIPEGREATER,   // |>
    TOKEN_COLONCOLON,    //   ::
    TOKEN_EQUALARROW,    //   =>
    TOKEN_DOTDOT,        // .. range
    TOKEN_DOTDOTEQUAL,   // ..= inclusive range
    TOKEN_PLUSPLUS,      // ++ list and string concat
    TOKEN_NEWLINE,       // \n
    TOKEN_EOF,           // EOF
    TOKEN_PIPE,          // |
    TOKEN_ANDPERCEN,     // &  Can both be for bit logic and references
    TOKEN_UNKNOWN,       // ???
    TOKEN_COMMA,         // ,
    TOKEN_ATSIGN,        // @ for builtins? hashtags??
    TOKEN_UNDERSCORE,    // _ for patternmatching
    TOKEN_NULL,          // null  DO WE WANT ?
    TOKEN_IF,            // if
    TOKEN_ELSEIF,        // elseif
    TOKEN_ELSE,          // else
    TOKEN_THEN,          // then
    TOKEN_WHILE,         // while
    TOKEN_FOR,           // for
    TOKEN_MUT,           // mut
    TOKEN_BREAK,         // break
    TOKEN_MATCH,         // match
    TOKEN_CONTINUE,      // continue
    TOKEN_RETURN,        // return
    TOKEN_THROW,         // throw
    TOKEN_TRY,           // try
    TOKEN_CATCH,         // catch
    TOKEN_IMPORT,        // import
    TOKEN_EXPORT,        // export
    TOKEN_PUBLIC,        // pub or public
    TOKEN_TYPE,          // type
    TOKEN_INLINE,        // inline
    TOKEN_TYPEOF,        // typeof
    TOKEN_ENUM,          // enum
    TOKEN_STRUCT,        // struct
    TOKEN_ATOMIC,        // atomic before type marks it as an atomic!
    TOKEN_COMPILETIME,   // Compiletime variables!
    TOKEN_IN,            // in   TODO: Find out if we actually want this
} TokenType;

static const std::string nameTT[] = {
    "TOKEN_INTEGER",
    "TOKEN_FLOAT",
    "TOKEN_STRING",
    "TOKEN_CHAR",
    "TOKEN_IDENTIFIER",
    "TOKEN_BOOL",
    "TOKEN_POINTER",
    "TOKEN_ARROW",
    "TOKEN_COLON",
    "TOKEN_EQUAL",
    "TOKEN_PLUSEQUAL",
    "TOKEN_MINUSEQUAL",
    "TOKEN_ASTERISKEQUAL",
    "TOKEN_DIVIDEEQUAL",
    "TOKEN_MODEQUAL",
    "TOKEN_BITANDEQUAL",
    "TOKEN_BITNOTEQUAL",
    "TOKEN_BITOREQUAL",
    "TOKEN_BITXOREQUAL",
    "TOKEN_BITSHIFTLEFTEQUAL",
    "TOKEN_BITSHIFTRIGHTEQUAL",
    "TOKEN_ASSIGNMENTEND",
    "TOKEN_CONCATEQUAL",
    "TOKEN_PARENTOPEN",
    "TOKEN_PARENTCLOSE",
    "TOKEN_BRACEOPEN",
    "TOKEN_BRACECLOSE",
    "TOKEN_BRACKETOPEN",
    "TOKEN_BRACKETCLOSE",
    "TOKEN_END",
    "TOKEN_PLUS",
    "TOKEN_MINUS",
    "TOKEN_ASTERISK",
    "TOKEN_DIVIDE",
    "TOKEN_MODULO",
    "TOKEN_POW",
    "TOKEN_BITAND",
    "TOKEN_BITNOT",
    "TOKEN_BITOR",
    "TOKEN_BITXOR",
    "TOKEN_BITSHIFTLEFT",
    "TOKEN_BITSHIFTRIGHT",
    "TOKEN_AND",
    "TOKEN_OR",
    "TOKEN_NOT",
    "TOKEN_GREATER",
    "TOKEN_LESS",
    "TOKEN_NOTEQUAL",
    "TOKEN_GREATEREQUAL",
    "TOKEN_LESSEQUAL",
    "TOKEN_QUOTE",
    "TOKEN_DOUBLEQUOTE",
    "TOKEN_PIPEGREATER",
    "TOKEN_COLONCOLON",
    "TOKEN_EQUALARROW",
    "TOKEN_DOTDOT",
    "TOKEN_DOTDOTEQUAL",
    "TOKEN_PLUSPLUS",
    "TOKEN_NEWLINE",
    "TOKEN_EOF",
    "TOKEN_PIPE",
    "TOKEN_ANDPERCEN",
    "TOKEN_UNKNOWN",
    "TOKEN_COMMA",
    "TOKEN_ATSIGN",
    "TOKEN_UNDERSCORE",
    "TOKEN_NULL",
    "TOKEN_IF",
    "TOKEN_ELSEIF",
    "TOKEN_ELSE",
    "TOKEN_THEN",
    "TOKEN_WHILE",
    "TOKEN_FOR",
    "TOKEN_MUT",
    "TOKEN_BREAK",
    "TOKEN_MATCH",
    "TOKEN_CONTINUE",
    "TOKEN_RETURN",
    "TOKEN_THROW",
    "TOKEN_TRY",
    "TOKEN_CATCH",
    "TOKEN_IMPORT",
    "TOKEN_EXPORT",
    "TOKEN_PUBLIC",
    "TOKEN_TYPE",
    "TOKEN_INLINE",
    "TOKEN_TYPEOF",
    "TOKEN_ENUM",
    "TOKEN_STRUCT",
    "TOKEN_ATOMIC",
    "TOKEN_COMPILETIME",
    "TOKEN_IN",
};

typedef enum LEXER_ERROR {
    UNTERMINATED_STRING = 1,
    UNKNOWN_CHARACTER
} LEXER_ERROR;

typedef struct Location {
        uint32_t row;
        uint32_t col;
        std::string_view source_file;

        friend std::ostream &operator<<(std::ostream &os, const Location &l) {
            return os << "Row: " << l.row << " Col: " << l.col << " at file "
                      << l.source_file << '\n';
        }
} Location;

typedef struct Token {
        TokenType type;

        Location location;

        std::string *lexeme;

        Token(TokenType type, Location location, std::string *lexeme = nullptr)
            : type{type}, location{location}, lexeme{lexeme} {}

        /// Copy constructor for emplace_back
        Token(const Token &other)
            : type{other.type}, location{other.location}, lexeme{other.lexeme} {
        }

        friend std::ostream &operator<<(std::ostream &os, const Token &t) {
            os << "Token Type " << nameTT[t.type];

            // If we dont have text we dont output it, just the type
            if (t.lexeme == nullptr) {
                return os << " Location: " << t.location << '\n';
            }
            return os << " Lexeme: " << t.lexeme << " Location: " << t.location
                      << '\n';
        }
} Token;
