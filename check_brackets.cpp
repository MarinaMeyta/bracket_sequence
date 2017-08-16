#include <iostream>
#include <stack>
#include <string>
#include <set>

using namespace std;

bool check_brackets(string str) {

    stack <char> mystack;
    set <char> opening_brackets = {'(', '{', '['};

    for (int i = 0; i < str.length(); i++) {

        auto it = opening_brackets.find(str[i]);

        if (it != opening_brackets.end()) {
            mystack.push(*it);
        } else if (mystack.empty()) {
            return false;
        } else {
            char top = mystack.top();
            mystack.pop();

            if ((top == '[' and str[i] != ']') ||
                (top == '(' and str[i] != ')') ||
                (top == '{' and str[i] != '}')) {
                return false;
            }
        }
    }
    return mystack.empty();
}


int main(int argc, char* argv[]) {
    if (check_brackets(argv[1])) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
}
