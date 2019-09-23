#include <iostream>
#include <set>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(void) {
    int T, N, M, temp;
    cin >> T;
    while(T--) {
        int removed = 0;
        multiset<int> list1;
        multiset<int> list2;
        cin >> N >> M;
        while(N--) {
            cin >> temp;
            list1.insert(temp);
        }
        while(M--) {
            cin >> temp;
            list2.insert(temp);
        }
        multiset<int>::iterator it1 = list1.begin(), it2 = list2.begin();
        while(it1 != list1.end() && it2 != list2.end()) {
            if(*it1 == *it2) {
                it1++;
                it2++;
                continue;
            }
            else if(*it1 > *it2) it2 = list2.erase(it2);
            else it1 = list1.erase(it1);
            removed++;
        }
        removed += abs((int)(list1.size() - list2.size())); 
        cout << removed << "\n";
    }
    return 0;

}