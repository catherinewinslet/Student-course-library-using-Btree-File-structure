/****				ONLINE STUDY PLATFORM				****/

#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
#include<windows.h>			//for Sleep() function
#include<ctype.h>

using namespace std;
fstream primaryfile,secondaryfile,datafile;

int i,indsize,sindsize;
char buffer[1000],find_name[50];
char categories[25][25]={"Computer","Electricals","Electronics","Civil","Mechanical","Architecture"};

//CLASS DEFINITION
class Course{
	//ATTRIBUTES
	char *category;
	char lectures[7],duration[7],published_year[7];
	char course_name[50],course_author[50],price[7];
	//CHOICES
	public:
		void addCourse();
		void viewAllCourses();
		int search(char*);
		int secsearch();
		void removeCourse();
		void editCourse();
		void inData();
		void outData();
}c;

void menuScreen();

//Primary index - course_author
class Primary{
	public:
		char pauthor[50],address[7];
		void initial();
		void write();
}id[50],in;

void Primary::initial(){
	primaryfile.open("primaryindex.txt",ios::in);
	if(!primaryfile){
		indsize=0;
		return;
	}
	for(indsize=0;;indsize++){
		primaryfile.getline(id[indsize].pauthor,50,'|');
		primaryfile.getline(id[indsize].address,7,'\n');
		if(primaryfile.eof())
			break;
	}
	primaryfile.close();
}

void Primary::write(){
	primaryfile.open("primaryindex.txt",ios::out);
	if(!primaryfile){
		cout<<"file not found";
		return;
	}
	for(i=0;i<indsize;i++)
		primaryfile<<id[i].pauthor<<"|"<<id[i].address<<"\n";
	primaryfile.close();
}

//Secondary index - course_name
class Secondary{
	public:
		char sname[50],sauthor[50];
		void sinitial();
		void swrite();
}sid[50],sin;

void Secondary::sinitial(){
	secondaryfile.open("secondaryindex.txt",ios::in);
	if(!secondaryfile){
		sindsize=0;
		return;
	}
	for(sindsize=0;;sindsize++){
		secondaryfile.getline(sid[sindsize].sname,50,'|');
		secondaryfile.getline(sid[sindsize].sauthor,50,'\n');
		if(secondaryfile.eof())
			break;
	}
	secondaryfile.close();
}

void Secondary::swrite(){
	secondaryfile.open("secondaryindex.txt",ios::out);
	if(!secondaryfile){
		cout<<"file not found";
		return;
	}
	for(i=0;i<sindsize;i++)
		secondaryfile<<sid[i].sname<<"|"<<sid[i].sauthor<<"\n";
	secondaryfile.close();
}

//ADD A COURSE
void Course::addCourse(){
	int cat,k;
	char a[2]; //for no reason at all
	system("cls");
	cout<<"\t\t  ADD THE NEW COURSE DETAILS"<<endl<<endl;
	cout<<"\t\tCHOOSE ANY CATEGORY TO CONTINUE"<<endl;
	cout<<"1.Computer\n2.Electronics\n3.Electrical\n4.Civil\n5.Mechnnical\n6.Architecture\nEnter your choice:	";
	cin>>cat;
	c.category=categories[cat-1];

	cout<<"\nCOURSE NAME:	";
	gets(a);
	gets(course_name);
	cout<<"\nAUTHOR:	";
	gets(course_author);
	//CHECK IF THE COURSE ALREADY EXISTS
/*	if(search(course_name)>=0 && search(course_author)>=0){
		cout<<"The course is already present."<<endl;
		return; ////////
	}*/
	//SORT THE PRIMARY INDEX FILE ACCORDING TO COURSE AUTHOR
	for(i=indsize;i>0;i--){
	    if(strcmp(course_author,id[i-1].pauthor)<0)
		    id[i]=id[i-1];     
		else    
			break;  
	}
	cout<<"\nNUMBER OF LECTURES:		";
	cin>>lectures;
	cout<<"\nDURATION OF COURSE(in hours):	";
	cin>>duration;
	cout<<"\nYEAR PUBLISHED:			";
	cin>>published_year;
	cout<<"\nPRICE:		";
	cin>>price;
	//STORE IN FILE
	inData();
	datafile.seekg(0,ios::end);
	k=datafile.tellg(); 					//tells position of get pointer 
	datafile<<buffer<<"#";
	strcpy(id[i].pauthor,course_author); 
 	itoa(k,id[i].address,10);  
	indsize++; 
	//SORT SECONDARY INDEX FILE ACCORDING TO COURSE NAME
	for(i=sindsize;i>0;i--){   
		if(strcmp(course_name,sid[i-1].sname)<0)    
			sid[i]=sid[i-1];   
		else if((strcmp(course_name,sid[i-1].sname)==0) && (strcmp(course_author,sid[i-1].sauthor)<0))     
			sid[i]=sid[i-1];   
		else     
			break;  
	}  
	strcpy(sid[i].sname,course_name);  
	strcpy(sid[i].sauthor,course_author);  
	sindsize++;

	cout<<endl<<"Would you like to add another record?(y/n)		";
	if(getch()=='n'){
		system("cls");
	}
	else{
		addCourse();
	}
	datafile.close();
}

void Course::inData(){
	strcpy(buffer,category); strcat(buffer,"|");   
	strcat(buffer,course_name); strcat(buffer,"|");   
	strcat(buffer,course_author); strcat(buffer,"|"); 
	strcat(buffer,lectures); strcat(buffer,"|"); 
	strcat(buffer,duration); strcat(buffer,"|"); 
	strcat(buffer,published_year); strcat(buffer,"|"); 
	strcat(buffer,price); strcat(buffer,"|"); 
}

