#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int c=0;
int c1=0;
struct node{
	int id,info;
	struct node *next,*back;
};
void print(struct node *start)
{
	node *ptr=start;
	while(ptr->next!=start)
	{
		cout<<ptr->id<<" "<<ptr->info<<"\n";
		ptr=ptr->next;
	}
	cout<<ptr->id<<" "<<ptr->info<<"\n\n";
}
struct node *Insert(struct node *start)
{
	node *ptr,*n;
  int r=rand()%7;
	time_t t;
	srand((unsigned) time(&t));
  if(r!=0){
	for(int i=0;i<r;i++)
	{
		c=i;
		n=new node;
		n->id=c;
		n->info=rand()%50;
		if(start==NULL)
		{
			start=n;
			n->next=start;
			n->back=start;
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
			{
				ptr=ptr->next;
			}
			ptr->next=n;
			n->next=start;
			n->back=ptr;
			start->back=n;
		}
	}
  }
	return start;
}
struct node* insert1(struct node *start){
	cout<<"\nNew process added"<<endl;
	struct node *ptr;
	time_t t;
	srand((unsigned) time(&t));
	if(c<10){
	struct node *n;
	n=new node;
	n->id=++c;
	n->info=rand()%50;
		if(start==NULL)
		{
			start=n;
			n->next=start;
			n->back=start;
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
			{
				ptr=ptr->next;
			}
			ptr->next=n;
			n->next=start;
 			n->back=ptr;
			start->back=n;
		}
}
	return start;
}
int func(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start){
		if(ptr->info!=-1){
		return 1;
		}
		ptr=ptr->next;
	}
	return 0;
}
void RoundRobin(struct node *start,int q)
{
	cout<<"Gantt Chart Is Given By\n";
	int t=0;
	struct node *ptr=start;
  while(func(start))
  { 
  if(ptr->info!=0 || ptr->info!=-1)
  	cout<<"| "<<ptr->id<<" ";
  	if(ptr->info==0)
  	{  ptr->info=-1;
  	   start=insert1(start);
       cout<<endl;
       print(start);
  	ptr=ptr->next;
	  }
	  else if(ptr->info==-1)
	  ptr=ptr->next;
  	 else if(ptr->info>q)
  	{
  		ptr->info=ptr->info-q;
		ptr=ptr->next; 
	}
	else
	{
		t=t+(q-ptr->info);
		ptr->info=0;
		ptr=ptr->next;
	}
  }
}
int main()
{
	struct node *start=NULL;
	start=Insert(start);
	cout<<"The Processes Are:-"<<endl;
	print(start);
	int q=rand()%7;
	if(q>0)
	{
	cout<<"Quantum Number Is "<<q<<endl;
	RoundRobin(start,q);
    }
else
cout<<"Quantum Number Is Invalid"<<endl;
	return 0;
}
