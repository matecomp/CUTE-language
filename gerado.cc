#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int X1[126];
int X2[21];
int  MDC( int a, int b ) {
  int Result;
int ti_1;
  ti_1 = a * b;
  Result = ti_1;
  return Result;
}

int main() { 
int ti_2;
int ti_3;
int ti_4;
int tb_5;
int tb_6;
int tb_7;
int tb_8;
int tb_9;
int tb_10;
int ti_11;
int tb_12;
int tb_13;
int tb_14;
int tb_15;
int tb_16;
int tb_17;
int tb_18;
int ti_19;
int tb_20;
int ti_21;
int tb_22;
int tb_23;
int tb_24;
int tb_25;
int tb_26;
int tb_27;
int ti_28;
int ti_29;
int tb_30;
int tb_31;
int tb_32;
int tb_33;
int tb_34;
int tb_35;
int ti_36;
int tb_37;
int ti_38;
int tb_39;
int ti_40;
int ti_41;
int i;
int j;
  i = 0;
  ti_19 = 20;
l_teste_for_5:;
  tb_20 = i > ti_19;
  if( tb_20 ) goto l_fim_for_6;
  j = 0;
  ti_11 = 5;
l_teste_for_2:;
  tb_12 = j > ti_11;
  if( tb_12 ) goto l_fim_for_3;
  ti_2 = i * 6;
  ti_3 = ti_2 + j;
  tb_5 = i >= 0;
  tb_6 = i <= 20;
  tb_7 = j >= 0;
  tb_8 = j <= 5;
  tb_9 = tb_5 && tb_6;
  tb_10 = tb_7 && tb_8;
  if( tb_9&&tb_10 ) goto l_limite_array_ok_1;
  printf( "Limite de array ultrapassado: linha(%d <= %d <= %d)", 0 ,i, 20 );
  printf( " e coluna(%d <= %d <= %d)", 0 ,j, 5 );
  cout << endl;
  exit( 1 );
  l_limite_array_ok_1:;
  ti_4 = 6*i;
  ti_4 = ti_4+j;
  X1[ti_4] = ti_3;
  j = j + 1;
  goto l_teste_for_2;
l_fim_for_3:;
  tb_13 = i >= 0;
  tb_14 = i <= 20;
  tb_17 = tb_13 && tb_14;
  if( tb_17 ) goto l_limite_array_ok_4;
    printf( "Limite de array ultrapassado: %d <= %d <= %d", 0 ,i, 20 );
  cout << endl;
  exit( 1 );
  l_limite_array_ok_4:;
  X2[i] = i;
  i = i + 1;
  goto l_teste_for_5;
l_fim_for_6:;
  tb_22 = 20 >= 0;
  tb_23 = 20 <= 20;
  tb_24 = 5 >= 0;
  tb_25 = 5 <= 5;
  tb_26 = tb_22 && tb_23;
  tb_27 = tb_24 && tb_25;
  if( tb_26&&tb_27 ) goto l_limite_array_ok_7;
  printf( "Limite de array ultrapassado: linha(%d <= %d <= %d)", 0 ,20, 20 );
  printf( " e coluna(%d <= %d <= %d)", 0 ,5, 5 );
  cout << endl;
  exit( 1 );
  l_limite_array_ok_7:;
  ti_21 = 6*20;
  ti_21 = ti_21+5;
  X1[ti_21] = 15;
  i = 0;
  ti_38 = 20;
l_teste_for_11:;
  tb_39 = i > ti_38;
  if( tb_39 ) goto l_fim_for_12;
  j = 0;
  ti_36 = 5;
l_teste_for_9:;
  tb_37 = j > ti_36;
  if( tb_37 ) goto l_fim_for_10;
  tb_30 = i >= 0;
  tb_31 = i <= 20;
  tb_32 = j >= 0;
  tb_33 = j <= 5;
  tb_34 = tb_30 && tb_31;
  tb_35 = tb_32 && tb_33;
  if( tb_34&&tb_35 ) goto l_limite_array_ok_8;
  printf( "Limite de array ultrapassado: linha(%d <= %d <= %d)", 0 ,i, 20 );
  printf( " e coluna(%d <= %d <= %d)", 0 ,j, 5 );
  cout << endl;
  exit( 1 );
  l_limite_array_ok_8:;
  ti_28 = 6 * i;
  ti_28 = ti_28 + j;
  ti_29 = X1[ti_28];
  cout << ti_29;
  cout << " ";
  j = j + 1;
  goto l_teste_for_9;
l_fim_for_10:;
  cout << "";
  cout << endl;
  i = i + 1;
  goto l_teste_for_11;
l_fim_for_12:;
  ti_40 = MDC( 2, 5 );
  i = ti_40;
  cout << i;
  cout << endl;
  ti_41 = MDC( 55, 1000 );
  cout << ti_41;
  cout << endl;
}

