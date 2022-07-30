problem link : https://www.spoj.com/problems/PRIME1/
#include <iostream>
#include <vector>
#define N 100000
#define int long long int
#define pb push_back

using namespace std;

vector<int> prime;

int seiveArr[N+1]={};



void seive(){

    for(int i = 2;i<=N;i++){
        if(!seiveArr[i]){
            prime.pb(i);
           for(int j = i*i; j <=N;j+=i)
             seiveArr[j] = 1;
        }
    }
}

int32_t main(){

    // freopen("input.txt","r",stdin);
    // freopen("output1.txt","w",stdout);
  seive();
  int t,m,n;
  cin >> t;
  while(t--){
    cin >> m >> n;
    vector<int>segment(n-m+1,0);
    for(auto x:prime){
        
        if(x*x > n) break;

        int start = (m/x)*x;

        if(x >= m && x <= n)
            start = 2*x;

        for(int i = start;i <= n;i+=x){
            if(i < m) continue;
            segment[i-m] = 1;
        }

    }
    for(int i = m; i <= n;i++){
        if(!segment[i-m] && i!=1)
            cout << i << endl;
    }
    cout << endl;
  }
  return 0;
}
