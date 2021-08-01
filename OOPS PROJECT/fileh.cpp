#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
class Menu
{
	int ;
	int age;
	char name[20];
	public :
	
	 void readf();
	 void writef();
	 void search();
	 void del();
	 void modify();
};

 void Student::writef()
{
	cout<<"ENTER NAME, ROLL NUMBER, AGE\n";
	cin>>name>>rollno>>age;
	fstream f;
	f.open("data.txt",ios::app);
	f.write((char*)this,sizeof(*this));
	f.close();
}
void Student::readf()
{
	fstream f;
	Student s;
	f.open("data.txt",ios::in);
	cout<<"NAME\tAGE\tROLL NUMBER\n";
	while(f.read((char*)&s,sizeof(s)))
	{
		cout<<s.name<<"\t"<<s.age<<"\t"<<s.rollno<<"\t";
		cout<<"\n";
	}
	f.close();
}
void Student::search()
{
	fstream f;
	Student s;
	int flag=-1,rno;
	cout<<"ENTER THE ROLL NO. TO BE SEARCHED\n";
	cin>>rno;
	f.open("data.txt",ios::in);
	
	f.seekg(0,ios::beg);
	while(f.read((char*)&s,sizeof(s)))
	{
			if(s.rollno==rno)
			{
				cout<<"RECORD FOUND\n";
				cout<<s.name<<"\t"<<s.age<<"\t"<<s.rollno<<"\t";
				cout<<"\n";
				flag =1;
				break;
			}
	}
	if(flag==-1)
		cout<<"RECORD NOT FOUND\n";
	f.close();
}
void Student::del()
{
	fstream f,f1;
	Student s;
	int flag=-1,rno;
	cout<<"ENTER THE ROLL NO. TO BE DELETED\n";
	cin>>rno;
	f.open("data.txt",ios::in);
	f1.open("newdata.txt",ios::app);
	f.seekg(0,ios::beg);
	while(f.read((char*)&s,sizeof(s)))
	{
			if(s.rollno==rno)
			{
				flag=1;
				cout<<"RECORD DELETED\n";
				continue;
			}
			f1.write((char*)&s,sizeof(s));
			
	}
	if(flag==-1)
		cout<<"RECORD NOT FOUND\n";
	f.close();
	f1.close();
	remove("data.txt");
	rename("newdata.txt","data.txt");
}
void Student::modify()
{
	fstream f,f1;
	Student s;
	int flag=-1,rno;
	cout<<"ENTER THE ROLL NO. TO BE Modified\n";
	cin>>rno;
	f.open("data.txt",ios::in);
	f1.open("newdata.txt",ios::app);
	f.seekg(0,ios::beg);
	while(f.read((char*)&s,sizeof(s)))
	{
			if(s.rollno==rno)
			{
				flag=1;
				cout<<"ENTER NAME, ROLL NUMBER, AGE OF MODIFIED RECORD\n";
				cin>>s.name>>s.rollno>>s.age;
				f1.write((char*)&s,sizeof(s));
				cout<<"RECORD MODIFIED\n";
				continue;
			}
			f1.write((char*)&s,sizeof(s));
			
	}
	if(flag==-1)
		cout<<"RECORD NOT FOUND\n";
	f.close();
	f1.close();
	remove("data.txt");
	rename("newdata.txt","data.txt");
}
int main()
{
	Student s;
	int ch,n;
	
	do
	{
		cout<<"MENU:\n1.ADD RECORD\n2.DISPLAY RECORD\n3.Search\n4.Delete\n5.Modify\n6.Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"ENTER NUMBER OF STUDENTS\n";
				cin>>n;
				for(int i=0;i<n;i++)
				{
					
					s.writef();
				}
				break;
			case 2:
				s.readf();
				break;
			case 3:
				s.search();
				break;
			case 4:
				s.del();
				break;
			case 5:
				s.modify();
				break;	
		}
	}while(ch!=6);
	
}
