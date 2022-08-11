// Fractional knapsack problem given value-weight pairs, given a capacity of weight
// item with highest value/weight pair should be selected first
bool myCompare (pair <int, int> a, pair <int, int> b) {
    double r1 = (double) (a.first/a.second);
    double r2 = (double) (b.first/b.second);
    return r1 > r2;
}
double frknaps (vector <pair<int, int>> items, int cap) {

    sort (items.begin(), items.end(), myCompare);
    double res = 0.0;
    for (int i = 0; i < items.size(); ++i) {
        if (items[i].second <= cap) {
            res += items[i].first;
            cap -= items[i].second;
        }
        else {
            res += ((items[i].first) * ((double) cap / items[i].second)); 
            break;
        }
    }
    return res;
