//PROJECT : address book
// header files :
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<iomanip.h>
// class :
class book
{
    unsigned long int phn1;
    unsigned long int phn2;
    char addr1[100];
    char addr2[100];
    char email[100];
  public :
    char nm[40];
    void menu();
    void input();
    void input2();
    void add();
void modi();
    void search();
    void dispall();
    void disp2();
    void disp();
    void del();
    void delall();
}obj,mobj;
// functions :
void open()
{
   cout<<"##################################################################";
   cout<<"##############";
   cout<<"\n\n\n "<<setw(50)<<" ******* ADDRESS BOOK ******* " ;
   cout<<"\n\n\n "<<setw(60)<<"   C++ project "<<endl;
   cout<<setw(80)<<"   By : Amrit Ohri ";
   cout<<"\n\n\n\n Press any key to continue \n\n\n\n\n\n";
   cout<<"##################################################################";
   cout<<"##############";
   getch();

}
void book::add()
{ clrscr();
  ofstream fout;
  fout.open("addrbook",ios ::out|ios ::app);
  cout<<setw(50)<<"Addition ";
  input();
  fout.write((char*)&obj,sizeof(obj));
  fout.close();

}
void book::input()
{
   cout<<"\n Enter name of the person : ";
   gets(nm);
   cout<<"\n Enter personal no. : ";
   cin>>phn1;
   cout<<"\n Enter office no. : ";
   cin>>phn2;
   cout<<"\n Enter house address : ";
   gets(addr1);
   cout<<"\n Enter office address : ";
   gets(addr2);
   cout<<"\n Enter email address : ";
   gets(email);
   clrscr();
   cout<<" \n \n \n \n \n \n \n \n"<<setw(60)<<" STORED ! ";
   getch();
   clrscr();
}
void book::input2()
{  char str[40]="0";
   cout<<"\n Type 0 if you do not want to modify that field else directly type the new data ";
   cout<<"\n Enter name of the person : ";
   gets(nm);
   if (strcmp(nm,str)==0)
strcpy(nm,obj.nm);
   cout<<"\n Enter personal no. : ";
   cin>>phn1;
   if (phn1==0)
   phn1=obj.phn1;
   cout<<"\n Enter office no. : ";
   cin>>phn2;
   if (phn2==0)
   phn2=obj.phn2;
   cout<<"\n Enter house address : ";
   gets(addr1);
   if (strcmp(addr1,str)==0)
   strcpy(addr1,obj.addr1);
   cout<<"\n Enter office address : ";
   gets(addr2);
   if (strcmp(addr2,str)==0)
   strcpy(addr2,obj.addr2);
   cout<<"\n Enter email address : ";
   gets(email);
   if (strcmp(email,str)==0)
   strcpy(email,obj.email);
   clrscr();
   cout<<" \n \n \n \n \n \n \n \n"<<setw(60)<<" STORED ! ";
   getch();
   clrscr();
}
void book::search()
{  clrscr();
   char snm[40],f='n',sch;
   ifstream fin("addrbook");
   if(fin.fail())
	    cout<<" File not found ";
   
cout<<"Enter the name of the person whose record you want to search for \n";
   gets(snm);    fin.seekg(0,ios::end);
   int n=fin.tellg()/sizeof(obj);
   fin.seekg(0);
   for (int i=0;i<n;i++)
    {  fin.read((char*)&obj,sizeof(obj));
	  if (strcmp(nm,snm)==0)
	    {
	      cout<<endl;
	      disp();
	      f='y';

	    }
    }
     if (f=='n') {  cout<<"Not found!! ";
		 }
     fin.close();

     clrscr();

}
void book::disp()
{  puts(obj.nm);
   char da;
   cout<<endl<<" Personal no. : "<<phn1<<" \n Office no. : "<<phn2;
   cout<<endl<<" House address : ";
   puts(addr1);
   cout<<" Office address : ";
   puts(addr2);
   cout<<" \t Email : ";
   puts(email);
   ;
getch();
}
void book::disp2()
{  puts(obj.nm);
   char da;
   cout<<endl<<" Personal no. : "<<phn1<<" \n Office no. : "<<phn2;
   cout<<endl<<" House address : ";
   puts(addr1);
   cout<<" Office address : ";
   puts(addr2);
   cout<<" \t Email : ";
   puts(email);
}
void book::dispall()
{  clrscr();
   int i=0;
   char dich;
   ifstream fin("addrbook");
   fin.seekg(0,ios::end);
   int n=fin.tellg()/sizeof(obj);
   if (n==0) cout<<"\n No contacts ! ";
   fin.seekg(0);
   for (i=0;i<n;i++)
   {  cout<<" Record "<<i+1<<endl;
      fin.read((char*)&obj,sizeof(obj));  
      disp2();
      cout<<endl;
   }
   fin.close();
    getch();
    clrscr();
}
void book::modi()
{  clrscr();
   char tempname[40],mnm[40],mch,mf='n';
   cout<<" Enter name of the person whose contact you want to modify ";
   gets(mnm);
   ofstream fout("mtemp",ios::out);
   ifstream fin("addrbook",ios::in);
   fin.seekg(0,ios::end);
   int n=fin.tellg()/sizeof(obj);
   fin.seekg(0);
   for(int i=0;i<n;i++)
   {  fin.read((char*)&obj,sizeof(obj));
      if (strcmp(mnm,nm)!=0)
	   {     fout.write((char*)&obj,sizeobj));
	   }
      else
	   {     mobj.input2();
		 mf='y';
		 fout.write((char*)&mobj,sizeof(mobj));
	   }
   }
   if (mf=='n') cout<<" Not found !!";
   getch();
   fin.close();
   fout.close();
   remove("addrbook");
   rename("mtemp","addrbook");

}
void book::del()
{  clrscr();
   char dnm[40],dch,df='n';
  
ifstream fin("addrbook",ios::in);
   ofstream fout("dtemp",ios::out);
   cout<<" Enter name whose record id to be deleted ";
   gets(dnm);
   fin.seekg(0,ios::end);
   int n=fin.tellg()/sizeof(obj);
   fin.seekg(0);
   for(int i=0;i<n;i++)
   { fin.read((char*)&obj,sizeof(obj));
     if (strcmp(dnm,nm)!=0)
	{ fout.write((char*)&obj,sizeof(obj));  }
     else
	{  disp2();
	   df='y';
	   cout<<" Are you sure you want to delete this record ? (y/n)  ";
	   cin>>dch;
	   if (dch=='y'||dch=='Y')
	     {
		clrscr();
		cout<<"\n\n\n\n\n\n\n Deleted !! ";
	     }
	   else
	      fout.write((char*)&obj,sizeof(obj));
	 }
    }
    if (df=='n')
	      cout<<" Not found !!";
    getch();
    fin.close();
    fout.close();
    remove("addrbook");
rename("dtemp","addrbook");

}
void book::delall()
{  clrscr();
   char dech;

   cout<<"\n Are you sure you want to delete all contacts ? (y/n) ";
   cin>>dech;
   if (dech=='y'||dech=='Y')
			   {
			     remove("addrbook");
			     rename("detemp","addrbook");
			     clrscr();
			     cout<<"\n\n\n\n\n\n\ Deleted ! ";

			   }
    getch();

}
void book::menu()
{
   int ch;
   for (int i=0;i<5;i++)
   cout<<endl;
   cout<<"\t\t\t\t^^^^~~~~~ MENU ~~~~^^^^ "<<endl;
   cout<<endl<<"\t\t * 1.Addition of a new contact *";
   cout<<endl<<"\t\t * 2.Modification of a contact *";
   cout<<endl<<"\t\t * 3.Search for a contact *";
   cout<<endl<<"\t\t * 4.Display all contacts *";
   cout<<endl<<"\t\t * 5.Delete a contact *";
   cout<<endl<<"\t\t * 6.Delete all contacts  *";
   
cout<<endl<<"\t\t * 7.Exit *";
   cout<<"\n\n  Enter your choice(1-7) : ";
   cin>>ch;
   switch (ch)
   {  case 1 :
	       add();
	       break;
      case 2 :
	       modi();
	       break;
      case 3 :
	       search();
	       break;
      case 4 :
	       dispall();
	       break;
      case 5 :
	       del();
	       break;
      case 6 :
	       delall();
	       break;
      case 7 :
	       exit(0);
	       break;
      default :
		{
		  cout<<"Wrong choice "<<endl;
		  getch();
		}
   }
}

// mains() of the program :
void main()
{  clrscr();
   open();
   for(int i=0;i>-1;i++)
   {
    clrscr();
    obj.menu();
   }
    getch();
}
// End of the program ;;;


