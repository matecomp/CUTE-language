#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int  formata( char saida[256], char a[256], char b[256] ) {
  int Result;
int tb_1;
char ts_2[256];
char ts_3[256];
char ts_4[256];
char ts_5[256];
char ts_6[256];
char ts_7[256];
char ts_8[256];
char ts_9[256];
char ts_10[256];
char ts_11[256];
char ts_12[256];
char ts_13[256];
char ts_14[256];
  tb_1 = strcmp( a, b ) > 0;
  tb_1 = !tb_1;

  if( tb_1 ) goto l_else_1;
  strncpy( ts_3, "Sr(a). ", 256 );
  strncat( ts_3, a, 256 );
ts_6[ 0 ] = ' ';
ts_6[ 1 ] = '\0';
  strncpy( ts_5, ts_3, 256 );
  strncat( ts_5, ts_6, 256 );
  strncpy( ts_7, ts_5, 256 );
  strncat( ts_7, b, 256 );
  strncpy( saida, ts_7, 256 );
  goto l_end_2;
l_else_1:;
  strncpy( ts_9, "Mr(s). ", 256 );
  strncat( ts_9, b, 256 );
  strncpy( ts_11, ts_9, 256 );
  strncat( ts_11, ", ", 256 );
  strncpy( ts_13, ts_11, 256 );
  strncat( ts_13, a, 256 );
  strncpy( saida, ts_13, 256 );
l_end_2:;
  Result = 0;
  return Result;
}

int main() { 
int ti_15;
char ts_16[256];
char ts_17[256];
int ti_18;
char ts_19[256];
char ts_20[256];
int ti_21;
char nome1[256];
char nome2[256];
char saida[256];
int i;
  cout << "Digite o seu nome: ";
  cin >> nome1;
  cout << "Digite o seu sobrenome: ";
  cin >> nome2;
  cout << "";
  cout << endl;
  cout << "Bom dia: ";
  ti_15 = formata( saida, nome1, nome2 );
  i = ti_15;
  cout << saida;
  cout << endl;
  cout << "Bom dia: ";
ts_17[ 0 ] = ' ';
ts_17[ 1 ] = '\0';
  strncpy( ts_16, ts_17, 256 );
  strncat( ts_16, nome1, 256 );
  ti_18 = formata( saida, ts_16, nome2 );
  i = ti_18;
  cout << saida;
  cout << endl;
  cout << "Bom dia: ";
ts_20[ 0 ] = ' ';
ts_20[ 1 ] = '\0';
  strncpy( ts_19, nome2, 256 );
  strncat( ts_19, ts_20, 256 );
  ti_21 = formata( saida, nome1, ts_19 );
  i = ti_21;
  cout << saida;
  cout << endl;
}

