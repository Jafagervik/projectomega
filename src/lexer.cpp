#include "lexer.h"

/** function tokenize goes through the main file and creates tokens out
 * of the ex
 *
 */
void Lexer::tokenize() {
    std::cout << "Starting tokenization ...\n";

    while (!end_of_file()) {
        const char current_byte = peek();
        switch (current_byte) {
        case '|':
            if (match('>')) {
                add_token(TOKEN_PIPE);
            } else {
                add_token(TOKEN_GREATER);
            }
            break;
        case '(':
            add_token(TOKEN_PARENTOPEN);
            break;
        case ')':
            add_token(TOKEN_PARENTCLOSE);
            break;
        case '[':
            add_token(TOKEN_BRACEOPEN);
            break;
        case ']':
            add_token(TOKEN_BRACECLOSE);
            break;
        case '{':
            add_token(TOKEN_BRACKETOPEN);
            break;
        case '}':
            add_token(TOKEN_BRACKETCLOSE);
            break;
        case ':':
            if (match(':')) {
                add_token(TOKEN_COLONCOLON);
            }

            break;
        case '/':
            // Single line comment
            if (match('/')) {
                while (peek() != '\n' && !end_of_file())
                    advance();
            } else {
                add_token(TOKEN_DIVIDE);
            }
            advance();
            break;
        case '\n': // This is what happens when we go to a new line
            add_token(TOKEN_NEWLINE);
            this->line++;
            this->beginning_of_line = 0; // This is for column to be calculated
            break;
        default: // Give an error since we could not
            throw_lexer_error(UNKNOWN_CHARACTER);
            exit(UNKNOWN_CHARACTER);
            break;
        }

        // Go to next char
        advance();
    }

    // End of file
    add_token(TOKEN_EOF);

    std::cout << "End of tokenization ...\n";
}

void Lexer::add_token(TokenType type) {
    auto location = Location{.row = this->line,
                             .col = this->cursor - this->beginning_of_line,
                             .source_file = this->source_file};

    this->token_list.emplace_back(
        std::make_unique<Token>(Token(type, location, nullptr)));
}

void Lexer::add_token(TokenType type, std::string lexeme) {
    auto location = Location{.row = this->line,
                             .col = this->cursor - this->beginning_of_line,
                             .source_file = this->source_file};

    this->token_list.emplace_back(
        std::make_unique<Token>(Token(type, location, &lexeme)));
}

char Lexer::peek() {
    if (end_of_file()) {
        return '\0';
    }
    return *this->cursor_itr;
}

// TODO: Possibly remove
char Lexer::peek_n_ahead(uint32_t n) {
    if (this->cursor_itr + n != this->data.end()) {
        return *(this->cursor_itr + n);
    }
    return '\0';
}

bool Lexer::end_of_file() { return this->cursor_itr == this->data.end(); }

void Lexer::advance() {
    this->cursor_itr++;
    this->cursor++;
}

/** function match
 *
 * Will peak ahead one and see if that char matches
 * If so it advances the token once
 *
 */
bool Lexer::match(char expected_char) {
    // If we're at the end, just stop
    if (end_of_file())
        return false;

    // TODO: This could segfault if we don't know the size of the file

    // If the next char doesn't match, we keep looking
    if (*(this->cursor_itr + 1) != expected_char)
        return false;

    // Else, we want to advance one more time since we've already looked ahead
    advance();
    return true;
}

// ===================================================
//      ERRORS
// ===================================================

// TODO: In the future, come with corrections to user?
void Lexer::throw_lexer_error(LEXER_ERROR error_code) {
    std::cerr << "Lexer error: " << error_code << " '" << *this->cursor_itr
              << "' found in line " << this->line
              << " at column: " << this->cursor - this->beginning_of_line
              << " in file " << this->source_file << std::endl;
}
