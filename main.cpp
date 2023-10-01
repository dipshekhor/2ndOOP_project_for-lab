#include<iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>
#include <iomanip>
#include<string>
using namespace std;
class user{
    protected:
    string name;
    string phone;
    vector<char> password;
    public:
    user(){}
    user(string n,string p){
        name=n;
        phone=p;
    }
    void getter1(vector<char>arr){
        password=arr;
    }
    virtual void file_read()=0;

};
class admin : virtual public user{
    protected:
    int adminpin=14453;
    string Nid;
   public:
   admin(string n,string p,string ni):user(n,p){
    Nid=ni;
   }
   admin(){};
    void login()
   {
   vector<char>pass;
   char ch;
   cout<<"\n\n\n\n\n\n\n\n\t\t\t\t       TruckLaagbe,EXPLORE THE CITY WITHOUT THE HEAVIERS!\n\n";
   cout<<"\t\t\t\t\t------------------------------";
   cout<<"\n\t\t\t\t\t\t     LOGIN \n";
   cout<<"\t\t\t\t\t------------------------------\n\n";
   cout << "\t\t\t\t\tEnter Password: ";
   int l=7;
   while(l--){//character 13 is enter
      //getline(cin,a);
       cin>>ch;;
      pass.push_back(ch);
      //cout << '*';
      //ch = _getch();
   }
   vector<char>pp={'p','a','s','s','s','s','s'};
   if(pass ==pp){
      cout << "\n\n\n\t\t\t\t\t\tAccess Granted! \n";
      system("PAUSE");
      system ("CLS");
   }
   else if(pass==password){
      cout << "\n\n\n\t\t\t\t\t\tAccess Granted! \n";
      system("PAUSE");
      system ("CLS");
   }
   else if(pass!=password || pass!=pp){
      cout << "\n\n\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\tPlease Try Again\n\n";
      system("PAUSE");
      system("CLS");
      login();
   }
}
void adminf(){
    cout<<"Enter your admin pin:---";
    int pin;
    cin>>pin;
    if(pin==adminpin){
     cout<<"\nRedirecting to editing page ,please wait............."<<endl;
      sleep(3);
      system ("CLS");
      ifstream out;
      out.open("admin.txt");
      while(out){
        string ss;
        getline(out,ss);
        cout<<ss<<endl;
      }
     out.close();
       int t;
      cout<<"\nDo you want to edit enything?type 1 for this:--";
      cin>>t;
      if(t==1){
        ofstream f("admin.txt",ios::app);
        string edits;
        cin>>edits;
        f<<edits;
      }
      else{
        cout<<"Thank u for staying with our family"<<endl;
      }

    }
    else {
        cout<<"\nIncorrect adminpin try again later"<<endl;
        adminf();
    }
}
void signup()
        {
            cout<<"Enter your name--";
            cin>>name;
            cout<<endl;
            cout<<"Enter your phone number--";
            cin>>phone;
            cout<<endl;
            string s2,s3;
            do{
                cout<<"enter your password for logging in anytime which will contain only 7 character with small and capital letter:-- ";
                cin>>s2;
                cout<<"\nenter your password again for correction:--";
                cin>>s3;
                cout<<endl;
            }
            while(s2!=s3);
            vector<char>array;

           for (int i = 0; i < s3.length(); i++) {
                array.push_back (s3[i]);
           }
            getter1(array);
            sleep(3);
            system ("CLS");
            login();
        }
   void file_read(){
    ifstream in;
    in.open("welcome.txt",ios :: in);
    string s1;
    while(in){
        getline(in,s1);
        cout<<s1<<endl;
    }
    in.close();
    cout<< "\n\n\t\t\t\t\t   PRESS FOR LOGIN     "<<endl;
    cout<<" \n\t\tPRESS N or n, IF U DON'T HAVE ANY ACCOUNT?\n\t\tPRESS A or a IF YOU ARE A ADMIN?";
    char ch;
    cin>>ch;

    if(ch=='n' || ch=='N'){
        cout<<"\nRedirecting to signup page ,please wait............."<<endl;
        sleep(3);
        system ("CLS");
        signup();

    }
   else if(ch=='a' || ch=='A'){
        cout<<"\nRedirecting to admin page ,please wait............."<<endl;
        sleep(3);
        system ("CLS");
        adminf();
        exit(1);


    }
    else{
        cout<<"\n Redirecting to login page ,please wait.............."<<endl;
        sleep(3);
        system ("CLS");
        login();

    }

}
};
class rent: virtual  public admin{
    protected:
    int km;
    string dest;
    public:
    bool isdhaka;
    rent(string n,string p,string ni,int k,string d,bool tt):user(n,p),admin(n,p,ni){
        km=k;
        dest=d;
        isdhaka=tt;
    }
    rent(){}
     int serial;
    friend ostream& operator <<(ostream &cout,rent d);
   int file_open(){
     ifstream inf;
        inf.open("admin.txt",ios:: in);
        string a;
        while(inf){
             getline(inf,a);
             cout<<a<<endl;
        }
        inf.close();
      
       // string line,input="";
       cout<<"--------------------------------------------------------------------------"<<endl;
       ifstream iff;
        do
        {
       cout<<"Type the number from the serial to add your vehicle in our list:--";
        cin>>serial;
        if(serial==1){
            cout<<"You have choosen Pickup"<<endl;
            cout<<"Redirecting to the pickup page....."<<endl;
            sleep(3);
            system("CLS");
            string line;
            iff.open("pickup.txt",ios::in);
            while(iff){
             getline(iff,line);
             cout<<line<<endl;
           }
           iff.close();
           break;
        }
        else if(serial==2) {
            cout<<"You have choosen medium trucks"<<endl;
            cout<<"Redirecting to the medium trucks page....."<<endl;
            sleep(3);
            system("CLS");
            string line;
            iff.open("medium.txt",ios::in);
            while(iff){
             getline(iff,line);
             cout<<line<<endl;
           }
           iff.close();
        break;

        }
        else if (serial==3)
        {
            cout<<"You have choosen large truck"<<endl;
            cout<<"Redirecting to the large truck page....."<<endl;
            sleep(3);
            system("CLS");
            string line;
            iff.open("large.txt",ios::in);
            while(iff){
             getline(iff,line);
             cout<<line<<endl;
           }
           iff.close();
           break;
        }
        else if(serial==4){
              cout<<"You have choosen trailer"<<endl;
            cout<<"Redirecting to the large trailer page....."<<endl;
            sleep(3);
            system("CLS");
            string line;
            iff.open("trailer.txt",ios::in);
            while(iff){
             getline(iff,line);
             cout<<line<<endl;
           }
           iff.close();
           break;
        }
        else if(serial !=1 && serial !=2 && serial !=3 && serial !=4){
        cout<<"Invalid operation"<<endl;
    }
}while(serial !=1 && serial !=2 && serial !=3 && serial !=4);
return serial;
}
int calculate(int k,int se){
    int  money;
  if(se==1){
    if(isdhaka==1){
        money=km*200;
    }
    else if(isdhaka!=1){
        money=km*150;
    }
  }
 else if(se==2){
    if(isdhaka==1){
        money=km*300;
    }
    else if(isdhaka!=1){
        money=km*220;
    }
  }
  else if(se==3){
    if(isdhaka==1){
        money=km*500;
    }
    else if(isdhaka!=1){
        money=km*350;
    }
  }
 else if(se==4){
    if(isdhaka==1){
        money=km*1000;
    }
    else if(isdhaka!=1){
        money=km*750;
    }
  }
    return money;
}
void showrent()
    {
        
    cout << "\n\t\t                       TRuck Rental - Customer Invoice                  "<<endl;
    cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\t\t	| Invoice No. :"<<"------------------|"<<setw(10)<<"#Cnb8"<<Nid<<endl;
    cout << "\t\t	| Customer Name:"<<"-----------------|"<<setw(10)<<name<<endl;
    cout << "\t\t	| Phone number :"<<"-----------------|"<<setw(10)<<phone<<endl;
    cout << "\t\t	| Destination :"<<"------------------|"<<setw(10)<<dest<<endl;
    cout << "\t\t	 ________________________________________________________"<<endl;
    cout <<"\n";
    cout << "\t\t	 ________________________________________________________"<<endl;
    cout << "\t\t	 # This is a computer generated money reciept and it does not"<<endl;
    cout << "\t\t	 require an authorised signture #"<<endl;
    cout <<" "<<endl;
    cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\t\t	You are advised to pay up the amount before due date."<<endl;
    cout << "\t\t	Otherwise penelty fee will be applied"<<endl;
    
    }
};
ostream& operator << (ostream& cout, rent d) {
    cout<<"Your given information is............."<<endl;
    cout<<"\n\n";
    cout <<"\t\t\tNAME:--" <<d.name << endl;
    cout <<"\t\t\tPHONE NUMBER:--"<< d.phone << endl;
    cout<<"\t\t\tNID:--"<< d.Nid <<endl;
    cout<<"\t\t\tDISTANCE:--"<<d.km<<endl;
    cout<<"\t\t\tDESTINATION:--"<<d.dest<<endl;
}
template<class T>
T gettk(T a){
    T tk;
    tk=a;
    return tk;
}
int main()

