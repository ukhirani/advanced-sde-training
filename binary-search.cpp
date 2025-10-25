#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  int target = 56;
  vector<int> arr = {1, 2, 5, 6, 7, 8, 56};

  bool found = false;
  int left = 0, right = arr.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      cout << "element found at " << mid << endl;
      found = true;
      break;
    } else if (target > arr[mid]) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  if (!found) {
    cout << "element not found";
  }

  return 0;
}
