#include<iostream>
#include<string>

using namespace std;
int main(){

	int n,tq;

	cout<<"\n Enter the number of processes -> ";
	cin>>n;
	
	cout<<"\n Enter the Time Quantum -> ";
	cin>>tq;
	
	int burst[n];
	
	int i,j;
	for(i=0;i<n;i++){
		cout<<"\n Enter burst time for Process "<<i+1<<" -> ";
		cin>>burst[i];
	}
	
	int count=0;
	int totaltime=0;
	while(count<n){
		int max=INT_MIN;
		for(i=0;i<n;i++){
			if(burst[i]!=-1){
				if(max<=burst[i]){
					max=burst[i];
					j=i;
				}
			}
		}
		
		if(burst[j]-tq>0)
		{
			burst[j]=burst[j]-tq;
			totaltime=totaltime+tq;
		}
		else if(burst[j]!=-1)
		{
			totaltime=totaltime+burst[j];
			burst[j]=0;
		}
		
		if(burst[j]==0){
			cout<<"\n Total completion time of Process "<<j+1<<" -> "<<totaltime;
			burst[j]=-1;
			count++;
		}
		
	}
	
	
	
	return 0;
}
