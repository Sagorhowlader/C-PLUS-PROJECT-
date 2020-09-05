#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<cstdlib>
using namespace std;
class Bookshop
{
private:
    char bname[50];
    char author[50];
    int bookno;
    int d,m,y;
    char stname;
    int id;
    int c;
public:
    void getdata();
    void bookshow();
    int rebookno();

};
void Bookshop::getdata()
{
 cout<<"\n\"        \"ENTER DETAILS ABOUT BOOK \" :\"";
 cout<<"\n\n\n\t\tEnter Book No  :\t";
 cin>>bookno;
 cout<<"\n\n\n\t\tEnter Name Of Book  :\t";
cin.ignore();
cin.getline(bname,49);
cout<<"\n\t\tEnter Name Of Author    :\t";
 cin.ignore();
	cin.getline(author,49);
 cout<<"\n\t\tEnter No. Of Copies  :\t";
 cin>>c;
 cout<<"\n\t\tEnter Date  :\t";
cin>>d;cin>>m,cin>>y;
}
void Bookshop::bookshow()
{
	//cout<<" "<<bookno<<setw(16)<<" "<<bname<<setw(15)<<" "<<author<<setw(12)<<" "<<c<<setw(12)<<" "<<d<<"-"<<" "<<<m<<"-"<<" "<<y<<endl;
	cout<<" "<<bookno<<setw(16)<<" "<<bname<<setw(15)<<" "<<author<<setw(12)<<" "<<c<<setw(12)<<" "<<d<<"-"<<m<<"-"<<y<<endl;
}
int Bookshop::rebookno()
{
    return bookno;
}
void write_account();
void display_all();
void delete_account(int);
int main()
{


	char ch;
	int num;

	do
	{
		system("cls");

		cout<<"\n\n\t\t\t...::::\xB2\xB2  WELCOME TO HouseRent System  \xB2\xB2:::::....\n\n";
		cout<<"\n\t\t\t\t          MAIN MENU\n\n";
		cout<<"\n\t\t\tPress recommended key for specific service:\n\n";
		cout<<"\n\n\t\t\t[1] ADD NEW Book";
		cout<<"\n\n\t\t\t[2] VIEW ALL TENANT LIST ";
		cout<<"\n\n\t\t\t[3] DELET A TENANT RECORD ";
		cout<<"\n\n\t\t\t[4] EDIT TENANT RECORD";
		cout<<"\n\n\t\t\t[5] CALCULATE RENTAL FEE ";
		cout<<"\n\n\t\t\t[0] EXIT";
        cout<<"\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
        cout<<"\n\n\t\t\tEnter Your Choice:";
		cin>>ch;
		system("cls");

		switch(ch)
		{
		case '1':
			write_account();
			break;
        case '2':

			display_all();
			break;
       case '3':
            cout<<"\n\n\tDelete Delete Book Record";
            cout<<"\n\n\n\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
			cout<<"\n\n\tEnter The BookNo. : "; cin>>num;
			delete_account(num);
			break;
        case '4':
            /*cout<<"\n\n\tEdit TENANT Record";
            cout<<"\n\n\n\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
			cout<<"\n\n\tEnter The House No. : "; cin>>num;
			edit_account(num);*/
			break;
        case '5':
             /*cout<<"\n\n\tCalculate Monthly Rental Fee";
            cout<<"\n\n\n\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
			cout<<"\n\n\tEnter The House No. : "; cin>>num;
			bill_calculation(num);*/
			break;
        case '0':
			 /*cout<<"\n\n\tThanks for using House Rent Managment System :) :)";*/
			break;
		 default :
            cout<<"\n\n\tInvalid Number";
            cout<<"\n\n\tPress Enter To Return Main Menu";
		}
		cin.ignore();
		cin.get();
	}while(ch<='5');
	return 0;
}
void write_account()
{
	Bookshop ac;
    ofstream outFile;
	outFile.open("BookShopManagement.txt",ios::binary|ios::app);
	ac.getdata();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bookshop));
	outFile.close();
}
void display_all()
{
	Bookshop ac;
	ifstream inFile;
	inFile.open("BookShopManagement.txt",ios::out);
	if(!inFile)
	{
		cout<<"\n\nFile could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\t\t\tBook List LIST\n\n\n\n";

	cout<<"       BookNo                 BookName           Author           Copies           Date\n\n";

	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bookshop)))
	{
		ac.bookshow();

	}

	inFile.close();
	cout<<"\n\n\tPress Enter To Return Main Menu";
}
void delete_account(int n)
{
	Bookshop ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("BookShopManagement.txt",ios::out);
	if(!inFile)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bookshop)))
	{
		if(ac.rebookno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bookshop));
		}
	}
	inFile.close();
	outFile.close();
	remove("BookShopManagement.txt");
	rename("Temp.dat","BookShopManagement.txt");
	cout<<"\n\n\tRecord Deleted ...";
	 cout<<"\n\n\tPress Enter To Return Main Menu.";
}
