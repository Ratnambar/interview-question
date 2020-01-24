#include<iostream>
#include <stdlib.h>
#include<conio.h>

using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *head=NULL;

void insertNode();
void postOrder(struct node *root);
void preOrder(struct node *root);
void inOrder(struct node *root);

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
	// cout<<"NULL";	
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

			default:cout<<"invalid choice";
		}
		cout<<"you want to continue?"<<endl;
		ch=getche();
		}
	while(ch!='n');

	return 0;
}