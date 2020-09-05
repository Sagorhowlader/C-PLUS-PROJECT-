#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<cstdlib>
using namespace std;
class HouseRent
{
    private:

    int phnum;
    int houseno;
    char name[50];
    int Total_Rent_Fee;
    int house_rent;
    int gas_bill;
    int water_bill;
public:
	void create_account();
	void show_account() const;
	void modify();
	void Claculation(int);

	void show() const;
	int rethouseno() const;
	void show_bill() const;
	void show_rent_bill() ;
};
void HouseRent::Claculation(int x)
{
   float unit=3.8;
   int m=55;
   float t;
   t=(x*unit)+m;

  Total_Rent_Fee=t+house_rent+gas_bill+water_bill;



}
void HouseRent::show_bill() const
{
    cout<<"\n\n\tTenant House No. : "<<houseno;
	cout<<"\n\n\tTenant Holder Name: ";
	cout<<name;
	cout<<"\n\n\tPhoneNumber :0"<<phnum;
	cout<<"\n\n\tHouse Rent: "<<house_rent;
	cout<<"\n\n\tGas Bill: "<<gas_bill;
	cout<<"\n\n\tWater Bill: "<<water_bill;
}
void HouseRent::show_rent_bill()
{
    cout<<"\n\n\tTenant House No. : "<<houseno;
	cout<<"\n\n\tTenant Holder Name: ";
	cout<<name;
	cout<<"\n\n\tPhoneNumber : "<<phnum;
	cout<<"\n\n\tThis Month House Rent: "<<Total_Rent_Fee<<"BDT";
}
int HouseRent::rethouseno() const
{
	return houseno;
}


void HouseRent::create_account()
{
            cout<<"\n\n\tEnter Full Name: ";
            cin.ignore();
            cin.getline(name,49);
            cout<<"\n\n\tEnter House No :";
            cin>>houseno;
            cout<<"\n\n\tEnter Your  Phone Number :";
            cin>>phnum;
            cout<<"\n\n\tEnter HouseRent: ";
            cin>>house_rent;
            cout<<"\n\n\tEnter WaterBill: ";
            cin>>water_bill;
            cout<<"\n\n\t Enter Gas Bill: ";
            cin>>gas_bill;
            cout<<"\n\n\t New Account has been created";
            cout<<"\n\n\tPress Enter To Return Main Menu";

}
void HouseRent::show() const
{
	cout<<" "<<name<<setw(17)<<" "<<houseno<<setw(15)<<"0"<<phnum<<setw(17)<<" "<<house_rent<<endl;
}
void HouseRent::modify()
{
	cout<<"\n\n\tTenant House No. : "<<houseno;
	cout<<"\n\n\tModify Tenant Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\n\tEnter new PhoneNumber: ";
	cin.ignore();
	cin>>phnum;
	cout<<"\n\n\tEnter new HouseRent: ";
	cin.ignore();
	cin>>house_rent;
	cout<<"\n\n\tEnter New WaterBill: ";
	cin.ignore();
    cin>>water_bill;
    cout<<"\n\n\t Enter New Gas Bill: ";
    cin.ignore();
    cin>>gas_bill;



}
void HouseRent::show_account() const
{
	cout<<"\n\n\tTenant House No. : "<<houseno;
	cout<<"\n\n\tTenant Holder Name: ";
	cout<<name;
	cout<<"\n\n\tPhoneNumber :0"<<phnum;
	cout<<"\n\n\tHouseRent: "<<house_rent;
	cout<<"\n\n\tWaterBill: "<<water_bill;
	cout<<"\n\n\tGasBill: "<<gas_bill;

}

void write_account();
void display_all();
void delete_account(int);
void edit_account(int);
void bill_calculation(int);

