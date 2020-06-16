#include<iostream>
#include<map>
#include<string>
#include<math.h>
using namespace std;
bool all_codes(string s, int k) {
        map<string, int> mp;
        int n = s.length()-k;
        
        for(int i=0;i<=n;i++)
        {
            string t = s.substr(i,k);            
            mp[t]++;
        }
        
        return (mp.size() == pow(2,k));       
    }
int main()
{
	string s;
	int k;
	cin>>s;
	cin>>k;
	cout<<all_codes(s,k);
	
	return 0;
}