//DISPLAY ALL COURSES
void Course::viewAllCourses(){
	system("cls");
	cout<<setiosflags(ios::left);
	cout<<"\t\t\t\t\tDISPLAYING ALL COURSES"<<endl<<endl;
	cout<<setw(15)<<"CATEGORY"<<setw(19)<<"COURSE NAME"<<setw(17)<<"AUTHOR"<<setw(20);
	cout<<"NO.OF LECTURES"<<setw(15)<<"DURATION"<<setw(16)<<"YEAR PUBLISHED"<<setw(10)<<"PRICE"<<endl;
	datafile.seekp(0,ios::beg);
	while(1){
		datafile.getline(category,15,'|');
		outData();
		if(datafile.eof())
			break;
		Sleep(200);
		if(category[0]!='$'){
			cout<<setw(15)<<category<<setw(19)<<course_name<<setw(17)<<course_author<<setw(20);
			cout<<lectures<<setw(15)<<duration<<setw(18)<<published_year<<setw(10)<<price<<endl;
		}
	}
	datafile.close();
	cout<<endl<<"Press any key to continue";
	if(getch())
		menuScreen();
}

void Course::outData(){
	char buffer1[100];
	datafile.getline(course_name,50,'|');
	datafile.getline(course_author,50,'|');
	datafile.getline(lectures,7,'|');
	datafile.getline(duration,7,'|');
	datafile.getline(published_year,7,'|');
	datafile.getline(price,7,'|');
	datafile.getline(buffer1,100,'#');
}

int Course::search(char*author){
	int low=0,high=indsize-1,mid;  
	while(low<=high)  {   
		mid=(low+high)/2;   
		if(strcmp(author,id[mid].pauthor)==0)    
			return mid;   
		if(strcmp(author,id[mid].pauthor)>0)    
			low=mid+1;   
		else    
			high=mid-1;  
	}  
	return -1;
}

int Course::secsearch(){
	int count=0,j,flag=-1;  
	char b[3];
	system("cls");
	cout<<"Please provide the name of the course\n_"<<endl;
	gets(b);
	gets(find_name);  
	cout<<endl<<endl;  
	cout<<setiosflags(ios::left);  
	cout<<setw(3)<<"CNO"<<setw(19)<<"COURSE NAME"<<setw(17)<<"TUTOR"<<endl;
	datafile.open("data.txt",ios::in|ios::out); 
	//secondaryfile.open("secondaryindex.txt",ios::in);
	for(j=0;j<sindsize;j++)    
	if(strcmp(find_name,sid[j].sname)==0)     { 
		++count;   
		cout<<setw(3)<<count<<setw(19)<<course_name<<setw(17)<<course_author<<endl; 
		flag=j;     
	}  
	return flag;
}

void Course::removeCourse(){
	char tutor[50];  
	int pos,spos;  
	cout<<"Enter the tutor name\n_";  
	cin>>tutor;
	for(i=0;i<sindsize;i++)  {     
		if(strcmp(sid[i].sauthor,tutor)==0)      {      
			spos=i;      
			break;      
		}  
	} 
 	if(strcmp(sid[spos].sname,find_name)==0)  {   
	 	pos=search(tutor);  
	 	datafile.seekp(atoi(id[pos].address),ios::beg);   
 		datafile.put('$');   
 		for(i=pos;i<indsize;i++)    
	 		id[i]=id[i+1];   
 		indsize--;   
	 	for(i=spos;i<sindsize;i++)    
	 		sid[i]=sid[i+1];   
 		sindsize--;  
 	} 
	else   
		cout<<"Incorrect Tutor Name."; 
}

void Course::editCourse() { 
	removeCourse();
	addCourse(); 
}

void menuScreen(){
	int choice,flag;
	char n;
	in.initial();  
	sin.sinitial();  
	system("cls");
	cout<<"1.	Add course \n2.	view all\n3.	search\n4.	remove\n5.	edit course details\n6.	close application"<<endl;
	cout<<"enter your choice:\t";
	cin>>choice;
	switch(choice){
		case 1:	datafile.open("data.txt",ios::app);				//open data.txt in append mode
				c.addCourse();
				in.write();    
				sin.swrite();
				break;
		case 2: datafile.open("data.txt",ios::in);				//opens data.txt in read mode
				c.viewAllCourses();
				break;
		case 3: datafile.open("data.txt",ios::in);				//opens data.txt in read mode
				flag=c.secsearch();
				if(flag=-1)
					cout<<"\nRecord not found";
				cout<<"\npress any key to continue...";
				cin>>n;
				break;
		case 4: datafile.open("data.txt",ios::in);				//opens data.txt in read mode
				cout<<"REMOVING";
				flag=c.secsearch();
				if(flag=-1)
					cout<<"Record not found";
				else{
					c.removeCourse();
					in.write();        
					sin.swrite();
				}
		case 5: datafile.open("data.txt",ios::in|ios::out);		//opens data.txt in read+write mode
				flag=c.secsearch();
				if(flag=-1)
					cout<<"Record not found";
				else{
					c.editCourse();
				}
		case 6:exit(0);
		
		default:cout<<"\nWrong Entry!!Please re-enter correct option";
				if(getch())
					menuScreen();
	}
}

int main(){
	while(true)
		menuScreen();
	getch();
}
