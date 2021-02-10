#include<iostream>
#include<cstring>
#include<fstream>
#include<iomanip>
using namespace std;
class student
{
public :
int sid,s_sem,k;
char sname[30],s_stream[30],n[30];
long int scont;
 void getd()
 {
  cout<<"Enter your name\n";
  cin>>sname;
  for(k=0;sname[k]!='\0';k++)
  {
   if(isalpha(sname[k])==0)
   {
    cout<<"Enter your name again";
    cin>>n;
    strcpy(sname,n);
   }
  }
  cout<<"Enter id\n";
  cin>>sid;
  cout<<"Enter contact\n";
  cin>>scont;
  cout<<"Enter Semester\n";
  cin>>s_sem;
  cout<<"Enter stream\n";
  cin>>s_stream;
 }
 void putd()
 {
  cout<<"Name is\t"<<sname;
  cout<<"Id is\t"<<sid;
  cout<<"Contact\t"<<scont;
  cout<<"Semester\t"<<s_sem;
  cout<<"stream\t"<<s_stream;
 }
};
class grievance : public student
{
public :
int gid;
char g_type[20],g_faculty[30],g_status[20];
 void getdata()
 {
  cout<<"\nEnter gid\n";
  cin>>gid;
  cout<<"\nEnter gtype\n";
  cin>>g_type;
  cout<<"\nEnter faculty name\n";
  cin>>g_faculty;
  cout<<"\nEnter status\n";
  cin>>g_status;
 }
 void putdata()
 {
  cout<<"Gid :\t"<<gid;
  cout<<"Gtype :\t"<<g_type;
  cout<<"Faculty :\t"<<g_faculty;
  cout<<"Status :\t"<<g_status;
 }
};
int main()
{
int i;
grievance ob[5];
for(i=0;i<=4;i++)
{
 ob[i].getd();
 ob[i].getdata();
}

cout<<"\n-------------------------------------------------";
cout<<"\nnames of all the students which belong to stream "BDA" and are in semester "VI" or "IV";
for(i=0;i<=4;i++)
{
if((ob[i].s_sem==6||ob[i].s_sem==4)&&(strcmp(ob[i].s_stream,"BDA")==0)||(strcmp(ob[i].s_stream,"Bda")==0)||(strcmp(ob[i].s_stream,"bda")==0))
{
cout<<"\n"<<ob[i].sname;
}
}

cout<<"\n----------------------------------------------------";
cout<<"\nnames of all the students who have reported grievance type as "Infrastructure Bad" and are from stream "CBA";
for(i=0;i<=4;i++)
{
if(((strcmp(ob[i].s_stream,"CBA")==0)||(strcmp(ob[i].s_stream,"cba")==0)||(strcmp(ob[i].s_stream,"Cba")==0))&&((strcmp(ob[i].g_type,"badinfrastructure")==0)))
{
cout<<"\n"<<ob[i].sname;
}
}


cout<<"\n----------------------------------------------------";
cout<<"\nnames of all the students who have reported grievance type as "Infrastructure Bad" and are from stream "CBA";
for(i=0;i<=4;i++)
{
if(((strcmp(ob[i].s_stream,"CBA")==0)||(strcmp(ob[i].s_stream,"cba")==0)||(strcmp(ob[i].s_stream,"Cba")==0))&&((strcmp(ob[i].g_type,"badinfrastructure")==0)))
{
cout<<"\n"<<ob[i].sname;
}
}
cout<<"\n--------------------------------------------------";
cout<<"\nFaculty whose gstatus is pending :";
for(i=0;i<=4;i++)
{
 if((ob[i].s_sem==1||ob[i].s_sem==2||ob[i].s_sem==3)&&(strcmp(ob[i].g_status,"pending")==0))
 {
  cout<<"\n"<<ob[i].g_faculty;
 }
}
cout<<"\n--------------------------------------------------\n";
int j,v,count=0,p=0;
char temp[30],a[30][30];
for(i=0;i<=4;i++)
{
if(((ob[i].s_sem==5)||(ob[i].s_sem==6))&&((strcmp(ob[i].g_type,"allocatedleaves")==0) || (strcmp(ob[i].g_type,"workload")==0)))
 {
   strcpy(a[p],ob[i].sname);
  v=count;
  count++;
  p++;
  
 }
}

for(i=0;i<=v;i++)
{
 for(j=i+1;j<=v;j++)
 {
  if(strcmp(a[i],a[j])>0)
  {
   strcpy(temp,a[i]);
   strcpy(a[i],a[j]);
   strcpy(a[j],temp);
  }
 }
}
cout<<"----------------------------------------------------";
cout<<"\n Names of all the grievance reported by students of semester "5" and "6" made for "Allocated leaves" and "Study load hours issue" alphabetically sorted. \n";
for(i=0;i<=v;i++)
{
 cout<<"\nName :"<<a[i];
}
cout<<"\n--------------------------------------------------";
int choice;
char ch;
cout<<"\n--------------------------USING FILE HANDLING CONCEPT---------------------\n";
cout<<"\n-------CHOICES-------\n";
do
{
cout<<"1.To display the given records in a file\n";
cout<<"2.To append records in a file\n";
cout<<"3.To read from file and display\n";
cout<<"4.Exit\n";
cout<<"Enter your choice\n";
cin>>choice;
if(choice==1)
{
 ofstream obj("123.1.cpp",ios::out|ios::binary|ios::trunc);
 obj<<"\t"<<"SID"<<"\t"<<"Name"<<"\t"<<"contact"<<"\t"<<"semester"<<"stream"<<"\t"<<endl;
  for(i=0;i<=4;i++)
  {
         obj<<"\t"<<ob[i].sid<<"\t"<<ob[i].sname<<"\t"<<ob[i].scont<<"\t"<<ob[i].s_sem<<"\t"<<ob[i].s_stream<<endl;
  }
  obj.close();    
}
grievance g[3];
if(choice==2)
{
 ofstream obj("123.1.cpp",ios::out|ios::binary|ios::trunc);
 for(i=0;i<=4;i++)
 {
  g[i].getd();
 }
 for(i=0;i<=4;i++)
 {
  obj<<"\t"<<g[i].sid<<"\t"<<g[i].sname<<"\t"<<g[i].scont<<"\t"<<g[i].s_sem<<"\t"<<g[i].s_stream<<endl;
 }
 obj.close();
}
if(choice==3)
{
 ifstream fin("123.1.cpp",ios::in);
while(fin.get(ch))
{
cout<<ch;
}
}
