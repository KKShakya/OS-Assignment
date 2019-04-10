//LRTF(LONGEST REMIANING TIME FIRST) SCHEDULING

#include<stdio.h>
#include<conio.h>

//Structure for storing the different values AT=Arrival time,BT=burst time;
struct process
{
     int p_id;
  char p_name[10];
     int AT;
     int BT

};

//program execution starts from here;
int main()
{
     // these three lines contains data related to CT=completion time,TAT=turn around time,WT=waiting time;
     int CT[5],p[5];
     int t=-1,TAT[5],WT[5];
     float totalTAT,totalWT;
     float avgTAT,avgWT;

     //Array of the structures...............
     struct process p1={2132,"a[p1]",0,2};
 struct process p2={2102,"b[p2]",0,4};
  struct process p3={2453,"c[p3]",0,8};

//Printing the details of the process before excecution...............
printf ("Details of the processes....\n\n");
printf("P_ID\tP_NAME\t AT\t BT\n\n");
     printf("%d\t %s\t %d\t %d\n\n",p1.p_id,p1.p_name,p1.AT,p1.BT);
     printf("%d\t %s\t %d\t %d\n\n",p2.p_id,p2.p_name,p2.AT,p2.BT);
          printf("%d\t %s\t %d\t %d\n\n",p3.p_id,p3.p_name,p3.AT,p3.BT);

          //Storing the initial value of the Burst time of the processes.............to use at last;
          //to calulate Waiting time...............
          p[0]=p3.BT;
          p[1]=p2.BT;
          p[2]=p1.BT;

          //GAntt chart of the process aa they get executed....................

          printf("..........................GANTT CHART of  THE  PROCESS EXCECUTION............\n\n\n");

void Completion_time()
{
int flag=0;
     while(flag!=3)
      {

           if(p3.BT>p2.BT && p3.BT>p1.BT)
        {
           p3.BT--;
           t++;
           printf("Process executing at time %d is : P3\n\n",t);

              if(p3.BT==0)
                {
                     flag++;
                     CT[0]=t+1;
                }

      }
      if(flag!=3)
           {if(p3.BT<=p2.BT && p2.BT>=p1.BT)
           {
                p2.BT--;
                t++;
                printf("Process executing at time %d is : P2\n\n",t);

                  if(p2.BT==0)
                  {
                     flag++;
                     CT[1]=t+1;
                  }
                  if(p1.BT>=p2.BT && p3.BT<=p1.BT)
                {
                     p1.BT--;
                     t++;
                    printf("Process executing at time %d is : P1\n\n",t);
                       if(p1.BT==0)
                       {
                           flag++;
                          CT[2]=t+1;
                        }

                }

          }
           }

      }
      t++;//to print the last time of process completed.........
        printf("All Processes completed at time T = %d",t);
        printf("\n\nprocess P1 is completed at time %d ",CT[2]);
        printf("\n\nprocess P2 is completed at time %d ",CT[1]);
        printf("\n\nprocess P3 is completed at time %d ",CT[0]);

}
//calling the completion function............
Completion_time();

//computing the values of Turn Around Time And Waiting time.............
//using formula {TAT=CT - AT
 //                         WT=TAT - BT}
//FOR PROCESS P3
TAT[0]=CT[0]-p3.AT;
WT[0]=TAT[0]-p[0];

//FOR PROCESS P2
TAT[1]=CT[1]-p2.AT;
WT[1]=TAT[1]-p[1];

//FOR PROCESS P1
TAT[2]=CT[2]-p1.AT;
WT[2]=TAT[2]-p[2];

//Total Turn Around Time And Waiting time.............
totalTAT=TAT[0]+TAT[1]+TAT[2];
totalWT=WT[0]+WT[1]+WT[2];

//average Turn Around Time And Waiting time.............
avgTAT=totalTAT/3;
avgWT=totalWT/3;


//Summarising the process exceution at one place........................
 printf( "\n\n\t**********************  After Scheduling  of all  the processes ... *******************\n\n\n");

    // after all process executes
printf("P_ID\tP_NAME\t AT\t BT\t TAT\t CT\t WT\n\n");
     printf("%d\t %s\t %d\t %d\t %d\t %d\t %d\n\n",p1.p_id,p1.p_name,p1.AT,p[2],TAT[2],CT[2],WT[2]);
     printf("%d\t %s\t %d\t %d\t %d\t %d\t %d\n\n",p2.p_id,p2.p_name,p2.AT,p[1],TAT[1],CT[1],WT[1]);
          printf("%d\t %s\t %d\t %d\t %d\t %d\t %d\n\n",p3.p_id,p3.p_name,p3.AT,p[0],TAT[0],CT[0],WT[0]);


          printf("\nAERAGE   TURN AROUND TIME  : %0.2f\n\n",avgTAT);
         printf("AERAGE  WAITING TIME  : %0.2f\n\n\n",avgWT);
}

