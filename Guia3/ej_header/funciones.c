#include <string.h>

int suma(int x, int y)
{
  int res;
  res = x+y;
  return res;
}

float resta(float *x, float *y)
{
  float res;
  res = *x-*y;

  return res;
}

int len_concat(char cad1[15], char *str2)
{
  int len;
  
  strcat(cad1, str2);
  len = strlen(cad1);
  return len;
}
