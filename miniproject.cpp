#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
class Major{private:
	string majorName;
	string enrollDate;
	double fees;
	int duration;
	public:Major(){
		majorName="";
		enrollDate="";
		fees=0;
		duration=0;
	}
	Major(string m,string ed,double fe,int du){
		majorName=m;
		enrollDate=ed;
		fees=fe;
		duration=du;
	}
	void setMajorName(string m){
		majorName=m;
	}
	string getMajorName(){
		return majorName;
	}
	void setEnrollDate(string date){
		enrollDate=date;
	}
	string getEnrollDate(){
		return enrollDate;
	}
	void setFees(double fe){
		fees=fe;
	}
		double getFees(){
			return fees;
	}
	void setDuration(int du){
			duration=du;
	}
	int getDuration(){
			return duration;
	}
	};
	class Student:public Major{
		private:
			int Sr;
			string rollNumber;
			string name;
			int age;
			public:
				Student(){
					Sr=1;
					rollNumber="";
					name="";
					age=0;
				}
				Student(int sr,string rn,string n,int a,string mj,string ed,double fe,int months):Major(mj,ed,fe,months)
				{
					Sr=sr;
					rollNumber=rn;
					name=n;
					age=a;
				}
				int getSr(){return Sr+1;
				}
				void setSr(int sr){Sr=sr;
				}
				string getRollNumber(){return rollNumber;
				}
				void setRollNumber(string rn){rollNumber=rn;
				}
				string getName(){return name;
				}
				void setName(string n){name=n;
				}
				int getAge(){return age;
				}
				void setAge(int a){age=a;
				}
				void print(int sr){cout<<setw(7)<<left<<sr<<setw(7)<<left<<getRollNumber()<<setw(7)<<left<<getName()<<setw(7)<<left<<getAge()<<setw(15)<<left<<getMajorName()<<setw(12)<<left<<getEnrollDate()<<setw(7)<<left<<getFees()<<setw(12)<<left<<getDuration()<<"\n";
				}
	};
	static Student s[100];
	int index=0;
	void mainMENU(){
		cout<<"\n Y-Max College: \n";
		cout<<"Student Enrollment System \n";
		cout<<"....................\n";
		cout<<"[1] Add New Student Record \n";
		cout<<"[2] View Student Record \n";
		cout<<"[3] Delete Student Record \n";
		cout<<"[4]Update Student Record \n";
		cout<<"[5]Sort Student Record \n";
		cout<<"[6]Exit Program \n";
		cout<<".....................\n";
	}
	int getChoice(){int choice;
	cout<<"Enter choice";
	cin>>choice;
	return choice;
	}
	string getRollNumber(){string dummy;
	getline(cin,dummy);
	string rn;
	cout<<"Enter Student Roll Number";
	getline(cin,rn);
	return rn;
	}
	string getName(){string name;
	cout<<"Enter Student Name:";
	getline(cin,name);
	return name;
	}
	int getAge(){int age;
	cout<<"Enter student Age";
	cin>>age;
	return age;
	}
	string getMajor(){string dummy;
	getline(cin,dummy);
	string major;
	cout<<"Enter Student Major Name";
	getline(cin,major);
	return major;
	}
	string getEnrollDate(){string enrollDate;
	cout<<"Enter Enroll Date:";
	getline(cin,enrollDate);
	return enrollDate;
	}
	double getFees(){double fees;
	cout<<"Enter Fees:";
	cin>>fees;
	return fees;
	}
	int getDuration(){int duration;
	cout<<"Enter Duration in months:";
	cin>>duration;
	return duration;
	}
	void addNewStudentRecord(){string rn=getRollNumber();
	string name=getName();
	int age=getAge();
	string major=getMajor();
	string enrollDate=getEnrollDate();
	double fees=getFees();
	int duration=getDuration();
	s[index]=Student(0,rn,name,age,major,enrollDate,fees,duration);
	index ++;
	}
	void viewStudentRecords(){int sr=0;
	cout<<"\n College Enrollment System \n";
	cout<<"View Student Record \n";
	for (int i=0;i<index;i++){
		cout<<"..................\n";
		sr=i+1;
		s[i].print(sr);
		cout<<".............\n";
		cout<<".............\n";
	}
	}
	void deleteStudentRecords(){string delRollNum;
	bool found=false;
	int delIndex=0;
	cout<<"\n College Enrollment System \n";
	cout<<"Deleting Student Record \n";
	cout<<"Enter Student Roll Number to Delete Record:";
	cin>>delRollNum;
	for (int i=0;i<index;i++){
		found=false;
		if (delRollNum.compare(s[i].getRollNumber())==0){
			delIndex=i;found=true;break;
		}
	}
	if (found==true){s[delIndex]=Student(0,"","",0,"","",0,0);
	cout<<"Successfully Deleted a Student Record \n";
	}
	else{cout<<"Sorry Student Roll Number not found.....Try again....\n";
	}
	
		}
	void updateStudentRecords(){string updateRollNum;
	bool found=false;
	int updateIndex=0;
	cout<<"\n College Student Enrollment System \n";
	cout<<"Update Student Record \n";
	cout<<"Enter Student Roll Number to Update Record:";
	cin>>updateRollNum;
	for (int i=0;i<index;i++){
		found=false;
		if (updateRollNum.compare(s[i].getRollNumber())==0){
			updateIndex=i;
			found=true;break;
		}
	}
	if (found=true){string rn=getRollNumber();
	string name=getName();
	int age=getAge();
	string major=getMajor();
	string enrollDate=getEnrollDate();
	double fees=getFees();
	int duration=getDuration();
	s[updateIndex].setRollNumber(rn);
	s[updateIndex].setName(name);
	s[updateIndex].setAge(age);
	s[updateIndex].setMajorName(major);
	s[updateIndex].setEnrollDate(enrollDate);
	s[updateIndex].setFees(fees);
	s[updateIndex].setDuration(duration);
	cout<<"Successfully updated a Student Record \n";
	}
	else{cout<<"Sorry Student Roll Number not found...Try again \n";
	}
	}
	void sortStudentRecords(){Student temp;
	cout<<"\n College Student Enrollment System \n";
	cout<<"Sort in Student Record \n";
	for (int i=0;i<index-1;i++){
		for (int j=j=i+1;j<index;j++){
			if(s[i].getName().compare(s[j].getName())>0){
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}
	cout<<"Successfully Sorted Alphabetically";
	}
	void exitProgram(){cout<<"\n........................\n";
	cout<<"\n Thank you very much exiting now \n";
	}
	void message(){cout<<"\n \n Back to Main Menu \n";
	}
	int main(){
		for (;;)
		{
			mainMENU();
			switch (getChoice()){
				case 1:addNewStudentRecord();message();system("pause");system("cls");break;
				case 2:viewStudentRecords();message();system("pause");system("cls");break;
				case 3:deleteStudentRecords();message();system("pause");system("cls");break;
				case 4:updateStudentRecords();message();system("pause");system("cls");break;
				case 5:sortStudentRecords();message();system("pause");system("cls");break;
				case 6:exitProgram();system("pause");return 0;break;
		}
	}
}
		
		
	
