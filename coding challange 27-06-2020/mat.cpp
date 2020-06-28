 #include<iostream>
 #include<vector>
 using namespace std;
 int maximalSquare(vector<vector<char>>& matrix) {
        int M = matrix.size();if(M == 0) return 0;
        int N = matrix[0].size();
        
        vector<vector<int>> DP(M+1,vector<int>(N+1,0));
        int largest = 0;
        for(int i=1; i<M+1; i++) {
            for(int j=1; j<N+1; j++) {
                if(matrix[i-1][j-1] == '1') {
                    DP[i][j] = 1 + min(DP[i-1][j-1],min(DP[i-1][j],DP[i][j-1]));
                    largest = max(DP[i][j],largest);
                }
            }
        }
        return largest*largest;
    }
  int main()
  {
  	int row,col;
  	cin>>row>>col;
  	vector<vector<char>> a;
  	for(int i=0;i<row;i++)
  	{
  		for(int j=0;j<col;j++)
  		{
  			cin>>a[i][j];
		  }
	  }
	  
	  cout<<maximalSquare(a);
	  
	  return 0;
	}  
