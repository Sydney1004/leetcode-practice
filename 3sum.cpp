#include <algorithm>
#include <vector>
#include <iostream>

using std::vector;

vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 and nums[i] == nums[i-1]) continue; // get rid of repeated i

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {
            if (nums[i] + nums[left] + nums[right] > 0) right--;
            else if (nums[i] + nums[left] + nums[right] < 0) left++;
            else {
                ans.push_back({nums[i], nums[left], nums[right]});
                while (left < right and nums[left] == nums[left + 1]) left++;
                while (left < right and nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            }
        }


    }
    return ans;
}

int main() {
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    auto vec = threeSum(v);
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[0].size(); ++j) {
            std::cout << vec[i][j] << "\n";
        }
    }
}
