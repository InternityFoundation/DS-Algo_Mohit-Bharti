#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	int data;
	node* left;
	node *right;
};
struct node* newnode(int x)
{
	struct node* temp=new node();
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
node* create(int a[],node *root,int i,int n)
{
	if(i<n)
	{
		node *temp=newnode(a[i]);
		root=temp;
		//insert left child
		root->left=create(a,root->left,2*i+1,n);
		//insert right child
		root->right=create(a,root->right,2*i+2,n);
	}
	return root;
}
/*void maximum(int a[],int n)
{
	
	cout<<a[0]<<" ";
	int j=1,i=2;
	while(i<n)
	{
		int x=0;
		while(j<=i)
		{
			x=max(x,a[j]);
			j++;
		}
		cout<<x<<" ";
		
		i=2*(i+1);
		x=0;
	}
 }
 */ 
 void largest(node * root,vector<int> &result,int b)
 {
 	if(!root)
 	return;
 	
 	if(b==result.size())
 	result.push_back(root->data);
 	
 	else
 	result[b]=max(result[b],root->data);
 	
 	largest(root->left,result,b+1);
 	largest(root->right,result,b+1);
 }
 vector<int>largest_value(node *root)
 {
 	vector<int> result;
 	largest(root,result,0);
 	return result;
 }
int main()
{
	int n,a[10000];
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	node*root=create(a,root,0,n);
	//maximum(a,n);
	vector<int> res=largest_value(root);
	for(int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	return 0;
}
