#include<iostream>
#include<string>

using namespace std;

int main(){
	int n;
	cout<<"\n Enter the number of processes you want to enter -> ";
	cin>>n;
	
	int burst[n];
	
	int i;
	for(i=0;i<n;i++){
		cout<<"\n Enter burst time for Process "<<i+1<<" -> ";
		cin>>burst[i];
	}
	int Totaltime=0;
	for(i=0;i<n;i++){
		Totaltime=Totaltime+burst[i];
		cout<<"\n Time of completion for Process "<<i+1<<" -> "<<Totaltime;
		cout<<"\n Waiting Time for Process "<<i+1<<" -> "<<Totaltime-burst[i];
		
	}
	
	return 0;
}
