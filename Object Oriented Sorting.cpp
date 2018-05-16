#include <iostream>
#include <string.h>
using namespace std;
typedef const char * String;

typedef unsigned short ushort;

class Person{
public:
String Name;
Person(String name):Name(name){}
};

class Staff:public Person{
	public:
		double Salary;
		Staff(String name,double salary):Person(name),Salary(salary){}
		virtual double getMonthlySalary() = 0; // pure virtual function(Abtract Method)
};

class Student:public Person{
	public:
	   float CGPA;
	   Student(String name, float cgpa):Person(name),CGPA(cgpa){}
		Student():Student("",0.0F){}
};

class Lecturer:public Staff{
public:
   float Allowance;
   Lecturer(String name,double salary,float allowance):
   Staff(name,salary),Allowance(allowance){}
   		   double getMonthlySalary()
		   {
		   	 return (1.0-0,11)*Salary+Allowance;
		   }
};

class Clerk:public Staff{
	public:
		float OTRate;
		ushort OTHours;
		Clerk(String name,double salary,float otrate):
		   Staff(name,salary),OTRate(otrate),OTHours(0){}
		
		double getMonthlySalary()
	   	{
	   		 return (1.0-0,11)*Salary+(OTRate+ OTHours);
	   	}

};

class Manager:public Staff{
	public:
		float CarAllowance;
		Manager(String name,double salary,float carallowance):
		Staff(name,salary),CarAllowance(carallowance){}
		virtual double getMonthlySalary(){ //Operation
		//Deduct 11% EPF Contribution
		return (1.0-0.11)*Salary + CarAllowance; //Method
		}
};

class SalesManager:public Manager{
	public:
		float PetrolAllowance;
		double MonthlySales;
		SalesManager(String name,double salary,float carallowance,float petrolallowance):
		Manager(name,salary,carallowance),PetrolAllowance(petrolallowance){
		MonthlySales = 0.0;
		}
		double getMonthlySalary(){ //Operation
		//Deduct 11% EPF Contribution
		return (1.0-0.11)*(0.6*Salary) + (0.1*MonthlySales) + CarAllowance + PetrolAllowance; //Method
		}
};

class HRManager:public Manager{
	public:
	HRManager(String name,double salary):
	Manager(name,salary,500.0){}
};

void showManagerInfo(Manager*m)
{
	cout<<"Monthly salary : $"<<m->getMonthlySalary()<<"\tName:"<<m->Name<<endl;
}
#define NOI(_arr) (sizeof(_arr)/sizeof(_arr[0]))

void ShowStaffInfo(int noi,Staff* allStaff[])
{
	for(int i =0; i<noi;i++)
	{
		cout<<"Monthly Salary : $"<<allStaff[i]->getMonthlySalary();
		cout<<"\tName"<<allStaff[i]->Name<<endl;
	}
	cout<<endl;
}
void SortStaffByMonthlySalary(int noi, Staff* allStaff[])
{
	int n = noi -1;
	for(int x=0; x<(noi-1);x++)
	{
			for(int y=0; y<(noi-1);y++)
			{
				if(allStaff[y]->getMonthlySalary()>allStaff[y+1]->getMonthlySalary())
				{
					Staff* staff = allStaff[y];
					allStaff[y]= allStaff[y+1];
					allStaff[y+1]= staff;
				}
			}
		
	}
}
void SortStaffByName(int noi, Staff* allStaff[])
{
	int n = noi -1;
	for(int x=0; x<(noi-1);x++)
	{
			for(int y=0; y<(noi-1);y++)
			{
				if(strcmp(allStaff[y]->Name,allStaff[y+1]->Name)>0)
				{
					Staff* staff = allStaff[y];
					allStaff[y]= allStaff[y+1];
					allStaff[y+1]= staff;
				}
			}
		
	}	
}
void SortStaffByNameDes(int noi, Staff* allStaff[])
{
	int n = noi -1;
	for(int x=0; x<(noi-1);x++)
	{
			for(int y=0; y<(noi-1);y++)
			{
				if(strcmp(allStaff[y]->Name,allStaff[y+1]->Name)<0)
				{
					Staff* staff = allStaff[y];
					allStaff[y]= allStaff[y+1];
					allStaff[y+1]= staff;
				}
			}
		
	}	
}
void SortStaffByMonthlySalaryDes(int noi, Staff* allStaff[])
{
	int n = noi -1;
	for(int x=0; x<(noi-1);x++)
	{
			for(int y=0; y<(noi-1);y++)
			{
				if(allStaff[y]->getMonthlySalary()<allStaff[y+1]->getMonthlySalary())
				{
					Staff* staff = allStaff[y];
					allStaff[y]= allStaff[y+1];
					allStaff[y+1]= staff;
				}
			}
		
	}
}

void SortStaff(int noi, Staff* allStaff[], bool (*cmpr)(Staff*lhs, Staff *rhs))
{
	int n = noi -1;
	for(int x=0; x<(noi-1);x++)
	{
			for(int y=0; y<(noi-1);y++)
			{
				if(cmpr(allStaff[y],allStaff[y+1]))
				{
					Staff* staff = allStaff[y];
					allStaff[y]= allStaff[y+1];
					allStaff[y+1]= staff;
				}
			}
		
	}
}

bool ByMonthlySalary(Staff *lhs, Staff *rhs)
{
	return lhs->getMonthlySalary()>rhs->getMonthlySalary();
}

bool ByMonthlySalaryDesc(Staff *lhs, Staff *rhs)
{
	return lhs->getMonthlySalary()<rhs->getMonthlySalary();
}

bool ByName(Staff *lhs, Staff *rhs)
{
	return strcmp(lhs->Name,rhs->Name)>0;
}

bool ByNameDesc(Staff *lhs, Staff *rhs)
{
	return strcmp(lhs->Name,rhs->Name)<0;
}
main()
{
	Staff * staff2018[]= 
	{
		new Lecturer("Ahmad ", 3500,550),
		new Clerk("Azizi ", 2000, 25),
		new Manager("Abdullad ", 3000, 550),
		new HRManager("Aaron ",3200),
		new SalesManager("Ali ",3500,600,800),
	};
	SortStaff(NOI(staff2018),staff2018,ByMonthlySalary);
	ShowStaffInfo(NOI(staff2018),staff2018);
	
	SortStaff(NOI(staff2018),staff2018,ByMonthlySalaryDesc);
	ShowStaffInfo(NOI(staff2018),staff2018);
	
	SortStaffByMonthlySalaryDes(NOI(staff2018),staff2018);
	ShowStaffInfo(NOI(staff2018),staff2018);
	
	SortStaff(NOI(staff2018),staff2018,ByName);
	ShowStaffInfo(NOI(staff2018),staff2018);
	
	SortStaff(NOI(staff2018),staff2018,ByNameDesc);
	ShowStaffInfo(NOI(staff2018),staff2018);
	for(int i =0; i<NOI(staff2018);i++) delete staff2018[i];
	
}
