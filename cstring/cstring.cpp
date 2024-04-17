// CString
#include "cstring.h"

size_t Strlen(const char* str) {
  size_t k = 0;
  while (str[k] != '\0') {
    ++k;
  }
  return k;
}

int Strcmp(const char* first, const char* second) {
  while (*first == *second) {
    if (*first != '\0') {
      ++first;
      ++second;
    } else {
      return 0;
    }
  }
  return (*first - *second);
}

int Strncmp(const char* first, const char* second, size_t count) {
  size_t kc = 0;
  while (kc < count and *first == *second) {
    if (*first != '\0') {
      ++first;
      ++second;
      ++kc;
    } else {
      return 0;
    }
  }
  if (kc == count) {
    return 0;
  }
  return (*first - *second);
}

char* Strcpy(char* dest, const char* src) {
  char* n = dest;
  *dest = *src;
  while (*src != '\0') {
    ++src;
    ++dest;
    *dest = *src;
  }
  return n;
}

char* Strncpy(char* dest, const char* src, size_t count) {
  size_t k = Strlen(src);
  size_t k1 = 0;
  char* s = dest;
  if (count < k) {
    while (k1 < count) {
      *dest = *src;
      ++src;
      ++dest;
      ++k1;
    }
  } else {
    while (*src != '\0') {
      *dest = *src;
      ++src;
      ++dest;
      ++k1;
    }
    while (k1 < count) {
      *dest = '\0';
      ++dest;
      ++k1;
    }
  }
  return s;
}

char* Strcat(char* dest, const char* src) {
  size_t k1 = Strlen(src);
  size_t k2 = Strlen(dest);
  char* k = dest + k2;
  for (size_t i = 0; i < k1; ++i) {
    *k = src[i];
    ++k;
  }
  *k = '\0';
  return dest;
}

char* Strncat(char* dest, const char* src, size_t count) {
  size_t k1 = Strlen(src);
  size_t k2 = Strlen(dest);
  char* k = dest + k2;
  if (count < k1) {
    for (size_t i = 0; i < count; ++i) {
      *k = src[i];
      ++k;
    }
  } else {
    for (size_t i = 0; i < count; ++i) {
      if (i < k1) {
        *k = src[i];
        ++k;
      } else {
        *k = '\0';
        ++k;
      }
    }
  }
  *k = '\0';
  return dest;
}

const char* Strchr(const char* str, char symbol) {
  size_t k = Strlen(str);
  ++k;
  for (size_t i = 0; i < k; ++i) {
    if (*str == symbol) {
      return str;
    }
    ++str;
  }
  return nullptr;
}

const char* Strrchr(const char* str, char symbol) {
  size_t k = Strlen(str);
  str = k + str;
  ++k;
  for (size_t i = 0; i < k; ++i) {
    if (*str == symbol) {
      return str;
    }
    --str;
  }
  return nullptr;
}

size_t Strspn(const char* dest, const char* src) {
  size_t dld = Strlen(dest);
  size_t dls = Strlen(src);
  size_t count = 0;
  for (size_t i = 0; i < dld; ++i) {
    size_t k = 0;
    for (size_t j = 0; j < dls; ++j) {
      if (dest[i] == src[j]) {
        ++k;
        ++count;
        break;
      }
    }
    if (k == 0) {
      break;
    }
  }
  return count;
}

size_t Strcspn(const char* dest, const char* src) {
  size_t dld = Strlen(dest);
  size_t dls = Strlen(src);
  size_t count = 0;
  for (size_t i = 0; i < dld; ++i) {
    size_t k = 0;
    for (size_t j = 0; j < dls; ++j) {
      if (dest[i] == src[j]) {
        ++k;
        break;
      }
    }
    if (k == 0) {
      ++count;
    } else {
      break;
    }
  }
  return count;
}

const char* Strpbrk(const char* dest, const char* breakset) {
  size_t dld = Strlen(dest);
  size_t dls = Strlen(breakset);
  for (size_t i = 0; i < dld; ++i) {
    for (size_t j = 0; j < dls; ++j) {
      if (dest[i] == breakset[j]) {
        return (dest + i);
      }
    }
  }
  return nullptr;
}

const char* Strstr(const char* str, const char* pattern) {
  size_t k1 = Strlen(pattern);
  size_t k2 = Strlen(str);
  size_t count = 0;
  if (*pattern == '\0') {
    return str;
  }
  if (k1 < k2 or k1 == k2) {
    for (size_t i = 0; i < k2 - k1 + 1; ++i) {
      size_t j = 0;
      size_t i1 = i;
      while ((j < k1) and str[i1] == pattern[j]) {
        ++i1;
        ++j;
      }
      if (j == k1) {
        ++count;
        return (str + i);
      }
    }
  }
  return nullptr;
}