#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;



int main() { 
int tb_1;
int tb_2;
int tb_3;
int tb_4;
int tb_5;
int tb_6;
int ti_7;
int tb_8;
int tb_9;
int tb_10;
int tb_11;
int tb_12;
int tb_13;
int tb_14;
int ti_15;
int tb_16;
int tb_17;
char ts_18[256];
int ti_19;
int ti_20;
int ti_21;
int ti_22;
int tb_23;
int tb_24;
int i;
int matriz_1[3];
int matriz_2[3];
int lin_a;
int lin_b;
  lin_a = 3;
  lin_b = 3;
  i = 1;
  ti_7 = lin_a;
l_teste_for_2:;
  tb_8 = i > ti_7;
  if( tb_8 ) goto l_fim_for_3;
  tb_1 = i >= 1;
  tb_2 = i <= 3;
  tb_5 = tb_1 && tb_2;
  if( tb_5 ) goto l_limite_array_ok_1;
    printf( "Limite de array ultrapassado: %d <= %d <= %d", 1 ,i, 3 );
  cout << endl;
  exit( 1 );
  l_limite_array_ok_1:;
  matriz_1[i] = 1;
  i = i + 1;
  goto l_teste_for_2;
l_fim_for_3:;
  i = 1;
  ti_15 = lin_b;
l_teste_for_5:;
  tb_16 = i > ti_15;
  if( tb_16 ) goto l_fim_for_6;
  tb_9 = i >= 1;
  tb_10 = i <= 3;
  tb_13 = tb_9 && tb_10;
  if( tb_13 ) goto l_limite_array_ok_4;
    printf( "Limite de array ultrapassado: %d <= %d <= %d", 1 ,i, 3 );
  cout << endl;
  exit( 1 );
  l_limite_array_ok_4:;
  matriz_2[i] = 1;
  i = i + 1;
  goto l_teste_for_5;
l_fim_for_6:;
  ti_19 = 1;
  ti_20 = 3;
  tb_24 = false;
l_teste_for_7:;
  tb_23 = ti_19 > ti_20;
  tb_23 = tb_23 || tb_24;
  if( tb_23 ) goto l_fim_for_8;
  ti_21 = matriz_1[ti_19];
  ti_22 = matriz_2[ti_19];
  tb_24 = ti_21 == ti_22;
  tb_24 = !tb_24;
  ti_19 = ti_19 + 1;
  goto l_teste_for_7;
l_fim_for_8:;
tb_17 = !tb_24;
  tb_17 = !tb_17;

  if( tb_17 ) goto l_else_9;
  cout << "Okayy!!";
  cout << endl;
  goto l_end_10;
l_else_9:;
  cout << "Dammn!!";
  cout << endl;
l_end_10:;
}

