#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
ll n, k, temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    set<ll> s;
    while(n--)
    {
        cin >> temp;
        s.insert(temp);
    }
    for(auto it = s.begin(); it != s.end(); ++it)
    {
        auto it2 = s.find((*it) * k);
        if(it2 != s.end() && it2 != it) s.erase(it2);
    }
    cout << s.size() << endl;
}