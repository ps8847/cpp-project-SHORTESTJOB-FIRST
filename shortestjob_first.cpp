#include<bits/stdc++.h>
#include<exception>
#define max 30
using namespace std;
int main() {
    int n,t;
    int p[max],bt[max],at[max],wt[max],tat[max],ct[max],st[max],rs[max];
    float awt=0,atat=0;
    cout<<endl;
cout<<"------------------------------------------------------
-$-- WELCOME TO OUR PROJECT --$------------------------------
----------------------------------\n";
    cout<<"                                          
 (Based upon SHORTEST JOB FIRST(SJF) NON-PREEMPTIVE SCEDULING)         \n";
    cout<<endl;

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\t\tENTER THE TOTAL NUMBER OF PROCESSES: ";

    while(!(cin>>n))
    {
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t************************************";
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ERROR : Please Enter Numbers Only\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t************************************";
    cout<<endl;
    cout<<"\t\t\t\t\t\tENTER THE TOTAL NUMBER OF PROCESSES: ";
    cin.clear();
    cin.ignore(22, '\n');
    }
    if(n<0)
    {
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t********************************************";
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t ERROR : Please Enter Positive Numbers Only\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t********************************************";
    exit(1);
    }
cout<<endl;
    cout<<" TOTAL NUMBER OF PROCESSES = "<<n <<"\n";
    cout<<endl;
    cout<<"\t\t\t\t\t   NOW, ENTER THE BURST TIME OF THESE "<<n<< " PROCESSES\n";
    cout<<"\t\t\t\t\t --------------------------------------------------------";
    cout<<endl;
    for(int i=0;i<n;++i){
        cout<<" Enter The BURST TIME for Process Number "<<i+1<<": ";
        while(!(cin>>bt[i]))
        {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t************************************";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ERROR : Please Enter Numbers Only\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t************************************";
        cout<<" Enter The BURST TIME for Process Number "<<i+1<<": ";
        cin.clear();
        cin.ignore(22, '\n');
         }
    if(bt[i]<0)
        {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t*******************************************";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ERROR: Please Enter Positive Numbers Only\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t*******************************************";
        exit(1);
        }
    }
    cout<<endl;
    cout<<"\t\t\t\t\t    NOW, ENTER THE ARRIVAL TIME OF THESE "<<n<< " PROCESSES\n";
    cout<<"\t\t\t\t\t --------------------------------------------------------";
    cout<<endl;
    for(int i=0;i<n;++i){
        cout<<" Enter The ARRIVAL TIME for Process Number "<<i+1<<": ";
        while(!(cin>>at[i]))
         {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t************************************";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ERROR: Please Enter Numbers Only ";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t************************************";
        cout<<" Enter The ARRIVAL TIME for Process Number "<<i+1<<": ";
        cin.clear();
        cin.ignore(22, '\n');
         }
    if(at[i]<0)
        {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t*******************************************";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ERROR: Please Enter Positive Numbers Only\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t*******************************************";
        exit(1);
        }
    }
    ct[0]=at[0]+bt[0];
    for(int i=1;i<n;++i){
        for(int j=1;j<n;++j){
            if(bt[i]<bt[j]){
                t=bt[j];
                bt[j]=bt[i];
                bt[i]=t;
            }
        }
    }
    for(int i=1;i<n;++i){
        ct[i]=ct[i-1]+bt[i];
    }
    cout<<endl;
    cout<<endl;
cout<<" ***********************************************************************************
************************************************************\n";
cout<<" | Process No\t| Arrival time\t| Burst Time\t| Complection Time\t| Turn Around Time\t| 
Waiting Time | Response Time | Start Time\n";
    cout<<" ***********************************************************************
*************************************************************************\n";

    for(int i=0;i<n;++i){
        tat[i]=0;
        wt[i]=0;
        tat[i]=tat[i]+ct[i]-at[i];
        wt[i]=wt[i]+tat[i]-bt[i];
        rs[i]=wt[i];
        st[i]=ct[i]-bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];

        cout<<" \n| "     <<i+1<<""<<"\t\t| "     <<at[i]<<"\t\t| "     <<bt[i]<<"\t\t| " 
    <<ct[i]<<"\t\t\t| "     <<tat[i]<<"\t\t\t| "     <<wt[i]<<"\t\t| "     <<rs[i]<<"\t\t| " 
    <<st[i]<<endl;
    }
    cout<<"\n *****************************************************************************
******************************************************************\n";
    cout<<endl;
    cout<<"\t\t\t\t\t\t\tAVERAGE WAITING TIME "<<" = ";
    cout<<awt/n<<endl;
    cout<<"\t\t\t\t\t\t\tAVERAGE TURN AROUND TIME "<<" = ";
    cout<<atat/n;
    return 0;
}

