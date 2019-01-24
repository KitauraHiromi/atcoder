#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
 
//INSERT ABOVE HERE
signed main(){
  Int l,n;
  cin>>l>>n;
  vector<Int> x(n);
  for(Int i=0;i<n;i++) cin>>x[i];
  Int ans=0;
  for(Int uku=0;uku<2;uku++){
    vector<Int> sm1(n+1,0),sm2(n+1,0);    
    for(Int i=0;i<n;i++){
      sm1[i+1]=sm1[i]+x[i]*2;      
      sm2[i+1]=sm2[i]+(l-x[n-(i+1)])*2;
    }
    chmax(ans,x.back());
    for(Int i=0;i<n;i++){
      Int k=n-(i+1);
      Int a=k/2,b=k-a;
      if(a==b){
        chmax(ans,sm1[i+1+a]-sm1[i]+sm2[b]-x[i+a]);        
      }else{
        chmax(ans,sm1[i+1+a]-sm1[i]+sm2[b]-(l-x[n-b]));
      }      
    }
    reverse(x.begin(),x.end());
    for(Int &a:x) a=l-a;
  }
  cout<<ans<<endl;
  return 0;
}