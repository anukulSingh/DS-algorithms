// activity selection problem
// find max no of activities that can be done without overlapping
 static bool comp(pair<int, int> &p1, pair<int,int> &p2) {
        if (p1.first < p2.first) return true;
        else if (p1.first > p2.first) return false;
        else if (p1.second < p2.second) return true;
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int> > v;
        for (int i = 0; i < n; ++i) {
            v.push_back({ end[i], i });
        }
        sort(v.begin(), v.end(), comp);
        int ans = 1;
        int limit = v[0].first;
        for (int i = 1; i < n; ++i) {
            if (start[v[i].second] > limit) {
                ans++;
                limit = v[i].first;
            } // compare previous end with current start
        }
        return ans;
    }
