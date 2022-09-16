#include<bits/stdc++.h>
using namespace std;
int main(){
      int i, limit, total = 0, x, counter = 0, time_quantum;
      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];
      float average_wait_time, average_turnaround_time;
      printf("nEnter Total Number of Processes: ");
      scanf("%d", &limit);
      x = limit;
      /// input Arrival Time,Burst Time and keep burst time in temp variable
      for(i = 0; i < limit; i++){
            printf("nEnter Details of Process[%d]n", i + 1);

            printf("Arrival Time: ");

            scanf("%d", &arrival_time[i]);

            printf("Burst Time: ");

            scanf("%d", &burst_time[i]);

            temp[i] = burst_time[i];
      }

      printf("nEnter Time Quantum: \n");
      scanf("%d", &time_quantum);
      printf("nProcess IDttBurst Time Turnaround Time Waiting Time \n");

      /// calculating turn around time, quantum time,
      for(total = 0, i = 0; x != 0;){
            if(temp[i] <= time_quantum && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - time_quantum;
                  total = total + time_quantum;
            }
            if(temp[i] == 0 && counter == 1){
                  x--;
                  printf("nProcess[%d] \t %d \t %d \t %d \n", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i];
                  turnaround_time = turnaround_time + total - arrival_time[i];
                  counter = 0;
            }
            if(i == limit - 1){
                  i = 0;
            }
            else if(arrival_time[i + 1] <= total){
                  i++;
            }
            else{
                  i = 0;
            }
      }
        /// calculating avg waiting time and average turnaround time
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("Average Waiting Time: %f \n", average_wait_time);
      printf("Avg Turnaround Time: %f \n", average_turnaround_time);
      return 0;
}
