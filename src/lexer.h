#pragma once

#include <iostream>
#include <map>
#include <ostream>
#include <string_view>
#include <vector>

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
  TOKEN_ASSIGNMENTEND, // Possibly nothing, since we don't allow this currently
  TOKEN_CONCATEQUAL,   // ++=
  TOKEN_PARENTOPEN,    // (
  TOKEN_PARENTCLOSE,   // )
  TOKEN_BRACEOPEN,     // [
  TOKEN_BRACECLOSE,    // ]
  TOKEN_BRACKETOPEN,   // {
  TOKEN_BRACKETCLOSE,  // }
  TOKEN_END,   // end     End is both a keyword and a assignment for somethings
  TOKEN_PLUS,  // +
  TOKEN_MINUS, // -
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
  TOKEN_ERROR,
} TokenType;

const static std::map<std::string, TokenType> keywords = {
    {"if", TOKEN_IF},         {"then", TOKEN_THEN}, // sgs;oifgjsgfiojsg[ij
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

typedef struct Location {
  int row;
  int col;
  std::string_view source_file;

  friend std::ostream &operator<<(std::ostream &os, const Location &l) {
    return os << "Row: " << l.row << " Col: " << l.col << " at file "
              << l.source_file << std::endl;
  }
} Location;

typedef struct Token {
  TokenType type = TOKEN_ERROR;

  Location location;

  std::string lexeme;

  friend std::ostream &operator<<(std::ostream &os, const Token &t) {
    return os << "Lexeme: " << t.lexeme << " Token Type " << t.type
              << " Location: " << t.location << std::endl;
  }
} Token;

/** Struct contains impl for what what we're trying to achieve
 *
 */
typedef struct Lexer {
  std::vector<char> data;
  std::vector<Token> token_list;

  // Construtor
  Lexer(std::vector<char> data) {
    this->data = data;
    this->token_list = std::vector<Token>();
  }

  // Main function that tokenizes
  void tokenize();
} Lexer;
