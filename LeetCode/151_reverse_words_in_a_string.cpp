#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.length();
        int i = 0;

        while (i < n) {
            // Skip spaces
            while (i < n && s[i] == ' ') i++;

            // Extract word
            string word = "";
            while (i < n && s[i] != ' ') {
                word += s[i++];
            }

            // Push non-empty word to stack
            if (!word.empty()) {
                st.push(word);
            }
        }

        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
            if (!st.empty()) {
                result += " "; // Add space between words
            }
        }

        return result;
    }
};

/*brute force(Two pointers approach) 

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0, res = 0;

        // Step 1: Clean up extra spaces in-place
        while (i < n) {
            // Skip spaces
            while (i < n && s[i] == ' ') i++;
            
            // Copy word characters
            if (i < n) {
                if (res != 0) s[res++] = ' '; // Add a single space between words
                while (i < n && s[i] != ' ') {
                    s[res++] = s[i++];
                }
            }
        }
        
        // Resize string to remove unused tail portion
        s.resize(res);
        n = s.length();

        // Step 2: Reverse the entire cleaned string
        reverse(s.begin(), s.end());

        // Step 3: Reverse each word back individually
        int start = 0;
        for (int end = 0; end <= n; end++) {
            if (end == n || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        return s;
    }
};*/