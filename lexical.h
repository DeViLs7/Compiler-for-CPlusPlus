#ifndef LEXICAL_H
#define LEXICAL_H
#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<regex>
using namespace std;
class Lexical
{
     private:
     string operators = "*/+-%=";
     string keywords[35] = { "if", "else", "do", "while", "for", "int", 
     "float", "long", "double", "char", "short", "continue", "break", "case", 
     "default", "switch", "public", "private", "class", "struct", "void", 
     "static", "typeof", "sizeof", "unsigned", "goto"};
     string delimiters = " +-*/%,;><=()[]{}";
     string separators = "()[]{},;";
     string comparators = "><";
     public:
     Lexical();
     bool isDelimiter(char lexeme);
     bool isOperator(char lexeme);
     bool isIdentifier(string lexeme);
     bool isFloatNumber(string lexeme);
     bool isNumber(string lexeme);
     bool isKeyword(string lexeme);
     bool isSeparator(char lexeme);
     bool isComparator(char lexeme);
};
class Token
{
      public:
      string lexeme, type;
};
#endif
