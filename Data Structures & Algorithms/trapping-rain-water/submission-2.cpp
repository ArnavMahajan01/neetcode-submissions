class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;

        if(height.empty())
            return 0;

        int size = height.size();
        int totalWaterTrapped =0;

        for(int i =0; i < size; i++){
            int maxLeft = height[i], maxRight = height[i];

            for(int j =0; j < i; j++){
                maxLeft = max(maxLeft, height[j]);
            }

            for(int j  =i ; j<size; j++){
                maxRight = max(maxRight, height[j]);
            }

            totalWaterTrapped = min(maxLeft, maxRight) - height[i] > 0? totalWaterTrapped + min(maxLeft, maxRight) - height[i]:totalWaterTrapped + 0;

        }

        return totalWaterTrapped;
    }
};
