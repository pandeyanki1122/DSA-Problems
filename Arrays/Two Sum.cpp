/* Approach Discussion:

BRUTE FORCE APPROACH
Write a for loop to traverse on the given array and while traversing keep i at the first position and check if " target - arr[i] " exist in right half of array or not.
If not , then increment 'i'.

Time Complexity = O(N^2)
Space Complexity = O(1).

OPTIMIZED APPROACH
1) Take empty Hash table.
2) Start iterating over given array and check whether (Target - arr[i]) exist in Hash table or not. If not , then put that element along with the index in the hash table , like
(element , index).
If yes, that is present in hash table , then you will find the index easily that on which index the remaining element appear in array.

Time Complexity = O(N).
Space Complexity = O(N) because , we are using extra space i.e. hash table to store 
*/
// CODE :- 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int>mpp;
        for(int i = 0; i< nums.size() ; i++)
        {
            if(mpp.find(target - nums[i]) != mpp.end())
            {
                ans.push_back(mpp[target - nums[i]]);
                ans.push_back(i);
                return ans;
                                  
            }
            mpp[nums[i]] = i;
        }
        return ans;
         
    }
};
