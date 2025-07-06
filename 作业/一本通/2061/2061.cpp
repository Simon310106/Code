#include <iostream>
#include <iomanip> 
using namespace std;
int main()
{
	cout<<fixed<<setprecision(2);
	//S三=底*高/2
	//S梯=（上底+下底）*高/2 
	cout<<(15+25)*(150*2/15.0)/2.0;
	return 0;
}
