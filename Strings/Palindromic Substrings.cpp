/* Problem statement
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/
//CODE :-

class Solution {
    public:
    
    void isPalindrome(string s , int start , int end , int &count)
    {
        while(start >= 0 && end <= s.size() && s[start] == s[end])
        {
            count++;
            start--;
            end++;
        }
    }

    int countSubstrings(string s) {
        int n = s.size();
        int count = 0 ;
        
        for(int i = 0 ; i < n ; i++)
        {
            // to judge odd substring
            isPalindrome(s , i , i , count);
            
            //to judge even substring
            isPalindrome(s , i , i+1 , count);
        }
        return count;
        
    }
};
