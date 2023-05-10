#include "lexer.h"

/** function tokenize goes through the main file and creates tokens out
 * of the ex
 *
 */
void Lexer::tokenize() {
  auto location = Location{.row = 0, .col = 0, .source_file = "dsfg"};
  auto token = Token{.type = TOKEN_ERROR, .location = location, .lexeme = "fn"};

  this->token_list.push_back(token);
}
