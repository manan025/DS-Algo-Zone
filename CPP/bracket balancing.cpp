Time Complexity: O(n) 
Auxiliary Space: O(n) for stack. 
#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 101
int A[MAX_SIZE];
int top=-1;
bool samepair(char open,char close)
{
	if(open == '(' && close == ')') return true;
	else if(open == '{' && close == '}') return true;
	else if(open == '[' && close == ']') return true;
	return false;
}
void Push (int x)
{
    if (top==MAX_SIZE-1)
    {cout<<"Stack overflow"<<endl;
    return;}
    top=top+1;
    A[top]=x;
    
}
void  Pop()
{
    if(top==-1)
    {cout<<"No element to Pop";
      return;
    }
    top--;


}
int Top ()
{
    return A[top];
}
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
			Push(s[i]);
		else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			if(top==-1 || !samepair(Top(),s[i]))
				{
                    cout<<"Not Balanced"<<endl;
                    return 0;
                }
			else
				Pop();
		}
    }
    if(top==-1)
    cout<<"Balanced"<<endl;
    else
    cout<<"Not Balanced"<<endl;
}


