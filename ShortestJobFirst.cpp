#include<iostream>
using namespace std;
int main(){
    int n,i,j,temp;
    cout<<"Enter how many process"<<"\n";
    cin>>n;
    int burst_time[n],process[n];
    for(i=0;i<n;i++){
        cout<<"Enter burst time of process"<<i+1<<":";
        cin>> burst_time[i];
        process[i]=i+1;
    }
    /// bubble sort
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(burst_time[i]>burst_time[j]){
                /// burst time sort
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
                /// process time sort
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }
    /// waiting time calculate
    int waiting_time = 0;
    for(i=0;i<n;i++){
        cout<<"waiting time of process - "<<process[i]<<":"<<waiting_time<<"\n" ;
        waiting_time=waiting_time+burst_time[i];
    }
    return 0;
}
