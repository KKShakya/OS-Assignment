//Round Robin
#include<stdio.h>
#include<conio.h>

int main()
{
     //declaration of different components needed at the time of process Execution
     //AT=arrival time, BT=burst time, TAT=turn around time,WT=waiting time,t=total  time ;
     //TQ=time Quantum
  int n;
    int i,j;
    int t=0;
    int time;
    int remain;
    int flag=0;
    int TQ;
    float avgWT=0;
    float avgTAT=0;
    int AT[n];
    int BT[n];
    int responce_time[n];
    remain=n;

    //Asking user to enter the no.of processes
printf("Enter no of Processes : ");
  scanf("%d",&n);

  //getting input from the user
    for(i=0;i<n;i++)
   {

               printf("Enter the arrival time of process p%d :",i);
               scanf("%d",&AT[i]);
               printf("Burst time :");
               scanf("%d",&BT[i]);
              responce_time[i]=BT[i];
               t=t+responce_time[i];

          }


  printf("..........Enter time quantum ........\n");
  scanf("%d",&TQ);
  printf("\n\nProcess\t Turnaround time waiting time\n\n");

  //Execution of the processes
           for(time=0,i=0;remain!=0;)

              {

                  if(responce_time[i]<=TQ && responce_time[i]>0)

                         {
                            time+=responce_time[i];
                            responce_time[i]=0;
                            flag=1;


                             }
                   else if(responce_time[i]>0)

                     {
                         responce_time[i]= responce_time[i] -TQ;
                         time=time + TQ;

                         }
                 if(responce_time[i]==0 && flag==1)
                     {
                           remain--;
printf("............................................After executing all the processes............................\n\n\n")
             printf("P%d\t \t%d\t \t%d\n",i+1,time-AT[i],time-AT[i]-BT[i]);

             avgWT= avgWT + time-AT[i]-BT[i];

             avgTAT=avgTAT + time-AT[i];



             flag=0;


                       }
              if(i==n-1)
              {

                i=0;
              }
            else if(AT[i+1]<=time)
            {

              i++;
            }

            else
            {
               i=0;
            }
                 }
                 avgWT=avgWT/n;
                 avgTAT=avgTAT/n;

//printing the average waiting time and turn around time
                printf("Avg  waiting time = %0.2f\n",avgWT);
                printf("Avg turnaround time = %0.2f\n\n\n",avgTAT);
                printf("Total time taken by the process  to complete is :%d\n",t);

 }
