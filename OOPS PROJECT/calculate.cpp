#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
#include"menu.h"
using namespace std;
class Calculate
{
	public:
	void acceptmenu();
	//void displaybill(); 
	void calculate_bill();
	void history_bill();
};
void Calculate::acceptmenu()
{
	Menu m;
	fstream f,f1;
	int flag=-1,ch=1;
	
	
	cout<<"ENTER KEY OF DISH YOU WANT TO ORDER:\n";
	cin>>ch;
	
	f.open("Menu.txt",ios::in);
	f1.open("bill.txt",ios::app);
	f.seekg(0,ios::beg);
	while(f.read((char*)&m,sizeof(m)))
	{
			if(m.dishkey==ch)
			{
				flag=1;
				cout<<"Enter the quantity\n";
				cin>>m.qty;
				f1.write((char*)&m,sizeof(m));
				cout<<"DISH ORDERED!\n";
				continue;
			}
		
			
	}
	if(flag==-1)
		cout<<"DISH NOT FOUND\n";
	f.close();
	f1.close();
	
	
	
	
}
/*void Calculate::displaybill()
{
	Menu m;
	fstream f1;
	f1.open("bill.txt",ios::in);
	while(f1.read((char*)&m,sizeof(m)))
	{
		cout<<m.dishkey<<"\t"<<m.dishname<<"\t\t\t\t\t\t\t\t\t"<<m.price<<"\t\t"<<m.qty<<"\n";
	}
	f1.close();
}*/
void Calculate::calculate_bill()
{
	Menu m;
	 float grandtotal=0,total;
	 cout<<"*******HOTEL XYZ*******\n         BILL         \n";
	 cout<<"DISH NAME\t\t\t\t\t\t\t\t\tQUANTITY\t\tPRICE\t\t\tTOTAL";
	fstream f1;
	f1.open("bill.txt",ios::in);
	while(f1.read((char*)&m,sizeof(m)))
	{
	  	total=0;
	   total=total+m.price*m.qty;
	   cout<<m.dishname<<"\t\t\t\t\t\t\t\t\t"<<m.qty<<"\t\t"<<m.price<<"\t\t\t"<<total<<"\n";
	   grandtotal+=total;
	}
	cout<<"PLEASE PAY "<<grandtotal<<" AMOUNT\n";
	f1.close();
	history_bill();
	remove("bill.txt");
}
void Calculate::history_bill()
{
	Menu m;
	fstream f,f1;

	f.open("bill.txt",ios::in);
	f1.open("Bill History.txt",ios::app);
	f.seekg(0,ios::beg);
	while(f.read((char*)&m,sizeof(m)))
	{
			
				f1.write((char*)&m,sizeof(m));
				
			
	}
	cout<<"STORED IN HISTORY\n";
	f.close();
	f1.close();
	}
	


int main()
{
	Menu m;
	int ch,ch1,ch3;
	char pass[10],key[10]={"shubham"};
	Calculate c;
	do
	{
		cout<<"\nWELCOME TO HOTEL XYZ\n";
		cout<<"PLEASE CHOOSE YOUR ROLE:\n1.OWNER\n2.USER\n3.EXIT";
		cout<<"\nENTER CHOICE:";
		cin>>ch;
		switch(ch)
		{
			case 1:
					abc:
					cout<<"\nPLEASE ENTER VALID PASSWORD FOR OWNER ACCESS:";
					cin>>pass;
					if(strcmp(pass,key)==0)
					{
						cout<<"\nNOW YOU CAN EDIT MENU\n";
						do
						{
							cout<<"MENU:\n1.ADD DISH\n2.DISPLAY MENU\n3.Search DISH\n4.Delete DISH\n5.Modify DISH\n6.Exit\n";
							cin>>ch1;
							switch(ch1)
							{
								case 1:
									
									 m.writemenu();
									break;
								case 2:
									m.readmenu();
									break;
								case 3:
									m.search();
									break;
								case 4:
									m.del();
									break;
								case 5:
									m.modify();
									break;	
							}
						}while(ch1!=6);
												
					}
					else
					{
						cout<<"\nINVALID PASSWORD PLEASE ENTER VALID PASSWORD\naDO YOU WANT TO CONTINUE 1.YES 2.NO:";
						cin>>ch3;
						if(ch3==1)
						goto abc;
						
					}
						
						break;
			case 2:
					do
					{
						m.readmenu();
						c.acceptmenu();
						cout<<"DO YOU WANT TO ORDER MORE:1.YES\t2.NO\n";
						cin>>ch;
					
					}while(ch==1);
					//c.displaybill();
					c.calculate_bill();
		}
		
			
	}while(ch!=3);
	return 0;
}
