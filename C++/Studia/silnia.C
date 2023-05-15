#include <iostream>
using namespace std;
int main()
{
	int silnia, liczba1=1,liczba2=1;
	cin>>silnia;
	for(int i=1;i<=silnia;i++)
	{
	liczba1=liczba1*liczba2;
	liczba2++;
	cout<<liczba1<<endl;
	}
return 0;


