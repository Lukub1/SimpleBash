#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define maxtemp 200
#define maxsizetemp 1000
#define max 1000

typedef struct s21_grep {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
} s21_grep;

typedef struct templateFile {
  char template[maxtemp][maxsizetemp];
  char file[maxtemp][maxsizetemp];
  int numbFile;
  int numbTemp;
  int size;
} templateFile;

int initial(char const str[], s21_grep* grep);
int readSTR(char const* str, templateFile* tf);
char* fillSTR(FILE* text, char* str);
void emptystr(char* str);
int searchO(char* str, char* searchStr, int skip);
void flagO(char* str, int i, templateFile* tf, int grep, int numStr);
void addTEmp(templateFile* tf);
void flagL(templateFile* tf, s21_grep* grep);
int readfile(templateFile* tf, s21_grep* grep);
int readARGV(char const* str, s21_grep* grep, templateFile* tf);


#endif  // SRC_GREP_S21_GREP_H_
