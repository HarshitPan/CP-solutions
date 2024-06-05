/*
Solution ->
    basic sliding window,

    if temp.i > q then we start again,
    else {
        curr ++; // to add another element,

        if(curr>=k) then count += (curr-k +1) 
        i.e. say for k=3 we have curr=5,
        1 2 3 4 5
        then we can take 1 2 3 4 5, 2 3 4 5, 3 4 5.
        so using 5 i.e. a.i element we can create pair of length k ,k+1, k+2, k+3.....curr; 
        i.e. pair = all element between k and curr. 
    }
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    int curr=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]>q){
            curr=0;
        }
        else {
            curr++;
            if(curr>=k) count+=(curr-k+1);
        }
    }
    cout<<count<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}