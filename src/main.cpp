#include "file.h"
#include "lexer.h"
#include "parser.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

enum ErrorCodes { FileNotFound = -1, E = 2 };

#define SUCCESS 0

int main(int argc, char *argv[]) {
  if (argc < 2)
    std::cout << "Too few arguments\n";

  // TODO: MOVE
  // Open file

  // Get name of file you wanna run and make this do the heavy lifting
  char *filename = argv[1];
  std::ifstream file(filename, std::ios::binary);

  std::vector<char> payload;

  if (!file.eof() && !file.fail()) {
    file.seekg(0, std::ios_base::end);
    std::streampos fileSize = file.tellg();
    payload.resize(fileSize);

    file.seekg(0, std::ios_base::beg);
    file.read(&payload[0], fileSize);
  }

  std::cout << payload.size() << std::endl;

  std::for_each(payload.begin(), payload.end(),
                [](const char &c) { std::cout << c << ""; });

  // Lex
  auto lexer = Lexer(payload);

  lexer.tokenize();

  std::for_each(lexer.token_list.begin(), lexer.token_list.end(),
                [](const Token &t) { std::cout << t << ' '; });

  // Parser
  auto parser = Parser();

  file.close();

  return SUCCESS;
}
