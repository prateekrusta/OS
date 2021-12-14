#include<bits/stdc++.h>
using namespace std;
#define nl endl
class Process{
    public:
    int pid,at,bt,ct,tbt;
};
void customSort(Process *arr, int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i].at > arr[j].at){
                swap(arr[i], arr[j]);
            }
        }
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].bt > arr[j].bt)
            {
                if (arr[i].at == arr[j].at)
                    swap(arr[i], arr[j]);
            }
        }
    }
}
int main(){
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"\nEnter the arrival times: ";
    Process arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i].at;
    cout<<"\nEnter the burst times: ";
    for(int i=0;i<n;i++){
        cin>>arr[i].bt;
        arr[i].tbt=arr[i].bt;
    }
    cout<<"\nEnter the time quantum: ";
    int tq;
    cin>>tq;
    for(int i=0;i<n;i++)
    arr[i].pid=i+1;
    int p=0;
    customSort(arr,n);
    int time=arr[0].at;
    int ct[n];
    while(p<n){
        int index=0;
        int mb=999;
        for(int i=0;i<n;i++){
            if(arr[i].at<=time && mb>arr[i].bt){
                index=i;
                mb=arr[i].bt;
            }
        }
        if(arr[index].bt > tq){
            time+=tq;
            arr[index].bt-=tq;
        }
        else{
            time+=arr[index].bt;
            arr[index].bt=999;
            arr[index].ct=time;
            p++;
        }
    }
    int tat[n],wt[n];
    
    for(int i=0;i<n;i++){
        tat[i]=arr[i].ct-arr[i].at;
        wt[i]=tat[i]-arr[i].tbt;
    }
    
    cout<<"PN    AT    BT    CT    TAT    WT    "<<nl;      
    for(int i=0;i<n;i++){
        cout<<arr[i].pid<<"     "<<arr[i].at<<"     "<<arr[i].tbt<<"     "<<arr[i].ct<<"    "<<tat[i]<<"     "<<wt[i]<<"     "<<nl;
    }
    cout<<nl;
}