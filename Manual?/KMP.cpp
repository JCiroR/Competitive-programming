#include <cstdio>
#include <cstring>
#include <string>

const int MAX_N = 100010;

string T, P; // T = text, P = pattern
//b[i] = lenght of longest prefix of P, which is also a proper suffix of P[0..I]
int b[MAX_N], n, m; // b = back table, n = length of T, m = length of P

void kmpPreprocess() {
  int i = 0, j = -1; b[0] = -1;
  // pre-process the pattern string P
  while (i < m) {
    // if different, reset j using b
    while (j >= 0 && P[i] != P[j]) j = b[j];
    // if same, advance both pointers
    i++; j++; 
    b[i] = j; 
  } 
}

void kmpSearch() {
  int i = 0, j = 0; // starting values
  // search through string T
  while (i < n) { 
    // if different, reset j using b
    while (j >= 0 && T[i] != P[j]) j = b[j]; 
    // if same, advance both pointers
    i++; j++; 
    // a match found when j == m
    if (j == m) { 
      printf("P is found at index %d in T\n", i - j);
      // prepare j for the next possible match
      j = b[j]; 
    } 
  } 
}