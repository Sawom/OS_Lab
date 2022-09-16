#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

int main(){
    int request[100],i,n,initial, totalHead=0;
    /// at first we declear how many number in array and take input
    cout<<"Enter the number of request: "<<endl;
    cin>>n;
    /// now we put all this number in array
    cout<<"Enter the request sequence: "<<endl;
    for(i=0;i<n;i++){
        cin>> request[i];
    }
    /// now we take input initial head position
    cout<<"Enter initial head position: \n"<<endl;
    cin>>initial;

    /// logics for FCFS disk scheduling.
    /// here total head is the addition of total head and absulate value of request value - initial value.
    for(i=0;i<n;i++){
        totalHead= totalHead+abs(request[i]-initial);
        initial= request[i];
    }
    cout<<"total head moment: "<<totalHead<<endl;
}
