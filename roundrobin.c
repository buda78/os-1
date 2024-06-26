/*
RoundRobin.c
*/
#include<stdio.h>
#include<string.h>
struct process
{
    char pname[10];
    int AT,BT,ST,FT,TT,WT,BT1;
}p[15];
    struct process t;
    int i,n,j,k,bt,tq;
    char GC[150];
    
        void get_data()
        {
            printf("Enter number of processes : ");
            scanf("%d",&n);
            printf("Enter process details for %d processes :",n);
            for(i=0;i<n;i++)
            {
                printf("\nEnter Process name,arival time,cpu burst time : ");
                scanf("%s %d %d",&p[i].pname,&p[i].AT,&p[i].BT);
                p[i].BT1=p[i].BT;
            }//for

            printf("\nEnter the time quantum : ");
            scanf("%d",&tq);
        }//getdata
        
        void put_data()
        {
            printf("\n\nProcesses are as below:\n");
            printf("\n\nProcess name\t arival time\t cpu burst time");
            for(i=0;i<n;i++)
            {
                printf("\n%s\t\t%d\t\t%d",p[i].pname,p[i].AT,p[i].BT1);
            }//for
        }//putdata

        void arrivalsort()
        {
            for(i=0;i<n;i++)
            {
                for(j=i+1;j<n;j++)
                {
                    if(p[i].AT > p[j].AT)
                    {
                        t=p[i];
                        p[i]=p[j];
                        p[j]=t;
                    }//if
                }//for
            }//for
        }//arrivalsort

        void avgTTWT()
        {
            float sumtt=0,sumwt=0;
            for(i=0;i<n;i++)
            {
                p[i].TT=p[i].FT-p[i].AT;
                p[i].WT=p[i].TT-p[i].BT1;
                sumtt=sumtt+p[i].TT;
                sumwt=sumwt+p[i].WT;
            }//for
                printf("\n Process\tAT\tBT\tTT\tWT\n");
                    for(i=0;i<n;i++)
                    {
                        printf("\n%s\t\t%d\t%d\t%d\t%d",p[i].pname,p[i].AT,p[i].BT,p[i].TT,p[i].WT);
                    }//for
                printf("\n\nAverage turn around time=%0.2f/%d = %0.2f",sumtt,n, sumtt/n);
                printf("\n\nAverage wait time=%0.2f/%d = %0.2f\n",sumwt,n, sumwt/n);
        }//avgTTWT

        void rr()
        {
            char str[5];
            i=0;
            int time=0;
            strcpy(GC,"0");
                 aaa:
                    for(i=0;i<n;i++)
                    {
                        if(p[i].BT!=0)
                        {
                            strcat(GC,"|");
                            if(p[i].AT>time)
                            {
                                strcat(GC,"CPUIDLE");
                                time=p[i].AT;
                                sprintf(str,"%d",time);
                                strcat(GC,str);
                                strcat(GC,"|");
                            }//if

                            p[i].ST=time;
                            strcat(GC,p[i].pname);

                            if(p[i].BT < tq)
                                bt=p[i].BT;
                            else
                                bt=tq;
                                p[i].BT=p[i].BT-bt;
                                k=0;

                            while(bt!=0)
                            {
                                strcat(GC," ");
                                k++;
                                bt--;
                            }//while

                            time=time+k;
                            sprintf(str,"%d",time);
                            strcat(GC,str);
                            p[i].FT=time;

                        }//if
                    }//for

                    for(i=0;i<n;i++)
                    {
                        if(p[i].BT!=0)
                            goto aaa;
                    }//for

                    printf("\n\n\t\tGantt Chart\n\n");
                    puts(GC);
                    avgTTWT();
        }//rr
        
        int main()
        {
            get_data();
            put_data();
            arrivalsort();
            put_data();
            rr();
        }//main

