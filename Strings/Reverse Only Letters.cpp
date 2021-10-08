/* Approach Discussion
Simple Approach :-
1) Create a temporary character from given array to temp.
2) Copy alphabetic character from given array to temp[].
3) Reverse temp[] using standard string reversal algorithm.
4) Now traverse input string and temp in single loop. Wherever there is alphabetic character in input string ,replace it with the current character of temp[].
5) Time Complexity = O(N).
6) Space Complexity = O(N) as it will require the extra space.

Efficient Approach :-
We can reverse with one traversal and without using extra space.
Let us take l = 0 , r = stringLength - 1;
while(l < r) do following 
. If str[l] != alphabetic character, do l++
. Else IF str[r] != alphabetic character do r--
. Else swap str[l] and str[r] , and then l++ , r--

*/
// CODE:-

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int l = 0;
        int r = S.size() - 1;
        while(l < r)
        {
            if(!isalpha(S[l]))
                l++;
            else if (!isalpha(S[r]))
                r--;
            else
            {
                swap(S[l],S[r]);
                l++;
                r--;
            }
        }
        return S;
        
    }
};

/* Inplace - Two Pointer
Time Complexity = O(N)
Space Complexity = O(1)

*/
    
