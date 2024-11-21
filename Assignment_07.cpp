/*
Pizza parlor accepting maximum M orders. Orders are served in
first come first served basis. Order once placed cannot be
cancelled. Write C++ program to simulate the system using queue
using array.
*/

#include<iostream>
using namespace std;
int n=5;//size of que
int que[5];//que
int rear=-1;//to insert element
int front=-1;//to delete element
int discount;
int f=0;//to give discount to only 1st customer
int price;//to display bill

class pizza
{
string name;
int mob;
int x;
public:
void enq();
void dq();
friend void display();
void peek();//to view current order in progress
}p[5];//array of objects




void pizza::enq()
{
	//que full
	if(rear==n-1 && front==0||rear==front-1)
	{
		cout<<"Coudn't take Order.\nOther orders in progress\n";
	}
	//que empty initial condition
	else if(rear==-1 && front==-1)
	{
		rear=0;
		front=0;
		cout<<"Enter name: ";
		cin>>p[rear].name;
		cout<<"Enter mobile no : ";
		cin>>p[rear].mob;
		cout<<"Enter the number of pizzas you want: ";
		cin>>x;
		que[rear]=x;
		price=100*x;
		if(f==0){
		f=1;
		discount=price/10;
		price=price-discount;
		cout<<"You are the first customer."<<endl;
		cout<<"You got discount of {10%} per pizza"<<endl;
		cout<<"your bill is: "<<price<<endl;
		}
		else{
			cout<<"Your bill is: "<<price<<endl;
		}
	}
	else
	{
		rear=(rear+1)%n;
		cout<<"Enter name: ";
		cin>>p[rear].name;
		cout<<"Enter mobile no : ";
		cin>>p[rear].mob;
		cout<<"Enter the number of pizzas you want: ";
		cin>>x;
		que[rear]=x;
		price=100*x;
		cout<<"Your bill is: "<<price<<endl;
	}
}

void pizza::dq()
{
				if(rear==-1&&front==-1)
				{
					cout<<"NO order placed"<<endl;
				}
				else if(rear==front)
				{
					cout<<"Name : "<<p[front].name<<endl;
					cout<<"MObile No: "<<p[front].mob<<endl;
					cout<<"Order of "<<que[front]<<" pizza Served"<<endl;
					front=-1;
					rear=-1;
				}
				else{
					cout<<"Name : "<<p[front].name<<endl;
					cout<<"MObile No: "<<p[front].mob<<endl;
					cout<<"Order of "<<que[front]<<" pizza Served"<<endl;
					front=(front+1)%n;
				}
}

void display()
{
	cout<<"NAME\tMOBILE No.\tPIZZA ordered"<<endl;
	for(int i=front;i!=rear+1;i=(i+1)%n)
	{
		cout<<p[i].name<<"\t"<<p[i].mob<<"\t"<<que[i]<<endl;
	}
}

void pizza::peek()
{

if(front!=-1){
	cout<<"Name: "<<name<<"\nMobile No: "<<mob<<"\nPizza Ordered: "<<que[front]<<endl;
	}
	else{
		cout<<"No order placed yet"<<endl;
	}
}


int main()
{
int ch;
do{
	cout<<"\nMENU"<<endl;
	cout<<"1.Accept\n2.Serve\n3.Display\n4.Order in progress\n";
	cout<<"Enter your choice: ";
	cin>>ch;
	cout<<"\n";
	switch(ch)
	{
	case 1:p[0].enq();
	break;
	case 2:p[0].dq();
	break;
	case 3:display();
	break;
	case 4:p[front].peek();	
	break;
	}
}while(ch!=0);

return 0;
}
