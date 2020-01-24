#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct node{
	int data;
	struct node *next;
} ;
struct node *head=NULL;
void insertAtbeg();
void insertAtlast();
void display();
void insertAtposition();
void insertInSortedList();
void MiddleDisplay();
void revLinedlist();
void lengthOfLinkedList();
void MergeLinkedList();
void insertAtbeg()
{
	struct node *newNode;
	newNode=(struct node *)malloc(sizeof(struct node));
	cout<<"enter the node";
	cin>>newNode->data;
	newNode->next=NULL;
	if(newNode==NULL)
	{
		cout<<"empty list";
	}
	else{
		newNode->next=head;
		head=newNode;
	}

}

void insertAtlast()
{
	struct node *newNode,*p=head;
	newNode=(struct node *)malloc(sizeof(struct node));
	cout<<"enter the node";
	cin>>newNode->data;
	newNode->next=NULL;

	if(head==NULL)
	{
		head=newNode;
	}
	else{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=newNode;
		p=newNode;
	}
}


void insertAtposition()
{
	struct node *newNode,*p;
	int position,count=0,i;
	newNode=(struct node *)malloc(sizeof(struct node));
	cout<<"enter the node";
	cin>>newNode->data;
	newNode->next=NULL;
	cout<<"enter the position";
	p=head;
	cin>>position;

	for(i=0;i<position-1;i++)
	{
		p=p->next;
	}
	newNode->next=p->next;
	p->next=newNode;
	p=newNode;

}

void insertInSortedList()
{
	struct node *newNode,*p=head,*temp;
	newNode=(struct node *)malloc(sizeof(struct node));
	cout<<"Enter the Data"<<endl;
	cin>>newNode->data;
	newNode->next=NULL;

	if(head==NULL)
	{
		cout<<"List is Empty";
	}
	else
	{
		while(p!=NULL && p->data<newNode->data)
		{
			temp=p;
			p=p->next;
		}
		newNode->next=p;
		temp->next=newNode;
		temp=newNode;
	}
}

void MiddleDisplay()
{
	struct node *p=head;
	struct node *slow=head;
	if(head==NULL)
	{
		cout<<"linked list is empty";
	}
	else{
		while(p!=NULL && p->next!=NULL)
		{
			p=p->next->next;
			slow=slow->next;
		}
		cout<<slow->data<<endl;
	}
}

void revLinedlist()
{
	struct node *current=head;
	struct node *prev=NULL,*next=NULL;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;

	}
	head=prev;
}

void display()
{
	struct node *p;
	if(head==NULL)
	{
		cout<<"list is empty";
	}
	else{p=head;
	while(p!=NULL)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	cout<<"NULL";
}
}

void removeNodewithSumZero()
{
	struct node *p1=head,*p=head;
	struct node *p2=head;
	int sum=0;
	while(p!=NULL)
	{
		if(p1->data + p2->data == 0)
		{
			p1 = p2->next;
			p2 = p2->next->next;
		}
		else
		{
			sum=p1->data + p2->data;
			p2=p2->next;
			if(sum + p2->data == 0)
			{
				p1 = p2->next;
				p2 = p2->next->next;
			}

		}
	}
}


void MergeLinkedList()
{
	struct node *newNode1,*newNode2;
	struct node *p,*q;
	struct node *head1,*head2;
	head1=NULL;
	head2=NULL;
	int data1,data2;
	newNode1=(struct node *)malloc(sizeof(struct node));
	cout<<"enter data for list1"<<endl;
	cin>>data1;
	newNode1->data=data1;
	newNode1->next=NULL;
	newNode2=(struct node *)malloc(sizeof(struct node));
	cout<<"enter data for list2"<<endl;
	cin>>data2;
	newNode2->data=data2;
	newNode2->next=NULL;

	if(head1==NULL || head2==NULL)
	{
		head1=newNode1;
		head2=newNode2;
	}
	else{
		while(p->next!=NULL || q->next!=NULL)
		{
			p=p->next;
			q=q->next;
		}
		p->next=newNode1;
		p=newNode1;
		q->next=newNode2;
		q=newNode2;
	}

}

void displayMerge()
{
	struct node *p,*q;
	if(head==NULL)
	{
		cout<<"list is empty";
	}
	else{p=head,q=head;
	while(p!=NULL || q!=NULL)
	{
		cout<<p->data<<"->";
		p=p->next;
		cout<<q->data<<"->";
		q=q->next;
	}
	cout<<"NULL";
}
}

void lengthOfLinkedList()
{
	struct node *p=head;
	int count=0;
	while(p!=NULL)
	{
		p=p->next;
		count++;
	}
	if(count%2==0)
	{
		cout<<"Length of List is Even"<<endl;
	}else{
		cout<<"Length of List is Odd"<<endl;
	}
}

int main()
{
	char ch;
	int choice;
	do{
	cout<<"press 1 for insert at begining"<<endl;
	cout<<"press 2 for insert at last"<<endl;
	cout<<"press 3 for insert at position "<<endl;
	cout<<"press 4 for print list"<<endl;
	cout<<"press 5 for reverse list"<<endl;
	cout<<"press 6 for display middle element"<<endl;
	cout<<"press 7 for removeNodewithSumZero"<<endl;
	cout<<"press 8 for insertInSortedList"<<endl;
	cout<<"press 9 for Length of List"<<endl;
	cout<<"press 10 for MergeLinkedList"<<endl;
	cout<<"press 11 for displayMerge"<<endl;
	cout<<"enter the choice";
	cin>>choice;
	switch(choice)
	{
		case 1:insertAtbeg();
			   break;
		case 2:insertAtlast();
			   break;
		case 3:insertAtposition();
			   break;
		case 4:display();
				break;
		case 5:revLinedlist();
			   break;
		case 6:MiddleDisplay();
			   break;
		case 7:removeNodewithSumZero();
			   break;
		case 8:insertInSortedList();
			   break;
		case 9:lengthOfLinkedList();
			   break;
		case 10:MergeLinkedList();
			    break;
		case 11:displayMerge();
				break;
		default:cout<<"invalid Choice";
	}
	cout<<"do you want to continue?";
	ch=getche();
	}while(ch!='n');
	return 0;
}