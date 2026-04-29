class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int time = 1;

        while(true){
            long long totalTime = 0;

            for(int pile: piles){
                totalTime += (pile + time - 1) / time;
            }

            if(totalTime <= h)
                return time;
            
            time++;
        }
    }
};
