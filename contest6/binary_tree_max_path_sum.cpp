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
int find_max(node *root,int &sum)
{
	if(root==NULL)
	return 0;
	
	int l=find_max(root->left,sum);
	int r=find_max(root->right,sum);
	
	int s=max(max(l,r)+root->data,root->data);
	
	int p=max(s,l+r+root->data);
	
	sum=max(sum,p);
	
	return s;
}
int maximum_sum(node *root)
{
	int sum=INT_MIN;
	find_max(root,sum);
	return sum;
}
int main()
{
	int n,a[10000];
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	node*root=create(a,root,0,n);
	cout<<maximum_sum(root);
	return 0;
}
