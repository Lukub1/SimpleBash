#include "s21_grep.h"
int initial(char const str[], s21_grep* grep) {
  int x = 1;
  while (*str != 0) {
    switch (*str) {
      case 'e':
        grep->e = 1;
        x += 1;
        break;
      case 'i':
        grep->i = 1;
        x += 1;
        break;
      case 'v':
        grep->v = 1;
        x += 1;
        break;
      case 'c':
        grep->c = 1;
        x += 1;
        break;
      case 'l':
        grep->l = 1;
        x += 1;
        break;
      case 'n':
        grep->n = 1;
        x += 1;
        break;
      case 'h':
        grep->h = 1;
        x += 1;
        break;
      case 's':
        grep->s = 1;
        x += 1;
        break;
      case 'f':
        grep->f = 1;
        x += 1;
        break;
      case 'o':
        grep->o = 1;
        x += 1;
        break;
      default:
        break;
    }
    str++;
  }
  if (x > 1) x = 1;
  return x;
}

int readSTR(char const* str, templateFile* tf) {
  int count = 0;
  while (*str != 0) {
    if (*str == '.') {
      int i = 0;
      while (count != i) {
        tf->file[tf->numbFile][i] = tf->template[tf->numbTemp][i];
        tf->template[tf->numbTemp][i] = '\0';
        i++;
      }
      while (*str != 0) {
        tf->file[tf->numbFile][count] = *str;
        count += 1;
        str++;
      }
      tf->numbFile += 1;
    } else {
      tf->template[tf->numbTemp][tf->size] = *str;
      tf->size += 1;
      str++;
      count += 1;
    }
  }
  tf->size = 0;
  if (tf->file[0][0] == '\0') {
    count = 1;
    tf->numbTemp += 1;
  } else {
    count = 0;
  }
  return count;
}

char* fillSTR(FILE* text, char* str) {
  int i = 0;
  while (str[i] != '\n') {
    str[i] = fgetc(text);
    if (str[i] == '\n' || str[i] == '\0' || str[i] == '\xff') break;
    i++;
  }
  return str;
}

void emptystr(char* str) {
  int i = strlen(str);
  for (; i > 0; i--) {
    *str = '\0';
    str++;
  }
}

int searchO(char* str, char* searchStr, int skip) {
  int flg = 0;
  if (skip != 0) {
    str += skip;
  }
  int count = 0;
  while (*str != '\0') {
    if (*str == *searchStr) {
      int countg = 0;
      while (*searchStr != '\0') {
        if (*str == *searchStr) {
          str++;
          searchStr++;
          countg++;
        } else {
          break;
        }
      }
      if (*searchStr != '\0') {
        count++;
        searchStr -= countg;
      }
    }
    if (*searchStr == '\0') {
      flg = 1;
      break;
    }
    str++;
    count++;
  }
  if (flg != 1) count = 0;
  return count;
}

void flagO(char* str, int i, templateFile* tf, int grep, int numStr) {
  int skip = 0;
  while (*str != '\0') {
    int count = searchO(str, tf->template[i], skip);
    if (count == 0) {
      break;
    }
    skip += count;
    int o = strlen(tf->template[i]);
    if (grep == 1) {
        printf("%d:", numStr);
      }
    for (; o != 0; skip++) {
      printf("%c", str[skip]);
      o--;
    }
    printf("\n");
  }
}

void addTEmp(templateFile* tf) {
  FILE* file;
  file = fopen(tf->file[0], "r");
  if (file == NULL) {
    printf("Error opening file: %s\n", tf->file[0]);
  } else {
    while (!feof(file)) {
      char c[max] = {'\0'};
      fillSTR(file, c);
      if (c[0] == '\xff') break;
      for (int i = 0; i < (int)strlen(c); i++) {
        if (c[i] == '\xff') break;
        tf->template[tf->numbTemp][i] = c[i];
      }
      tf->numbTemp += 1;
    }
  }
}

