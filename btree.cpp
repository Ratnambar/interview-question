#include<iostream>
#include <stdlib.h>
#include<conio.h>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node *head=NULL;

void insertNode();
int heightOfBtree(struct node* root);

struct node* createNode(int n)
{
	struct node *newNode;
	newNode=(struct node *)malloc(sizeof(struct node));
	cin>>n;
	newNode->data=n;
	newNode->left=newNode->right=NULL;
	return newNode;
}

struct node* insertNode(struct node* root ,int n)
{
	if(root==NULL)
	{
		root = createNode(n);
	}
	else
	{		
		if(n<root->data)
		{
			root->left=insertNode(root->left,n);			
		}
		else
		{
			root->right=insertNode(root->right,n);
		}
	}
	return root;
}

void postOrder(struct node* root)
{
	if(root==NULL)
	 return;
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<"->";	
}

void preOrder(struct node* root)
{
	if(root==NULL)
		return;
	preOrder(root->left);
	cout<<root->data<<"->";
	preOrder(root->right);
}

void inOrder(struct node* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<"->";
	inOrder(root->left);
	inOrder(root->right);
}

int find(struct node* root,int n)
{
	if(root==NULL || root->data==n)
	{
		return 1;
	}
	else if(n<root->data)
		return find(root->left,n);
	else if(n>root->data)
		return find(root->right,n);
}

int findMax(struct node* root)
{
	int root_val,left,right,max=0;
	if(root!=NULL)
	{
		root_val=root->data;
		left=findMax(root->left);
		right=findMax(root->right);
		if(left>right)
			max=left;
		else max=right;
		if(root_val>max)
			max=root_val;
	}
	return max;
}

int sizeofBtree(struct node* root)
{
	if(root==NULL)
		return 0;
	else
		return(sizeofBtree(root->left)+1+sizeofBtree(root->right));
}

void GivenLevel(struct node* root,int level)
{
	if(root==NULL)
		return;
	if(level==1)
		cout<<root->data<<" ";
	else if(level>1)
	{
		GivenLevel(root->left,level-1);
		GivenLevel(root->right,level-1);
	}
}

void printLevel(struct node* root)
{
	int h=heightOfBtree(root);
	int i;
	for(i=1;i<=h;i++)
	{
		GivenLevel(root,i);
	}
}

int heightOfBtree(struct node* root)
{
	int leftHeight,rightHeight;
	if(root==NULL)
		return 0;
	else
	{
		leftHeight=heightOfBtree(root->left);
		rightHeight=heightOfBtree(root->right);
		if(leftHeight>rightHeight)
			return leftHeight+1;
		else
			return rightHeight+1;
	}
}

int sumOfAllNodes(struct node* root)
{
	if(root==NULL)
		return 0;
	else
		return (root->data+sumOfAllNodes(root->left)+sumOfAllNodes(root->right));
}

int main()
{
	char ch;
	int choice,n;
	struct node* root=NULL;
	do{
		cout<<"press 1 for insertion"<<endl;
		cout<<"press 2 for postOrder"<<endl;
		cout<<"press 3 for preOrder"<<endl;
		cout<<"press 4 for inOrder"<<endl;
		cout<<"press 5 for Search element"<<endl;
		cout<<"press 6 for Search largest element"<<endl;
		cout<<"press 7 for sizeofBtree"<<endl;
		cout<<"press 8 for heightOfBtree"<<endl;
		cout<<"press 9 for printLevel"<<endl;
		cout<<"press 10 for sumOfAllNodes"<<endl;
		cout<<"enter the choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:root = insertNode(root,n);
				   break;

			case 2:postOrder(root);
				   break;

			case 3:preOrder(root);
				   break;

			case 4:inOrder(root);
				   break;

			case 5:cout<<"enter element to be search"<<endl;
					cin>>n;
					if(find(root,n)==1)
						cout<<"item found"<<endl;
					else
						cout<<"item not found"<<endl;
					break;

			case 6:cout<<"Largest element in the tree is = "<<findMax(root)<<endl;
				   break;

			case 7:cout<<"Size of Binary tree is = "<<sizeofBtree(root)<<endl;
				   break;

			case 8:cout<<"height of Binary tree is = "<<heightOfBtree(root)<<endl;
				   break;

			case 9:cout<<"Level oreder tree traverasl is : ";
					printLevel(root);
					cout<<endl;
				   break;

			case 10:cout<<"sum Of AllNodes = "<<sumOfAllNodes(root)<<endl;
				    break;

			default:cout<<"invalid choice";
		}
		cout<<"you want to continue?"<<endl;
		ch=getche();
		}
	while(ch!='n');

	return 0;
}