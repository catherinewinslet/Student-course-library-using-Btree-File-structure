#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
#define datafile "stud6.txt"
#define indexfile "pri6.txt"
#define sindexfile "sec6.txt"

using namespace std;
fstream dfile, ifile, sifile;

int i,indsize,sindsize;
char buffer[100],skey[20];

class student{
	char dusn[15],name[25],age[7],branch[7],sem[7];
	public:
		void read();
		void pack();
		int search(char*);
		void remove();
		void datadisp();
		void unpack();
		int sec_search();
}s;

class index{
	public:
		char iusn[15],addr[5];
		void initial();
		void write();
}id[50],in;

class sindex{
	public:
		char sname[25],susn[15];
		void sinitial();
		void swrite();
}sid[50],sin;

void index::initial(){
	ifile.open(indexfile,ios::in);
	if(!ifile){
		indsize=0;
		return;
	}
	for(indsize=0;;indsize++){
		ifile.getline(id[indsize].iusn,15,'|');
		ifile.getline(id[indsize].addr,5,'\n');
		if(ifile.eof())
			break;
	}
	ifile.close();
}

void sindex::sinitial(){
	sifile.open(sindexfile,ios::in);
	if(!sifile){
		sindsize=0;
		return;
	}
	for(sindsize=0;;sindsize++){
		sifile.getline(sid[sindsize].sname,20,'|');
		sifile.getline(sid[sindsize].susn,15,'\n');
		if(sifile.eof())
			break;
	}
	sifile.close();
}

void index::write(){
	ifile.open(indexfile,ios::out);
	if(!ifile){
		cout<<"file not found";
		return;
	}
	for(i=0;i<indsize;i++)
		ifile<<id[i].iusn<<"|"<<id[i].addr<<"\n";
}

void sindex::swrite(){
	sifile.open(sindexfile,ios::out);
	if(!sifile){
		cout<<"file not found";
		return;
	}
	for(i=0;i<sindsize;i++)
		sifile<<sid[i].sname<<"|"<<sid[i].susn<<"\n";
}

void student::read(){
	int k; 
	char a[10];
	cout<<"enter the usn number=";  
	gets(a);
	gets(dusn);
	if(search(dusn)>=0){
		cout<<"usn is already present we can't add to index file\n";
		return; 
	}
	for(i=indsize;i>0;i--){
	    if(strcmp(dusn,id[i-1].iusn)<0)
		    id[i]=id[i-1];     
		else    
			break;  
	}
	dfile.open(datafile,ios::app); 
	cout<<"enter the name=";     gets(name);  
	cout<<"enter the age=";      gets(age);  
	cout<<"enter the branch=";   gets(branch);  
	cout<<"enter the semester=";    gets(sem);  
	pack();
	dfile.seekg(0,ios::end);  
	k=dfile.tellg();  
	dfile<<buffer<<"\n";  
	strcpy(id[i].iusn,dusn); 
 	itoa(k,id[i].addr,10);  
	indsize++; 
	for(i=sindsize;i>0;i--){   
		if(strcmp(name,sid[i-1].sname)<0)    
			sid[i]=sid[i-1];   
		else if((strcmp(name,sid[i-1].sname)==0) && (strcmp(dusn,sid[i-1].susn)<0))     
			sid[i]=sid[i-1];   
		else     
			break;  
	}  
	strcpy(sid[i].sname,name);  
	strcpy(sid[i].susn,dusn);  
	sindsize++;
}

void student::pack(){
	strcpy(buffer,dusn); 
	strcat(buffer,"|");   
	strcat(buffer,name); 
	strcat(buffer,"|");   
	strcat(buffer,age); 
	strcat(buffer,"|"); 
	strcat(buffer,branch); 
	strcat(buffer,"|"); 
	strcat(buffer,sem); 
	strcat(buffer,"|"); 
}

int student::search(char*fusn){
	int low=0,high=indsize-1,mid;  
	while(low <=high)  {   
		mid = (low+high)/2;   
		if(strcmp(fusn,id[mid].iusn)==0)    
			return mid;   
		if(strcmp(fusn,id[mid].iusn)>0)    
			low=mid+1;   
		else    
			high=mid-1;  
	}  
	return -1;
}

