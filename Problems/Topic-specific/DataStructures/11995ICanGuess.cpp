#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(void) {
    int n;
    while(cin >> n) {
        int command, number;
        bool candidates[3] = {true, true, true};         // Stack[0] queue[1] pqueue[2]
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        while(n--) {
            cin >> command >> number;
            if(command == 1) {
                if(candidates[0]) s.push(number);
                if(candidates[1]) q.push(number);
                if(candidates[2]) pq.push(number);
            } else {
                if(s.empty() || s.top() != number) candidates[0] = false;
                if(q.empty() || q.front() != number) candidates[1] = false;
                if(pq.empty() || pq.top() != number) candidates[2] = false;
                if(candidates[0]) s.pop();
                if(candidates[1]) q.pop();
                if(candidates[2]) pq.pop();
            }
        }
        int counter = 0;
        for(int i = 0; i < 3; i++) 
            if(candidates[i]) counter++;
        if(counter == 0) cout << "impossible\n";
        else if(counter > 1) cout << "not sure\n";
        else {
            if(candidates[0]) cout << "stack\n";
            else if(candidates[1]) cout << "queue\n";
            else cout << "priority queue\n";
        } 
    }
}