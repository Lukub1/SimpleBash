#include "s21_cat.h"

void optionString(char const argv[], s21_cat* cat) {
  argv++;
  if (strcmp("number-nonblank", argv) == 0)
    cat->b = 1;
  else if (strcmp("number", argv) == 0)
    cat->n = 1;
  else if (strcmp("squeeze-blank", argv) == 0)
    cat->s = 1;
}

int inicial(char const argv[], s21_cat* cat) {
  int x = 0, i = 0;
  if (*argv == '-') {
    argv++;
    while (*argv != ' ') {
      switch (*argv) {
        case 'b':
          cat->b = 1;
          x += 1;
          break;
        case 'e':
          cat->v = 1;
          cat->E = 1;
          x += 1;
          break;
        case 'E':
          cat->E = 1;
          cat->v = 0;
          x += 1;
          break;
        case 'n':
          cat->n = 1;
          x += 1;
          break;
        case 's':
          cat->s = 1;
          x += 1;
          break;
        case 't':
          cat->v = 1;
          cat->T = 1;
          x += 1;
          break;
        case 'T':
          cat->T = 1;
          cat->v = 0;
          x += 1;
          break;
        case 'h':
          cat->h = 1;
          x += 1;
          break;
        case 'v':
          cat->v = 1;
          x += 1;
          break;
        default:
          break;
      }
      i++;
      if (*(argv) == '-') {
        optionString(argv, cat);
        i++;
        break;
      }
      if (*(argv + 1) == '\0') break;
      argv++;
    }
  }
  if (i > 1) x = 1;
  return x;
}

char* addNumbPrint(s21_cat* cat, int* string, char* str, int i) {
  int flag = 0;
  if (cat->b == 1) {
    if (str[i+1] != -1) {
      flag = 1;
      *string += 1;
      if (str[i + 1] == '\n') {
        *string -= 1;
        flag = 0;
      }
    }
  } else if (cat->n == 1) {
    if (str[i+1] != -1) {
      flag = 1;
      *string += 1;
    }
  }
  if (flag == 1) {
     printf("%6d\t", *string);
    }
    return str;
}

int printSqueeze(char* str) {
  int i = 0;
  char string[2000] = {0};
  int count = 0;
  while (str[i] != '\xff') {
    string[count] = str[i];
    i++;
    count += 1;
    if (str[i] == '\n') {
      string[count] = str[i];
      i++;
      count += 1;
      while (str[i] == '\n') {
        if (str[i+1] == '\n') {
          i++;
        } else {
          string[count] = str[i];
          i++;
          count += 1;
        }
      }
    }
  }
  string[count] = '\xff';
  for (int i = 0; i <= count; i++) {
    str[i] = string[i];
  }
  return count;
}

void strPrint(char* str, s21_cat* cat) {
  int i = 0;
  int stringNum = 0;
  if (cat->s == 1) printSqueeze(str);
  if (cat->b == 1 || cat->n == 1) addNumbPrint(cat, &stringNum, str, i);
  while (str[i] != -1) {
    if (str[i] == '\n') {
      if (cat->E == 1) {
        printf("$\n");
      } else {
        printf("%c", str[i]);
      }
      if (cat->b == 1 || cat->n == 1) addNumbPrint(cat, &stringNum, str, i);
    } else if (str[i] == '\t') {
      if (cat->T == 1) {
        str[i] += 64;
        printf("^%c", str[i]);
      } else {
        printf("%c", str[i]);
      }
    } else if ((str[i] >= 0) && (str[i] <= 32) && cat->v == 1) {
      if (str[i] == 32) {
        printf("%c", str[i]);
      } else {
        str[i] += 64;
        printf("^%c", str[i]);
      }
    } else if ((str[i] > 32) && (str[i] < 127) && cat->v == 1) {
      printf("%c", str[i]);
    } else if ((str[i] <= -96) && (str[i] > -128) && cat->v == 1) {
      str[i] += 128 + 63;
      printf("M-^%c", str[i]);
    } else {
      printf("%c", str[i]);
    }
    i++;
  }
}

char* readSTR(FILE* text, char* str) {
  int i = 0;

  while (str[i] != -1) {
    str[i] = fgetc(text);
    if (str[i] == -1) break;
    i++;
  }
  return str;
}

void print(char const argv[], s21_cat* cat) {
  char str[2000] = {0};
  FILE* text;
  text = fopen(argv, "r");
  if (text == NULL) {
    printf("Error opening file: %s\n", argv);
  } else {
    readSTR(text, str);
    strPrint(str, cat);
  }
  fclose(text);
}

// int help(s21_cat* cat) {
//   int x = 1;
//   if (cat->h == 1) {
//     printf("cat: illegal option -- h\nusage: cat [-benstuv] [file ...]");
//     x = 0;
//   }
//   return x;
// }

int main(int argc, char* const argv[]) {
  s21_cat cat = {0, 0, 0, 0, 0, 0, 0, 0};
  int i = 1, options = 0;
  while (argv[i] != NULL) {
    options += inicial(argv[i], &cat);
    i++;
  }
  i = 1 + options;
  // i *= help(&cat);
  while (i < argc && i > 0) {
    print(argv[i], &cat);
    i++;
  }
  return 0;
}
