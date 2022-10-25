#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define all(j) (j).begin(),(j).end() //reverse(all(a));

int main(){
	int t;
	cin>>t;
	while(t--){
	    
// 	    unordered_map<int, int> mp;
	    int n;
	    cin>>n;
		string s;
		cin>>s;
		int cnt = 0;
		for(int i = 0; i < n; i++){
		    if(s[i] == '1'){
		        cnt++;
		    }else{
		        break;
		    }
		}
		cout<<cnt<<endl;
    }
    }
