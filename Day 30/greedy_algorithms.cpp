#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumActivities(vector<int> start, vector<int> end) {
    // sort on end time if needed
    // A0 select
    cout << "Selecting Activity A0\n";
    int count = 1;
    int currEndTime = end[0];

    for(int i = 1; i < start.size(); i++) {
        if(start[i] >= currEndTime) { // non overlapping condition
            cout << "Selecting Activity A" << i << endl;
            count++;
            currEndTime = end[i];
        }
    }

    return count;
}

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second; // ascending - end

    // return p1.second > p2.second; // descending - end
    // return p1.first < p2.first; // ascending - start
    // return p1.first > p2.first; // descending - start
}

bool comp(pair<double, int> p1, pair<double, int> p2) {
    return p1.first > p2.first; // descending - start
}



void fractionalKnapsack(vector<int> val, vector<int> wt, int W) {
    // sort on value/weight ratio
    int n = val.size();
    vector<pair<double, int>> ratio(n, make_pair(0.0, 0)); // pair(ratio, idx) -> (double, int)
    for(int i = 0; i < n; i++) {
        double r = (double)val[i] / (double)wt[i];
        ratio[i] = make_pair(r, i);
    }

    sort(ratio.begin(), ratio.end(), comp);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int idx = ratio[i].second; // wt, val
        if(wt[idx] <= W) {
            ans += val[idx];
            W -= wt[idx];
        } else {
            ans += ratio[i].first * W;
            W = 0;
            break;
        }
    }

    cout << "Maximum Value = " << ans << endl;
}

void minAbsoluteDifference(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int absDiff = 0;

    for(int i = 0; i < A.size(); i++) {
        absDiff += abs(A[i] - B[i]);
    }

    cout << "MIN Absolute Difference = " << absDiff << endl;
}

int maxChainLength(vector<pair<int,int>> pairs) {
    int n = pairs.size();
    sort(pairs.begin(), pairs.end(), compare);

    int ans = 1;
    int currEnd = pairs[0].second;

    for(int i = 1; i < n; i++) {
        if(pairs[i].first > currEnd) {
            ans++;
            currEnd = pairs[i].second;
        }
    }

    cout << "Maximum Chain Length = " << ans << endl;
    return ans;
}

void getMinChange(vector<int> coins, int V) {
    // sort coins if needed
    int n = coins.size();
    int ans = 0;
    for(int i = n-1; i >= 0 && V > 0; i--) {
        if(V >= coins[i]) {
            ans += V / coins[i];
            V = V % coins[i];
        }
    }

    cout << "Minimum Coins For Change = " << ans << endl;
}

bool compareProfit(pair<int,int> p1, pair<int,int> p2) {
    return p1.second > p2.second; // descending
}

void maximumProfit(vector<pair<int, int>> jobs) {
    sort(jobs.begin(), jobs.end(), compareProfit);
    // first -> deadline , second -> profit
    int profit = jobs[0].second;
    int safeDeadLine = 2;

    for(int i = 1; i < jobs.size(); i++) {
        if(jobs[i].first >= safeDeadLine) {
            profit += jobs[i].second;
            safeDeadLine++;
        }
    }

    cout << "Maximum Profit from jobs = " << profit << endl;
}


class Job {
public:
    int idx, deadline, profit;

    Job(int idx, int deadline, int profit) {
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

void maxProfitWithSequence(vector<pair<int,int>> pairs) {
    int n = pairs.size();
    vector<Job> jobs;

    for(int i = 0; i < n; i++) {
        // jobs.push_back(Job(i, pairs[i].first, pairs[i].second));
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);
    }

    // [] => Empty List
    // () => Lambda function

    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b) {
        return a.profit > b.profit;
    });

    cout << "Selecting Job " << static_cast<char>('A' + jobs[0].idx) << endl;
    int profit = jobs[0].profit;
    int safeDeadline = 2;

    for(int i = 1; i < n; i++) {
        if(jobs[i].deadline >= safeDeadline) {
            cout << "Selecting Job " << static_cast<char>('A' + jobs[i].idx) << endl;
            profit += jobs[i].profit;
            safeDeadline++;
        }
    }

    cout << "Maximum Profit from jobs = " << profit << endl;
}


int main() {
    //! Activity Selection: Select the no. of activities that can be performed by a single person.
    //! (A Person Can work on one activities at a time)
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    // cout << maximumActivities(start, end) << endl;

    //! Pair in C++ : STL container to store two objects
    // vector<int> s = {0, 1, 2};
    // vector<int> e = {9, 2, 4};

    // vector<pair<int, int>> activities(3, make_pair(0, 0));

    // activities[0] = make_pair(0, 9);
    // activities[1] = make_pair(1, 2);
    // activities[2] = make_pair(2, 4);

    // for(int i = 0; i < activities.size(); i++) {
    //     cout << "A" << i << " : " << activities[i].first << "," << activities[i].second << endl;
    // }

    // sort(activities.begin(), activities.end(), compare);

    // cout << "----------------sorted----------------\n";

    // for(int i = 0; i < activities.size(); i++) {
    //     cout << "A" << i << " : " << activities[i].first << "," << activities[i].second << endl;
    // }


    //! Fractional Knapsack: Put items in knapsack to get the maximum total value in the knapsack.

    vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int W = 50; // knapsack
    // fractionalKnapsack(value, weight, W);

    //! Min Absolute Difference Pairs: Pair Elements of A & B to minimize sum of absolute differences between pairs.

    vector<int> A = {4, 1, 8, 7};
    vector<int> B = {2, 3, 6, 5};
    // minAbsoluteDifference(A, B);


    //! Max Length Chain of Pairs
    /*
        * A pair (c,d) can come after pair (a,b) if b < c.
        * Find the longest chain which can be formed from a given set of pairs.
    */
    int n = 5;
    vector<pair<int, int>> pairs(n, make_pair(0, 0));

    pairs[0] = make_pair(5, 24);
    pairs[1] = make_pair(39, 60);
    pairs[2] = make_pair(5, 28);
    pairs[3] = make_pair(27, 40);
    pairs[4] = make_pair(50, 90);

    // maxChainLength(pairs);



    //! Indian Coins
    /*
        * We are given an infinite supply of denominations [1, 2, 5, 10, 20, 50, 100, 500, 2000].
        * Find the minimum number of coins to make change for a value V
        * 
        * V = 121
        * ans = 3 (100 + 20 + 1)
        * 
        * V = 590
        * ans = 4 (500 + 50 + 20 + 20)
    */

    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int V = 590;

    // getMinChange(coins, V);

    //! Job Sequencing Problem: Maximize the total profit if only one job can be scheduled at a time.

    n = 4;
    vector<pair<int, int>> jobs(n, make_pair(0, 0));

    jobs[0] = make_pair(4, 20); // Job A
    jobs[1] = make_pair(1, 10); // Job B
    jobs[2] = make_pair(1, 40); // Job C
    jobs[3] = make_pair(1, 30); // Job D


    // maximumProfit(jobs);
    maxProfitWithSequence(jobs);


    return 0;
}