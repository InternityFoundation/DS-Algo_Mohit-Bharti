#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
int check_paran(string str)
{
	int res=0;
	stack <int> s;
	s.push(-1);
	int n=str.length();
	
	for(int i=0;i<n;i++)
	{
		if(str[i]=='(')
		s.push(i);
		
		else
		{
			s.pop();
			
			if(!s.empty())
			res=max(i-s.top(),res);
		    
		    else
		    s.push(i);
		}
	}
	return res;
}
int main()
{
	string s;
	cin>>s;
	cout<<check_paran(s);
	return 0;
}
