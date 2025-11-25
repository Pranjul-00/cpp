#include <iostream>

using namespace std;

int migratoryBirds(int arr[], int n, int &countOut);

int main() {
    int n;
    cout << "How many birds did you see? : ";
    cin >> n;

    int birds[100]; 

    for (int i = 0; i < n; i++) {
        cout << "Enter ID of sighting " << i + 1 << ": ";
        cin >> birds[i];
    }

    int actualCount = 0; 

    int result = migratoryBirds(birds, n, actualCount);
    
    cout << "---------------------------------" << endl;
    cout << "The most frequent bird ID is: " << result 
         << " with the sight count: " << actualCount << endl;

    return 0;
}

int migratoryBirds(int arr[], int n, int &countOut) {

    int counts[100] = {0}; 

    for(int i = 0; i < n; i++) {
        int birdType = arr[i];
        counts[birdType]++; 
    }

    int maxFreq = 0;
    int ansId = 0;

    for(int id = 0; id < 100; id++) {
        if(counts[id] > maxFreq) {
            maxFreq = counts[id];
            ansId = id;
        }
    }

    countOut = maxFreq;

    return ansId;
}