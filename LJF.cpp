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

	int totaltime=0;
	int count=0;
	while(count<n){
	
		int j,max=INT_MIN;
		for(i=0;i<n;i++){
			if(burst[i]!=0){
				if(max<=burst[i]){
					max=burst[i];
					j=i;
				}	
			}
		}
		
		totaltime=totaltime+burst[j];
		cout<<"\n Total completion time taken by process "<<j+1<<" -> "<<totaltime;
		count++;
		burst[j]=0;
	}
	
	return 0;
}
