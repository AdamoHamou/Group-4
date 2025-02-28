#include <bits/stdc++.h>

using namespace std;

// Original code
class Solution {
    public:
        vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
            vector<unordered_map<char, int>> v;
            for (int i = 0; i < words1.size(); i++){
                unordered_map<char, int> z;
                for (int j = 0; j < words1[i].size(); j++)
                {
                    z[words1[i][j]]++;
                }
                v.push_back(z);
            }
    
            unordered_map<char, int> in;
            for (int i = 0; i < words2.size(); i++){
                unordered_map<char, int> temp;
                for (int j = 0; j < words2[i].length(); j++){
                    temp[words2[i][j]]++;
                }
                for (auto& p : temp) {
                    in[p.first] = max(in[p.first], p.second);
                }
            }
    
            vector<string> ret;
            for (int i = 0; i < v.size(); i++){
                unordered_map<char, int> x = v[i];
                bool flag = true;
                for (auto y : in){
                    if (x.find(y.first) == x.end() || x[y.first] < y.second){
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ret.push_back(words1[i]);
                }
            }
            
            return ret;
        }
    };

// Refactored code (AI GENERATED)
class SolutionRefactored {
    public:
        vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
            vector<int> maxFreq(26, 0);
    
            // Compute the max frequency of each character across words2
            for (const string& word : words2) {
                vector<int> tempFreq(26, 0);
                for (char c : word) {
                    tempFreq[c - 'a']++;
                }
                for (int i = 0; i < 26; i++) {
                    maxFreq[i] = max(maxFreq[i], tempFreq[i]);
                }
            }
    
            vector<string> result;
            for (const string& word : words1) {
                vector<int> wordFreq(26, 0);
                for (char c : word) {
                    wordFreq[c - 'a']++;
                }
    
                bool isValid = true;
                for (int i = 0; i < 26; i++) {
                    if (wordFreq[i] < maxFreq[i]) {
                        isValid = false;
                        break;
                    }
                }
                if (isValid) {
                    result.push_back(word);
                }
            }
    
            return result;
        }
    };
// ****************************************************************//

int main() {
    Solution s;
    SolutionRefactored sr;

    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> words2 = {"e","o"};
    vector<string> result = s.wordSubsets(words1, words2);
    vector<string> resultRefactored = sr.wordSubsets(words1, words2);

    cout << "Original code result: ";
    for (string word : result) {
        cout << word << " ";
    }
    cout << endl;

    cout << "Refactored code result: ";
    for (string word : resultRefactored) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}