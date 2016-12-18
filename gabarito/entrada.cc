#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int  MDC( int a, int b ) {
  int Result;
int tb_1;
char ts_2[256];
int ti_3;
char ts_4[256];
int ti_5;
int saida;
  tb_1 = b == 0;
  tb_1 = !tb_1;

  if( tb_1 ) goto l_else_1;
  saida = a;
  goto l_end_2;
l_else_1:;
  ti_3 = a % b;
  ti_5 = MDC( b, ti_3 );
  saida = ti_5;
l_end_2:;
  Result = saida;
  return Result;
}

int main() { 
int ti_6;
int a;
int b;
  cout << "Programinha MDC";
  cout << endl;
  cout << "Digite o primeiro digitozinho:";
  cout << endl;
  cin >> a;
  cout << "Digite o segundo digitozinho:";
  cout << endl;
  cin >> b;
  cout << "O MDC entre ";
  cout << a;
  cout << " e ";
  cout << b;
  cout << "é: ";
  ti_6 = MDC( a, b );
  cout << ti_6;
  cout << endl;
}

