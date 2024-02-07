#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
struct student_info
{
	string name,adress,Fname,board,Fsc_board,center,gender;
	int age;
	double telno,cnic;
	float matric,fsc,result,NTS;
};
string s;
void student();
void Education();
float Merit_Calculator(float a,float b,float c);
void Program_Offered();
void BS_ME();
void BS_EE();
void BS_SE();
void BS_MATHS();
void BS_ISL();
int scolarship_Eng_Programs();
int schlorship_NonEng_Programs();
void NotEligible();
int main()
{
	char o,exit;
	int choose;
	string s;
	cout<<"*****UNIVERSITY ADMISSION TEST FORM********"<<endl;
	cout<<"Student Details:"<<endl;
	student ();
	cout<<"Program Offered"<<endl;
	Program_Offered();
	cout<<"\n****FOR ADMIN USE ONLY*******"<<endl;
	do
	{
	cout<<"\nUnder Graduate Students List:\nDo You Want To Open:(Y/N):\n";
	cin>>o;
	if(o=='Y'||o=='y')
	{
		cout<<"Choose BS Program:\n1.Mechanical Engineering\n2.Electrical Engineering\n3.Software Engineering\n4.Mathematics\n5.Islamiyat\n6.Not Admitted"<<endl;
		cin>>choose;
		switch(choose)
		{
		case 1:
	{
	fstream f;
	f.open("BS(ME)Students List.txt");
	while(!f.eof())
   {
    	f>>s;
		cout<<s<<"\t";
		if(s=="Engineering")
		{
			cout<<endl;
		}
	}
	f.close();}		    	
			break;
			case 2:
				{
						fstream f;
	f.open("BS(EE)Students List.txt");
	while(!f.eof())
   {
    	f>>s;
		cout<<s<<"\t";
		if(s=="Engineering")
		{
			cout<<endl;
		}
	}
	f.close();}
	break;
	case 3:
	{
		fstream f;
    	f.open("BS(SE)Students List.txt");
     	while(!f.eof())
         {
           	f>>s;
	     	cout<<s<<"\t";
	        if(s=="Engineering")
		  {
		      	cout<<endl;
	       	}
         }
	     f.close();			}
			break;
		case 4:
			{
				fstream f;
				f.open("BS Maths Students List.txt",ios::app);
				while(!f.eof())
				{
					f>>s;
					cout<<s<<"\t";
					if(s=="Mathematics")
					{
						cout<<endl;
					}
				}
				f.close();}
			break;
		case 5:
			{
				fstream f;
				f.open("BS(Islamiyat)Students List.txt",ios::app);
				while(!f.eof())
				{
					f>>s;
					cout<<s<<"\t";
					if(s=="Studies")
					{
						cout<<endl;
					}
				}
				f.close();}
			break;
			case 6:
			{
				fstream f;
				f.open("NotEligibleStudents.txt",ios::app);
				while(!f.eof())
				{
					f>>s;
					cout<<s<<"\t";
					if(s=="addmision")
					{
						cout<<endl;
					}
				}
				f.close();}
			break;
		default :
			cout<<"\nEnter From (1,2,3,4,5or6)\n";
			break;
		}
	}
	cout<<"Do You Want To Exit(Y/N)\t";
	cin>>exit;
   }while(exit=='n'||exit=='N');
	return 0;
}
student_info s_all[1000];
student_info t; 
void student()
{
	ofstream file;
	file.open("Student Admission.txt",ios::app);
	if(file.is_open())
	{
		cout<<"\"Personal Details\"\n";
		cout<<"Full Name:\t";
		getline(cin,t.name);
		cout<<"Father Name:\t";
		cin.ignore();
		getline(cin,t.Fname);
		cout<<"Gender:\t";
		cin>>t.gender;
		cout<<"Age:\t";
		cin>>t.age;
		cout<<"CNIC:\t";
		cin>>t.cnic;
		cout<<"Adress:\t";
		cin.ignore();
		getline(cin,t.adress);
		cout<<"Phone Number:\t";
		cin>>t.telno;
		cout<<"\"Education information\"\n";
		Education();
		file<<"\"Personal Details\"\n";
		file<<"Name:"<<t.name<<"\tFather Name:"<<t.Fname<<"Gender:\t"<<t.gender<<"\tAge:"<<t.age<<"\tCNIC:"<<t.cnic<<"\tAdress:"<<t.adress<<"\tCell no:"<<t.telno<<endl;
		file<<"\"Education information\"\n";
		file<<"Matric Marks:"<<t.matric<<"\tBoard:"<<t.board<<"\tInter Marks:"<<t.fsc<<"\tBoard:"<<t.Fsc_board<<"\tNTS Marks:"<<t.NTS<<"Nts Center"<<t.center<<endl;
		file<<"Final Merit Calculated is: "<<t.result<<"%"<<endl;
		file.close();
	}
}
void Education()
{
	cout<<"Enter Your SSC Details:\n";
	cout<<"Marks:\t";
	cin>>t.matric;
	cout<<"Board:\t";
	cin.ignore();
	getline(cin,t.board);
	cout<<"Enter Your HSSC Details:\n";
	cout<<"Marks:\t";
	cin>>t.fsc;
	cout<<"Board:\t";
	cin.ignore();
	getline(cin,t.Fsc_board);
	cout<<"Enter Your NTS Details:\n";
	cout<<"Marks:\t";
	cin>>t.NTS;
	cout<<"Center:\t";
	cin.ignore();
	getline(cin,t.center);
	cout<<"Your Merit is:\n";
	cout<<Merit_Calculator(t.matric,t.fsc,t.NTS);
	cout<<"%";
}
float Merit_Calculator(float a,float b,float c)
{
	t.result=(a/1100)*20+(b/1100)*30+(c/100)*50;
	return(t.result);
}
void Program_Offered()
{
	int option;
	cout<<"\"Under Graduate Programs Offered:\"\n";
	cout<<"1.BS(ME)\n2.BS(EE)\n3.BS(SE)\n4.BSC(MATHEMATICS)\n5.BSC(ISLAMIYAT)\n";
	cout<<"Chooose The Option:\n";
	cin>>option;
	switch(option)
	{
		case 1:
			if(t.result>=60)
			{
				cout<<"You Are Eligible To Apply in Mechanical Engineering\n";
				BS_ME();
				cout<<"Fee Chalan Info:"<<endl;
				cout<<scolarship_Eng_Programs();
			}
			else
			cout<<"You Are Not Eligible\n";
		break;
		case 2:
			if(t.result>=60)
			{
				cout<<"You Are Eligible To Apply in Electical Engineering\n";
				BS_EE();
				cout<<"Fee Chalan Info:"<<endl;
				cout<<scolarship_Eng_Programs();
			}
			else
				{
			cout<<"You Are Not Eligible\n";
		     NotEligible();}
		break;
		case 3:
			if(t.result>=50)
			{
				cout<<"You Are Eligible To Apply in Software Engineering\n";
				BS_SE();
				cout<<"Fee Chalan Info:"<<endl;
				cout<<scolarship_Eng_Programs();
			}
			else
				{
			cout<<"You Are Not Eligible\n";
		     NotEligible();}
		break;	
		case 4:
		    if(t.result>=40)
			{
				cout<<"You Are Eligible To Apply in BS(Mathematics)\n";
				BS_MATHS();
				cout<<"Fee Chalan Info:"<<endl;
				cout<<schlorship_NonEng_Programs();
			}
			else
				{
			cout<<"You Are Not Eligible\n";
		     NotEligible();}
		break;
		case 5:
			if(t.result>=40)
			{
				cout<<"You Are Eligible To Apply in BS(Islamiyat)\n";
				BS_ISL();
				cout<<"Fee Chalan Info:"<<endl;
				cout<<schlorship_NonEng_Programs();
			}
			else
				{
			cout<<"You Are Not Eligible\n";
		     NotEligible();}
		break;
		default:
			cout<<"Enter From (1,2,3,4,5)\n";
		break;
	}
}
void BS_ME()
{
	ofstream file;
	file.open("BS(ME)Students List.txt",ios::app);
	if(file.is_open())
	{
		file<<"Name: "<<t.name<<"\tMerit: "<<t.result<<"\tProgram:BS(ME)\tDepartment:Mechanical Engineering\n";
	}
	file.close();
}
void BS_EE()
{
	ofstream file;
	file.open("BS(EE)Students List.txt",ios::app);
	if(file.is_open())
	{
		file<<"Name: "<<t.name<<"\tMerit: "<<t.result<<"\tProgram:BS(EE)\tDepartment:Electrical Engineering\n";
	}
	file.close();
}
void BS_SE()
{
	ofstream file;
	file.open("BS(SE)Students List.txt",ios::app);
	if(file.is_open())
	{
		file<<"Name: "<<t.name<<"\tMerit: "<<t.result<<"\tProgram:BS(SE)\tDepartment:Software Engineering\n";
	}
	file.close();
}
void BS_MATHS()
{
	ofstream file;
	file.open("BS Maths Students List.txt",ios::app);
	if(file.is_open())
	{
		file<<"Name: "<<t.name<<"\tMerit: "<<t.result<<"\tProgram:BS(Maths)\tDepartment:Mathematics\n";
	}
	file.close();
}
void BS_ISL()
{
	ofstream file;
	file.open("BS(Islamiyat)Students List.txt",ios::app);
	if(file.is_open())
	{
		file<<"Name: "<<t.name<<"\tMerit: "<<t.result<<"\tProgram:BS(Islamiyat)\tDepartment:Islamic Studies\n";
	}
	file.close();
}
int scolarship_Eng_Programs()
{
	float x=t.result;
	float a;
	if(x>=85)
	{
		a=81000-(81000*0.5);
		cout<<"You Have Been Awarded 50% Scholarship.\n";
		cout<<"Total Amount to Pay:\t";
		return a;
	}
	else if(x>=75&&x<85)
	{
		a=81000-(81000*0.4);
		cout<<"You Have Been Awarded 40% Scholarship.\n";
		cout<<"Total Amount to Pay:\t";
		return a;
	}
	else if(x>=70&&x<75)
	{
		a=81000-(81000*0.3);
		cout<<"You Have Been Awarded 30% Scholarship.\n";
		cout<<"Total Amount to Pay:\t";
		return a;
	}
	else
	{
		cout<<"No Fee Concession.\nTotal Amount to Pay:\t";
		a=81000;
		return a;
	}
}
int schlorship_NonEng_Programs()
{
	float x=t.result;
	float a;
	if(x>=85)
	{
		a=61000-(61000*0.5);
		cout<<"You Have Been Awarded 50% Scholarship.\n";
		cout<<"Total Amount to Pay:\t";
		return a;
	}
	else if(x>=75&&x<85)
	{
		a=61000-(61000*0.4);
		cout<<"You Have Been Awarded 40% Scholarship.\n";
		cout<<"Total Amount to Pay:\t";
		return a;
	}
	else
	{
		cout<<"No Fee Concession.\nTotal Amount to Pay:\t";
		a=61000;
		return a;
	}
}
void NotEligible()
{
   ofstream file;
	file.open("NotEligibleStudents.txt",ios::app);
	if(file.is_open())
	{
		file<<"Name: "<<t.name<<"\tMerit: "<<t.result<<"\tNot Eligible for addmision\n";
	}
	file.close();	
}
