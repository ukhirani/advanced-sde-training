
#include <bits/stdc++.h>
#include <vector>

using namespace std;
class Solution {
private:
  void hello(vector<vector<int>> &subsets, vector<int> &nums, vector<int> &temp,
             int index) {
    if (index >= nums.size())
      return;
    // take
    temp.push_back(nums[index]);
    subsets.push_back(temp);
    hello(subsets, nums, temp, index + 1);
    temp.pop_back();

    // move till you find an element != next element
    while (index < nums.size() - 1 && nums[index] == nums[index + 1]) {
      index++;
    }
    // not take
    hello(subsets, nums, temp, index + 1);
  }

public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> subsets;
    sort(nums.begin(), nums.end());
    vector<int> temp = {};
    subsets.push_back(temp);
    hello(subsets, nums, temp, 0);
    return subsets;
  }
};
