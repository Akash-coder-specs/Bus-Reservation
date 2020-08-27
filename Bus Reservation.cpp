#include<iostream>
#include<string.h>
#include<conio.h>

using namespace std;
static int p=0;
class b{
	public:
		char busn[5],seat[8][4][10],from[10],to[10],arrive[10],depart[10];
	void install();
	void allotment();
	void position(int n);
	void empty();
	void avail();
	void show();
}
bus[10];

void vline(char ch)
{
	for(int i=120;i>0;i--)
		cout<<ch;
}

void b::install()
{
	system("cls");
	cout<<"\t\t\tEnter the bus number:";
	cin>>bus[p].busn;
	cout<<"\t\t\tFrom:    ";
	cin>>bus[p].from;
	cout<<"\t\t\tTo:      ";
	cin>>bus[p].to;
	cout<<"\t\t\tArrive: ";
	cin>>bus[p].arrive;
	cout<<"\t\t\tDepart: ";
	cin>>bus[p].depart;
	bus[p].empty();
	p++;
}

void b::allotment()
{
	top:
	system("cls");
	char number[10];
	int n,seat;
	cout<<"Enter the bus number: ";
	cin>>number;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		break;
	}
	while(n<=p)
	{
		cout<<"Enter the Seat number: ";
		cin>>seat;
		if(seat>32)
		{
			cout<<"there are only 32 seats available";
		}
		else
		{
			if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
			{
				cout<<"Enter the passenger name: ";
				cin>>bus[n].seat[seat/4][(seat%4)-1];
				break;
			}
			else
			{
				cout<<"This seat is already reserved"<<endl;
			}
		}
	}
	if(n>p)
	 {
	 	cout<<"\n\n\n\nEnter the correct bus number.";
	 	goto top;
	 }
}

void b::empty()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			strcpy(bus[p].seat[i][j],"Empty");
		}
		
	}
}
void b::position(int n)
{
	int s=0,p=0;
	for(int i=0;i<8;i++)
	{
		cout<<"\n";
		for(int j=0;j<4;j++)
		{
			s++;
			if(strcmp(bus[n].seat[i][j],"Empty")==0)
			{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<'.';
				cout.width(10);
				cout.fill(' ');
				cout<<bus[n].seat[i][j];
				p++;			
			}
			else
			{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<'.';
				cout.width(10);
				cout<<bus[n].seat[i][j];
			}
		}
	}
	cout<<"\n\nThere are"<<p<<"seats available in the bus"<<bus[n].busn;
}
void b::show()
{
	to:
	system("cls");	
	int n;
	char number[5];
	cout<<"Enter the bus number: ";
	cin>>number;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		{
			break;
		}
	}
	while(n<=p)
	{
		vline('*');
  		cout<<"\nBus no: \t"<<bus[n].busn<<"\t\tArrival time: \t"
 		<<bus[n].arrive<<"\tDeparture time:"<<bus[n].depart
  		<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<
  		bus[n].to<<"\n";
  		vline('*');
  		bus[0].position(n);
  		int a=1;
  		for(int i=0;i<8;i++)
  		{
  			for(int j=0;j<4;j++)
  			{
  				a++;
  				if(strcmp(bus[n].seat[i][j],"Empty")!=0)
  				{
  					cout<<"\n\nThe seat no."<<(a-1)<<"is alloted for "<<bus[n].seat[i][j]<<".";
				  }
			  }
		  }
		  break; 
	}
	if(n>p)
	{
		cout<<"\nThis bus number is now not available.";
		goto to;
	}
}
void b::avail(){
	system("cls");
	int n;
	for(n=0;n<p;n++)
	{
		vline('*');
		cout<<"\nBus no: "<<bus[n].busn<<"\tArrive time: "<<bus[n].arrive<<"\tDeparture time: "<<bus[n].depart<<"\n\tFrom: "<<bus[n].from<<"\t\tTo: "<<bus[n].to<<endl;
		vline('*');
	}
}
int main()
{
	system("cls");
	cout<<"\n\n\t\t\tWelome To The Bus Reservation";
	char ch='y';
	while(ch=='y')
	{
		system("cls");
		int choice;
		cout<<"\n\n\t\t\t1.Install";
		cout<<"\n\n\t\t\t2.Allotment";
		cout<<"\n\n\t\t\t3.Show";
		cout<<"\n\n\t\t\t4.Available Buses";
		cout<<"\n\n\t\t\t5.Exit";
		cout<<"\n\n\t\t\tEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
					bus[p].install();
					break;
			case 2:
					bus[p].allotment();
					break;		
			case 3:
					bus[0].show();
					break;
			case 4:
					bus[0].avail();
					break;
			case 5:
					exit(0);
					break;						
			default:
				cout<<"\t\t\t\t\t\tWrong choice";		
		
		}
		cout<<"\n\nIf you want to continue (y/n):";
		cin>>ch;			
	}	

}

