/*
College library has N books. Write C/C++ program to store the
cost of books in array in ascending order. Books are to be
arranged in descending order of their cost. Write function for
A) Copy costs of books those with cost less than 500 in new array
a) Delete the duplicate entries using temporary array
b) Delete duplicate entries without using temporary array
c) Count number of books with cost more than 500
*/
#include<iostream>
using namespace std;
int n,i=0,j=0;
class book{
	public:
	int cost;
	string title,aut;
	book(){
	string title="-";
	cost=0;
	string aut="-";
	}
	void accept();
	void display();
	void asc();
	void dec();
	void cl5();
	void count();
	void deluta();
	void del();
}b[100],t,c[100];
//accept data from user
void book::accept()
{
	cout<<"Enter book title, author, cost: ";
	cin>>title>>aut>>cost;
}
//display the book record
void book::display()
{
	cout<<"\n"<<title<<"\t"<<aut<<"\t"<<cost;
}
//display in the ascending order
void asce()
{
	cout<<"NAME\tAuthor\tCOST"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(b[i].cost>b[j].cost)
			{
				t=b[i];
				b[i]=b[j];
				b[j]=t;
			}
		}
		cout<<b[i].title<<"\t"<<b[i].aut<<"\t"<<b[i].cost<<endl;
	}
}
//display in descending order
void desc()
{
        cout<<"NAME\tAuthor\tCOST"<<endl;
        for(i=0;i<n;i++)
        {
                for(j=i;j<n;j++)
                {
                        if(b[i].cost<b[j].cost)
                        {
                                t=b[i];
                                b[i]=b[j];
                                b[j]=t;
                        }
                }
                cout<<b[i].title<<"\t"<<b[i].aut<<"\t"<<b[i].cost<<endl;
        }
}
//delete duplicate record using temporary array
void delut()
{
int k=0;
	c[0]=b[0];
          j=0;
	for(i=0;i<n;i++)
        {

		if(b[i].title!=c[j].title && b[i].aut!=c[j].aut)
		{
          		j++;
			c[j]=b[i];


		}
	}
k=j;
	cout<<"NAME\tAuthor\tCOST"<<endl;
        for(i=0;i<=k;i++)
        {
		cout<<c[i].title<<"\t"<<c[i].aut<<"\t"<<c[i].cost<<endl;

	}
}
//display books record having cost less than 500
void cl500()
{
	cout<<"NAME\tAuthor\tCOST"<<endl;
	for(i=0;i<n;i++)
	{
		if(b[i].cost<500)
		{
			b[i].display();
		}
	}
}
//display count of books having cost greater than 500
void countg500()
{
	int count=0;
        for(i=0;i<n;i++)
        {
                if(b[i].cost>500)
                {
                        count++;
                }
        }
	cout<<"The count of books having price greater than 500 is "<<count<<endl;

}
//delete without using temporary 
void delwut()
{
	int m=0;
	for(i=0;i<n;i++)
	{
		for(j=1+i;j<n;j++)
		{
			if(b[i].title==b[j].title && b[i].aut==b[j].aut)
			{
				m++;
				for(int k=j;k<n;k++)
				{
					b[k]=b[k+1];
				}
			}
		}
	}
	for(i=0;i<n-m;i++)
	{
		b[i].display();
	}


}


//main function
int main()
{
	int ch;
	cout<<"Enter the number of books to be stored: ";
	cin>>n;
	do{
		cout<<"\n\nMain Menu\n";
		cout<<"1.Accept\n2.Display\n3.Ascending\n4.Descending\n5.Delete duplicate using temporary array\n";
		cout<<"6.Books having cost less than 500\n7.Count of books having price greater than 500\n";
		cout<<"8.Delete without using temporary array\n9.Exit\n";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:for(i=0;i<n;i++)
				{
					b[i].accept();
				}
			break;
			case 2:cout<<"NAME\tAuthor\tCOST"<<endl;
				for(i=0;i<n;i++)
                                {
                                        b[i].display();
                                }
			break;
			case 3:asce();
			break;
			case 4:desc();
			break;
			case 5:delut();
			break;
			case 6:cl500();
			break;
			case 7: countg500();
			break;
			case 8:delwut();
			break;
			case 9:cout<<"\n"<<endl;
			break;
			default:cout<<"Invalid choice\n";
		}
	}while(ch!=9);


	
return 0;
}
