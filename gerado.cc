#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int X1[25];
int  MDC( int &a, int &b ) {
  int Result;
int ti_1;
char ts_2[256];
  a = 5;
  b = 10;
  ti_1 = a * b;
  Result = ti_1;
  return Result;
}

int main() { 
int ti_3;
int tb_4;
char ts_5[256];
int tb_6;
char ts_7[256];
int tb_8;
char ts_9[256];
int i;
int j;
int result;
  i = 3;
  j = 3;
  ti_3 = MDC( i, j );
  result = ti_3;
  cout << i;
  cout << endl;
  cout << j;
  cout << endl;
  tb_4 = i == 2;
  tb_6 = i > 2;
  tb_8 = tb_4 || tb_6;
  tb_8 = !tb_8;

  if( tb_8 ) goto l_else_1;
  cout << "Ok";
  cout << endl;
  goto l_end_2;
l_else_1:;
  cout << "Not";
  cout << endl;
l_end_2:;
}

