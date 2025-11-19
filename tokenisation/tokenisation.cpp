#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <map>
using namespace std;

enum TokenType {
    KEYWORD, IDENTIFIER, OPERATOR, SEPARATOR, PARENTHESIS, NUMBER, UNKNOWN
};

struct Token {
    TokenType type;
    string value;
    int id;
};

class Tokenizer {
private:
    string input;
    int pos;
    vector<Token> tokens;
    map<string, int> idMap;
    int nextId;
    
    string keywords[20] = {"int", "float", "double", "char", "void", "if", 
                           "else", "while", "for", "return", "break", "continue",
                           "switch", "case", "default", "do", "const", "static",
                           "struct", "main"};
    
    char current() {
        return pos < input.length() ? input[pos] : '\0';
    }
    
    void advance() { pos++; }
    
    void skip() {
        while (isspace(current())) advance();
    }
    
    bool isKeyword(string word) {
        for (int i = 0; i < 20; i++)
            if (keywords[i] == word) return true;
        return false;
    }
    
    Token makeToken(TokenType type, string value, int id = -1) {
        Token t;
        t.type = type;
        t.value = value;
        t.id = id;
        return t;
    }
    
    void readNumber() {
        string num = "";
        while (isdigit(current()) || current() == '.') {
            num += current();
            advance();
        }
        tokens.push_back(makeToken(NUMBER, num));
    }
    
    void readWord() {
        string word = "";
        while (isalnum(current()) || current() == '_') {
            word += current();
            advance();
        }
        
        if (isKeyword(word)) {
            tokens.push_back(makeToken(KEYWORD, word));
        } else {
            if (idMap.find(word) == idMap.end()) {
                idMap[word] = nextId++;
            }
            tokens.push_back(makeToken(IDENTIFIER, word, idMap[word]));
        }
    }
    
    void readOperator() {
        string op = "";
        op += current();
        advance();
        
        char next = current();
        if ((op[0] == '=' && next == '=') || (op[0] == '!' && next == '=') ||
            (op[0] == '<' && next == '=') || (op[0] == '>' && next == '=') ||
            (op[0] == '&' && next == '&') || (op[0] == '|' && next == '|') ||
            (op[0] == '+' && next == '+') || (op[0] == '-' && next == '-') ||
            (op[0] == '+' && next == '=') || (op[0] == '-' && next == '=') ||
            (op[0] == '*' && next == '=') || (op[0] == '/' && next == '=')) {
            op += next;
            advance();
        }
        tokens.push_back(makeToken(OPERATOR, op));
    }
    
public:
    Tokenizer(string code) : input(code), pos(0), nextId(1) {}
    
    void tokenize() {
        while (current() != '\0') {
            skip();
            if (current() == '\0') break;
            
            char c = current();
            
            if (isdigit(c)) {
                readNumber();
            }
            else if (isalpha(c) || c == '_') {
                readWord();
            }
            else if (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']') {
                tokens.push_back(makeToken(PARENTHESIS, string(1, c)));
                advance();
            }
            else if (c == ';' || c == ',' || c == '.' || c == ':') {
                tokens.push_back(makeToken(SEPARATOR, string(1, c)));
                advance();
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
                     c == '=' || c == '<' || c == '>' || c == '!' || c == '&' ||
                     c == '|' || c == '^' || c == '~') {
                readOperator();
            }
            else {
                tokens.push_back(makeToken(UNKNOWN, string(1, c)));
                advance();
            }
        }
    }
    
    void print() {
        cout << "\n=== TOKENIZATION RESULT ===\n" << endl;
        cout << "Token#\tType\t\t\tValue\t\t\tID" << endl;
        cout << "----------------------------------------------------------------" << endl;
        
        string typeNames[] = {"KEYWORD", "IDENTIFIER", "OPERATOR", "SEPARATOR", 
                              "PARENTHESIS", "NUMBER", "UNKNOWN"};
        
        for (int i = 0; i < tokens.size(); i++) {
            cout << (i + 1) << "\t" << typeNames[tokens[i].type] << "\t\t";
            
            if (typeNames[tokens[i].type].length() < 8) cout << "\t";
            
            cout << tokens[i].value << "\t\t\t";
            
            if (tokens[i].type == IDENTIFIER)
                cout << "ID" << tokens[i].id;
            else
                cout << "-";
            
            cout << endl;
        }
    }
};

int main() {
    cout << "=== LEXICAL ANALYZER - TOKENIZATION ===" << endl;
    cout << "\nEnter your code string:\n" << endl;
    
    string code;
    getline(cin, code);
    
    if (code.empty()) {
        cout << "No input provided!" << endl;
        return 1;
    }
    
    Tokenizer tokenizer(code);
    tokenizer.tokenize();
    tokenizer.print();
    
    return 0;
}
