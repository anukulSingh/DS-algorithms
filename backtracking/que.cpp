#include <iostream>
#include <algorithm>
using namespace std;


// Naive way 
void permute (string s) {
    do{
        if (s.find("AB") == string::npos)
            cout << s << endl;
    } while (next_permutation(s.begin(),s.end()));
}
// void
// bool isSafe (string str, int l,int i, int r) {
//     if (l != 0 &&  str[l-1] = 'A' && str[l] == 'B') // skipping "AB" containing calls
//         return false;
//     if (r = l+ 1 && str[i] = 'A' & str[l] ='B') // skipping "BA"
//         return false;
// }
// // given a string, print all the permutations which do not contain "AB" as substring
// void permute (string str, int l, int r) {
//     if (l == r && str.find("AB") == string::npos) {
//         cout << str << " ";
//         return;
//     }   
//     else {
//         for (int i = l; i <= r; ++i) {
//             if (isSafe(str, l, i, r)) {
//                 swap(str[i], str[l]);
//                 permute(str, l+1, r);
//                 swap(str[i], str[l]);
//             }
//         }  
//     }
// }
int main () {
    string str = "ABC";
    permute(str);
    // permute(str, 0, str.length()-1);
    return 0;
}