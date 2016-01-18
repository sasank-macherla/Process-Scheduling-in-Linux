// Implementation file for Cpu scheduling

#include "scheduling.h"
#include <iostream>

using namespace std;
//Getting no of processes and Burst time
void cpuscheduling::Getdata()
{
	int i;
	cout<<"Enter the no of processes:";
	cin >>n;
	for(i=1;i<=n;i++)
	{
		cout<<"\nEnter the burstTime for Process p"<<i<<"= ";
		cin>>Bu[i];
	}
}

//First come First served Algorithm
void cpuscheduling::Fcfs()
{
	int i,B[10];
	Twt=0.0;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		cout<<"\n Burst time for process p"<<i<<"=	";
		cout<<B[i];
	}
	Wt[1]=0;
	for(i=2;i<=n;i++)
	{
		Wt[i]=B[i-1]+Wt[i-1];
	}

	//Calculating Average Weighting Time
	for(i=1;i<=n;i++)
		Twt=Twt+Wt[i];
	Awt=Twt/n;
	cout<<"\nTotal Weighting Time="<<Twt<<endl;
	cout<<"Average Weighting Time="<<Awt<<""<<endl;
}



//Priority Algorithm

void cpuscheduling::Priority()
{
	int i,B[10],P[10],j;
	w=0.0;
	int max;
	Twt=0.0;
	max=1;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		cout<<"\n Burst time for process p"<<i<<"=	";
		cout<<B[i];
		cout<<"Enter the priority for process P"<<i<<"=	"<<endl;
		cin>>P[i];
		if(max<P[i])
			max=P[i];
	}
	j=1;
	while(j<=max)
	{
		i=1;
		while(i<=n)
		{
			if(P[i]==j)
			{
				Wt[i]=w;
				w=w+B[i];
			}
			i++;
		}
		j++;
	}

	//calculating average weighting Time
	for(i=1;i<=n;i++)
		Twt=Twt+Wt[i];
	Awt=Twt/n;
	cout<<"\nTotal   Weighting Time="<<Twt<<""<<endl;
	cout<<"Average Weighting Time="<<Awt<<""<<endl;
}

//Round Robin Algorithm
void cpuscheduling::RoundRobin()
{

	int i,j,tq,k,B[10],Rrobin[10][10],count[10];
	int max=0;
	int m;
	Twt=0.0;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		cout<<"\nBurst time for process p"<<i<<"=	";
		cout<<B[i];
		if(max<B[i])
			max=B[i];
		Wt[i]=0;
	}
	cout<<"Enter the Time Quantum=";
	cin>>tq;
	//TO find the dimension of the Rrobin array
	m=max/tq+1;

	//initializing Rrobin array
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			Rrobin[i][j]=0;
		}
	}
	//placing value in the Rrobin array
	i=1;
	while(i<=n)
	{
		j=1;
		while(B[i]>0)
		{
			if(B[i]>=tq)
			{
				B[i]=B[i]-tq;
				Rrobin[i][j]=tq;
				j++;
			}
			else
			{
				Rrobin[i][j]=B[i];
				B[i]=0;
				j++;
			}
		}
		count[i]=j-1;
		i++;
	}

	cout<<"Display";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cout<<"\nRr["<<i<<","<<j<<"]="<<Rrobin[i][j];
			cout<<"	";
		}
		cout<<"";
	}
	//calculating weighting time
	int x=1;
	i=1;
	while(x<=n)
	{
		for(int a=1;a<x;a++)
		{
			Wt[x]=Wt[x]+Rrobin[a][i];
		}
		i=1;
		int z=x;
		j=count[z];
		k=1;
		while(k<=j-1)
		{
			if(i==n+1)
			{
				i=1;
				k++;
			}
			else
			{
				if(i!=z)
				{
					Wt[z]=Wt[z]+Rrobin[i][k];
				}
				i++;
			}
		}
		x++;
	}
	for(i=1;i<=n;i++)
		cout<<"\n Weighting Time for process P"<<i<<"="<<Wt[i];

	//calculating Average Weighting Time
	for(i=1;i<=n;i++)
		Twt=Twt+Wt[i];
	Awt=Twt/n;
	cout<<"Total Weighting Time="<<Twt<<endl;
	cout<<"Average Weighting Time="<<Awt<<""<<endl;
}