/*
Implement C++ program for expression conversion infix to
postfix using stack.
*/
#include<iostream>
#include<cstring>
using namespace std;

#define MAX 100

class Postfix
{
	char stack[MAX];
	int stackIndex;
	
public:	
	Postfix() 
	{
        	stackIndex = -1;
    	}
    		
	void push(char ele)
	{
		if(stackIndex == MAX-1)
		{
			cout<<"Stack overflow";
		}
		else
		{
			stack[++stackIndex] = ele;
		}
	}
	
	char pop() 
	{
        	if (stackIndex == -1) 
        	{
            		cout << "Stack Underflow" << endl;
            		return -1; 
            	} 
            	else 
            	{
            		return stack[stackIndex--];
        	}
    	}
    	
    	bool isEmpty() 
    	{
        	return stackIndex == -1;
    	}
    
	int prec(char c)
	{
		if(c == '^')
			return 3;
		else if(c == '/' || c == '*')
			return 2;
		else if(c == '+' || c == '-')
			return 1;
		else
			return -1;
	}
	
	char associativity(char c)
	{
		char R,L;
		if(c == '^')
			return R;
		return L;
	}
	
	void infixtopostfix(char s[])
	{
		int len = strlen(s);
		char postfix[100];
		int postIndex = 0;
		char c;
		
		for(int i=0;i<len;i++)
		{
			c = s[i];
			
			if(isalpha(c) || isdigit(c))
			{
				postfix[postIndex++]=c;
			}
			
			else if(c == '(')
			{
				push(c);
			}
			
			else if(c == ')')
			{
				while(!isEmpty() && stack[stackIndex]!= '(')
				{
					postfix[postIndex++] = pop();
				}
				if (!isEmpty()) 
				{
                    			pop(); 
                		}
			}
			
			else if(c == '[')
			{
				push(c);
			}
			
			else if(c == ']')
			{
				while(!isEmpty() && stack[stackIndex]!= '[')
				{
					postfix[postIndex++] = pop();
				}
				if (!isEmpty()) 
				{
                    			pop(); 
                		}
			}
			
			else if(c == '{')
			{
				push(c);
			}
			
			else if(c == '}')
			{
				while(!isEmpty() && stack[stackIndex]!= '{')
				{
					postfix[postIndex++] = pop();
				}
				if (!isEmpty()) 
				{
                    			pop(); 
                		}
			}
			
			else
			{
				while (!isEmpty() && (prec(c) < prec(stack[stackIndex]) ||
                                       (prec(c) == prec(stack[stackIndex]) &&
                                           associativity(c) == 'L'))) 
				{
					postfix[postIndex++] = pop();
				}
				push(c);
			}
		}
		
		while (!isEmpty()) 
		{
        		postfix[postIndex++] = pop();
    		}
	
    		postfix[postIndex] = '\0';
    		cout<<"Postfix Expression is:"<<postfix<<endl;
    	}
};	
		
int main() 
{
	char exp[10];
	cout<<"Enter the Infix Expression:";
	cin>>exp;
	
	Postfix b;
	b.infixtopostfix(exp);
    	return 0;
}
