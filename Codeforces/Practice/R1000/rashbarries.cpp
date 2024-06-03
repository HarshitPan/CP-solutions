
/*
Solution ->
for a product to be divisible by k, its any number should be divisible by k
i.e. for 2 or 3 or 5, find a[i]+j % k == 0 , j can be 0, 1 ,2,3 ... k-1
so making any one number divisible by k, we can make whole number divisible by k

edge case -> 4 
4 can be found with 2 * 2,
so we need 2 multiple of 2, 
i.e. 
if no of evens >= 2, product is divisible by 4,
else is no of evens == 1 , then we can make any other odd number even by incr 1, note that n>1 
else we can change two odd number to even, so two operations.
*/

#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);

    for(int i=0;i<n;i++) cin>>a[i];
    int mini=INT_MAX;
    int even=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            if((a[i]+j )%k ==0 ) mini =min(mini,j);
        }
        if(a[i]%2==0) even++;
    }
    if(k==4){
        if(even>=2) mini=min(mini,0);
        else if(even==1 && n>1) mini= min(mini,1);
        else if(!even){
            mini=min(mini,2);
        } 
    }
    cout<<mini<<endl;
    

}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
