#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
  int jump(vector<int> nums) {
    int i = 0, curr = 0, count = 0, maxJump = 0;
    while(i < nums.size()-1){
        maxJump = max(maxJump, i + nums[i]);
        if(i == curr){
            count++;
            curr = maxJump;
        }
        i++;
    }
    return count;
  }
};
int main(){
    Solution s;
  vector<int> v={2,3,1,1,4};
  int rest=s.jump(v);
  cout<<"Minimum Jumps to reach: "<<rest;
}