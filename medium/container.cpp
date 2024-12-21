#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int max_area = 0;

    while (left < right) {
        // Calculate the area between the current pair of lines
        int width = right - left;
        int h = min(height[left], height[right]);
        int area = width * h;
        // Update max_area if the current area is larger
        max_area = max(max_area, area);
        // Move the pointer pointing to the shorter line
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    
    int result = maxArea(height);
    cout << "Maximum water that can be contained: " << result << endl;
    
    return 0;
}
