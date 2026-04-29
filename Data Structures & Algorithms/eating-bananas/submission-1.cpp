class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int startTime = 1, endTime = *max_element(piles.begin(), piles.end());
        int result = endTime;

        while(startTime <= endTime){
            int mid = (startTime + endTime) / 2;

            long long totalTime = 0;
            for (int p : piles) {
                totalTime += ceil(static_cast<double>(p) / mid);
            }

            if(totalTime <= h){
                result = mid;
                endTime = mid - 1;
            }else{
                startTime = mid + 1;
            }
        }

        return result;
    }
};
