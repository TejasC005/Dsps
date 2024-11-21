/*
Check if the entrerd string is a pallindrome or not
using the stack operations
*/
#include<iostream>
using namespace std;

char stack[20];
int n,i;
string s1;
int len=0;
int top=-1;
int length(string ss)
{
	int len1=0;
	for(i=0;ss[i]!='\0';i++)
	{
		len1++;
	}
	return len1;
}
//Stack push Operatiom
void push()
{
	if(top==len)
	{
		cout<<"\nStack Full";
	}
	else{
		for(top=0;top<len;top++)
		{
			stack[top]=s1[top];
		}
		top--;
		cout<<"\nString pushed successfully";
	}
}
//Display stack
void display()
{
	if(top==-1)
	{
		cout<<"\nStack empty";
	}
	else{
	cout<<"\nStack is as follows:";
	for(i=top;i>=0;i--)
	{
		cout<<"\n"<<stack[i];
	}
	}
}
//POp all elements in the stack
void pop(){
	if(top==-1)
	{
		cout<<"\nStack empty";
	}
	else{
		while(top!=-1)
		{
		top--;
		}
	}
}
//Check if pallindrome or not
void check()
{
	cout<<"top is : "<<top<<endl;
	int f=0;
	for(i=0;i<len;i++)
	{
		if(stack[top]!=s1[i])
		{
			f=1;
		}
		else{
		
			top--;
		}
	}
	if(f==1)
	{
		cout<<"\nEntered string is not a Pallindrome";
	}
	else{
		cout<<"\nEntered string is Pallindrome";
	}
}

int main()
{
	int ch;
	cout<<"\nEnter string: ";
	cin>>s1;
	n=len;
	do{
		cout<<"\nMAIN MENU";
		cout<<"\n1.Push string to stack";
		cout<<"\n2.Check if pallindrome or not";
		cout<<"\n3.Pop all";
		cout<<"\n4.Display stack elements";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:len=length(s1);
			cout<<len<<endl;
			push();
		break;
		case 2: check();
		break;
		case 3: pop();
		break;
		case 4: display();
		break;
		default: cout<<"\nInvalid choice"<<endl;
		
		}	
	}while(ch!=0);		
return 0;
}

