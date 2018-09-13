#include <iostream>
#include <climits>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

long long  dist[103][103];

int main(void) {
    int T; 
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int N, M; long long K;
        cin >> N >> M >>K;
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                long long val = 0;
                scanf("%lld", &val);
                if(i > 0) val += dist[i-1][j];
                if(j > 0) val += dist[i][j-1];
                if(i > 0 && j > 0) val -= dist[i-1][j-1];
                dist[i][j] = val;                      
            }     
        }   
            
        int maxArea = 0; long long price = K + 1;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
               if(abs(i-(N)) * abs(j-(M)) < maxArea) break;
                for(int k = i; k < N; k++) {
                   if(abs(i-(k+1)) * abs(j-(M)) < maxArea) continue;                    
                    for(int l = j; l < M; l++) {
                        int area = abs(i-(k+1)) * abs(j-(l+1));
                        if(area < maxArea) continue;

                        long long subRect = dist[k][l];
                        if(i > 0) subRect -= dist[i-1][l];
                        if(j > 0) subRect -= dist[k][j-1];
                        if(i > 0 && j > 0) subRect += dist[i-1][j-1];

                        if(maxArea < area && subRect <= K) {
                            price = subRect;
                            maxArea = area;
                        
                        } else if(maxArea == area && subRect < price && subRect <= K) {
                            price = subRect;
                        
                        }
                        
                    }
                }
            }
        }
            
        if(price == K + 1) price = 0;
        printf("Case #%i: %i %lld\n", t, maxArea, price);
    
    }

    return 0;
}