#include "file.h"
#include <fstream>
#include <vector>

std::vector<char> read_file(std::ifstream &file) {
  std::vector<char> payload = std::vector<char>();

  if (!file.eof() && !file.fail()) {
    file.seekg(0, std::ios_base::end);
    std::streampos fileSize = file.tellg();
    payload.resize(fileSize);

    file.seekg(0, std::ios_base::beg);
    file.read(&payload[0], fileSize);
  }

  return payload;
}
