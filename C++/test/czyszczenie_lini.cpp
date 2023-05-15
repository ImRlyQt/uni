#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main()
{
  cout <<"chuj\n";
  for (int i=0;i<100;i++)
  {
    
    cout << i <<endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    cout << "\033[1A\033[2K";
  }
  return 0;
}
