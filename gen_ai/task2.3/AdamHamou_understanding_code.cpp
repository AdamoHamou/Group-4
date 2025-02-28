#include <bits/stdc++.h>

using namespace std;

// originial code
class Solution {
    public:
        vector<string> stringMatching(vector<string>& words) {
            set<string> ret;
            for(int i = 0; i < words.size(); i++){
                for(int j = 0; j < words.size(); j++){
                    if(i != j){
                        if (words[i].find(words[j]) != string::npos){
                            ret.insert(words[j]);
                        }
                    }
                }
            }
            vector<string> x;
            for(auto xx : ret)
                x.push_back(xx);
            
            return x;
        }
    };

// ChatGPT AI generated code better readability for complex code
class SolutionCode {
    public:
        vector<string> findSubstrings(vector<string>& words) {
            set<string> substrings;
            
            // Iterate through each word in the list
            for (size_t i = 0; i < words.size(); i++) {
                // Compare the current word with all other words in the list
                for (size_t j = 0; j < words.size(); j++) {
                    // Ensure we are not comparing the same word with itself
                    if (i != j && words[i].find(words[j]) != string::npos) {
                        // If words[j] is a substring of words[i], add it to the set
                        substrings.insert(words[j]);
                    }
                }
            }
            
            // Convert the set of unique substrings into a vector and return it
            return vector<string>(substrings.begin(), substrings.end());
        }
    };

int main()
{
    vector<string> words = {"mass","as","hero","superhero"};
    Solution obj;
    SolutionCode objCode;
    vector<string> result = obj.stringMatching(words);
    for (string s : result) {
        cout << s << " ";
    }
    cout << endl;
    vector<string> resultCode = objCode.findSubstrings(words);
    for (string s : resultCode) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}