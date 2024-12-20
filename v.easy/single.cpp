#include<iostream>
#include<unordered_map>
using namespace std;
int gold(int arr[],int size){
    if(size==1){
        return arr[size];
    }
    unordered_map<int, int> freqMap;

    // Populate the frequency map
    for (int i = 0; i < size; i++) {
        freqMap[arr[i]]++;
    }
        for (auto& entry : freqMap) {
        if (entry.second==1) {
            return entry.first;  // Return the odd element
        }
    }
}
int main(){
    int arr[5]={4,1,2,1,2};
    int res=gold(arr,5);
    cout<<"The single number is: "<<res;
}