void flagL(templateFile* tf, s21_grep* grep) {
  int i = 0;
  regmatch_t pmatch[1];
  regex_t reg;
  const char* pattern = tf->template[i];
  int cflags = (grep->i == 1) ? REG_ICASE : REG_NOSUB;
  regcomp(&reg, pattern, cflags);
  while (i != tf->numbFile) {
    int search = regexec(&reg, tf->file[i], 1, pmatch, 0);
    if (search == 0) {
      if (grep->c != 1) {
        printf("%s\n", tf->file[i]);
      }
      if (grep->c == 1) {
        if (tf->numbFile > 1) {
          printf("%s:1\n", tf->file[i]);
          printf("%s\n", tf->file[i]);
        } else {
          printf("1\n");
          printf("%s\n", tf->file[i]);
        }
      }
    }
    i++;
  }
  regfree(&reg);
}

int readfile(templateFile* tf, s21_grep* grep) {
  int count = 0;
  int numfi = 0;
  if (grep->f == 1) numfi = 1;
  for (; numfi != tf->numbFile; numfi++) {
    FILE* file;
    file = fopen(tf->file[numfi], "r");
    char c[max] = {'\0'};
    if (file == NULL) {
      if (grep->s == 1) continue;
      printf("Error opening file: %s\n", tf->file[numfi]);
    } else {
      if (grep->l == 1 && (grep->v == 1)) {
        printf("%s\n", tf->file[numfi]);
      } else {
        int numbStr = 1;
        int i = 0;
        while (!feof(file)) {
          fillSTR(file, c);
          if (*c == '\xff') break;
          if (*c != '\0') {
            while (tf->numbTemp != i) {
              int search = 0;
              regmatch_t pmatch[1];
              regex_t reg;
              const char* pattern = tf->template[i];
              int cflags = (grep->i == 1) ? REG_ICASE : REG_NOSUB;
              regcomp(&reg, pattern, cflags);
              search = regexec(&reg, c, 1, pmatch, 0);
              regfree(&reg);
              if (search == 0 && tf->numbFile > 1 && grep->h == 0)
                printf("%s:", tf->file[numfi]);
              if (search == 0 && grep->v != 1) {
                if (grep->c == 1) {
                  count++;
                  break;
                }
                if (grep->n == 1&& grep->o != 1) {
                  printf("%d:", numbStr);
                }
                if (grep->o == 1) {
                  flagO(c, i, tf, grep->n, numbStr);
                } else {
                  printf("%s", c);
                }
              }
              if (search == 1 && grep->v == 1) {
                if (grep->c == 1) {
                  count++;
                  break;
                }
                if (grep->n == 1) {
                  printf("%d:", numbStr);
                }
                if (grep->f != 1) {
                  printf("%s", c);
                } else {
                  break;
                }
              }
              i++;
            }
          }
          numbStr += 1;
          i = 0;
          emptystr(c);
        }
        if (grep->c == 1) printf("%d\n", count);
      }
    }
    fclose(file);
  }
  return count;
}

int readARGV(char const* str, s21_grep* grep, templateFile* tf) {
  int x = 0;
  if (*str == '-') {
    str++;
    x = initial(str, grep);
  } else {
    x = readSTR(str, tf);
  }
  return x;
}

int main(int argc, char* const argv[]) {
  s21_grep grep = {0};
  templateFile tf = {0};
  int i = 1;
  while (i != argc) {
    readARGV(argv[i], &grep, &tf);
    i++;
  }
  if (grep.l == 1) {
    flagL(&tf, &grep);
  }
  if (grep.f == 1) {
    addTEmp(&tf);
    grep.h = 1;
  }
  if ((grep.c == 0 || grep.e == 0 || grep.i == 0 || grep.l == 0 ||
       grep.n == 0 || grep.o == 0 || grep.s == 0 || grep.v == 0) &&
      tf.numbTemp < 0)
    grep.h = 1;
  if (grep.l != 1) {
    readfile(&tf, &grep);
  }
  return 0;
}
