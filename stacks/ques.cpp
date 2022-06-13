#include <iostream>
#include <stack>
using namespace std;


// balanced parenthesis problem
bool isMatch (char a, char b) {
    return ((a == '(' && b == ')') ||
            (a == '{' && b == '}') ||
            (a == '[' && b == ']')
            );
}
bool isBalanced (string &str) {
    stack<char> s;
    for (char x: str) {
        if (x == '(' || x == '{' || x == '[')
            s.push(x);
        else {
            if (s.empty()) return false;
            if (!isMatch (s.top(), x)) return false;
            else
                s.pop();
        }
    }
    return (s.empty());
}
int main () {

    string s = "({[()]})";
    isBalanced(s) ? cout << "balanced" : cout << "unbalanced";
    return 0;
}