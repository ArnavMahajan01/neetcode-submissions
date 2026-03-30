class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> closestPoints;

        while (k > 0) {
            int minDist = INT_MAX;
            int minIndex = -1;

            
            for (int i = 0; i < points.size(); i++) {
                int dist = points[i][0] * points[i][0]
                         + points[i][1] * points[i][1];

                if (dist < minDist) {
                    minDist = dist;
                    minIndex = i;
                }
            }

            
            closestPoints.push_back(points[minIndex]);

            
            points.erase(points.begin() + minIndex);

            k--;
        }

        return closestPoints;
    }
};