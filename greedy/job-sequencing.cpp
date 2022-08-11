// job sequencing problem, each job is a pair
// first ele is deadline, second is profit
// bool myCompare (pair <int, int> a, pair <int, int> b) {
//     return a.second > b.second;
 static bool comp(Job &j1, Job &j2) {
        if (j1.profit > j2.profit) return true;
        else if (j1.profit < j2.profit) return false;
        else if (j1.id < j2.id) return true;
        return false;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, comp);
        int profit = arr[0].profit;
        int jobs = 1;
        int curr_time = 1;
        vector<int> ans;
       
        int deadline = arr[0].dead;
        for (int i = 1; i < n; ++i) {
            if(arr[i].dead >= deadline && curr_time < arr[i].dead) {
                jobs++;
                curr_time++;
                profit += arr[i].profit;
                //deadline = arr[i].dead;
            }
            deadline = arr[i].dead;
        }
        
        ans.emplace_back(jobs);
        ans.emplace_back(profit);
        return ans;
    } 
