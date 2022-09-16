#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    /** bt= burst time, wt = waiting time, tat= turn around time
	, avwt=  avg waiting time , avtat= avg turn around time  */
    cout<<"Enter total number of processes(maximum size 20):";
    cin>>n;
    /// input burst time here
    cout<<"\nEnter Process Burst Time\n";
    for(i=0;i<n;i++){
        cout<<"P["<<i+1<<"]:";
        cin>>bt[i];
    }
    wt[0]=0;
    /**waiting time for the first process is 0
    calculating waiting time */
    for(i=1;i<n;i++){
        wt[i]=0;
        for(j=0;j<i;j++){
                wt[i]+=bt[j];
        }
    }
    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
    ///calculating turnaround time
    for(i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
        avwt=avwt+wt[i];
        avtat=avtat+tat[i];
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
    }
    avwt=avwt/i;
    avtat=avtat/i;
    cout<<"\n\n Average Waiting Time:"<<avwt;
    cout<<"\n Average Turnaround Time:"<<avtat;
    return 0;
}
