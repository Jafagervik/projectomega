#include "constants.h"
#include "file.h"
#include "lexer.h"
#include "parser.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

typedef enum ErrorCodes {
  FileNotFound = -1,
  EndOfFile = 2,
  TokenError,
} ErrorCodes;

int main(int argc, char *argv[]) {
  if (argc < 2)
    std::cout << "Too few arguments\n";

  const std::vector<std::string_view> args(argv + 1, argv + argc);

  for (const auto &option : args) {
    if (option == "--help" || option == "-h")
      std::cout << MENU;
  }
  // TODO: MOVE

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
  auto lexer = Lexer(filename, payload);

  lexer.tokenize();

  std::cout << lexer.token_list.size() << std::endl;

  // TODO: Tokenlist should be turned into iterator

  std::for_each(lexer.token_list.begin(), lexer.token_list.end(),
                [](const auto &t) { std::cout << *t << ' '; });

  // Parser
  // auto parser = Parser();

  file.close();

  return 0;
}
