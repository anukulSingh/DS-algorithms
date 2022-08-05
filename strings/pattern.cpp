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
// t(i+1) = t(i) + txt[i+m] = txt[i] (sliding window, rolling hash)
// but is causes spurious hit ("god" == "dog")
// better hash function is weughted sum
// here, rolling hash formula is:
// t (i+1) = d (t(i) - txt[i] * pow(d, m-1)) + txt[i+m]
vector <int> rabin_carp (string const &pat, string const &txt, int m, int n) {
    const int d = 256;
    const int q = 101;
    // compute (d^ (m-1)) % q
    int h = 1;
    for (int i = 0; i < m-1; ++i)
        h = (h*d) % q;

    // compute pattern's and first window's hash
    int p = 0, t = 0;
    for (int i = 0; i < m; ++i) {
        p = (p*d + pat[i]) % q;
        t = (t*d + txt[i]) % q;
    }
    for (int i = 0; i < (n-m); ++i) {
        // check for hit
        if (p == t) {
            bool flag = true;
            for (int j = 0; j < m; ++j) {
                if (txt[i+j] != pat[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) cout << i << " ";
        }
        // compute t(i+1) using t(i)
        if (i < (n-m)) {
            t = (d * (t - txt[i] * h) + txt[i+m]) % q;
            if (t < 0) t+= q;
        }
    }

}
int main () {

    string s1 = "abcdegshusdabcd", s2 = "abcd";
    // naiveSearch(s1, s2);
    naiveSearchDistinct(s1, s2);

    return 0;
}