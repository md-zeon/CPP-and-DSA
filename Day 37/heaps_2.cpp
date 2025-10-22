#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
    int maxI = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[maxI]) {
        maxI = l;
    }
    if (r < n && arr[r] > arr[maxI]) {
        maxI = r;
    }
    if (maxI != i) {
        swap(arr[i], arr[maxI]);
        heapify(arr, n, maxI);
    }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();
    // step 01: Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // step 02: Taking elements to their correct positions
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

class Car {
public:
    int idx;
    int distSq;

    Car(int idx, int distSq) {
        this->idx = idx;
        this->distSq = distSq;
    }

    bool operator < (const Car &c) const {
        return this->distSq > c.distSq; // min heap
    }
};

void nearbyCars(vector<pair<int,int>> pos, int k) {
    vector<Car> cars;
    for (int i = 0; i < pos.size(); i++) { // O(n)
        int distSq = pos[i].first * pos[i].first + pos[i].second * pos[i].second;
        cars.push_back(Car(i, distSq));
    }

    priority_queue<Car> pq(cars.begin(), cars.end()); // O(n)

    for (int i = 0; i < k; i++) { // O(k*log n + n)
        cout << "Car " << pq.top().idx << "\n";
        pq.pop(); // O(log n)
    }

}

void connectNRopes(vector<int> ropes) {
    priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.end());

    int cost = 0;

    while (pq.size() > 1) {
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        cost += min1 + min2;
        pq.push(min1 + min2);
    }

    cout << "Minimum Cost: " << cost << endl;
}

class Row {
public:
    int soldiers;
    int idx;

    Row(int soldiers, int idx) {
        this->soldiers = soldiers;
        this->idx = idx;
    }

    bool operator < (const Row &r) const {
        // min heap
        if (this->soldiers == r.soldiers) {
            return this->idx > r.idx;
        } else {
            return this->soldiers > r.soldiers;
        }
    }
};

void weakestSoldiers(vector<vector<int>> matrix, int k) {
    vector<Row> rows;
    for (int i = 0; i < matrix.size(); i++) {
        int count = 0;
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 1) {
                count++;
            }
        }
        rows.push_back(Row(count, i));
    }

    priority_queue<Row> pq(rows.begin(), rows.end());

    for (int i = 0; i < k; i++) {
        cout << "Row " << pq.top().idx << endl;
        pq.pop();
    }
} 

void slidingWindowMax(vector<int> arr, int k) {
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < k; i++) {
        pq.push({arr[i], i});
    }

    cout << "Output: " << pq.top().first << " ";

    for (int i = k; i < arr.size(); i++) {
        while (!pq.empty() && pq.top().second <= (i-k)) { // outside window
            pq.pop();
        }
        pq.push({arr[i], i});
        cout << pq.top().first << " ";
    }

    cout << endl;
}

int main() {
    //! Heap Sort
    // vector<int> arr = {1, 4, 2, 5, 3};
    // heapSort(arr);
    // for (int i : arr) {
    //     cout << i << " ";
    // }
    // cout << endl;

    //! Nearby Cars
    //* Based on Car Locations (cx, cy), find nearest K cars
    vector<pair<int,int>> pos;
    pos.push_back(make_pair(3, 3));
    pos.push_back(make_pair(5, -1));
    pos.push_back(make_pair(-2, 4));
    int k = 2;
    // nearbyCars(pos, k);

    //! Connect N Ropes
    //* If cost to connect 2 ropes = sum of their lengths. Find min cost to connect N ropes.
    vector<int> ropes = {4, 3, 2, 6};
    // connectNRopes(ropes);

    //! Weakest Soldier
    //* For an MxN matrix, a row i is weaker than a row j if one of the following is true:
    //* The number of soldiers in row i is less than the number of soldiers in row j.
    //* Both rows have the same number of soldiers and i < j.

    //* Find K weakest rows.

    vector<vector<int>> matrix = {{1, 0, 0, 0},
                                  {1, 1, 1, 1},
                                  {1, 0, 0, 0},
                                  {1, 0, 0, 0}};

    k = 3;
    // weakestSoldiers(matrix, k);


    //! Sliding Window Maximum
    //* Maximum of all sub arrays of size K
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    k = 3;
    slidingWindowMax(arr, k);

    return 0;
}