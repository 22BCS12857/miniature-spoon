#include<iostream>
#include<vector>
using namespace std;
class Solution {
 public:
  int numPoints(vector<vector<int>>& points, int r) {
    const int n = points.size();
    int ans = 1;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        const auto [x1, y1] = points[i];
        const auto [x2, y2] = points[j];
        const double d = hypot(x1 - x2, y1 - y2);
        for (const double delta = 0; delta <= M_PI * 2 + 1e-7; delta += M_PI * 1 / 180.0) {
          const double x = (x1 + x2) / 2.0 + cos(delta) * sqrt(r * r - d * d / 4);
          const double y = (y1 + y2) / 2.0 + sin(delta) * sqrt(r * r - d * d / 4);
          int cnt = 0;
          for (const auto& [xi, yi] : points)
            cnt += hypot(x - xi, y - yi) < r + 1e-7;
          ans = max(ans, cnt);
        }
      }
    return ans;
  }
};

int main(){
    Solution s;
    vector<vector<int>> inut={{-2,0},{2,0},{0,2},{0,-2}};
    int p=2;
    int result=s.numPoints(inut,p);
    cout<<"Max Cherries: "<<result; 
}