{
    //admin obj;
    //obj.file_read();
    user *ptr=new admin;
    ptr->file_read();
    //delete ptr;
    cout<<"If you are eager to rent truck,then type Yes:--";
    string f;
    cin>>f;
    if(f=="Yes"){
    rent ob;
    int ser=ob.file_open();
    cout<<"If you are eager to use our services then press 1 again:--";
    int t;
    cin>>t;
    if(t==1){
        cout<<"Processing......."<<endl;
        
        string nam,ph,des,id;
        bool isDh;
        int dis;
        int v;
        rent obj4;
        do{
        sleep(3);
        system("CLS");
        cout<<"\n--------------------------------------------------------------------------"<<endl;
        cout<<"Enter your name:--";
        cin>>nam;
        cout<<"\nEnter your phone number:--";
        cin>>ph;
        cout<<"\nEnter your destination:--";
        cin>>des;
        cout<<"\nEnter your NID number:--";
        cin>>id;
        cout<<"\nEnter your distance;--";
        cin>>dis;
        cout<<"\nEnter true or 1 if it is inside dhaka:--";
        cin>>isDh;
        rent obj2(nam,ph,id,dis,des,isDh);
        cout<<"\n\n\n\t\t\tCheck your information,please wait........"<<endl;
        obj4=obj2;
        sleep(3);
        system("CLS");
        cout<<obj2;
        cout<<"Type 1,if your information is correct:--";
        cin>>v;
        }while(v!=1);
        int k= obj4.calculate(dis,ser);
       system("CLS");
        cout<<"Printing the money reciept........."<<endl;
        sleep(3);
        system("CLS");
        obj4.showrent();
        int TK;
        TK=gettk<int>(k);
        cout << "\n\t\t    Total Rental Amount is :"<<"-------"<<setw(10)<<TK<<endl;
        cout << "\t\t	 # This is a computer generated invoce and it does not"<<endl;
        cout << "\t\t	 require an authorised signture #"<<endl;
        cout <<" "<<endl;
        cout << "\t\t_________________________________________________________"<<endl;
        cout << "\t\t	You are advised to pay up the amount before due date."<<endl;
        cout << "\t\t	Otherwise penelty fee will be applied"<<endl;
        cout << "\t\t	______________________________________________________"<<endl;
        cout<<"\n\n";
        cout<<"____________________Thank you for staying with us";

    }
    else{
        system("CLS");
        cout<<"____________________Thank u for your query......"<<endl;
        sleep(3);
        exit(0);
    }
    }
    delete ptr;
    return 0;

}
