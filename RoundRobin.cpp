#include<iostream>
#include<string>

using namespace std;

int main(){
	int n,tq;
	cout<<"\n Enter the number of processes you want to enter -> ";
	cin>>n;
	
	cout<<"\n Enter the Time Quantum -> ";
	cin>>tq;
	
	int burst[n],priority[n];
	
	int i;
	for(i=0;i<n;i++){
		cout<<"\n Enter burst time for Process "<<i+1<<" -> ";
		cin>>burst[i];
	}
	
	int totaltime=0;
	int count=0;
	
	while(count<n){
	
	for(i=0;i<n;i++){
		
		if(burst[i]-tq>0){
			burst[i]=burst[i]-tq;
			totaltime=totaltime+tq;
		}
		else if(burst[i]!=0){
			totaltime=totaltime+burst[i];
			cout<<"\n Total Completion Time for process "<<i+1<<" -> "<<totaltime;
			cout<<"\n Waiting Time for process "<<i+1<<" -> "<<totaltime-burst[i];
			burst[i]=0;
			count++;
		}
		
		if(i==n-1){
			i=-1;
		}
	}
	}
	

	return 0;
}
