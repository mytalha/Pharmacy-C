#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<stdlib.h>
int num=0 ,sum =0;
using namespace std;
class pharm{
	public:
	int order_no,price;
	int drug_ID[30];
	
	int tot[10];
	string name, cell_no;
	int number_drugs,qty_drug[40];

	void order();//decleration
	void bill();
	void find();
	void dataupdate();
	void input_dataupdate();
 	void dispose();
 	void med();
	void showdata();
};
void menu(){
	
	cout<<"\n \t\t\t1. Take Order of Medicine ";
	cout<<"\n\t\t\t2. Bill Summary"<<endl;
	cout<<"\t\t\t3. Search of Bill"<<endl;
	cout<<"\t\t\t4. Modify the Bill"<<endl;
	cout<<"\t\t\t5. Delete Data"<<endl;
	cout<<"\t\t\t6. Show all data"<<endl;
	cout<<"\t\t\t7. Exit"<<endl;
	 
}
	pharm a; //Global variable 
	void pharm::showdata(){
	 	cout<< "Name\t"<<"cell no.\t"<<"Drag Id\t "<<" Medicine name\t"<<"Qty\t"<<"Price\t "<<"Total"<<endl;
			fstream File;
	File.open("Database.txt",ios::in);
	if(!File)
	{
	cout<<"File can not open";
		
	}
	
	char a[2000];
	File.getline(a,2000,'\0');
	cout<<a;
	File.close();
	
	cout<<"\n\n-------------------------------------------\n"; 
}
void pharm::order(){ 
	
	cout<<"\n\n-------------------------------------------\n";
	fstream med_file;
	med_file.open("med.txt",ios::in); //Medicine data file open and only read this file 
	char b[2000];
	med_file.getline(b,2000,'\0');
	cout<<b;
	med_file.close();	//Medicine database file is closed after reading 
	cout<<"\n-------------------------------------------";
	
	fstream out("Database.txt",ios::app);//customer record database on file which save in mass storage 
	//out.open("Database.txt");
//	out.seekp(0,ios::beg);
	out<<endl;
	cout<<"\nCustomer Name : ";
	cin.ignore();
	getline(cin,a.name);
	out<<a.name<<'\t';
	cout<< "Cell Number : ";
	cin>>(cin,a.cell_no);
	out<<a.cell_no<<'\t';	
	cout<< "Order Number : ";
	cin>>a.order_no;
	//out<<a.order_no<<'\t';
	int i=0;
	while (i<1){
		cout<<" \nDrug ID : ";
		cin>>a.drug_ID[i];
		out<<a.drug_ID[i]<<'\t';
		if (a.drug_ID [i]== 01){
			cout<<"\t\t\"Mytika\"\n";
		cout<<"\nQuantity of Medicine : ";
		out<<"Mytika\t";	//prin in file 
		cin>>a.qty_drug[i];
		a.tot [i]= a.qty_drug[i]*50;
		cout<<"\nPrice : "<<a.tot[i]<<endl;
		out<<a.qty_drug[i];
		out<<'\t'<<"50"<<'\t';
		out<<a.tot[i]<<'\t';
		}
		else if (a.drug_ID[i]==02){
			cout<<"\t\t\"Ventoline\"\n";
			out<<"Ventoline\t";		//prin in file 
		cout<<"\nQuantity of Medicine : ";
		cin>>a.qty_drug[i];
		a.tot[i] = a.qty_drug[i]*1000;
		cout<<"\nPrice : "<<a.tot[i]<<endl;
		out<<a.qty_drug[i];
		out<<'\t'<<"1000"<<'\t';
		out<<a.tot[i]<<'\t';
		}
		else if (a.drug_ID[i]==03){
			cout<<"\n\t\t\"Quibrine Tsr\"";
			out<<"QuibrineTsr\t";		//print in file 
			cout<<"\nQuantity of Medicine : ";
		cin>>a.qty_drug[i];
		a.tot [i]= a.qty_drug[i]*200;
		cout<<"\nPrice : "<<a.tot[i]<<endl;
		out<<a.qty_drug[i];
		out<<'\t'<<"200"<<'\t';
		out<<a.tot[i]<<'\t';
		}
		else if(a.drug_ID[i]==04){
			cout<<"\t\t\"Betnisole\"";
					out<<"Betnisole\t";		//print in file
			cout<<"\nQuantity of Medicine : ";
		cin>>a.qty_drug[i];
		a.tot [i]= a.qty_drug[i]*25;
		cout<<"\nPrice : \n"<<a.tot[i]<<endl;
		out<<a.qty_drug[i];
		out<<'\t'<<"25"<<'\t';
		out<<a.tot[i]<<'\t';
		}
		else if(a.drug_ID[i]==05){
			cout<<"\t\t\"Discole\"";
			out<<"Discole\t";			//print in file 
			cout<<"\nQuantity of Medicine : ";
		cin>>a.qty_drug[i];
		a.tot [i]= a.qty_drug[i]*40;
		cout<<"\nPrice : "<<a.tot[i]<<endl;
		out<<a.qty_drug[i];
		out<<'\t'<<"40"<<'\t';
		out<<a.tot[i]<<'\t';
		}
		else
		 cout<<" Error! Invalid ID ";
	
		sum+=a.tot[i];
		i++;
	}
	out.close();
	
	
}
void pharm::bill(){
	//pharm b;
	cout<<"\  --------------------HAT PHARMACY-------------------\n";
	cout<<"Customer Name : "<<a.name<<endl;
	cout<<"Cell Number : "<<a.cell_no<<endl;
	cout<<"\  ___________________________________________________\n";
	cout<<"\n\t\tBill summary\n\n";
	cout<<"  Drug ID\t Medicine name\t    Qty\t Price\t Total\n";
	int i=0;
	while (i<1)
	{
		if (a.drug_ID[i]==01)
	cout<<"  "<<a.drug_ID[i]<<setw(20)<<"\t Mytika\t"<<setw(13)<<a.qty_drug[i]<<"\t 50\t "<<a.tot[i]<<endl ;
	if (a.drug_ID[i]==02)
	cout<<"  "<<a.drug_ID[i]<<setw(20)<<"\t ventoline\t"<<setw(5)<<a.qty_drug[i]<<"\t 1000\t "<<a.tot[i] <<endl;
	if (a.drug_ID[i]==03)
	cout<<"  "<<a.drug_ID[i]<<setw(20)<<"\t Quibrine\t"<<setw(5)<<a.qty_drug[i]<<"\t 200\t "<<a.tot[i] <<endl;
	if (a.drug_ID[i]==04)
	cout<<"  "<<a.drug_ID[i]<<setw(20)<<"\t Betnisole\t"<<setw(5)<<a.qty_drug[i]<<"\t 25\t "<<a.tot[i]<<endl ;
	if (a.drug_ID[i]==05)
	cout<<"  "<<a.drug_ID[i]<<setw(20)<<"\t Discole\t"<<setw(5)<<a.qty_drug[i]<<"\t 40\t "<<a.tot[i]<<endl ;
			i++;
		
	}
		cout<<"\  ___________________________________________________\n";
		cout<<"\n\nGrand Total : "<<sum;
		float discount;
		discount = (sum/100)*13;
		cout<<"\nDiscount : "<<discount;
		int paid;
		paid = sum - discount;
		cout<<"\nPayable Bill : "<<paid;	
		cout<<"\n\n\t\tGo to reception and pay the bill \n\n";
		cout<<"\t---------------Thank You!!--------------"<<endl;		
		
}
void pharm::find(){
	fstream file;
	file.open("Database.txt",ios::binary|ios::in|ios::out);//coustomer
	string x,b,c,d,e,f,g;
	string z;
	int f1 =0,pos;
	cout<<"Enter first name : ";
	cin.ignore();
	getline(cin,z);
	
	while (!file.eof()){
		file>>x>>b>>c>>d>>e>>f>>g;
		if(z==x|| z==b|| z==c|| z==d|| z==e)
		{
			f1=1;
			
	cout<<"\  --------------------HAT PHARMACY-------------------\n";
	cout<<"Customer Name : "<<x<<endl;
	cout<<"Cell Number : "<<b<<endl;
	cout<<"\  ___________________________________________________\n";
	cout<<"\n\t\tBill summary\n\n";
	cout<<"  Drug ID\t Medicine name\t    Qty\t Price\t Total\n";
	cout<<"  "<<c<<"\t\t "<<d<<"\t     "<<setw(0)<<e<<setw(3)<<"\t "<<f<<"\t "<<g<<endl;
			 break;
	}
}
		
	if (!f1)
	{
		cout<<"Record not found"<<endl;
	}
}


