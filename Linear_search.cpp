#include <iostream>
using namespace std;
int n;//variable to accept size from user


class lsearch{
    private:
        int a[20];
        int target;//to get target element from user 
    public:
        void accept();
        int l_search();
        int occur();
        int FALindex();
};
//Accept array size and array elements from user
void lsearch::accept(){
    cout<<"Enter the size of array ";
    cin>>n;
    cout<<"Enter the array elements ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

//Accept target element and return its value
int lsearch::l_search()
{
    cout<<"Enter the target element to be searched : ";
    cin>>target;
    int i,flag=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==target)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        return i;//return the index
    }
    else{
        return -1;
    }
}
//Count the total occurence of element
int lsearch::occur(){
    int i,count=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==target)
        {
            count++;
        }
    }
    if(count!=0)
    {
        return count;
    }
    else{
        return 0;
    }
}

int main() {
    // Write C++ code here
    lsearch b;
    b.accept();
    int flag=b.l_search();
    cout<<"Target element :\n";
    if(flag>=0)
    {
        cout<<"Status: Found at "<<flag<<" index.\n";
    }else{
        cout<<"Status: Not Found.\n";
    }
    int occurence=b.occur();
    if(occurence!=0)
    {
        cout<<"\nOccurence: "<<occurence<<" times.\n";
        cout<<"First Index: "<<flag<<endl;
        cout<<"Last Index: "<<flag+occurence-1<<endl;
    }else{
        cout<<"\nOccurence: 0 times.";
    }
    return 0;
}
