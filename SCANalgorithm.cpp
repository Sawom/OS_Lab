#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

int main(){
    int request[100],i,j,n,totalHead=0,initial,sizee,movee,temp,index;
    cout<<"Enter the number of request: "<<endl;
    cin>>n;
    cout<<"Enter the request sequence: "<<endl;
    for(i=0;i<n;i++){
        cin>> request[i];
    }
    /// now we take input initial head position
    cout<<"Enter initial head position: \n"<<endl;
    cin>>initial;
    cout<<"enter total disk size: "<<endl;
    cin>>sizee;
    cout<<"Enter the head movement direction for high 1 and low 0: "<<endl;
    cin>>movee;
    /// now we sort the request array
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(request[j]>request[j+1]){
               temp= request[j];
                request[j] =request[j+1];
                request[j+1] = temp;
            }
        }
    }
    for(i=0;i<n;i++){
        if(initial<request[i]){
            index=i;
            break;
        }
    }
    /// if movement is towards high value
    if(movee==1){
        for(i=index;i<n;i++){
            totalHead= totalHead+abs(request[i]-initial);
            initial = request[i];
        }
        /// last movement for max size
        totalHead= totalHead+abs(sizee-request[i-1]-1);
        initial=sizee-1;
        for(i=index-1;i>=0;i--){
            totalHead= totalHead+abs(request[i]-initial);
            initial=request[i];
        }
    }
    /// if movement is towards low value
    else{
         for(i=index-1;i>=0;i--){
            totalHead= totalHead+abs(request[i]-initial);
            initial=request[i];
        }
        /// last movement for min size
        totalHead= totalHead+abs(request[i+1]-0);
        initial= 0;
        for(i=index;i<n;i++){
           totalHead= totalHead+abs(request[i]-initial);
           initial=request[i];
        }
    }
    cout<<"total head moment is: "<<totalHead<<endl;
    return 0;
}
