//copyright : Imran Irshad
#include<iostream>
#include <ctime>
#include<time.h>
#include<Windows.h>
#include <fstream>
#include<string>
using namespace std;
ofstream file;
time_t now = time(0);   //for time storing
class Counter{
		bool Empty;
		int count;
		public:
		int getcount()
		{ return count;}
		void setcounter()
		{
			count = 0;
		}
		void proceed()
		{
			Empty=false;
			count++;
		}
		void makeEmpty()
		{
			Empty=true;	
		}
		bool isEmpty()
		{ return Empty;}
		
	void display(){
		cout<<"\t\t\t\t=============================="<<endl;
		cout<<"\t\t\t\t|        Counter = "<<count<<"         |"<<endl;
		cout<<"\t\t\t\t=============================="<<endl;
		cout<<endl;
	}
};
class Node{
	public:
		int token;
		string timeStamps;
		Node*next;
		Node(){
			next=NULL;
		}
		
};

class List{
	public:
		Node *rear;
		Node *front;
		int numItems;
		int maxCapacity;
		List(){
			maxCapacity=10;
			numItems=0;
			front=rear=NULL;
		}
		void Enque(int n){
			
			time_t now = time(0);
			 tm *ltm = localtime(&now);
			Node*newNode=new Node();
			numItems++;
			if(numItems>maxCapacity)
			{
				cout<<"No seat is vecant!!\n";
				cout<<"Please wait a while!!!!\n";
				return;
			}
			file.open("file.txt",ios::app);
			file<<" Token no : "<<n;
		    newNode->token=n;
			char* dt = ctime(&now);
   			string str = dt;
			file<<" , TimeStamps : "<<str<<"\n";
			file.close();
			newNode->timeStamps= str;
			if(front==NULL)
			{
			front=rear=newNode;
			}
			else{
				rear->next=newNode;
				rear=newNode;
			}
		}
		bool isFull()
		{
			return (numItems==maxCapacity);
		}
		bool Deque(int &num){
			
			Node *temp;
			if(isEmpty()){
			cout<<"The list is empty\n";
		    return false;
		   }
			else{
				num = front->token;
				temp=front->next;
				delete front;
				front=temp;
				numItems--;
				return true;
			}
		}
	
		
//	int count(Node *l1){
//		 if(l1->next)
//		   return 1+count(l1->next);
//		   return 1;
//}
	bool isEmpty()
		{	
		 if (numItems)
		 	return false;
		else
			return true;
			}
	void print(Node *n){
			if(n->token == front->token)
			{
				cout<<"\n\t\t======================================================"<<endl;
				cout<<"\t\t                   Waiting Place Items"<<endl;
				cout<<"\t\t======================================================"<<endl;
				cout<<"\t\t Token # |              Creation Time"<<endl;
				cout<<"\t\t------------------------------------------------------"<<endl;
			}
			if(n){
			
			cout<<"\t\t    "<<n->token<<"    |  ";
			cout<<"  Created at : "<<n->timeStamps;
			cout<<endl;
			if(n->next)
				cout<<"\t\t------------------------------------------------------"<<endl;
		}
		
			if(n->next)
			print(n->next);
			else
				cout<<"\t\t======================================================\n\n"<<endl;
		}
};
//Utility Functions
enum color{ //enumeration is a user-defined data type
	NONE,
	DARK_BLUE,
	GREEN,
	DARK_CYAN,
	DARK_RED,
	PURPLE,
	DARK_YELLOW,
	NORMAL,
	GRAY,
	BLUE,
	LIME,
	CYAN,
	RED,
	PINK,
	YELLOW,
	WHITE
};
void setcolor   (color newColor) 
{
	//A "handle" is a generic identifier (typically a pointer) used to represent something.
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), (newColor ) );
}
void pause(int dur)
{
int temp = time(NULL) + dur;
	while(temp > time(NULL));
}
void splash()
{
	for(int i=0;i<=6;i++)
	{
		Beep(5000,150);
		system("cls");
		if(i==0)
		system("COLOR 1f");
		else if(i==1)
		system("COLOR 2f");
		else if(i==2)
		system("COLOR 3f");
		else if(i==3)
		system("COLOR 9f");
		else if(i==4)
		system("COLOR cf");
		else if(i==5)
		system("COLOR 6f");
		else
		system("COLOR 0f");
		cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t   __      __   ___  | |   ___    ___    _ __ ___     ___  "<<endl;
		cout<<"\t\t\t\t   \\ \\ /\\ / /  / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\ "<<endl;
		cout<<"\t\t\t\t    \\ V  V /  |  __/ | | | (__  | (_) | | | | | | | |  __/ "<<endl;
		cout<<"\t\t\t\t     \\_/\\_/    \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___| "<<endl;
		pause(1);
		
	}
	cout<<"\n";setcolor(DARK_YELLOW);
	cout<<"\t\t\t\t\tT O K E N  M A N A G E M E N T  S Y S T E M ";
	Beep(1000,25);setcolor(CYAN);
	cout<<"\n\t\t\t\t\tLOADING.";
	for(int i=0;i<6;i++)
	{
		pause(1);
		cout<<".";
		Beep(1000,25);
	}cout<<".";
}
void gotoXY(int x, int y) 	//function to decide location of the screem
{
	//A "handle" is a generic identifier (typically a pointer) used to represent something
	//Retrieves a handle to the specified standard device (standard input, standard output).
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 		 
	COORD CursorPosition; 
	CursorPosition.X = x; // Locates column
	CursorPosition.Y = y; // Locates Row
	//Sets the cursor position in the specified console screen buffer.
	//A COORD structure that specifies the new cursor position, in characters. The coordinates are 
	//the column and row of a screen buffer character cell. The coordinates must be within the 
	//boundaries of the console screen buffer.
	SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}
