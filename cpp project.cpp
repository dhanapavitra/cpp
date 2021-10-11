//Header file declaration
#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

//Creating the class as Bank
class Bank
{

	private: 

	    int total;
	    string acc_no;

        //Creating the structure for person
	    struct person
		{
	    	string name,account_no,account_type,address;
	    	int contact,cash;
		}
		
		person[100];

	public:

		Bank()
		{
			total=0;
		}

		void choice();
		void personal_Data();
		void show();
		void update();
		void search();
		void transactions();
		void del();

};

//The starting of main program
int main()
{
	
	cout<<"**WELCOME TO THE BANKING SYSTEM**"<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<"-----------------------------------"<<endl;

	Bank b;
	b.choice();
	
	return 0;

}

//For selecting the choice of the person
void Bank::choice(){

	char ch;
    
    //infinity loop
	while(1)
	{

	   cout<<"\n\nPRESS.."<<endl;
	   cout<<"1. Create new account"<<endl;
	   cout<<"2. View customers list"<<endl;
   	   cout<<"3. Update information of existing account"<<endl;
	   cout<<"4. Check the details of an existing account"<<endl;
	   cout<<"5. For transactions"<<endl;
	   cout<<"6. Deleting an account"<<endl;
	   cout<<"7. Exit"<<endl;

	   ch=getch();

	   system("CLS");

	   //Use of switch case conditions after selecting the choice
	  switch(ch)
	  {

		case '1':
			Bank::personal_Data();
			break;

		case '2':
			if(total==0)
			{
				cout<<"No data is entered"<<endl;
			}
			else
			{
			    Bank::show();
		    }
			break;

		case '3':
			if(total==0)
			    cout<<"No data is entered"<<endl;
			else
			    Bank::update();
			break;

		case '4':
			if(total==0)
			    cout<<"No data is entered"<<endl;
			else
			    Bank::search();
			break;

		case '5':
			if(total==0)
			    cout<<"No data is entered"<<endl;
			else
		     	Bank::transactions();
			break;

		case '6':
			if(total==0)
		    	cout<<"No data is entered"<<endl;
			else
		    	Bank::del();
			break;

		case '7':			
			cout<<"THANK YOU"<<endl;
			exit(0);
			break;

		default:
			cout<<"Invalid input"<<endl;
			break;
  	  }
    }
}

//For displaying the information of the person
void Bank::personal_Data()
{
	cout<<"Enter data of person "<<total+1<<endl;
	cout<<"-------------------------"<<endl;

	cout<<"Enter name: ";
	cin>>person[total].name;

	cout<<"Account no: ";
	cin>>person[total].account_no;
	
	cout<<"Account type: ";
	cin>>person[total].account_type;

	cout<<"Address: ";
	cin>>person[total].address;

	cout<<"Contact: ";
	cin>>person[total].contact;

	cout<<"Total Cash: ";
	cin>>person[total].cash;

	total++;
}

//For Displaying the total data of account holders in the record
void Bank::show(){

	for(int i=0;i<total;i++){

		cout<<"Data of person "<<i+1<<endl;
		cout<<"Name: "<<person[i].name<<endl;
		cout<<"Account no: "<<person[i].account_no<<endl;
		cout<<"Account type: "<<person[i].account_type<<endl;
		cout<<"Address: "<<person[i].address<<endl;
		cout<<"Contact: "<<person[i].contact<<endl;
		cout<<"Cash: "<<person[i].cash<<endl;

	}

}

//For update the details
void Bank::update(){
	cout<<"Enter account number of person whose data you want to update"<<endl;
	cin>>acc_no;
	for(int i=0;i<total;i++)
	{
		if(acc_no==person[i].account_no)
		{
		  cout<<"Previous data"<<endl;
		  cout<<"Data of person "<<i+1<<endl;
		  cout<<"Name: "<<person[i].name<<endl;
		  cout<<"Account no: "<<person[i].account_no<<endl;
		  cout<<"Account type: "<<person[i].account_type<<endl;
		  cout<<"Address: "<<person[i].address<<endl;
		  cout<<"Contact: "<<person[i].contact<<endl;
		  cout<<"Cash: "<<person[i].cash<<endl;		 
		  cout<<"\nEnter new data"<<endl;
		  cout<<"---------------------"<<endl;
		  cout<<"Enter name: ";
	      cin>>person[i].name;
	      cout<<"Account no: ";
	      cin>>person[i].account_no;
	      cout<<"Account type: ";
	      cin>>person[i].account_type;
	      cout<<"Address: ";
	      cin>>person[i].address;
	      cout<<"Contact: ";
	      cin>>person[i].contact;
	      cout<<"Total Cash: ";
          cin>>person[i].cash;
	      break;
        }
		if(i==total-1)
		{
			cout<<"No such record found"<<endl;
		}
	}
}

