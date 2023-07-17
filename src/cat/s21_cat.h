#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s21_cat {
  int b;
  int E;
  int n;
  int s;
  int T;
  int h;
  int v;
  int A;
} s21_cat;

void optionString(char const argv[], s21_cat* cat);
int inicial(char const argv[], s21_cat* cat);
char* addNumbPrint(s21_cat* cat, int* string, char* str, int i);
int printSqueeze(char* str);
void strPrint(char* str, s21_cat* cat);
char* readSTR(FILE* text, char* str);
void print(char const argv[], s21_cat* cat);
// int help(s21_cat* cat);
int main(int argc, char* const argv[]);

#endif  // SRC_CAT_S21_CAT_H_
