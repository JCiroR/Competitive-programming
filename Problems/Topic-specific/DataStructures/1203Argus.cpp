#include <iostream>
#include <queue>
#include <tuple>
#include <string>

using namespace std;
// <time, period, id>
typedef tuple<int, int, int> query;

int main(void) {
    string indicator;
    priority_queue<query, std::vector<query>, greater<query>> queries;
    int period, ID, K;

    cin >> indicator;
    while(indicator == "Register") {
        cin >> ID >> period;
        queries.push(query(period, ID, period));
        cin >> indicator;
    }
    cin >> K;
    for(int i = 0; i < K; i++) {
        query next = queries.top();
        cout << get<1>(next) << "\n";
        queries.pop();
        get<0>(next) += get<2>(next);
        queries.push(next);
    }
    return 0;
}