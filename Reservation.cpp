#include<iostream>
#include<conio.h>
#include<cstdio>
#include<string.h>
#include<cstdlib>
using namespace std;
static int p = 0;
class a
{
    char busn[5] , driver[20] , arrival[5] , departure[5] , from[20] , to[20] , seat[8][4][10];
    public:
        void install();
        void allotment();
        void empty();
        void show();
        void avail();
        void position(int i);

};

a bus[10];
void vline(char ch)
{
    for(int i=80;i>0;i--)
    cout<<ch;
}

void a :: install()
{
    cout<<"Enter bus number: ";
    cin>>bus[p].busn;
    cout<<"\nEnter driver's name:  ";
    cin>>bus[p].driver;
    cout<<"\nEnter arrival time: ";
    cin>>bus[p].arrival;
    cout<<"\nEnter departure time: ";
    cin>>bus[p].departure;
    cout<<"\nFrom: \t";
    cin>>bus[p].from;
    cout<<"\nTo: \t";
    cin>>bus[p].to;
    bus[p].empty();
    p++;


}

void a :: allotment()
{
    int seat;
    char number[5];
    top:
       cout<<"Bus number: ";
       cin>>number;
       int n;
       for(n=0;n<=p;n++)
       {
           if(strcmp(bus[n].busn,number)==0)
           break;
       }
       while(n<=p)
       {
           cout<<"\nEnter seat number: ";
           cin>>seat;
           if (seat>32)
           {
               cout<<"\nThere are only 32 seats available in this bus,kindy give the no. accordingly";

           }
           else
           {
               if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
               {
                   cout<<"Enter the passenger name: ";
                   cin>>bus[n].seat[seat/4][(seat%4)-1];
                   break;
               }
               else{
                   cout<<"The seat is already reserved,kindly check for other seats";

               }
           }
          
           
       }
       if(n>p)
           {
               cout<<"\nEnter correct bus number";
               goto top;
           }


}
void a :: empty()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<4;j++)
        {
            strcpy(bus[p].seat[i][j], "Empty");
        }
    }
}
void a :: show()
{
    int n;
    char number[5];
    cout<<"Enter bus no: ";
    cin>>number;
    for(n=0;n<=p;n++)
       {
           if(strcmp(bus[n].busn,number)==0)
           break;
       }
    while(n<=p)
    {
        vline('*');
        cout<<"\nBus No: \t"<<bus[n].busn
        <<"\nDriver Name: \t"<<bus[n].driver<<"\t\tArrival Time: \t"
        <<bus[n].arrival<<"\tDeparture Time: "<<bus[n].departure
        <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"
        <<bus[n].to<<"\n";
        vline('*');
        cout<<"\n";
        bus[0].position(n);

        int a=1;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<4;j++)
            {
                a++;
                if(strcmp(bus[n].seat[i][j],"Empty")!=0)
                cout<<"\nThe seat number"<<(a-1)<<"is reserved for"<<bus[n].seat[i][j];
            }
        }
        break;


    }
    if(n>p)
    {
        cout<<"Enter correct bus number: ";
    }


}
void a::position(int l)

{
    int s=0;p=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<4;j++)
        {
            s++;
            if(strcmp(bus[l].seat[i][j], "Empty")==0)
            {
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<bus[l].seat[i][j];
                p++;

            }
            else
            {
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<bus[l].seat[i][j];  
            }

            
        }
    }
    cout<<"\n\nThere are "<<p<<"seats empty in bus no: "<<bus[l].busn;


}
void a::avail()
{
    for(int n=0;n<p;n++)
    {
        vline('*');
         cout<<"\nBus No: \t"<<bus[n].busn
        <<"\nDriver Name: \t"<<bus[n].driver<<"\t\tArrival Time: \t"
        <<bus[n].arrival<<"\tDeparture Time: "<<bus[n].departure
        <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"
        <<bus[n].to<<"\n";
        vline('*');
        vline('_');
    }
}

int main()
{
    
    int w;
    while(1)
    {
        cout<<"\n\n\n";
        cout<<"\t\t\t1.Install\n\t\t\t"
        <<"2.Reservation\n\t\t\t"
        <<"3.Show\n\t\t\t"
        <<"4.Buses Available. \n\t\t\t"
        <<"5.Exit\n";
        cout<<"Enter your choice:-> ";
        cin>>w;


        switch(w)
        {
            case 1: bus[p].install();
            break;

            case 2: bus[p].allotment();
            break;

            case 3: bus[p].show();
            break;

            case 4: bus[p].avail();
            break;

            case 5: exit(0);

            

        }

    }
    return 0;
}
