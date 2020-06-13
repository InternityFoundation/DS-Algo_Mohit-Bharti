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
struct node* lowest_common_an(struct node * root,int a,int b)
{
	if(root==NULL)
	return NULL;
	
	if(root->data==a || root->data ==b)
	return root;
	
	node* left=lowest_common_an(root->left,a,b);
	
	node* right=lowest_common_an(root->right,a,b);
	
	if(left && right)
	return root;
	
	return (left != NULL)?left:right;
}
int main()
{
	int n,a[10000];
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	node*root=create(a,root,0,n);
	int x,y;
	cout<<"enter x and y to find their ansester";
	cin>>x>>y;
	cout<<lowest_common_an(root,x,y)->data;
	return 0;
}
