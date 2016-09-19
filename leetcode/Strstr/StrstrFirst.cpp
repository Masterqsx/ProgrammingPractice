#include <iostream>

int m_strstr(char *s1, char *s2){
  if (!s1 || !s2)
    return 0;
  char *s1_cur = s1, *s2_begin = s2;
  while (*s1){
    while (*s1 && *s2 && *s2 == *s1){
      s2++;
      s1++;
    }
    if (*s2 == '\0')
      return 1;
    else if (*s1 == '\0')
      return 0;
    s1 = ++s1_cur;
    s2 = s2_begin;
  }
  return 0;
}

int main(int argc, char **argv){
  printf("%d\n", m_strstr(argv[1],argv[2]));
  return 0;
}