int main()
{


	char ch;
	int num;
	do
	{

		system("cls");

		cout<<"\n\n\t\t\t...::::\xB2\xB2         WELCOME TO HouseRent System         \xB2\xB2:::::....\n\n";
		cout<<"\n\n\t\t\t\t\t\t\tMAIN MENU\n\n";
		cout<<"\n\n\t\t\t\t\tPress recommended key for specific service:\n\n";
		cout<<"\n\n\t\t\t\t\t[1] ADD A NEW TENANT";
		cout<<"\n\n\t\t\t\t\t[2] VIEW ALL TENANT LIST ";
		cout<<"\n\n\t\t\t\t\t[3] DELET A TENANT RECORD ";
		cout<<"\n\n\t\t\t\t\t[4] EDIT TENANT RECORD";
		cout<<"\n\n\t\t\t\t\t[0] EXIT";
        cout<<"\n\n\n\n\n\t\t\t\t    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
        cout<<"\n\n\n\n\t\t\t\tEnter Your Choice:";
		cin>>ch;

		switch(ch)
		{
		case '1':
			write_account();
			break;
        case '2':

			display_all();
			break;
       case '3':
			cout<<"\n\n\tEnter The House No. : "; cin>>num;
			delete_account(num);
			break;
        case '4':
			cout<<"\n\n\tEnter The House No. : "; cin>>num;

			edit_account(num);
			break;
           case '5':
			cout<<"\n\n\tEnter The House No. : "; cin>>num;
			bill_calculation(num);
			break;

        case '0':
			cout<<"\n\n\tThanks for using House Rent Managment System :) :)";
			break;
		 default :
            cout<<"Invalid Number";
		}
		cin.ignore();
		cin.get();
	}while(ch<='4');
	return 0;
}
void write_account()
{
	HouseRent ac;
    ofstream outFile;
	outFile.open("HouseRentManagement.txt",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(HouseRent));
	outFile.close();
}
void display_all()
{
	HouseRent ac;
	ifstream inFile;
	inFile.open("HouseRentManagement.txt",ios::binary);
	if(!inFile)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\t\tTenant HOLDER LIST\n\n\n\n";

	cout<<"       NAME                  Room no.           PhoneNumber           HouseRent\n\n";

	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(HouseRent)))
	{
		ac.show();

	}

	inFile.close();
	cout<<"\n\n\tPress Enter To Return Main Menu";
}
void delete_account(int n)
{
	HouseRent ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("HouseRentManagement.txt",ios::binary);
	if(!inFile)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(HouseRent)))
	{
		if(ac.rethouseno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(HouseRent));
		}
	}
	inFile.close();
	outFile.close();
	remove("HouseRentManagement.txt");
	rename("Temp.dat","HouseRentManagement.txt");
	cout<<"\n\n\tRecord Deleted ...";
	 cout<<"\n\n\tPress Enter To Return Main Menu.";
}

void edit_account(int n)
{
	bool found=false;
	HouseRent ac;
	fstream File;
	File.open("HouseRentManagement.txt",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(HouseRent));
		if(ac.rethouseno()==n)
		{
			ac.show_account();
			cout<<"\n\n\tEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(HouseRent));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(HouseRent));
			cout<<"\n\n\t Record Updated";
			cout<<"\n\n\tPress Enter To Return Main Menu.";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t Record Not Found ";

}
void bill_calculation(int n)
{
	int un;
	HouseRent ac;
	fstream File;
	bool found=false;
	File.open("HouseRentManagement.txt", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
		return;
	}
	while(!File.eof())
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(HouseRent));
		if(ac.rethouseno()==n&& found==false)
		{
			ac.show_bill();

				cout<<"\n\n\tTO BILL ";
				e:
				cout<<"\n\n\tEnter the Unit of Elctricity: ";
				cin>>un;
				ac.Claculation(un);
				   cout<<"\n\n\tHouse Rent BIll";
				   ac.show_rent_bill();
				   found=true;


			}
			         }
        File.close();
        cout<<"\n\n\tPress Enter To Return Main Menu.";
}
