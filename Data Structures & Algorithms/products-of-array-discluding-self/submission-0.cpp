class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProduct(nums.size(), 1);
        vector<int> rightProduct(nums.size(), 1);
        vector<int> finalProduct(nums.size(), 1);

        int leftRunningProduct = 1;
        for(int i = 0; i < nums.size(); i++){
            leftProduct[i] = leftRunningProduct;
            leftRunningProduct *= nums[i];
        }

        int rightRunningProduct = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            rightProduct[i] = rightRunningProduct;
            rightRunningProduct *= nums[i];
        }

        int finalRunningProduct = 1;
        for(int i = 0; i < nums.size(); i++){
            finalProduct[i] = rightProduct[i] * leftProduct[i];
        }   

        return finalProduct;
    }
};
