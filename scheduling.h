#include<iostream>


class cpuscheduling
{
	int n,Bu[20];
	float Twt,Awt,A[10],Wt[10],w;
public:
	//Getting the No of processes & burst time
	void Getdata();
	//First come First served Algorithm
	void Fcfs();
	//Round Robin Algorithm
	void RoundRobin();
	//Priority Algorithm
	void Priority();
};