#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int X1[25];
int  MDC( int a, int b ) {
  int Result;
int ti_1;
char ts_2[256];
  ti_1 = a * b;
  Result = ti_1;
  return Result;
}

int main() { 
int ti_3;
char ts_4[256];
int ti_5;
char ts_6[256];
int tb_7;
char ts_8[256];
int ti_9;
int tb_10;
int tb_11;
int tb_12;
int tb_13;
int tb_14;
int tb_15;
int ti_16;
int tb_17;
int tb_18;
int tb_19;
int tb_20;
int tb_21;
int tb_22;
int ti_23;
int tb_24;
int ti_25;
int tb_26;
int ti_27;
int ti_28;
int tb_29;
int tb_30;
int tb_31;
int tb_32;
int tb_33;
int tb_34;
int ti_35;
int tb_36;
int ti_37;
int tb_38;
int i;
int j;
  i = 1;
  ti_25 = 5;
l_teste_for_7:;
  tb_26 = i > ti_25;
  if( tb_26 ) goto l_fim_for_8;
  j = 1;
  ti_23 = 5;
l_teste_for_5:;
  tb_24 = j > ti_23;
  if( tb_24 ) goto l_fim_for_6;
  ti_3 = i + j;
  ti_5 = ti_3 % 2;
  tb_7 = ti_5 == 0;
  tb_7 = !tb_7;

  if( tb_7 ) goto l_else_3;
  tb_10 = i >= 1;
  tb_11 = i <= 5;
  tb_12 = j >= 1;
  tb_13 = j <= 5;
  tb_14 = tb_10 && tb_11;
  tb_15 = tb_12 && tb_13;
  if( tb_14&&tb_15 ) goto l_limite_array_ok_1;
  printf( "Limite de array ultrapassado: linha(%d <= %d <= %d)", 1 ,i, 5 );
  printf( " e coluna(%d <= %d <= %d)", 1 ,j, 5 );
  cout << endl;
  exit( 1 );
  l_limite_array_ok_1:;
  ti_9 = 5*i;
  ti_9 = ti_9+j;
  X1[ti_9] = 0;
  goto l_end_4;
l_else_3:;
  tb_17 = i >= 1;
  tb_18 = i <= 5;
  tb_19 = j >= 1;
  tb_20 = j <= 5;
  tb_21 = tb_17 && tb_18;
  tb_22 = tb_19 && tb_20;
  if( tb_21&&tb_22 ) goto l_limite_array_ok_2;
  printf( "Limite de array ultrapassado: linha(%d <= %d <= %d)", 1 ,i, 5 );
  printf( " e coluna(%d <= %d <= %d)", 1 ,j, 5 );
  cout << endl;
  exit( 1 );
  l_limite_array_ok_2:;
  ti_16 = 5*i;
  ti_16 = ti_16+j;
  X1[ti_16] = 1;
l_end_4:;
  j = j + 1;
  goto l_teste_for_5;
l_fim_for_6:;
  i = i + 1;
  goto l_teste_for_7;
l_fim_for_8:;
  i = 1;
  ti_37 = 5;
l_teste_for_12:;
  tb_38 = i > ti_37;
  if( tb_38 ) goto l_fim_for_13;
  j = 1;
  ti_35 = 5;
l_teste_for_10:;
  tb_36 = j > ti_35;
  if( tb_36 ) goto l_fim_for_11;
  tb_29 = i >= 1;
  tb_30 = i <= 5;
  tb_31 = j >= 1;
  tb_32 = j <= 5;
  tb_33 = tb_29 && tb_30;
  tb_34 = tb_31 && tb_32;
  if( tb_33&&tb_34 ) goto l_limite_array_ok_9;
  printf( "Limite de array ultrapassado: linha(%d <= %d <= %d)", 1 ,i, 5 );
  printf( " e coluna(%d <= %d <= %d)", 1 ,j, 5 );
  cout << endl;
  exit( 1 );
  l_limite_array_ok_9:;
  ti_27 = 5 * i;
  ti_27 = ti_27 + j;
  ti_28 = X1[ti_27];
  cout << ti_28;
  cout << ' ';
  j = j + 1;
  goto l_teste_for_10;
l_fim_for_11:;
  cout << "";
  cout << endl;
  i = i + 1;
  goto l_teste_for_12;
l_fim_for_13:;
}

