#include<iostream>
#include<unordered_map>
using namespace std;

// Function to find majority element
int majority(int arr[], int size) {
    if(size==1){
        return arr[size];
    }
    unordered_map<int, int> freqMap;  // Map to store frequency of elements

    // Populate the frequency map
    for (int i = 0; i < size; i++) {
        freqMap[arr[i]]++;
    }

    // Check for majority element (appears more than size/2 times)
    int crit = size / 2;
    if(size%2==0){
        crit=crit+1;
    }
    for (auto& entry : freqMap) {
        if (entry.second > crit) {
            return entry.first;  // Return the majority element
        }
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    
    int arr[n];

    // Input elements
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element " << i << ": ";
        cin >> arr[i];
    }

    // Print the original array
    cout << "Original Array: ";
    for (int j = 0; j < n; j++) {
        cout << arr[j] << "\t";
    }
    cout << endl;

    // Find and print the majority element
    int maj = majority(arr, n);
    if (maj != -1) {
        cout << "Majority Element is: " << maj << endl;
    } else {
        cout << "No Majority Element found" << endl;
    }

    return 0;
}
