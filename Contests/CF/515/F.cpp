#include <bits/stdc++.h>



template <class T>
inline void hash_combine(std::size_t & seed, const T & v)
{
  std::hash<T> hasher;
  seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
 
namespace std
{
  template<typename S, typename T> struct hash<pair<S, T>>
  {
    inline size_t operator()(const pair<S, T> & v) const
    {
      size_t seed = 0;
      ::hash_combine(seed, v.first);
      ::hash_combine(seed, v.second);
      return seed;
    }
  };
}

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, int> inf;
typedef pair<pii, inf> step;

const int N = 2e5 + 10;
pii points[N];
vector<pii> lev[N];
vector<pii> answers;
int n, g;
unordered_map<pii, ll> distances(N*2);

bool beforeThan(pii a, pii b) {
    int a_lev = max(a.first, a.second);
    int b_lev = max(b.first, b.second);
    int a_sublev = min(a.first, a.second);
    int b_sublev = min(b.first, b.second);

    if(a_lev < b_lev || (a_lev == b_lev && a_sublev < b_sublev)) return true;
    return false;
}

ll dis(pii a, pii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void bfs() {
    queue<step> q;
    step init(pii(0,0), inf(0,-1));
    q.push(init);

    while(!q.empty()) {
        step s = q.front();
        int nextG = s.second.second + 1;
        ll cdis = s.second.first;
        pii coord = s.first;
        q.pop();

        if(distances.count(coord) > 0 && distances[coord] <= cdis) continue;
        distances[coord] = cdis;
        if(nextG > g) continue;
        pii p1, p2;
        if(lev[nextG].size() == 1) {
            p1 = lev[nextG][0];
            step nextStep(p1, inf(cdis + dis(coord, p1), nextG));
            q.push(nextStep);
        } else if (lev[nextG].size() == 2) {
            p1 = lev[nextG][0];
            p2 = lev[nextG][1];
            ll path1 = dis(coord, p1) + dis(p1, p2) + cdis;
            ll path2 = dis(coord, p2) + dis(p2, p1) + cdis;
            step nextStep1(p1, inf(path2, nextG));
            step nextStep2(p2, inf(path1, nextG));
            q.push(nextStep1);
            q.push(nextStep2);
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        points[i] = pii(x, y);        
        lev[i].clear();
    }
    sort(points, points + n,  beforeThan);
    g = -1;
    int last_lev = 0;
    pii lastPoint;
    bool xAxis, yAxis;
    for(int i = 0; i < n; i++) {
        pii p = points[i];
        int p_lev = max(p.first, p.second);
        int p_sublev = min(p.first, p.second);
        if(p_lev != last_lev) {
            if(lev[g].size() == 1) lev[g].push_back(lastPoint);
            g++;
            last_lev = p_lev;
            xAxis = yAxis = false;
            answers.clear();
        }
        if(p_sublev == p.first && !xAxis) {
            xAxis = true;
            lev[g].push_back(p);
            answers.push_back(p);
        }
        if(p_sublev == p.second && !yAxis) {
            yAxis = true;
            lev[g].push_back(p);
            answers.push_back(p);
        }
        lastPoint = p;
    }
    if(lev[g].size() == 1) { 
        lev[g].push_back(lastPoint);
        answers.push_back(lastPoint);
    }
    // cout << lev[0][0].first << "," << lev[0][0].second << ";" << lev[0][1].first << "," << lev[0][1].second << endl;
    bfs();
    ll ans = LLONG_MAX;
    for(int i = 0; i < answers.size(); i++) {
        ans = min(ans, distances[answers[i]]);
    }
    cout << ans << endl;
}