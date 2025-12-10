class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If mid is smaller than next element, peak lies on right side
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else { 
                // Peak lies on left side (including mid)
                right = mid;
            }
        }
        
        // left == right is a peak index
        return left;
    }
};
