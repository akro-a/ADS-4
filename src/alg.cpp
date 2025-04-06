// Copyright 2021 NNTU-CS
#include <algorithm>
#include <cstdint>

int countPairs1(int* arr, int len, int value) {
  int result = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++result;
      }
    }
  }
  return result;
}

int countPairs2(int* arr, int len, int value) {
  int result = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int64_t s = static_cast<int64_t>(arr[left]) +
                static_cast<int64_t>(arr[right]);
    if (s == value) {
      int lv = arr[left];
      int rv = arr[right];
      if (lv == rv) {
        int64_t n = static_cast<int64_t>(right - left + 1);
        result += static_cast<int>((n * (n - 1)) / 2);
        break;
      }
      int lc = 0;
      while (left < right && arr[left] == lv) {
        ++lc;
        ++left;
      }
      int rc = 0;
      while (right >= left && arr[right] == rv) {
        ++rc;
        --right;
      }
      result += lc * rc;
    } else if (s < value) {
      ++left;
    } else {
      --right;
    }
  }
  return result;
}

static int countOccurrences(const int* arr, int left, int right, int key) {
  const int* lb = std::lower_bound(arr + left, arr + right + 1, key);
  const int* ub = std::upper_bound(arr + left, arr + right + 1, key);
  return static_cast<int>(ub - lb);
}

int countPairs3(int* arr, int len, int value) {
  int result = 0;
  for (int i = 0; i < len; ++i) {
    int need = value - arr[i];
    if (need < 0) {
      continue;
    }
    result += countOccurrences(arr, i + 1, len - 1, need);
  }
  return result;
}
