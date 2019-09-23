#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<char> s;
    string line; 
    cin >> line;
    for(int i = 0; i < line.size(); i++)
        if(line[i] == ')' && !s.empty() && s.top() == '(') s.pop();
        else s.push(line[i]);
    cout << line.size() - s.size() << endl;            
}