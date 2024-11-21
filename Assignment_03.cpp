/*
Write C++ program to store roll numbers of student in array who
attended training program in random order. Write function for
a) Searching whether particular student attended training
program or not using linear search . OR
a) Searching whether particular student attended training
program or not using binary search
*/

/*TRAINING PROGRAM*/

#include<iostream>
using namespace std;

int i=0,n,k,p;

class student
{
 public:
	int rno;
	string name;
	int fb[5];
	int feed;
	void accept();
	void display();
	int feedback();
	//void lsearch();

	//void bsearch();
}s[100],T;
int student::feedback()
{
	int count=0;
	cout<<"\nFEEDBACK";
	cout<<"\n1.Was session useful?";
	cin>>fb[0];
	cout<<"\n2.Was content delivered satisfactory?";
	cin>>fb[1];
	cout<<"\n3.Did you enjoy session?";
	cin>>fb[2];
	cout<<"\n4.were all points clearly explained?";
	cin>>fb[3];
	cout<<"\n5.Do you wish to attend similar program again?";
	cin>>fb[4];

	 count=fb[0]+fb[1]+fb[2]+fb[3]+fb[4];
	return count;

}

void student::accept(){
	cout<<"Enter the name and roll no: ";
	cin>>name>>rno;
	feed=feedback();
}

void student::display()
{
	cout<<rno<<"\t"<<name<<endl;
}


void lsearch()
{
	int f=0,r;
	cout<<"Enter the roll no you want to  search: ";
	cin>>r;
	for(i=0;i<n;i++)
	{
		if(s[i].rno==r)
		{
			f=1;
			cout<<"Roll no. "<<r<<" attended the training proigram"<<endl;
		}
	}
	if(f==0){
		cout<<"Roll no. "<<r<<" not attended the training proigram"<<endl;

	}
}

void bsearch()
{
        int f=0,r;
        cout<<"Enter the roll no you want to  search: ";
        cin>>r;

	for(i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(s[i].rno>s[j].rno)
			{
				T=s[i];
				s[i]=s[j];
				s[j]=T;
			}
		}
	}

	int low=0;
	int high=n-1;
	//int mid=(low+high)/2;
	while(low<=high)
	{
		 int mid=(low+high)/2;
		if(s[mid].rno==r)
		{
			f=1;
                        cout<<"Roll no. "<<r<<" attended the training proigram and found at "<<mid<<" position"<<endl;
			break;
		}
		else if(s[mid].rno>r)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	if(f==0)
 	{
		cout<<"Roll no. "<<r<<" not attended the training proigram"<<endl;

	}
}



int main()
{
	int total=0,c1=0;
	int ch;

	cout<<"Enter the total number of student that attended the session";
	cin>>n;
 do{
	cout<<"\nMain Menu\n";
	cout<<"1.Accept\n2.Display\n3.Linear search\n4.Binary search\n5.Exit\n";
	cout<<"Enter your choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:for(i=0;i<n;i++)
			{
				s[i].accept();
//				s[i].feedback();
			}
		break;
		case 2:cout<<"Roll no\tNAME\n";
			for(i=0;i<n;i++)
                        {
                                s[i].display();
                        }
                break;
		case 3:lsearch();
		break;
		case 4:bsearch();
		break;
		case 5:for(i=0;i<n;i++)
			{
				total+=s[i].feed;
			}
			 p=((float)total/(n*5))*100;
			cout<<"Response for Useful= "<<p<<endl;
			if(p>=70)
			{
				cout<<"\nResult= Session was useful.\n";
			}
			else{
				cout<<"\nResult= Session was not useful\n";
			}
		break;
		default: cout<<"\ninvalid choice\n";
	}
  }while(ch!=6);



return 0;
}
