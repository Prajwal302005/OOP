#include<iostream>
using namespace std;
class circle{
	public:
		int r;
		float  area;
		float circumference;
		
	circle(){
			cout<<"Enter Radius: ";
			cin>> r;
			area = 3.142*r*r;
			circumference = 2*3.142*r;
			cout<< " area1: "<< area<<"\n";
			cout<<"Circum1: "<< circumference<<"\n";
		}
	circle(int r1){
			r = r1;
			area = 3.142*r*r;
			circumference = 2*3.142*r;
			cout<< "\n area2: "<< area<<"\n";
			cout<<"Circum2: "<< circumference<<"\n";
			
		}
		
	circle(circle &obj)
	{
			r = obj.r;
			area = 3.142*r*r;
			circumference = 2*3.142*r;
			cout<< "\n area3: "<< area<<"\n";
			cout<<"Circum3: "<< circumference<<"\n";
			
		}
	~circle();
		
};

int main(){
	circle obj1;
	circle obj2(3);
	{circle obj3(obj2);}
	cout<<"Finished"<<"\n";
	return 0;
}
circle::~circle()
{
	cout<<"Destructor run"<<"\n";
}
