class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxVolume = INT_MIN, left = 0, right = heights.size() - 1;

        while(left < right){
            int tempArea = min(heights[left], heights[right]) * (right - left);
            
            if(tempArea > maxVolume){
                maxVolume = tempArea;
            }

             if(heights[right] > heights[left]){
                left++;
            }else{
                right--;
            }
        }

        return maxVolume;
    }
};
