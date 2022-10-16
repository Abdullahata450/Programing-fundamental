
#include<iostream>
#include<fstream>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>
using namespace std;

//---------------------------------------user define function----------------------------------
void viewinfo();
void bookticket();
void cancelticket();
void admin();
void password();
void viewpassenger();
void addtrain();
void dlttrain();
void awrite();
void aread();
void bookticket_write();
void viewpassengers_read();
//-----------------------------------------user define function close-----------------------------------
//-----------------------------------------structure start----------------------------------------------
struct adddata
{

	char si[20];
	char train_number[20];
	char train_name[20];
	char start[20];
	char destination[20];
	char price[20];
	int seat;
	char time[20];
} ;
 adddata add[1000];

struct book_ticket
{
	char train_number[20];
	char name[20];
	char phone[20];
	char date[20];
	int seat;
} ;
book_ticket book[1000];

//---------------------------------------structure close----------------------------------------------
//---------------------------------------global variable----------------------------------------------
int k=0,u=0;
char trn_nmbr[100],name[100],phn[100];
//---------------------------------------main function start------------------------------------------
int main()
{

	aread();
	viewpassengers_read();

	system("COLOR 60");
	int ch;
		cout<<"\t\t\t*******RAILWAY RESERVATION User Menu*******\n";
	
		cout<<"\n\t\t\t<<<<<<<<<<WELCOME USERS>>>>>>>>>>\n";
		cout<<"\n\n\t\t\t\t      MENU\n";
		cout<<"\t\t\t             ******";
		cout<<"\n\t\t\t Press 1: VIEW INFORMATION\n";
		cout<<"\n\t\t\t Press 2: BOOK TICKET\n";
		cout<<"\n\t\t\t Press 3: CANCEL TICKET\n";
		cout<<"\n\t\t\t Press 4: ADMIN";
		cout<<"\n\n\t\t\t Press 5: EXIT\n";
		cout<<"\n\t\t\t********************************";
		cout<<"\n\t\t\tENTER YOUR CHOICE: ";

	cin>>ch;
	switch(ch)
	{
		case 1:
		viewinfo();
		break;
		
		case 2:
		bookticket();
		break;
		
		case 3:
		cancelticket();
		break;
		
		case 4:
		password();
		break;
		
		case 5:
		system("cls");
		cout<<"\n\t\t\t =========================================\n";
		cout<<"\t\t\t *******RAILWAY RESERVATION SYSTEM*******\n";
	    cout<<"\t\t\t =================Exitied====================\n";
		exit(0);
		break;
		
		default:
    	system("cls");
    	cout<<"\n\n\t\t\t<<<<<<<<YOU ENTERED WRONG CHOICE>>>>>>>>\n";
	    cout<<"\t\t\t<<<<<<<<PLEASE ENTER RIGHT THING>>>>>>>>\n";
		getch();
		system("cls");
		main();
		break;
	}

}
//---------------------------------------main function close--------------------------------------------------
//---------------------------------------book ticket function-----------------------------------------------
 void bookticket()
{

	int c,j,n,i,a=-1;
	char v,train_number[10];
	system ("cls");
	aread();
		cout<<"\n\n\t\t\t============================================";
		cout<<"\n\t\t\t**********RAILWAY RESERVATION SYSTEM**********\n";
		cout<<"\t\t\t==================================================";
		cout<<"\n\n\t\t\thow many ticket do you want to buy: ";
	cin>>n;
	for(j=u;j<u+n;j++)
	{
		cout<<"\n\n\t\t\tEnter train number: ";
	cin>>book[j].train_number;
	for(i=0;i<k;i++)
	{
	if(strcmp(book[j].train_number,add[i].train_number)==0)
	{
	if(add[i].seat==0)
	{
			cout<<"\n\n\t\t\tnot available seat";
		
		getch();
		system("cls");
		main();
	}
	else
	{
	    a=1;
			cout<<"\n\t\ Booked Number of ticket are: "<<j+1;
			cout<<"\n\t\t\t Enter date: ";
		cin>>book[j].date;

			cout<<"\n\t\t\tenter your name: ";
		cin>>book[j].name;
		
			cout<<"\n\t\t\tenter your phone number: ";
		cin>>book[j].phone;
		
			cout<<"\n\t\t\tseat number :"<<add[i].seat ;
		book[j].seat=add[i].seat;
		bookticket_write();
		add[i].seat--;
		awrite();
	
		}
	}
}
	if(a==-1)
	{
			cout<<"\n\n\t\t\ttrain not found!!!";
		getch();
		system("cls");
		main();
	}

	}
		u=j;
		bookticket_write();
			cout<<"\n\n\t\t\tenter '1' for main menu & press any key to exit: ";
		cin>>(c);
			if(c==1)
			{
				system("cls");
				main();
			}
			if(c!=1)
			{
				exit;
			}			
}
//---------------------------------------cancel ticket function---------------------------------------------
void cancelticket()
{
	viewpassengers_read();
    char pnnmbr[50];
    int location =-1,e;
    	cout<< "\n\n\t\t\tenter phone number: ";
    cin>> pnnmbr;
    for (e=0;e<u;e++)
    {

        for (e=location;e<u;e++)
        {
           
            strcpy(book[e].phone,book[e+1].phone);
            bookticket_write();
        }
        u--;
        bookticket_write();
        	cout<<("\n\n\t\t\t<<<<<<<<<<<<<<<ticket cancelled successfully>>>>>>>>>>>>");
        	
        main();
    }
    system("cls");
}
//-------------------------------------admin portal function----------------------------------------
void admin()
{
	int chhh;
	system("cls");
	system("COLOR 06");
		cout<<("\n *************************** You Are Enterd To an Admin Mode ********************************");
		cout<<("\n\n           <<<<<<<<<<<<<<<WELCOME_ADMIN>>>>>>>>>>>>>>>\n\n");
		cout<<("\n                                     \n");
		cout<<("\n        Press 1: VIEW PASSENGERS        \n");
		cout<<("\n        Press 2: ADD TRAIN              \n");
		cout<<("\n        Press 3: DELETE TRAIN           \n");
		cout<<("\n        Press 4:  To Go BACK           \n");
		cout<<("\n                                       \n");
	
		cout<<("\n ************************************\n\n");
		
		cout<<("\n\tENTER YOUR CHOICE: ");
	cin>>(chhh);

	switch(chhh)
	{
		case 1:
		viewpassenger();
		break;
			
			case 2:
			addtrain();
			break;
				
				case 3:
			    dlttrain();
				break;
					
					case 4:
					system("cls");
					main();
					break;
					
					default:
					getch();
					cout<<"\n\t\t\tYou entered wrong KEY!!!!";
					system("cls");
					main();
	}
	getch();
}
//-----------------------------password function----------------------------------
void password()
{
	int number=12345;
	int pass;
		cout<<("\n\t\t\tEnter password: ");
	cin>>(pass);
	if(pass==number)
	{
			cout<<("\n\n\t\t\t<<<<<login successfully>>>>>");
			system("cls");
		{
		cout<<"\n\n\n\n\n";
			 cout<<"\t\t\t Loading";
		 char x=219;
		 for(int a=0;a<30;a++){
			 cout<<x;
		 	 Sleep(100);
	}
		system("cls");
		admin();
	}
}
	{
			cout<<("\n\n\t\t\t\t   ERROR!!!!!");
			cout<<("\n\n\t\t\t<<<<<<<<wrong password>>>>>>>>");
		getch();
		system("cls");
		main();
	}
}
//------------------------------------delete train function----------------------------------------------
void dlttrain()
{
	aread();
    char train[100];
    int location = -1,f;
    	cout<< "\n\n\t Enter train number: ";
    cin>>train;
    for (f=0;f<k;f++)
    {
        if (strcmp(train,add[f].train_number)==0)
        {
            location=f;
            break;
        }
    }
    if (location==-1)
    {
        	cout<< "\n\n\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n";
        getch();
        system("cls");
        admin();
    }
    else
    {
        for (f=location;f<k;f++)
            strcpy(add[f].si,add[f+1].si);
            strcpy(add[f].train_number,add[f+1].train_number);
            strcpy(add[f].train_name,add[f+1].train_name);
            strcpy(add[f].start,add[f+1].start);
            strcpy(add[f].destination,add[f+1].destination);
            strcpy(add[f].price,add[f+1].price);

            strcpy(add[f].time,add[f+1].time);
            awrite();
        }
        k--;
        awrite();
			cout<<"\n\n\t<<<<<<<<<<<<<train deleted successfully>>>>>>>>>>>>>";
		getch();
		system("cls");
		admin();
    }

