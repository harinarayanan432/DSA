#include <iostream>
#include <vector>

using namespace std;

// Counting Sort function
void countingSort(vector<int>& arr) {
    int max_value = *max_element(arr.begin(), arr.end());
    int min_value = *min_element(arr.begin(), arr.end());
    int range = max_value - min_value + 1;
    
    vector<int> count(range), output(arr.size());
    
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min_value]++;
    
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];
    
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min_value] - 1] = arr[i];
        count[arr[i] - min_value]--;
    }
    
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    
    countingSort(arr);
    
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}
