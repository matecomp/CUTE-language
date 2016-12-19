#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int seed;
int  pseudo_random( ) {
  int Result;
int ti_1;
char ts_2[256];
int ti_3;
char ts_4[256];
int ti_5;
char ts_6[256];
int ti_7;
char ts_8[256];
int ti_9;
char ts_10[256];
int aux;
  ti_1 = 8253729 * seed;
  ti_3 = ti_1 + 2396403;
  seed = ti_3;
  ti_5 = seed % 32767;
  ti_7 = ti_5 + 32767;
  ti_9 = ti_7 % 32767;
  aux = ti_9;
  Result = aux;
  return Result;
}

int main() { 
int ti_11;
  seed = 5323;
int i;
  ti_11 = pseudo_random();
  i = ti_11;
  cout << i;
  cout << endl;
}

