#include<iostream>
#include<string>

using namespace std;

int main(){
	int n;
	cout<<"\n Enter the number of processes you want to enter -> ";
	cin>>n;
	
	int burst[n],priority[n];
	
	int i;
	for(i=0;i<n;i++){
		cout<<"\n Enter burst time for Process "<<i+1<<" -> ";
		cin>>burst[i];
	}
	for(i=0;i<n;i++){
		cout<<"\n Enter Priority for Process "<<i+1<<" -> ";
		cin>>priority[i];
	}
	int totaltime=0;
	int count=0;
	while(count<n){
	
		int j,min=INT_MAX;
		for(i=0;i<n;i++){
			if(priority[i]!=-1){
				if(min>=priority[i]){
					min=priority[i];
					j=i;
				}	
			}
		}
		
		totaltime=totaltime+burst[j];
		cout<<"\n Total completion time taken by process "<<j+1<<" -> "<<totaltime;
		count++;
		priority[j]=-1;
	}
	
	return 0;
}
