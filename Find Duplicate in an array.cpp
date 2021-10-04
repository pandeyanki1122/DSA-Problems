// Problem Statement
/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [1,1]
Output: 1
Example 4:

Input: nums = [1,1,2]
Output: 1
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times. */
// -------------------------------------------------------------- Approach Discussion -------------------------------------------------------->>

/* ------------------------------------------------------           NAIVE APPROACH :         -------------------------------------------------->>
i) Sort the given array.
ii) After Sorting , the duplicate element will occur together.
iii) Traverse the sorted array and Check condition i.e. if arr[i] == arr[i+1] , return arr[i].
iv) Time Complexity = O(NlogN) (if we use merge sort to sort the array).
v) space Complexity = O(1).
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] == nums[i+1])
                return nums[i];
            
        }
        return 0;
        }
    };
/* Approach 2) We can use Hashing Technique as well.
Optimal Approach:-
Step1) Use Linked List Cycle Method.
Step2) Now , take slow and fast pointer and keep traversing over the circular list till both lie on same element. Move slow by one and fast by distance 2.
Step3) When slow and fast pointer lie on same element , Now take the fast pointer and put it on the starting element, and keep moving bothby distance 1 simultaneousliy.
Step4) A point at which both collide ( or lie on same point) will be the duplicate element because , If there will duplicate , then cycle will definitely formed.
*/
// Code
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        fast = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
            
        return slow;    
        
    }
};

// Time Complexity = O(N)
// Space Complexity = O(1)

