/* Notes : 
    * Tower of Hanoi is one of the most famous questions in recursion
    * In this I have used recursive approach to implement tjis problem
    * Time complexity is O(2^n)
*/

#include<bits/stdc++.h>
using namespace std;

//working implementation of tower of hanoi
void toh(int n,char from, char help,char to)
{ 
	if(n==1)
	{
		cout<<"Move Disk "<<n<<" from "<<from<<" to "<<to<<endl;
		return;
	}
	
	toh(n-1,from,to,help);
	cout<<"Move Disk "<<n<<" from "<<from<<" to "<<to<<endl;
	toh(n-1,help,from,to);
}

//main program
int main()
{ 
	int n;
	
	cout<<"Enter no. of disks:";	
	cin>>n;
	
	toh(n,'A','B','C'); // calling function toh
	
	return 0;
}