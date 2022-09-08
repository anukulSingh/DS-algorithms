class Solution {
public:
    bool isMatch(char a, char b) {
        return (
            (a == '(' && b == ')') ||
            (a == '{' && b == '}') ||
            (a == '[' && b == ']')
        );
    }
    bool isValid(string str) {
        stack<char> s;
        for (char &x: str) {
            if (x == '(' || x == '{' || x == '[')
                s.push(x);
            else {
                if (s.empty()) return false;
                if (isMatch(s.top(), x)) s.pop();
                else return false;
            }
        }
        return (s.empty());
    }
};


// ww can add a closing bracke iff count(close_bracket) > count(open_bracket)