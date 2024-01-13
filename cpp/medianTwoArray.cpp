// Given two sorted arrays nums1 and nums2 of size m and n respectively, 
// return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result;
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        cout << "par o impar " << nums1.size() % 2 << endl;
        if(nums1.size() % 2 == 0){
            double one = nums1[nums1.size()/2 - 1]; 
            double two = nums1[nums1.size()/2]; 
            result = (one + two)/2;
        }else{
            result = nums1[(nums1.size() - 1) / 2];
        }
        cout << "La string ordenada es: " << endl;
        for(int num: nums1){
            cout << num << endl;
        }
        return result;
        
    }
};

int main(){
    Solution result;
    vector<int> nums1 = {1,3,5};
    vector<int> nums2 = {2,4};
    double solution;
    solution = result.findMedianSortedArrays(nums1, nums2);
    cout << "La media de los vectores[{";
    for(int i: nums1){
        cout << i << " ";
    }  
    cout << "},{" ;
    for(int i: nums2){
        cout << i << " ";
    }  
    cout << "}] es: " << solution << endl;
    nums1 = {1,2};
    nums2 = {3,4};
    solution = result.findMedianSortedArrays(nums1, nums2);
    cout << "La media de los vectores[{";
    for(int i: nums1){
        cout << i << " ";
    }  
    cout << "},{" ;
    for(int i: nums2){
        cout << i << " ";
    }  
    cout << "}] es: " << solution << endl;
    return 0;
}