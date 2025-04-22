#include <iostream>
using namespace std;

int fact(int n)
{
	if(n==0)
	return 1;
	
	return n*fact(n-1);
} 

int main()
{
	int num,factorial;
	cout<<"Enter Integer Value:";
	cin>>num;
	factorial=fact(num);
	cout<<"Factorial of "<<num<<"="<<factorial;
	return 0;
}
