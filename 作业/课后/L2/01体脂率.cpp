#include <bits/stdc++.h>
using namespace std;
int main()
{
	float height,weight,age,gender,BMI,body_fat;
	cin>>height>>weight>>age>>gender;
	BMI=weight/(height*height);
	body_fat=1.2*BMI+0.23*age-5.4-10.8*gender; 
	cout<<body_fat;
	return 0;
}
