
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
