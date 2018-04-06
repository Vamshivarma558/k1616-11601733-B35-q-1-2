#include<stdio.h> 
 
int main() 
{ 
 
  int count,j=0,n,time,remain,timequantum,timequantum2; 
  int waitingtime[10],turnaroundtime[10],arrivaltime[10],bursttime[10],runningtime[10],t[10];
  int total_turnaround_time=0,total_waiting_time=0;
  float average=0,averagewaitingtime=0; 
  int i,m,k=0;
  int maximum,l;
  printf("Enter no of process:\t \n"); 
  scanf("%d",&n); 
  remain=n; 
  for(i=0;i<n;i++) 
  { 
    printf("Enter Arrival Time & Burst Time for Process P[%d]  :\n",i+1); 
    scanf("%d",&arrivaltime[i]); 
    scanf("%d",&bursttime[i]); 
    runningtime[i]=bursttime[i]; 
  } 
  time=arrivaltime[0]; 
printf("Enter Time Quantum: for 1st iteration as per th question time slice for 1st iteration is 6 \t\n"); 
  scanf("%d",&timequantum); 
   
 	for(i=0;i<n;i++){
		if(arrivaltime[i]<=time && runningtime[i]!=0)
		{
			printf("the process P[%d] is running at present\n",i+1);
			runningtime[i] -=timequantum;
			time+=timequantum;
			if(runningtime[i]<=0)
			{
				printf("the process P[%d] is completed at 1st iteration \n",i+1);
				t[i]=time;
				runningtime[i]=0;
				turnaroundtime[i]=time-bursttime[i];
				waitingtime[i]=turnaroundtime[i]-arrivaltime[i];
				printf("%d   %d",turnaroundtime[i],waitingtime[i]);
			}
			
		}
	}
	printf("Enter Time Quantum: for 2nd iteration as per question time slice for 2md is 10 \t\n"); 
  scanf("%d",&timequantum2);
  for(i=0;i<n;i++)
  {
		if(arrivaltime[i]<=time && runningtime[i]!=0)
		{
			printf("the process P[%d] is running at present\n",i+1);
			runningtime[i]-=timequantum2;
			time+=timequantum2;
			if(runningtime[i]<=0)
			{
				printf("the process P[%d] is completed at 2nd iteration\n",i+1);
				t[i]=time;
				runningtime[i]=0;
					turnaroundtime[i]=time-bursttime[i];
				waitingtime[i]=turnaroundtime[i]-arrivaltime[i];
				
			}
		
		}
		
		
	} 
	printf("Third iteration \n");
	printf("searching for maximum burst time\n");
	for(i=0;i<n;i++)
	{
		if(runningtime[i]>0)
		{
			maximum=runningtime[i];
		}
	}
	printf("burst time maximum is %d\n",maximum);
	if(maximum!=0){
		for(j=0;j<n;j++)
		{
			m=0;
			l=0;
			for(i=0;i<n;i++)
			{
				if(runningtime[i]>=maximum && runningtime[i]>0)
				{
					maximum = runningtime[i];
					l=i;
				}
				
			}
			 
			if(maximum!=0)
			{	
			m=l;		
			printf("the process P[%d]   having maximum burst time %d is running at present\n",m+1,runningtime[l]);
			time+=runningtime[l];
			runningtime[l]=0;
			printf("the process P[%d] is completed at 3rd iteration\n",m+1);
			t[l]=time;
				turnaroundtime[l]=time-bursttime[l];
				waitingtime[l]=turnaroundtime[l]-arrivaltime[l];
	    	for(k=0;k<n;k++)
     	     {
	     	    if(runningtime[k]>0)
	    	   {
			      maximum=runningtime[k];
			
	    	   }
	    	   else
	    	   {
	    	   	maximum=0;
			   }
    	     }	
			 printf("next maximum is %d",maximum);
	}
		}
	}
	else{
		printf("All process are completed in 2nd iteration\n");
	}

	 printf("\n\nProcess\t|Turnaround Time|Waiting Time|Time completed\n\n"); 
	for(i=0;i<n;i++)
	{
		printf("P[%d]   %d  %d  %d \n",i+1,turnaroundtime[i],waitingtime[i],t[i]);
	}
	for(i=0;i<n;i++)
	{
		total_turnaround_time +=turnaroundtime[i];
		total_waiting_time +=waitingtime[i];
		
	}
	average=total_turnaround_time/n;
	averagewaitingtime=total_waiting_time/n;
	printf("total waiting time is %d\n",total_waiting_time);
	printf("total turnaround time is %d",total_turnaround_time);
	 printf("Average turn around time is%f\n",average);
	 printf("Average wating time is %f\n",averagewaitingtime); 
}