int main(){
	
while(1){
	menu();
	cout<<"\nEnter the Number: ";
	cin>>num;
	switch(num)
	{
		
		case 1:{
			a.order();
			system("pause");
			system("cls");
			break;
			menu();
			
			}
		case 2: 
		{
			a.bill();
			system("pause");
			system("cls");
		break;
	}
	case 3: 
		{
			a.find();
				system("pause");
			system("cls");
		break;		
		}
		
		case 4:
			{
				a.dataupdate();
				system("Pause");
				break;
			}
		case 5:
			{
				a.dispose();
				system("Pause");
				break;
			}
	case 6:{
		a.showdata();
		break;
	}
	case 7:{
		return 0;
		break;
	}
		default :
		cout<<"Invalid input ";
	}
}
	getch();
	return 0;
}
void pharm::input_dataupdate(){
	
	cout<<"\nCustomer Name : ";
	cin.ignore();
	getline(cin,a.name);
	
	cout<< "Cell Number : ";
	cin>>(cin,a.cell_no);
		
	cout<< "Order Number : ";
	cin>>a.order_no;
	
	int i=0;
	while (i<1){
		cout<<" \nDrug ID : ";
		cin>>a.drug_ID[i];
			if (a.drug_ID [i]== 01){
			cout<<"\t\t\"Mytika\"\n";
		cout<<"\nQuantity of Medicine : ";
	 
		cin>>a.qty_drug[i];
		a.tot [i]= a.qty_drug[i]*50;
		cout<<"\nPrice : "<<a.tot[i]<<endl;
		}
		else if (a.drug_ID[i]==02){
			cout<<"\t\t\"Ventoline\"\n";
			cout<<"\nQuantity of Medicine : ";
		cin>>a.qty_drug[i];
		a.tot[i] = a.qty_drug[i]*1000;
		cout<<"\nPrice : "<<a.tot[i]<<endl;
		}
		else if (a.drug_ID[i]==03){
			cout<<"\n\t\t\"Quibrine Tsr\"";
			cout<<"\nQuantity of Medicine : ";
		cin>>a.qty_drug[i];
		a.tot [i]= a.qty_drug[i]*200;
		cout<<"\nPrice : "<<a.tot[i]<<endl;
		}
		else if(a.drug_ID[i]==04){
			cout<<"\t\t\"Betnisole\"";
			cout<<"\nQuantity of Medicine : ";
		cin>>a.qty_drug[i];
		a.tot [i]= a.qty_drug[i]*25;
		cout<<"\nPrice : \n"<<a.tot[i]<<endl;
		}
		else if(a.drug_ID[i]==05){
			cout<<"\t\t\"Discole\"";
			cout<<"\nQuantity of Medicine : ";
		cin>>a.qty_drug[i];
		a.tot [i]= a.qty_drug[i]*40;
		cout<<"\nPrice : "<<a.tot[i]<<endl;
		}
		else
		 cout<<" Error! Invalid ID ";
	
		sum+=a.tot[i];
		i++;
	}
		
}
void pharm::dataupdate(){
	fstream file;
	file.open("Database.txt",ios::binary|ios::in|ios::out);//coustomer
	string x,b,c,d,e,f,g;
	string z;
	int f1 =0,pos;
	cout<<"Enter first name : ";
	cin.ignore();
	getline(cin,z);
	
	while (!file.eof()){
		file>>x>>b>>c>>d>>e>>f>>g;
		if(z==x|| z==b|| z==c|| z==d|| z==e)
		{
			f1=1;
			
	cout<<"\  --------------------HAT PHARMACY-------------------\n";
	cout<<"Customer Name : "<<x<<endl;
	cout<<"Cell Number : "<<b<<endl;
	cout<<"\  ___________________________________________________\n";
	cout<<"\n\t\tBill summary\n\n";
	cout<<"  Drug ID\t Medicine name\t    Qty\t Price\t Total\n";
	cout<<"  "<<c<<"\t\t "<<d<<"\t     "<<setw(0)<<e<<setw(3)<<"\t "<<f<<"\t "<<g<<endl;
		
	cout<<"\n\n-------------------------------------------\n";
	fstream med_file;
	med_file.open("med.txt",ios::in); //Medicine data file open and only read this file 
	char b[2000];
	med_file.getline(b,2000,'\0');
	cout<<b;
	med_file.close();	//Medicine database file is closed after reading 
	cout<<"\n-------------------------------------------"<<endl;

	
	pos=file.tellg();
		file.seekg(-33,ios::cur);
		//file.seekp(pos-sizeof(a));
	cout<<"Customer name : ";cin.ignore(); getline(cin,a.name);
	x=a.name;
	file<<" "<<x<<'\t';
	cout<<"Cell no. : "; cin>>a.cell_no;
	//b=a.cell_no;
	file<<a.cell_no<<'\t';
	int i=0;
		while (i<1){
		cout<<" \nDrug ID : ";
		cin.ignore();
		cin>>a.drug_ID[i];
		file<<a.drug_ID[i]<<'\t';
		
		
			if (a.drug_ID [i]== 01){
			cout<<"\t\t\"Mytika\"\n";
		cout<<"\nQuantity of Medicine : ";
	 
		cin>>a.qty_drug[i];
		a.tot [i]= a.qty_drug[i]*50;
		cout<<"\nPrice : "<<a.tot[i]<<endl;
		file<<"Mytika"<<"\t"<<a.qty_drug[i]<<'\t'<<"50"<<'\t'<<a.tot[i];
		}
		else if (a.drug_ID[i]==02){
			cout<<"\t\t\"Ventoline\"\n";
			cout<<"\nQuantity of Medicine : ";
		cin>>a.qty_drug[i];
		a.tot[i] = a.qty_drug[i]*1000;
		cout<<"\nPrice : "<<a.tot[i]<<endl;
		file<<"Ventoline"<<"\t"<<a.qty_drug[i]<<'\t'<<"1000"<<'\t'<<a.tot[i];

		}
		else if (a.drug_ID[i]==03){
			cout<<"\n\t\t\"Quibrine Tsr\"";
			cout<<"\nQuantity of Medicine : ";
		cin>>a.qty_drug[i];
		a.tot [i]= a.qty_drug[i]*200;
		cout<<"\nPrice : "<<a.tot[i]<<endl;
		file<<"Quibrine Tsr"<<"\t"<<a.qty_drug[i]<<'\t'<<"200"<<'\t'<<a.tot[i];

		}
		else if(a.drug_ID[i]==04){
			cout<<"\t\t\"Betnisole\"";
			cout<<"\nQuantity of Medicine : ";
		cin>>a.qty_drug[i];
		a.tot [i]= a.qty_drug[i]*25;
		cout<<"\nPrice : \n"<<a.tot[i]<<endl;
		file<<"Betnisole"<<"\t"<<a.qty_drug[i]<<'\t'<<"25"<<'\t'<<a.tot[i];

		}
		else if(a.drug_ID[i]==05){
			cout<<"\t\t\"Discole\"";
			cout<<"\nQuantity of Medicine : ";
		cin>>a.qty_drug[i];
		a.tot [i]= a.qty_drug[i]*40;
		cout<<"\nPrice : "<<a.tot[i]<<endl;
		file<<"Discole"<<"\t"<<a.qty_drug[i]<<'\t'<<"40"<<'\t'<<a.tot[i];

		}
		else
		 cout<<" Error! Invalid ID ";
	
		sum+=a.tot[i];
		i++;
	}
	
			 break;
	}
	if (f1==0){
		cout<<"Record not found "<<endl;
	}
}
}
void pharm::dispose(){
	
	ifstream file;
	file.open("Database.txt",ios::in);
	ofstream fout;
	if (!file){
		cout<<"file not open";
	}
	string x,b,c,d,e,f,g;
	string z;
	int f1 =0,pos;
	cout<<"Enter first name : ";
	cin.ignore();
	getline(cin,z);
	
	while (!file.eof()){
		file>>x>>b>>c>>d>>e>>f>>g;
		if(z==x|| z==b|| z==c|| z==d|| z==e)
		{
			f1=1;
	fout.open("del.txt",ios::app);
			cout<<"Record found.........\n";
		fout.write((char *)&a, sizeof(pharm));
	
	break;

		}
	}
	if (f1==0){
		cout<<"Record not found..."<<endl;
	}
	
	file.close();
	fout.close();
	remove("Database.txt");
	rename("del.txt","Database.txt");
	cout<<"Record deleted......"<<endl;
	//break;
}

