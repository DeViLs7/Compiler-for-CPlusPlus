#include "lexical.h"
#include<fstream>
#include<string.h>
using namespace std;


string types[6] = { "Keyowrd", "Constant", "Operator", "Separator", "Identifier", "Comparator" }, line, tmp;
Token tokens[5005];
int siz, idx, cnt_t = 0;
int main()
{
    Lexical l;
    ifstream file("Devils.txt");
    while (getline(file, line))
    {
          tmp = "";
          siz = line.length();
          idx = 0;
          while (idx < siz)
          {
                if (l.isDelimiter(line[idx]))
                {
                   if (tmp.length() != 0)
                   {
                      if (l.isKeyword(tmp))
                      {
                         cout << tmp << " is keyword\n";
                         tokens[cnt_t].lexeme = tmp;
                         tokens[cnt_t++].type = types[0];
                      }
                      else if (l.isIdentifier(tmp))
                      {
                         cout << tmp <<" is identifier\n";
                         tokens[cnt_t].lexeme = tmp;
                         tokens[cnt_t++].type = types[4];
                      }
                      else if (l.isNumber(tmp))
                      {
                         cout << tmp << " is constant\n";
                         tokens[cnt_t].lexeme = tmp;
                         tokens[cnt_t++].type = types[1];
                      }
                      else if (l.isFloatNumber(tmp))
                      {
                         cout << tmp << "is constant\n";
                         tokens[cnt_t].lexeme = tmp;
                         tokens[cnt_t++].type = types[1];
                      }
                      else
                      { 
                         cout << tmp << " isn't in language\n";
                      }
                      tmp = "";
                   }                     
                   if (l.isOperator(line[idx]))
                      if (idx + 1 < siz && line[idx] == '=' && line[idx + 1] == '=')
                      {
                         cout << "== is comparator\n";
                         tokens[cnt_t].lexeme = "==";
                         tokens[cnt_t++].type = types[5];
                         ++idx;
                      }
                      else
                         cout << line[idx] << " is operator\n";
                   else if(l.isSeparator(line[idx]))
                   {
                         cout << line[idx] << " is separator\n";
                         tokens[cnt_t].lexeme = line[idx];
                         tokens[cnt_t++].type = types[3];
                   }
                   else if(l.isComparator(line[idx]))
                   {
                         if (idx + 1 < siz && line[idx + 1] == '=')
                         {
                            cout << line[idx] << line[idx + 1] << " is comparator\n";
                            tokens[cnt_t].lexeme = line[idx] + line[idx + 1];
                            tokens[cnt_t++].type = types[5];
                            ++idx;
                         }
                         else
                         { 
                            cout << line[idx] << " is comparator\n";
                            tokens[cnt_t].lexeme = line[idx];
                            tokens[cnt_t++].type = types[5];
                         }
                   }
                   tmp = "";
                }
                else
                   tmp += line[idx];
                ++idx;
          }

    }
    return 0;
}
