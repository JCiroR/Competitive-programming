#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>

using namespace std;
bool myfunction (int i,int j) { return (i<j); }
int main(void) {
    int T, S, A, F;
    cin >> T;
    while(T--) {
        cin >> S >> A >> F;
        vector<int> streets;
        vector<int> avenues;
        streets.reserve(S);
        avenues.reserve(A);
        while(F--) {
            cin >> S >> A;
            streets.push_back(S);
            avenues.push_back(A);
        }
       sort(streets.begin(), streets.end(), myfunction);
       sort(avenues.begin(), avenues.end(), myfunction);

       S = (streets.size() & 1)? streets[streets.size() / 2]: streets[streets.size()/2 -1];
       A = (avenues.size() & 1)? avenues[avenues.size() / 2]: avenues[avenues.size()/2 - 1]; 
       cout << "(Street: " <<  S << ", Avenue: " << A << ")\n";

    }
    
 
    return 0;
}