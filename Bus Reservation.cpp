#include <conio.h>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;
/* no variable counts the number of buses available at that moment
If we have added 6 buses then no will be 6. Used as index of bus array.At first no=0 as there is no bus in the system.
*/
static int no=0;
// Class is use to define variables and functions used.
class a
{
 char bus_no[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
 public:
  void add_bus_details();//Adds a new bus
   void allotment();//Allots a seat
   void empty();//Used to intilialize all bus seats as vacant
   void show();//Shows available seats on a particular bus
   void avail();//Shows available buses
   void position(int i);//Shows reserved seats on a bus
}
   bus[10];
   void vline(char ch)
        {
            for(int i=80;i>0;i--)
			cout<<ch;
        }
   void a::add_bus_details()
        {
            cout<<"Enter bus no: ";
            cin>>bus[no].bus_no;
            cout<<"\nEnter Driver's name: ";
            cin>>bus[no].driver;
            cout<<"\nArrival time: ";
            cin>>bus[no].arrival;
            cout<<"\nDeparture: ";
            cin>>bus[no].depart;
            cout<<"\nFrom: \t\t\t";
            cin>>bus[no].from;
            cout<<"\nTo: \t\t\t";
            cin>>bus[no].to;
            bus[no].empty();
            no++;
        }
   void a::allotment()
        {
            int seat;
            char number[5];
            top:
            cout<<"Bus no: ";
            cin>>number;
            int n;
            for(n=0;n<=no;n++)
                {
                    if(strcmp(bus[n].bus_no, number)==0)
	            break;
	            }
	        while(n<=no)
	            {
	                cout<<"\nSeat Number: ";
	                cin>>seat;
	            if(seat>32)
	            {
	                cout<<"\nThere are only 32 seats available in this bus.";
	            }
	            else
	            {
				if(strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
	            {
	                cout<<"Enter passanger's name: ";
				    cin>>bus[n].seat[seat/4][(seat%4)-1];
					break;
		        }
				else
				cout<<"The seat no. is already reserved.\n";
				}
				}
				if(n>no)
				{
				cout<<"Enter correct bus no.\n";
				goto top;
				}
				}
	void a::empty()
		{
		   for(int i=0;i<8;i++)
		   {
		   for(int j=0;j<4;j++)
		   {
		   strcpy(bus[no].seat[i][j], "Empty");
		   }
		   }
		}
	void a::show()
		{
		   int n;
		   char number[5];
		   cout<<"Enter bus no: ";
		   cin>>number;
		   for(n=0;n<=no;n++)
		   {
		   if(strcmp(bus[n].bus_no, number)==0)
		   break;
		   }
		   while(n<=no)
		   {
		   vline('*');
		   cout<<"Bus no: \t"
		   <<bus[n].bus_no
		   <<"\nDriver: \t"
		   <<bus[n].driver
		   <<"\t\tArrival time: \t"
		   <<bus[n].arrival
		   <<"\tDeparture time:"
		   <<bus[n].depart
		   <<"\nFrom: \t\t"
		   <<bus[n].from
		   <<"\t\tTo: \t\t"
		   <<bus[n].to<<"\n";
		   vline('*');
		   bus[0].position(n);
		   int a=1;
		   for(int i=0; i<8; i++)
		   {
		   for(int j=0;j<4;j++)
		   {
		   a++;
		   if(strcmp(bus[n].seat[i][j],"Empty")!=0)
		   cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
		   }
		   }
		   break;
		   }
		   if(n>no)
		   cout<<"Enter correct bus no: ";
		}
	void a::avail()
		{
		   for(int n=0;n<no;n++)
		   {
		   vline('*');
		   cout<<"Bus no: \t"<<bus[n].bus_no<<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"
		   <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"
		   <<bus[n].to<<"\n";
		   vline('*');
		   vline('_');
		   }
	    }
void a::position(int l)
    {
		   int s=0;no=0;
		   for(int i =0;i<8;i++)
		   {
		   cout<<"\n";
		   for (int j = 0;j<4; j++)
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
		   no++;
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
		   cout<<"\n\nThere are "<<no<<" seats empty in Bus No: "<<bus[l].bus_no;
    }
int main()
{
		   system("cls");
		   int w;
		   char a[50],u_n[50];
		   while(1)
		   {
		   //system("cls");
		   cout<<"                                       WELCOME TO BUS RESERVATION SYSTEM                                       ";
		   cout<<"\n\n\n\n\n";
		   cout<<"\t\t\t1.Add Bus Details\n\t\t\t"
		   <<"2.Reservation\n\t\t\t"
		   <<"3.Show\n\t\t\t"
		   <<"4.Buses Available. \n\t\t\t"
		   <<"5.Exit";
		   cout<<"\n\t\t\tEnter your choice: ";
		   cin>>w;
		   switch(w)
		   {
		   case 1:bus[no].add_bus_details();
		   break;
		   case 2:bus[no].allotment();
		   break;
		   case 3:bus[0].show();
		   break;
		   case 4:bus[0].avail();
		   break;
		   case 5:exit(0);
		   }
		   }
	return 0;
}