void Help()
{
	system("cls");
	Beep(1000,50);
	setcolor(RED);
	gotoXY(56,4);
		cout<<"Options Help"<<endl;
	setcolor(YELLOW);
	gotoXY(39,5);	
		cout<<"T O K E N  M A N A G E M E N T  S Y S T E M"<<endl;
	
		setcolor(BLUE);
		gotoXY(38,6);	
		cout<<"   ________________________________________"<<endl;
		gotoXY(38,7);
		cout<<" / \\                             	         \\."<<endl;
		Beep(5000,25);
		pause(1);
		gotoXY(38,8);
		setcolor(RED);
		cout<<"|   | Enter only Valid Opton--> (1,2,3...) |."<<endl;
		Beep(5000,25);
		gotoXY(38,9);
		setcolor(YELLOW);
		cout<<" \\_ | Issue a Token==>                     |."<<endl;
		gotoXY(38,10);
		setcolor(LIME);
		cout<<"    | A token will issue, on the status of |."<<endl;
		gotoXY(38,11);
		cout<<"    | wating list,if empty u can proced to |."<<endl;
		gotoXY(38,12);
		cout<<"    | counter!!                            |."<<endl;
		gotoXY(38,13);
		cout<<"    |                            	   	 |."<<endl;
		pause(1);
		Beep(5000,25);setcolor(YELLOW);
		gotoXY(38,14);
		cout<<"    | Waiting place ==>                    |."<<endl;
		gotoXY(38,15);setcolor(LIME);
		cout<<"    | This will show the visitors that are |."<<endl;
		gotoXY(38,16);
		cout<<"    | in waiting list.              	 |."<<endl;
		gotoXY(38,17);
		cout<<"    |                                      |."<<endl;
		pause(1);
		Beep(5000,25);
		gotoXY(38,18);setcolor(YELLOW);
		cout<<"    | Make Counter Free ==>                |."<<endl;
		gotoXY(38,19);setcolor(LIME);
		cout<<"    | This will make counter free, so the  |."<<endl;
		gotoXY(38,20);
		cout<<"    | visitor from the waiting list will   |."<<endl;
		gotoXY(38,21);
		cout<<"    | remove.                              |."<<endl;
		gotoXY(38,22);
		cout<<"    |                                      |."<<endl;
		pause(1);
		Beep(5000,25);setcolor(YELLOW);
		gotoXY(38,23);
		cout<<"    | History of Issued Tokens ==>         |."<<endl;
		gotoXY(38,24);setcolor(LIME);
		cout<<"    | In this all the history of issued    |."<<endl;
		gotoXY(38,25);
		cout<<"    | Token will show!!                    |."<<endl;
		gotoXY(38,26);
		cout<<"    |                                      |."<<endl;
		pause(1);
		Beep(5000,25);
		gotoXY(38,27);setcolor(YELLOW);
		cout<<"    | Turn off ==>                         |."<<endl;
		gotoXY(38,28);setcolor(LIME);
		cout<<"    | Exit the system!!!                   |."<<endl;
		gotoXY(38,29);setcolor(BLUE);
		cout<<"    |   ___________________________________|___"<<endl;
		Beep(5000,25);
		gotoXY(38,30);
		cout<<"    |  /                                      /."<<endl;
		gotoXY(38,31);
		cout<<"    \\_/______________________________________/."<<endl;
		pause(1);
	
}
void displayHistory(){
	fstream history;
string his;
history.open("file.txt",ios::in);
	getline(history,his);
	setcolor(LIME);
	cout<<"\t==================================================================="<<endl;setcolor(YELLOW);
	cout<<"\t\t  "<<his;
	cout<<endl;
	while(!history.eof())
	{
		getline(history,his);
		cout<<"\t\t"<<his;
		cout<<endl;
	}
	setcolor(LIME);
	cout<<"\t===================================================================\n\n"<<endl;setcolor(NORMAL);
	history.close();
}
int main(){
    file.open ("file.txt");
	List list;
	char* dt = ctime(&now);
	file<<" System turn ON at Time : "<<dt<<"\n";
	file.close();
	splash();
	cout<<endl;
	pause(1);
   int ch,temp;
    int token=0;
    Counter obj;
    obj.setcounter();
   do {
		pause(1);
		setcolor(WHITE);
		cout<<"System is about to clear the screen"<<endl;
		system("pause");
		system("cls");
		setcolor(CYAN);
		cout<<"\n\t\t\t\t=================================="<<endl;
		cout<<"\t\t\t\t|";setcolor(YELLOW);cout<<" S.no ";setcolor(CYAN);cout<<"|";setcolor(YELLOW);cout<<"        Functions       ";setcolor(CYAN);cout<<" |"<<endl;
		cout<<"\t\t\t\t----------------------------------"<<endl;setcolor(CYAN);
		cout<<"\t\t\t\t|";setcolor(WHITE);cout<<"   1  ";setcolor(CYAN);cout<<"|";setcolor(WHITE);cout<<"       Issue Token       ";setcolor(CYAN);cout<<"|"<<endl;
		cout<<"\t\t\t\t----------------------------------"<<endl;setcolor(CYAN);
		cout<<"\t\t\t\t|";setcolor(WHITE);cout<<"   2  ";setcolor(CYAN);cout<<"|";setcolor(WHITE);cout<<"   Waiting Place list    ";setcolor(CYAN);cout<<"|"<<endl;
		cout<<"\t\t\t\t----------------------------------"<<endl;setcolor(CYAN);
		cout<<"\t\t\t\t|";setcolor(WHITE);cout<<"   3  ";setcolor(CYAN);cout<<"|";setcolor(WHITE);cout<<"    Make counter free    ";setcolor(CYAN);cout<<"|"<<endl;
		cout<<"\t\t\t\t----------------------------------"<<endl;setcolor(CYAN);
		cout<<"\t\t\t\t|";setcolor(WHITE);cout<<"   4  ";setcolor(CYAN);cout<<"|";setcolor(WHITE);cout<<"    History of tokens    ";setcolor(CYAN);cout<<"|"<<endl;
		cout<<"\t\t\t\t----------------------------------"<<endl;setcolor(CYAN);
		cout<<"\t\t\t\t|";setcolor(WHITE);cout<<"   5  ";setcolor(CYAN);cout<<"|";setcolor(WHITE);cout<<"           Help          ";setcolor(CYAN);cout<<"|"<<endl;
		cout<<"\t\t\t\t----------------------------------"<<endl;setcolor(CYAN);
		cout<<"\t\t\t\t|";setcolor(WHITE);cout<<"   6  ";setcolor(CYAN);cout<<"|";setcolor(WHITE);cout<<"         Turn off        ";setcolor(CYAN);cout<<"|"<<endl;
		cout<<"\t\t\t\t----------------------------------"<<endl;setcolor(CYAN);
		cout<<"\t\t\t\t|";setcolor(YELLOW);cout<<"         Enter Serial No.       ";setcolor(CYAN);cout<<"|"<<endl;
		cout<<"\t\t\t\t=================================="<<endl;setcolor(CYAN);
		cout<<"\t\t\t\t\t\t";
		setcolor(CYAN);
      cin>>ch;
      setcolor(WHITE);
      fstream history;
		string his; 
      switch (ch) {
         case 1: 
		 	 if(obj.isEmpty()) {
				  token++;
			 	 cout<<"\t\tYour Token number is "<<token<<endl;
			 	 obj.proceed();
			 	 obj.display();
			 	 Beep(500,200);Beep(500,200);
			 	 setcolor(LIME);
			 	 cout<<"\n\t\tToken # "<<token<<", please come to counter for proceed!!!"<<endl<<endl;
			 	 setcolor(WHITE);
			 	 list.Enque(token);
			 	 list.Deque(temp);
			}
			 else
			 {
			 	
				obj.display();
			 	if(!list.isFull()){
			 		token++;
			 		setcolor(CYAN);
				cout<<"\n\t==============================================="<<endl;
				setcolor(YELLOW);
			 	cout<<"\t  Your Token # is "<<token<<" "<<endl;
			 	cout<<"\t  Counter is not free, plz wait your turn!!!"<<endl;
			 	setcolor(CYAN);
			 	cout<<"\t===============================================\n"<<endl;
			 	list.Enque(token);
				 }else{
				 	setcolor(LIME);
				 	cout<<"\n\t======================================="<<endl;setcolor(YELLOW);
				 	cout<<"\a\t    Sorry!, waiting place is full!!"<<endl;
				 	cout<<"\t    please come after a while!!!"<<endl;setcolor(LIME);
				 	cout<<"\t=======================================\n"<<endl;
				 }
			 	
			 }
         break;
         case 2:
		 	if(list.isEmpty())
		 	{
				setcolor(CYAN);
				cout<<"\a\n\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
				cout<<"\t!";setcolor(RED);cout<<"     No visitor in waiting list.   ";setcolor(CYAN);cout<<"!"<<endl;
				cout<<"\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
				cout<<endl;
				break;
			}
				list.print(list.front);
	        	
         break;
            int num;
         case 3: 
		 		cout<<endl;
		        Node *n;
		        num = obj.getcount();
		        if(!obj.isEmpty())
		        {
		        	time_t now = time(0);
					obj.makeEmpty();
					file.open("file.txt",ios::app);
		        	file<<" Token no : "<<num;
					char* dt = ctime(&now);
				file<<" , Leaving TimeStamps : "<<dt<<"\n";
				file.close();
				setcolor(CYAN);
					cout<<"\n\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;setcolor(LIME);
		        	cout<<"\n\t\tToken : "<<num<<" is done with his work"<<endl;setcolor(CYAN);
		        	cout<<"\n\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl<<endl;
				}else
				{
					setcolor(CYAN);
					cout<<"\n\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
					cout<<"\t!";setcolor(YELLOW);cout<<"      Counter is Already Free      ";setcolor(CYAN);cout<<"!"<<endl;
					cout<<"\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl<<endl;
					setcolor(NORMAL);
				}
			    
		        if(!list.isEmpty()) {
		        	n = list.front;
		        	int num=n->token;
				list.Deque(temp);
		        obj.proceed();
		        obj.display();
		        Beep(500,200);Beep(500,200);
		        setcolor(LIME);
		        cout<<"Token # "<<num<<" come to counter to proced!!"<<endl;;
				}
				
		    
         break;
         case 4:
		 		displayHistory(); 
         		
         break;
         case 5:
		        Help();
		        break;
         case 6: 
				setcolor(GREEN);
				cout<<"\t\t\t\t\tTHNAKS FOR USING OUR SOFTWARE"<<endl;
				pause(2);
				system("cls");
				setcolor(DARK_RED);
				cout<<"\t\tSYSTEM IS SHUTING DOWN";
			 	now = time(0);
	         	dt = ctime(&now);
	         	file.open("file.txt",ios::app);
				file<<" System turned OFF at time :"<<dt<<"\n";
				pause(1);
				setcolor(YELLOW);
				cout<<" ...";
				pause(1);
				cout<<"..."<<endl;
         break;  		
    default: 
		setcolor(DARK_RED);
		cout<<"Invalid choice"<<endl;
		setcolor(NORMAL);
      }
   } while(ch!=6);
   
}
