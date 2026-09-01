class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prev(size);
        vector<int> after(size);

        prev[0] = 1;
        after[size - 1] = 1;

        for(int i = 1; i<size; i++){
            prev[i] = nums[i - 1] * prev[i - 1];
        }

        for(int i = size - 2; i >= 0; i--)
            after[i] = after[i+1] * nums[i+1];

        vector<int> prod(size);

        for(int i =0 ; i< size; i++)
            prod[i] = prev[i] * after[i];

        return prod;
    }
};
