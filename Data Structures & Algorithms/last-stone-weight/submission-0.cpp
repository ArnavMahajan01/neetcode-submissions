class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {


        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());

            int x = stones.back();        // largest
            stones.pop_back();

            int y = stones.back();        // second largest
            stones.pop_back();

            if (x != y) {
                stones.push_back(x - y);
            }
        }

        return stones.empty() ? 0 : stones[0];

    }
};
