// Copyright 2021 NNTU-CS
#include <algorithm>

int countPairs1(int* arr, int len, int value) {
  int pair_count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++pair_count;
      }
    }
  }
  return pair_count;
}

int countPairs2(int* arr, int len, int value) {
  int pair_count = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    long long current_sum = static_cast<long long>(arr[left]) +
                            static_cast<long long>(arr[right]);

    if (current_sum == value) {
      int left_val = arr[left];
      int right_val = arr[right];
      if (left_val == right_val) {
        long long n = right - left + 1;
        pair_count += static_cast<int>((n * (n - 1)) / 2);
        break;
      }
      int left_count = 0;
      while (left < right && arr[left] == left_val) {
        ++left_count;
        ++left;
      }
      int right_count = 0;
      while (right >= left && arr[right] == right_val) {
        ++right_count;
        --right;
      }
      pair_count += left_count * right_count;
    } else if (current_sum < value) {
      ++left;
    } else {
      --right;
    }
  }
  return pair_count;
}

static int countOccurrences(int* arr, int left, int right, int key) {
  int* lb = std::lower_bound(arr + left, arr + right + 1, key);
  int* ub = std::upper_bound(arr + left, arr + right + 1, key);
  return static_cast<int>(ub - lb);
}

int countPairs3(int* arr, int len, int value) {
  int pair_count = 0;
  for (int i = 0; i < len; ++i) {
    int need = value - arr[i];
    if (need < 0) {
      continue;
    }
    int occurrences = countOccurrences(arr, i + 1, len - 1, need);
    pair_count += occurrences;
  }
  return pair_count;
}