int student::sec_search(){
	int pos,j,flag=-1;  
	char b[10];
	cout<<"\nenter the name to search(sec key):";  
	gets(b);
	gets(skey);  
	cout<<"the searched record details are :"<<endl;  
	cout<<setiosflags(ios::left);  
	cout<<"usn"<<"\t\tname"<<endl;
	dfile.open(datafile,ios::in|ios::out); 
	for(j=0;j<sindsize;j++)    
	if(strcmp(skey,sid[j].sname)==0)     {    
		cout<<sid[j].susn<<"\t\t"<<sid[j].sname<<endl;    
		flag=j;     
	}  
	cout<<endl<<endl;
	return flag; 
}

void student::remove(){
	char rusn[10];  
	int pos,spos;  
	cout<<"enter the usn number above listed to delete:\n";  
	cin>>rusn;  
	for(i=0;i<sindsize;i++)  {     
		if(strcmp(sid[i].susn,rusn)==0)      {      
			spos=i;      
			break;      
		}  
	} 
 	if(strcmp(sid[spos].sname,skey)==0)  {   
	 	pos=search(rusn);   
	 	dfile.seekp(atoi(id[pos].addr),ios::beg);   
 		dfile.put('$');   
 		for(i=pos;i<indsize;i++)    
	 		id[i]=id[i+1];   
 		indsize--;   
	 	for(i=spos;i<sindsize;i++)    
	 		sid[i]=sid[i+1];   
 		sindsize--;  
 	} 
	else   
		cout<<"usn number and name doesnot match"; 
}

void student::unpack(){
	dfile.getline(buffer,100,'\n');   
	i=0;   
	if(buffer[i]!='$')    
		while(buffer[i]!='\0')   {    
			if(buffer[i]=='|')     
				cout<<"\t\t";    
			else     
				cout<<buffer[i];    
			i++;   
		}
}

void student::datadisp(){
	cout<<setiosflags(ios::left);  
	cout<<setw(16)<<"usn"<<setw(16)<<"name"<<setw(16)<<"age"<<setw(16);  
	cout<<"branch"<<setw(16)<<"sem"<<endl;  
	while(1)  {   
		unpack();   
		if(dfile.eof())       
			break;  
	}  
	cout<<endl<<"the index file details are "<<endl;  
	cout<<setw(10)<<"usn"<<setw(10)<<"address"<<endl;  
	for(i=0;i<indsize;i++)    
		cout<<endl<<setw(10)<<id[i].iusn<<setw(10)<<id[i].addr;  
	cout<<endl<<"\n the secondary file details are " <<endl;  
	cout<<setw(20)<<"name"<<setw(15)<<"primary reference"<<endl;  
	for(i=0;i<sindsize;i++)     
		cout<<endl<<setw(20)<<sid[i].sname<<setw(15)<<sid[i].susn<<endl<<endl; 
}

int main(){
	int ch,flag;  
	in.initial();  
	sin.sinitial();  
	system("cls");  
	for(;;)  {  
		cout<<endl<<"1-read,2-display,3-search,4-delete,5-exit\n";  
		cin>>ch;  
		switch(ch)  {   
			case 1: cout<<endl<<"enter student details : " <<endl;    
					s.read();    
					in.write();    
					sin.swrite();    
					break;   
			case 2: dfile.open(datafile,ios::in);      
					cout<<"\nthe datafile,indexfile and secondary file" <<endl;       
					s.datadisp();       
					break;   
			case 3: cout<<"To search based on  sec key "; 
					flag=s.sec_search();    
					if(flag==-1)        
						cout<<"no data record ";    
					break;   
			case 4: flag=s.sec_search();    
					if(flag==-1)     
						cout<<"no data record found";    
					else    {        
						s.remove();        
						in.write();        
						sin.swrite();     
					}    
					break;   
			default :  exit(0);     
		}     
		dfile.close();     
		ifile.close();      
		sifile.close();  
	}
}


