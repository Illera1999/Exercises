/*
Given an array of integers [nums] and an integer [target], return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(2 <= nums.size() <= pow(10,4) and pow(-10,9) <= target <= pow(10,9) ){
            for(int i = 0; i < sizeof(nums); i++ ){
                for(int j = 0; j < sizeof(nums); j++ ){
                    if(i != j){
                        if(nums[i] + nums[j] == target){
                            return vector<int> {i,j};
                        }
                    }

                }
            }
        } 
        return {};
    }
};

int main() {
    vector <int> myvector = {1,2,3,4};
    int target = 3;
    Solution index;
    vector<int> result = index.twoSum(myvector, target);

    cout << "El resultado es: [ ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << "]" ;


    return 0;
}
