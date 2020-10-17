#include<iostream>
#include"binary_tree.h"
#include<queue>
using namespace std;

void printTree_lwl(BinaryTreeNode<int>* root)
{
	if(root==NULL)
	{
		return;
	}
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty())
	{
		BinaryTreeNode<int>* frontNode=pendingNodes.front();
		pendingNodes.pop();
		if(frontNode==NULL)
		{
			cout<<endl;
			if(!pendingNodes.empty())
				pendingNodes.push(NULL);
		}
		else
		{
			cout<<frontNode->data<<":";
			
			if(frontNode->left)
			{
				cout<<"L";
				pendingNodes.push(frontNode->left);
				cout<<frontNode->left->data<<",";
			}
			
			if(frontNode->right)
			{
				cout<<"R";
				pendingNodes.push(frontNode->right);
				cout<<frontNode->right->data<<endl;
			}	
			else
				cout<<endl;
		}
	}
}
BinaryTreeNode<int>* takeInput_lw()
{
	int rootdata;
	cout<<"enter root data:"<<endl;
	cin>>rootdata;
	if(rootdata==-1)
	{
		return NULL;
	}
	BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0)
	{
		BinaryTreeNode<int>* front=pendingNodes.front();
		pendingNodes.pop();
		cout<<"enter left child of "<<front->data<<endl;
		int leftchildData;
		cin>>leftchildData;
		if(leftchildData!=-1)
		{
			BinaryTreeNode<int>* child=new BinaryTreeNode<int>(leftchildData);
			front->left=child;
			pendingNodes.push(child);
		}
		cout<<"enter right child of "<<front->data<<endl;
		int rightchildData;
		cin>>rightchildData;
		if(rightchildData!=-1)
		{
			BinaryTreeNode<int>* child=new BinaryTreeNode<int>(rightchildData);
			front->right=child;
			pendingNodes.push(child);
		}
	}	
	return root;
}
//using inbuilt pair class
//it is used to decrease the time complexity to 0(n)
//if we used general way then time complexity would be 0(n^2)
pair<int,int>heightDiameter(BinaryTreeNode<int>* root)
{
	if(root==NULL)
	{
		pair<int,int> p;
		p.first=0;
		p.second=0;
		return p;
	}
	pair<int,int> leftans=heightDiameter(root->left);
	pair<int,int> rightans=heightDiameter(root->right);
	int lh=leftans.first;
	int ld=leftans.second;
	int rh=rightans.first;
	int rd=rightans.second;
	
	int height=max(lh,rh)+1;
	int diameter=max(lh+rh,max(ld,rd));
	pair<int,int> p;
	p.first=height;
	p.second=diameter;
	return p;
}

int main()
{
	BinaryTreeNode<int>* root=takeInput_lw();
	printTree_lwl(root);
	cout<<endl;
	pair<int,int> p=heightDiameter(root);
	cout<<"height:"<<p.first<<endl;
	cout<<"diameter:"<<p.second<<endl;
	delete root;
}