//--------------------------------------view passengers function----------------------------------------
void viewpassenger()
{
	int a,j;
	system("cls");
	viewpassengers_read();
		cout<<"\n\t\t\t       **********************************************************";
		cout<<"\n\t\t\t       ********************RAILWAY RESERVATION SYSTEM********************";
		cout<<"\n\t\t\t       **********************************************************";
		cout<<"\n\n\t\t\t Train number\t\t Name\t\t  Phone number\t\t\t Date\t\t \tSeatNO.\n";
		cout<<"\n\t\t\t************************************************************************************************************\n";
	for(j=0;j<u;j++)
	{
		cout<<"\n\n\t\t"<<"\t\t"<<book[j].train_number<<"\t\t"<<book[j].name<<"\t\t";
		cout<<book[j].phone<<"\t\t"<<book[j].date<<"\t\t"<<book[j].seat;
		book[j].seat++;
	}
		cout<<"\n\t\t\t************************************************************************************************************\n";
		cout<<"\n\n\t\t\t Enter '1' for main menu & enter '0' for back: ";
	cin>>a;
	if(a==1)
	{
		system("cls");
		main();
	}
	if(a==0)
	{
		system("cls");
		admin();
	}
}
//--------------------------------------add train function--------------------------------------------
void addtrain()
{
	system("cls");
	int ch;
	aread();
	int i,a;
		cout<<"\n\t\t     **********************************************************";
		cout<<"\n\t\t     ********************RAILWAY RESERVATION SYSTEM********************";
		cout<<"\n\t\t     **********************************************************";
		cout<<"\n\n\t\t\t How many trains do you want to add: ";
	cin>>a;
	for(i=k;i<k+a;i++)
	{
			cout<<"\n\t\t\t Entering  train No.: "<<i+1;
			cout<<"\n\t\t\t Enter serial number: ";
		cin>>add[i].si;
		
			cout<<"\n\t\t\t Enter train number: ";
		cin>>add[i].train_number;
		
			cout<<"\n\t\t\t Enter train name: ";
		cin>>add[i].train_name;
		
			cout<<"\n\t\t\t Enter start place: ";
		cin>>add[i].start;
		
			cout<<"\n\t\t\t Enter destination place: ";
		cin>>add[i].destination;
		
			cout<<"\n\t\t\t Enter price: ";
		cin>>add[i].price;
		
			cout<<"\n\t\t\t Enter seat: ";
		cin>> add[i].seat;
		
			cout<<"\n\t\t\t Enter time: ";
		cin>>add[i].time;
	}

			cout<<"\n\n\t\t\t To Confirm train: (Yes='1'/No='0'):- ";
		cin>>(ch);
		if(ch==1)
		{
			awrite();
			k=i;
			awrite();
			system("cls");
				cout<<"\n\t\t\t\t   **********************************";
				cout<<"\n\t\t\t\t   *<<<<Train added successfully>>>>*";
				cout<<"\n\t\t\t\t   **********************************";
			getch();
			system("cls");
			main();
		}
			if(ch==0)
			{
				system("cls");
				admin();
			}
			if((ch!=1)&&(ch!=0))
			{
				system("cls");
				main();
			}
}
//-----------------------------------view information function--------------------------------------
void viewinfo()
{
		cout<<"\n\t\t\tPlease Wait";
	Sleep(3000);
	system("COLOR 0F");

	int ch,i;
	system("cls");
	aread();
		cout<<"\n\t\t     **********************************************************";
		cout<<"\n\t\t     ********************RAILWAY RESERVATION SYSTEM********************";
		cout<<"\n\t\t     **********************************************************";
		//cout<<"\n\n\nSI\t Train number\t Train name\t Start place\t Destination place\t Price\tTotal Seats \t Time\n\n";
	for (i=0;i<k;i++)
	{
      cout<<"\n\tSerial No."<<add[i].si;
      cout<<"\n\tTrain Number\t:"<<add[i].train_number<<endl;
      cout<<"\tTrain Name\t:"<<add[i].train_name<<endl;
      cout<<"\tStart Place\t:"<<add[i].start<<endl;
      cout<<"\tDestination\t:"<<add[i].destination<<endl;
      cout<<"\tPrice\t\t:"<<add[i].price<<endl;
      cout<<"\tTotalSeats\t:"<<add[i].seat<<endl;
      cout<<"\tTime\t\t:"<<add[i].time<<endl;
           
	  	}
		cout<<"  \n  ***********************************************************************************************\n";
		cout<<"\n\t\t\t Press '1' for main menu & press any key for exit:  ";
	cin>>(ch);
	switch(ch)
	{	
		case 1:
			system("cls");
			main();
			break;
				default:
					exit(0);
	}
}
//------------------------------------------book ticket file start-----------------------------------------
void bookticket_write()
{
	FILE *booklist;
	booklist=fopen("booklist.txt","w");
	fwrite(&book,sizeof(book),1,booklist);
	fclose(booklist);

	FILE *booklistreport;
	booklistreport=fopen("booklistreport.txt","w");
	fwrite(&u,sizeof(u),1,booklistreport);
	fclose(booklistreport);
}
void viewpassengers_read()
{
	FILE *booklist;
	booklist=fopen("booklist.txt","r");
	fread(&book,sizeof(book),1,booklist);
	fclose(booklist);

	FILE *booklistreport;
	booklistreport=fopen("booklistreport.txt","r");
	fread(&u,sizeof(u),1,booklistreport);
	fclose(booklistreport);
}
//-----------------------------------------add train file start---------------------------------------------------
void awrite()
{
	FILE *train_details;
	train_details = fopen("train_details.txt","w");
	fwrite(&add,sizeof(add),1,train_details);
	fclose(train_details);

	FILE *train_report;
	train_report = fopen("train_report.txt","w");
	fwrite(&k,sizeof(k),1,train_report);
	fclose(train_report);
}
void aread()
{
	FILE *train_details;
	train_details = fopen("train_details.txt","r");
	fread(&add,sizeof(add),1,train_details);
	fclose(train_details);

	FILE *train_report;
	train_report = fopen("train_report.txt","r");
	fread(&k,sizeof(k),1,train_report);
	fclose(train_report);
}
//----------------------------------------------------file close----------------------------------------------
//----------------------------------------------------program close----------------------------------------


