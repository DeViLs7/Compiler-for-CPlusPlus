#include "lexical.h"
#include <regex>
using namespace std;
Lexical::Lexical()
{
}
bool Lexical::isNumber(string lexeme)
{ 
     regex reg("\\d+");
     return regex_match(lexeme, reg);
}
bool Lexical::isFloatNumber(string lexeme)
{
     regex reg("\\d+.?\\d+");
     return regex_match(lexeme, reg);
}
bool Lexical::isIdentifier(string lexeme)
{
     regex reg("^[a-zA-Z]\\w{0,}");
     return regex_match(lexeme, reg);
}
bool Lexical::isKeyword(string lexeme)
{
     for (int i = 0; i < 26; ++i)
         if (lexeme == keywords[i])
            return true;
     return false;
}
bool Lexical::isOperator(char lexeme)
{
     for (int i = 0; i < operators.length(); ++i)
         if (lexeme == operators[i])
            return true;
     return false;
}
bool Lexical::isDelimiter(char lexeme)
{
     for (int i = 0; i < delimiters.length(); ++i)
         if (lexeme == delimiters[i])
            return true;
     return false;
}
bool Lexical::isSeparator(char lexeme)
{
     for (int i = 0; i < separators.length(); ++i)
         if (lexeme == separators[i])
            return true;
     return false;
}
bool Lexical::isComparator(char lexeme)
{
     for (int i = 0; i < comparators.length(); ++i)
         if (lexeme == comparators[i])
            return true;
     return false;
}
