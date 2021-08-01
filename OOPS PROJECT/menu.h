#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
class Menu
{
	public:
	float price;
	char dishname[30];
	int dishkey;
	int qty=0;
	
	void writemenu();
	void readmenu();
	void search();
	void del();
	void modify();
};

void Menu::writemenu()
{
	ofstream f;
	f.open("Menu.txt",ios::app);
	cout<<"Enter Dish name, Dish Price, Dish Key\n";
	cin>>this->dishname;
	cin>>this->price;
	cin>>this->dishkey;
	f.write((char*)this,sizeof(*this));
	f.close();
}
void Menu::readmenu()
{
	ifstream f;
	cout<<"************MENU***************\n";
	cout<<"KEY\tDISH NAME\tPRICE\n";
	f.open("Menu.txt",ios::out);
	while(f.read((char*)this,sizeof(*this)))
	{
		cout<<this->dishkey<<"\t"<<this->dishname<<"\t\t\t\t\t\t\t\t\t"<<this->price<<"\n";
	}
	f.close();
}
void Menu::search()
{
	fstream f;
	Menu s;
	int flag=-1,dno;
	cout<<"ENTER THE DISH KEY TO BE SEARCHED\n";
	cin>>dno;
	f.open("Menu.txt",ios::in);
	
	f.seekg(0,ios::beg);
	while(f.read((char*)&s,sizeof(s)))
	{
			if(s.dishkey==dno)
			{
				cout<<"DISH FOUND\n";
				cout<<s.dishkey<<"\t"<<s.dishname<<"\t"<<s.price<<"\t";
				cout<<"\n";
				flag =1;
				break;
			}
	}
	if(flag==-1)
		cout<<"RECORD NOT FOUND\n";
	f.close();
}
void Menu::del()
{
	fstream f,f1;
	Menu m;
	int flag=-1,dno;
	cout<<"ENTER THE DISHKEY TO BE DELETED\n";
	cin>>dno;
	f.open("Menu.txt",ios::in);
	f1.open("newMenu.txt",ios::app);
	f.seekg(0,ios::beg);
	while(f.read((char*)&m,sizeof(m)))
	{
			if(m.dishkey==dno)
			{
				
				flag=1;
				cout<<"RECORD DELETED\n";
				continue;
			}
			f1.write((char*)&m,sizeof(m));
			
	}
	if(flag==-1)
		cout<<"RECORD NOT FOUND\n";
	f.close();
	f1.close();
	remove("Menu.txt");
	rename("newMenu.txt","Menu.txt");
}
void Menu::modify()
{
	fstream f,f1;
	Menu m;
	int flag=-1,dno;
	cout<<"ENTER THE DISH KEY TO BE Modified\n";
	cin>>dno;
	f.open("Menu.txt",ios::in);
	f1.open("newMenu.txt",ios::app);
	f.seekg(0,ios::beg);
	while(f.read((char*)&m,sizeof(m)))
	{
			if(m.dishkey==dno)
			{
				flag=1;
				cout<<"ENTER Dishkey, Dish Name, Price of this dish:\n";
				cin>>m.dishkey>>m.dishname>>m.price;
				f1.write((char*)&m,sizeof(m));
				cout<<"DISH MODIFIED\n";
				continue;
			}
			f1.write((char*)&m,sizeof(m));
			
	}
	if(flag==-1)
		cout<<"RECORD NOT FOUND\n";
	f.close();
	f1.close();
	remove("data.txt");
	rename("newdata.txt","data.txt");
}
/*int main()
{
	Menu m;
	int ch;
	do
	{
		cout<<"MENU:\n1.ADD RECORD\n2.DISPLAY RECORD\n3.Search\n4.Delete\n5.Modify\n6.Exit\n";
		cin>>ch;
		switch(ch)
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
	}while(ch!=6);
}*/

