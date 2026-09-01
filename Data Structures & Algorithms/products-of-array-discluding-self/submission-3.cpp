class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();

        vector<int> prod(size, 1);

        for(int i = 1; i<size; i++)
            prod[i] = prod[i - 1] * nums[i - 1];

        int prev = 1;

        for(int i = size - 1; i >= 0; i--){
            prod[i] *= prev;
            prev *= nums[i];
        }

        return prod;
    }
};
