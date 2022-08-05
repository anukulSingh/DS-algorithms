#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

// find min coins required to pay an amount (10, 5, 2 , 1 paise coins)
// greedy fails for (18, 10, 1), why ?

// int minCoins (int *coins, int n, int amount) {
//     sort(coins, coins + n, greater<int>());
//     int ans = 0;
//     for (int i = 0; i < n; ++i) {
//         if (coins[i] <= amount) {
//             int c = (amount / coins[i]);
//             ans += c;
//             amount -= c*coins[i];
//         }
//         if (amount == 0) break;
//     }
//     return ans;
// }



// activity selection problem
// find max no of activities that can be done without overlapping
// bool myCompare (pair <int, int> a, pair <int, int> b) {
//     return (a.second < b.second);
// }

// int maxActivities (vector <pair <int, int>> v) {
//     int n = v.size();
//     sort(v.begin(), v.end (), myCompare);
//     int prev = 0, res = 1;
//     for (int curr = 1; curr < n; ++curr) {
//         if (v[curr].first >= v[prev].second) {
//             res++;
//             prev = curr;
//         }
//     }
//     return res;
// }

bool mycmp (pair <int, int> a, pair <int, int> b) {
    return (a.second < b.second);
}
void busyman() {
    int t;cin>>t;
    while(t--) {
        int N; cin >> N;
        vector <pair <int, int> > activity;
            int n,m;
        while (N--) {
            cin>>m>>n;
            activity.push_back({m, n});
        }
        sort(activity.begin(),activity.end(),mycmp);
        int prev =0,res=1;
        for (int curr=1;curr<n;++curr) {
            if (activity[curr].first >= activity[prev].second) {
                res++;
                prev=curr;
            }
        }
        cout << res << endl;
    }
    
}


// Fractional knapsack problem given value-weight pairs, given a capacity of weight
// item with highest value/weight pair should be selected first
// bool myCompare (pair <int, int> a, pair <int, int> b) {
//     double r1 = (double) (a.first/a.second);
//     double r2 = (double) (b.first/b.second);
//     return r1 > r2;
// }
// double frknaps (vector <pair<int, int>> items, int cap) {

//     sort (items.begin(), items.end(), myCompare);
//     double res = 0.0;
//     for (int i = 0; i < items.size(); ++i) {
//         if (items[i].second <= cap) {
//             res += items[i].first;
//             cap -= items[i].second;
//         }
//         else {
//             res += ((items[i].first) * ((double) cap / items[i].second)); 
//             break;
//         }
//     }
//     return res;
// 

// job sequencing problem, each job is a pair
// first ele is deadline, second is profit
// bool myCompare (pair <int, int> a, pair <int, int> b) {
//     return a.second > b.second;
// }
// int maxJobProfit (vector <pair <int, int> jobs) {

//     vector <bool> slot(n);
//     // sort all jobs accn to dec order of profit
//     sort (jobs.begin(), jobs.end(), myCompare);
//     for (int i = 0; i < slot.size(); ++i) {
//         slot[i] = false;
//     }
//     int ans = jobs[0].second;
//     for (int i = 1; i < jobs.size(); ++i) {
        
//     }

// }
int main () {

    // int coins[] = {5,2,10,1};
    // cout << minCoins(coins, 4, 59);

    // vector <pair <int, int>> v = {{12,25}, {10,20}, {20,30}};
    // cout << maxActivities(v);
    busyman();

    //  vector <pair <int, int>> v = {{120,30}, {100,20}, {60,10}};
    //  cout << frknaps(v, 50);



    return 0;
}