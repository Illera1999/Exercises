// Given a string s, find the length of the longest substring without repeating characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> aux;
        int result = 0;
        int compresult = 0;
        for(int i = 0; i < s.length(); i++){
            auto iter = aux.find(s[i]);
            if(iter != aux.end()){
                i = aux[s[i]];
                if(compresult >= result){
                    result = compresult;
                    // cout << result << endl;
                    compresult = 0;
                }
                aux.clear();
            }else{
                aux[s[i]] = i;
                compresult++;
            }
        }
        if(compresult > result){
            result = compresult;
            // cout << result << endl;
            compresult = 0;
        }
        // cout << "Cual es la substring:" << endl;
        // for (const auto& par : aux) {
        //     cout << "Clave: " << par.first << ", Valor: " << par.second << std::endl;
        // }
        return result;
    }
};

int main(){
    Solution result;
    cout << "El resultado de abcab: " << result.lengthOfLongestSubstring("abcab") << endl;
    cout << "El resultado es bbbbb: " << result.lengthOfLongestSubstring("bbbbb") << endl;
    cout << "El resultado es pwwkew: " << result.lengthOfLongestSubstring("pwwkew") << endl;
}