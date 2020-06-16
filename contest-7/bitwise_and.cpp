#include <bits/stdc++.h> 
#define pp long long 
  
using namespace std; 
pp bit_wise_AND(pp a, pp b){ 
while(a < b){ 
    b -= (b & -b); 
} 
return b; 
} 
// Driver code 
int main(){ 
    pp a, b; 
    cin>>a>>b; 
    cout << bit_wise_AND(a, b); 
} 
