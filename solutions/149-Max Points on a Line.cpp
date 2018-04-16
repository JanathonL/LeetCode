// 149. Max Points on a Line
// 以每个“点”为中心，然后遍历剩余点，找到所有的斜率，
// 如果斜率相同，那么一定共线对每个点，用一个哈希表，key为斜率，value为该直线上的点数，
// 计算出哈希表后，取最大值，并更新全局最大值，最后就是结果。时间复杂度O(n^2)，空间复杂度O(n)。
// 这题直接用斜率会不够精确，建议用gcd求出斜率分子分母的最大公约数，然后都弄成最简分数存起来就好。
class Solution { 
public: 
    int maxPoints(vector<Point>& points) {
        map<pair<int, int>, int> slopes;
        int maxp = 0, n = points.size();
        for (int i = 0; i < n; i++) {
            slopes.clear();
            int duplicate = 1;
            for (int j = i + 1; j < n; j++) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    duplicate++;
                    continue;
                }
                int dx = points[j].x - points[i].x;
                int dy = points[j].y - points[i].y;
                int dvs = gcd(dx, dy);
                slopes[make_pair(dx / dvs, dy / dvs)]++;
            }
            maxp = max(maxp, duplicate); 
            for (auto slope : slopes)
                if (slope.second + duplicate > maxp)
                    maxp = slope.second + duplicate;
        } 
        return maxp;
    }
private:
    int gcd(int num1, int num2) {
        while (num2) {
            int temp = num2; 
            num2 = num1 % num2;
            num1 = temp;
        }
        return num1;
    }
};
