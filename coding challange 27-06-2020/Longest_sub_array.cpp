#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;
int L_sub_array(vector<int>& nums,int n) 
{
        unordered_map<int,int>x;
        x[0] =0;
        int ans=0;
        int p=0;
        
        for(int i=0;i<n;i++){
            p += (nums[i] == 1 ? 1 :-1);
            if(x.find(p)!= x.end())
                ans = max(ans, i+1 -x[p]);
            else
                x[p] = i+1;
        }
        return ans;
    
	}
int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	
	for(int i=0;i<n;i++)
	 cin>>a[i];
	 
	 cout<<L_sub_array(a,n);
	 return 0;
}
