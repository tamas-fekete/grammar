#include <stdio.h>
#include "tokenizer.h"


void statements(void);
void expression(void);
void term(void);
void expression_prime(void);
void term_prime(void);
void factor(void);


int main(void)
{
  nextToken();
  statements();
  return 0;
}
void statements(void)
{
  //printf("statements\n");
  if(currentToken() == END_OF_FILE)
  {
    return;    
  }

  expression();
  
  if(currentToken() == SEMICOLON)
  {
      printf("%c\n", getToken());
      nextToken();
      statements();
  }
  else
  {
    printf("error: ; expected and got: %c\n", getToken());
  }
}
void expression(void)
{
  //printf("expression\n");
  term();
  expression_prime();
  return;
}
void expression_prime(void)
{
  //printf("expression_prime\n");
  if(currentToken() == PLUS )
  {
    printf("%c ", getToken());
    nextToken();
    term();
    expression_prime();
  }
}
void term(void)
{
  //printf("term\n");
  factor();
  term_prime();
}
void term_prime(void)
{
  //printf("term_prime\n");
  if(currentToken() == STAR)
  {
    printf("%c ", getToken());
    nextToken();
    factor();
    term_prime();
  }
}
void factor(void)
{
  //printf("factor\n");
  if(currentToken() == NUMBER)
  {
    printf("%c ", getToken());
    nextToken();
  }
  else if(currentToken() == OPAREN)
  {
    printf("%c ", getToken());
    nextToken();
    expression();
    if(currentToken() == CPAREN)
    {
      printf("%c ", getToken());
      nextToken();
    }
    else
    {
      printf("Error: missig close parenthesis, got: %c\n", getToken());
    }
  }
  else
  {
    printf("Error: expected number or open parenthesis, got: %c\n", getToken());
  }
  return;
}
