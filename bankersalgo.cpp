#include<iostream>

#include<string>

using namespace std;
int main(){

	int m,n;

	cout<<"\n Enter the number of processes -> ";
	cin>>m;

	cout<<"\n Enter the number of resources -> ";
	cin>>n;

	int allocated[m][n], required[m][n];

	int i,j;

	cout<<"\n Allocated Resources -> \n";
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin>>allocated[m][n];
		}
	}

	cout<<"\n Required Resources -> \n";
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin>>required[m][n];
		}
	}

	int available[n];
	cout<<"\n Available Resources -> \n";
	for(j=0;j<n;j++){
		cin>>available[j];
	}

	int count=0;
	for(i=0;i<m;i++){

		int counter=0;

		for(j=0;j<n;j++){
			if(allocated[i][j]==-1)
				break;
			if(allocated[i][j]+available[j]>=required[i][j])
				counter++;
			else
				break;
		}

		if(counter==n && allocated[i][0]!=-1){
			for(j=0;j<n;j++){
				available[j]=available[j]+allocated[i][j];
				allocated[i][j]=-1;
			}
			cout<<" <- P["<<i+1<<"] -> ";
			count++;
		}
	
		if(count==m){
			break;
		}
	
		if(i==m-1){
			i=-1;
		}
	}
	return 0;	
}
