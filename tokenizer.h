enum tokens
{
  SEMICOLON,
  END_OF_FILE,
  PLUS,
  STAR,
  OPAREN,
  CPAREN,
  NUMBER,
  UNKNOWN
};


void nextToken(void);
int currentToken(void);
int getToken(void);
int isNumber(int c);
void ungetToken(void);
