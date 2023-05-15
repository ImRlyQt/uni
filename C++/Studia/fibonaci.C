#include <iostream>
using namespace std;
int main()
{
	int ile_liczb, liczba1=0, liczba2=1,liczba3=0;
	cin>>ile_liczb;
	for(int i=1;i<=ile_liczb;i++)
	{
	liczba3=liczba1+liczba2;
	liczba1=liczba2;
	liczba2=liczba3;
	cout<<liczba1<<endl;
	}
return 0;
}
