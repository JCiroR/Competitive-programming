#include <utility>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> point;
typedef pair<point, point> segm;

bool eq(segm s1, segm s2) {
    if(s1.first == s2.first && s1.second == s2.second) return true;
    if(s1.second == s2.first && s1.first == s2.second) return true;
    return false;
}

bool intersects(segm s1, segm s2) {
    return(s1.first == s2.first || s1.second == s2.second || s1.second == s2.first || s1.first == s2.second);
}

int main() {
    ll x1,y1,x2,y2;
    bool ok = true;
    vector<segm> H, V;
    for(int i = 0; i < 4; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        point p1(x1,y1), p2(x2,y2);
        if(p1 == p2) ok = false;
        segm Si(p1, p2);
        if(x1 == x2) V.push_back(Si);
        else if(y1 == y2) H.push_back(Si);
        else ok = false;
    }
    if(H.size() == 2 && V.size() == 2 && ok) {
        if(eq(H[0], H[1]) || eq(V[0], V[1])) ok = false;
        if(!ok) goto LAWEA;
        for(int i = 0; i < 2; i++) {
            int inters = 0;
            for(int j = 0; j < 2; j++)
                if(intersects(H[i], V[j])) inters++;            
            if(inters != 2) ok = false;
        }        
    } else ok = false;
    LAWEA:
    cout << ((ok)? "YES\n":"NO\n");
}