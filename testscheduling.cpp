//Application file for cpu Scheduling
#include "scheduling.h"
#include<iostream>
using namespace std;

void main()
{
	int ch,cho;
	cpuscheduling c;
	do
	{
		cout<<"Enter the BurstTimes " << endl;
		c.Getdata();
		cout << " Please select the required algorithm " << endl;
		cout << " ************************************" << endl;
		cout<<"1.FirstComeFirstServed " << endl;
		cout<<"2.RoundRobin " << endl;
		cout<<"3.Priority " << endl;
		cout<<"4.EXIT " << endl;
		cout << "Enter your choice " << endl;
		cin >> ch;
		switch(ch)
		{
			case 1:
			cout<<"FIRST COME FIRST SERVED SCHEDULING " << endl;
			c.Fcfs();
			break;
			case 2:
				cout << "ROUND ROBIN SCHEDULING " << endl;;
			c.RoundRobin();
			break;
			case 3:
				cout << "PRIORITY SCHEDULING " << endl;
			c.Priority();
			break;
			case 4:
			break;
		}
	}while(ch<=3);
	system("pause");
}
