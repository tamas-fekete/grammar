#include <stdio.h>
#include "tokenizer.h"
#define MAX 5u
int isWhiteSpace(int c);
int isNumber(int c);
int getCharacter(void);

static int lexeme = 0;
static int token;
static int tokenBuffer[MAX];
static int tokenIndex = 0; // token pointer always points to an empty cell


void nextToken(void)
{
  while(isWhiteSpace(lexeme = getCharacter()));
  
  if (lexeme == ';')
  {
    token = SEMICOLON;
  }
  else if(lexeme == '*')
  {
    token = STAR;
  }
  else if(lexeme == '+')
  {
    token = PLUS;
  } 
  else if(lexeme == '(')
  {
    token = OPAREN;
  }
  else if(lexeme == ')')
  {
    token = CPAREN;
  }
  else if(isNumber(lexeme))
  {
    token = NUMBER;
  }
  else if (lexeme == EOF)
  {
    token = END_OF_FILE;
  } 
  else
  {
    token = UNKNOWN;
  }
  return;
}
int currentToken(void)
{
  return token;
}
int getToken(void)
{
  return lexeme;
}
int getCharacter(void)
{
  if(tokenIndex > 0)
  {
    return tokenBuffer[--tokenIndex];
  }
  else
  {
    return getchar();
  }
}
void ungetToken(void)
{
 if(tokenIndex < MAX)
 {
  tokenBuffer[tokenIndex++] = lexeme; 
 } 
} 
int isNumber(int c)
{
  if(c>='0' && c<='9')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int isWhiteSpace(int c)
{
  if(c == ' ' || c == '\n' ||  c == '\t' )
  {
    return 1;
  }
  else 
  {
    return 0;
  }
}