//For searching the data of the person
void Bank::search()
{
   cout<<"Enter account no of the person whose data you want to search"<<endl;
   cin>>acc_no;
   for(int i=0;i<total;i++)
   {
	 if(acc_no==person[i].account_no)
	 {
		cout<<"Name: "<<person[i].name<<endl;
		cout<<"Account no: "<<person[i].account_no<<endl;
		cout<<"Account type: "<<person[i].account_type<<endl;
		cout<<"Address: "<<person[i].address<<endl;
		cout<<"Contact: "<<person[i].contact<<endl;
		cout<<"Cash: "<<person[i].cash<<endl;
		break;
	 }
	 if(i==total-1)
	 {
		cout<<"No such record found"<<endl;
	 }
    }
}

//For making the transaction
void Bank::transactions()
{
	int cash;
	char ch;
	cout<<"Enter the account number for transactions"<<endl;
     cin>>acc_no;
     for(int i=0;i<total;i++)
	 {
     	if(acc_no==person[i].account_no)
		    {
     		 cout<<"Name: "<<person[i].name<<endl;
     	     cout<<"Address: "<<person[i].address<<endl;
     	     cout<<"Account type: "<<person[i].account_type<<endl;
		     cout<<"Contact: "<<person[i].contact<<endl;
		     cout<<"\nExisting Cash "<<person[i].cash<<endl;
		     cout<<"Press 1 to deposit"<<endl;
		     cout<<"Press 2 to withdraw"<<endl;
		     ch=getch();
		     switch(ch)
		     {

		     	case '1':
		     		cout<<"enter amount you want to deposit??"<<endl;
		     		cin>>cash;
		     		person[i].cash+=cash;
		     		cout<<"Your new cash is "<<person[i].cash<<endl;
		     		break;

		     	case '2':
		     		back:
		     		cout<<"enter amount you want to withdraw??"<<endl;
		     		cin>>cash;
		     		if(cash>person[i].cash){
		     			cout<<"Your existing cash is  "<<person[i].cash<<endl;
		     			Sleep(3000);
		     			goto back;
					 }
					 person[i].cash-=cash;
					 cout<<"Your existing cash is "<<person[i].cash<<endl;
					 break;

				default:
					cout<<"Invalid input"<<endl;
					break;
			 }
			 break;
		 }
		 if(i==total-1)
		 {
		 	cout<<"No such record found"<<endl;
		 }
	 }
}

//For deleting the account
void Bank::del()
{
	char ch;
	cout<<"Press 1 to remove specific record"<<endl;
	cout<<"Press 2 to remove full record"<<endl;
	ch=getch();
	switch(ch)
	{
		case '1':
	      cout<<"Enter the account no of the person whose data you want to remove"<<endl;
          cin>>acc_no;
          for(int i=0;i<total;i++)
	      {
     	     if(acc_no==person[i].account_no)
		     {
     		    for(int j=i;j<total;j++)
				 {
     		        person[j].name=person[j+1].name;
     		        person[j].account_no=person[j+1].account_no;
     		        person[j].account_type=person[j+1].account_type;
     		        person[j].address=person[j+1].address;
     		        person[j].contact=person[j+1].contact;
     		        person[j].cash=person[j+1].cash;

     		        total--;
     		        cout<<"Your required data is deleted"<<endl;
     		        break;
			     }
		     }
		     if(i=total-1)
			 {
		         cout<<"No such record found"<<endl;
		     }
	      }
	      break;

	    case '2':
	 	   total=0;
	 	   cout<<"All record is deleted"<<endl;
	 	   break;

	    default:
		   cout<<"Invalid Input"<<endl;
		   break;
	}
}