/*
Problem Statement :-
Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array and return it
In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5].....

Example 1:

Input:
n = 5
arr[] = {1,2,3,4,5}
Output: 2 1 4 3 5
Explanation: Array elements after 
sorting it in wave form are 
2 1 4 3 5.

Example 2:

Input:
n = 6
arr[] = {2,4,7,8,9,10}
Output: 4 2 8 7 10 9
Explanation: Array elements after 
sorting it in wave form are 
4 2 8 7 10 9.

Your Task:
The task is to complete the function convertToWave() which converts the given array to wave array.

APPROACH:
BRUTE FORCE APPROACH:
1) First Sort the given array 
2) Then swap adjacent elements
*/
void swap(int *x , int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    void convertToWave(vector<int>& arr, int n){
        
        // Your code here
        sort(arr.begin() , arr.end());
        
        for(int i = 0 ; i < n-1 ; i += 2)
        {
            swap(&arr[i] , &arr[i+1]);
        }
        
    }
/* Time Complexity : O(NLogN) , if we use Merge Sort for Sorting
Space Complexity = O(1)

Efficient Approach :-
The idea is based on the fact that if we make sure that all even positioned (at index 0, 2, 4, ..) elements are greater than their adjacent odd elements, we don’t need 
to worry about odd positioned element. 
Following are simple steps. 
1) Traverse all even positioned elements of input array, and do following. 
   a) If current element is smaller than previous odd element, swap previous and current. 
   b) If current element is smaller than next odd element, swap next and current.
   
   */
//CODE

void convertToWave(vector<int>& arr, int n){
        
        // Your code here
        for(int i = 0 ; i < n ; i += 2)
        {
            if(i > 0 && arr[i-1] > arr[i])
            {
                swap(arr[i-1] , arr[i]);
            }
            
            if(i < n-1 && arr[i+1] > arr[i])
            {
                swap(arr[i] , arr[i+1]);
            }
        }
        
    }

/* Time Complexity = O(N)
   Space Complexity = O(1)
   
