// https://leetcode.com/problems/sort-an-array/


class Solution {
public:
    
    int partition(vector<int>& nums, int start, int end){
        int secondIndex = start;
        
        for(int i = start; i < end; ++i){
            if(nums[i] < nums[end]){
                swap(nums[i], nums[secondIndex]);
                secondIndex++;
            }
        }
        
        swap(nums[end], nums[secondIndex]);
        return secondIndex;
    }
    
    int partitionRandom(vector<int>& nums, int start, int end){
        srand(time(NULL));
        int pivotIndex = start + rand() % (end - start);
        
        swap(nums[pivotIndex], nums[end]);
        
        return partition(nums, start, end);
    }
    
    void quickSort(vector<int>& nums, int start, int end){
        if(start < end){
            int pivotIndex = partitionRandom(nums, start, end);
            
            quickSort(nums, start, pivotIndex - 1);
            quickSort(nums, pivotIndex + 1, end);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
