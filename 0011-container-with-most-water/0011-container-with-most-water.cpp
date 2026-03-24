class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_water = 0;

        while(left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            int area = h * w;

            max_water = max(max_water, area);

            if(height[left] < height[right])
                left++;
            else
                right--;
        }

        return max_water;
    }
};