// #include <iostream>
// #include <queue>
// #include <stack>
#include <iostream>
#include <deque>


using namespace std;


// void print (queue <int> &q) {
//     while (! q.empty()) {
//         cout << q.front() << " ";
//         q.pop();
//     }
// }

// // reverse a queue
// void reverseQueue (queue <int> &q) {
//     stack <int> s;
//     while (! q.empty()) {
//         s.push (q.front());
//         q.pop();
//     }
//     while (! s.empty()) {
//         q.push (s.top());
//         s.pop();
//     }

// }
// int main () {

//     queue <int> q;
//     q.push(10);
//     q.push(20);
//     q.push(30);
//     q.push(40);

//     reverseQueue(q);
//     print(q);

//     return 0;
// }

// max of every subarray of size k
void printKMax(int *arr, int n, int k) {
    deque <int> dq;
    for (int i = 0; i < k; ++i){
        while (!dq.empty() && arr[i] >= dq.back()){
            dq.pop_back();
        }
        dq.push_back(i)
    }
}

int main (void) {

    return 0;
}
