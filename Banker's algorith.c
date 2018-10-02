//C Program to implement Banker's algorithm to avoid deadlocks
 
#include<stdio.h>
void main()
{
    int allocation[10][10],max[10][10],available[10],need[10][10],finish[10],order[10],work[10];
    int n,res_num,temp1,temp2,temp3,temp4,i,j,k,flag;
 
    printf("\n\n Banker's Algorithm \n\n");
    printf("Enter number of processes:"); //rows
    scanf("%d",&n);
    printf("Insert number of resources:"); //columns
    scanf("%d",&res_num);
 
 
    //Taking input into allocation array
    printf("\n\nAllocation array\n\n Insert number of instances of resource already allocated to a particular process: \n\n");
 
    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=res_num-1;j++)
        {
            printf("Instances of resource %d allocated to process %d :",j+1,i+1);
            scanf("%d",&allocation[i][j]);
        }
    }
 
    //Taking input into max array
    printf("\n\nMax array\n\n Insert max number of instances of a resource that can be given to a particular process: \n\n");
 
    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=res_num-1;j++)
        {
            printf("Max instances of resource %d that can be allocated to process %d:",j+1,i+1);
            scanf("%d",&max[i][j]);
        }
    }
 
    //Taking input to available array=1D array
    printf("\n\nAvailbale array\n\n Insert number of instances of a resource that is available:\n\n");
    for(i=0;i<=res_num-1;i++)
    {
        printf("Number of available instances of resource %d :",i+1);
        scanf("%d",&available[i]);
 
    }
 
    //Calculating Need array using Need=max-allocation
    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=res_num-1;j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    //Printing Need array
    printf("\n\n Need array is : \n\n");
    printf("Process \t\t Need Array\n\n");
    temp1=1;   //gives process number when printing
    temp2=1;   //gives resource number when printing
    printf("\t");
    for(i=0;i<=res_num-1;i++) //for loop for printing resource number on top (optional)
    {
        printf("R%d\t",i+1); //R stands for resource
    }
 
    printf("\n");
 
    for(i=0;i<=n-1;i++)
    {
        printf("P%d\t",temp1); //P stands for process
        for(j=0;j<=res_num-1;j++)
        {
            printf("%d\t",need[i][j]);
        }
        temp1=temp1+1;
        printf("\n");
    }
 
    //printf("Aloha");
 
    //Insert into work array   Work[i]=available[i]
    for(i=0;i<=res_num-1;i++)
    {
        work[i]=available[i];
    }
   
  //printf("simply testing");
 
    //SAFETY ALGORITHM
 
    //initialise finish array as -1
    for(i=0;i<=n-1;i++)
    {
        finish[i]=-1;        //-1=false ie; not allocated
    }
    //printf("Just testing");
 
 
    printf("\nSafe sequence is:");
 
    flag=0;
    temp3=0;
    while(flag!=1)
    {
        for(i=0;i<=n-1;i++)
        {
            for(j=0;j<=res_num-1;j++)
            {
                if(!(finish[i]!=1 && need[i][j]<=work[j]))   //checking not(condition) because we need to check for all resources against a particular process and not just against the last resource
                {
                    temp4=-1;
                }
                    if(temp4!=-1)
                    {    finish[i]=1;
                        work[j]=work[j]+allocation[i][j]; //process allocated and already held resource released
                        //printf("\t P%d ",i);
                        order[temp3]=i+1;
                        temp3=temp3+1;
                    }    
               
            }
        temp4=0;
        }
 
        flag=1;
        for(i=0;i<=n-1;i++)
        {
            if(finish[i]==-1)
            {
                flag=0;  //checking if all processes have been allocated
            }
        }
    }
 
    //printing order of safe sequence
    for(i=0;i<=n-1;i++)
    {
        printf("\tP%d",order[i]);
    }
 
    printf("\n");
 
 
 
 
    //RESOURCE REQUEST ALGORITHM
 
 
 
   
    printf("\n\nRESOURCE REQUEST ALGORITHM \n\n");
    printf("\nNow checking safe state after resource request [1 0 2] from process P2 \n");
   
    available[0]-=1;
    available[1]-=0;    //available = available - request
    available[2]-=2;
 
    allocation[1][0]+=1;
    allocation[1][1]+=0;    //allocation = allocation + request
    allocation[1][2]+=2;
 
    need[1][0]-=1;
    need[1][1]-=0;  //need = need - request
    need[1][2]-=2;
 
    //check safe states again by copying the same code again
    //calculating new safe state
 
            //Insert into work array   Work[i]=available[i]
            for(i=0;i<=res_num-1;i++)
            {
                work[i]=available[i];
            }
 
            //initialise finish array as -1
            for(i=0;i<=n-1;i++)
            {
                finish[i]=-1;        //-1=false ie; not allocated
            }
            //printf("Just testing");
       
            //initialise order array as -1
            for(i=0;i<=n-1;i++)
            {
                order[i]=-1;        //-1=false ie; not allocated
            }
 
            printf("\nNew safe sequence is:");
       
            flag=0;
            temp3=0;
            while(flag!=1)
            {
                for(i=0;i<=n-1;i++)
                {
                    for(j=0;j<=res_num-1;j++)
                    {
                        if(!(finish[i]!=1 && need[i][j]<=work[j]))   //checking not(condition) because we need to check for all resources against a particular process and not just against the last resource
                        {
                            temp4=-1;
                        }
                            if(temp4!=-1)
                            {    finish[i]=1;
                                work[j]=work[j]+allocation[i][j]; //process allocated and already held resource released
                                //printf("\t P%d ",i);
                                order[temp3]=i+1;
                                temp3=temp3+1;
                            }    
                       
                    }
                temp4=0;
                }
       
                flag=1;
                for(i=0;i<=n-1;i++)
                {
                    if(finish[i]==-1)
                    {
                        flag=0;  //checking if all processes have been allocated
                    }
                }
            }
       
            //printing order of safe sequence
            for(i=0;i<=n-1;i++)
            {
                printf("\tP%d",order[i]);
            }
 
            printf("\n\n");
 
 
 
   
}
