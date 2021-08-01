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
