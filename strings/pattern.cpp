#include <iostream>
#include <string>

using namespace std;


// Naive pattern searching
// O(n-m+1 * m)
// void naiveSearch (string &txt, string &pat) {
//     int m = pat.length();
//     int n = txt.length();

//     for (int i = 0; i <= n-m; ++i) {
//         int j;
//         for (j = 0; j < m; ++j) 
//             if (pat[j] != txt[i+j])
//                 break;
//         if (j == m) cout << i << " ";
//     }
// }

// for distinct text O(n)
void naiveSearchDistinct (string &txt, string &pat) {
    int m = pat.length();
    int n = txt.length();

    for (int i = 0; i <= n-m; ) {
        int j;
        for (j = 0; j < m; ++j) 
            if (pat[j] != txt[i+j])
                break;
        if (j == m) cout << i << " ";
        if (j == 0) i++;
        else 
            i += j;
    }
}

// rabin carp algorithn, uses hashing
// O(|s| + |t|) time
//Problem: Given two strings - a pattern s and a text t, determine if the pattern appears in the text and if it does, enumerate all its occurrences 
vector <int> rabin_carp (string const &s, string const &t) {
    
}
int main () {

    string s1 = "abcdegshusdabcd", s2 = "abcd";
    // naiveSearch(s1, s2);
    naiveSearchDistinct(s1, s2);

    return 0;
}