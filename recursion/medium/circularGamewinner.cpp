#include<iostream>
using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1) 
            return 1;
        int winner = findTheWinner(n - 1, k);
        int adjustedWinner = (winner + k) % n;
        return adjustedWinner == 0 ? n : adjustedWinner;
    }
};

int main(){
    Solution s;
    int n,k;
    cout<<"Enter Number of Players: ";
    cin>>n;
    cout<<"Enter number of passes: ";
    cin>>k;
    int res=s.findTheWinner(n,k);
    cout<<"Result: "<<res;
}