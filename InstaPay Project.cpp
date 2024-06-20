#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct User
{
    string insta_passwd , user_name , phone  , pin , bankName ;
    double balance ;
    vector<string> FavList ;
};

vector<User> user;
map<char , string> company;

void menu1();
void menu2();
void menu3();
void menu4();

class Account{
    string name , pass , Phonenum ;
public:
    User x ;
    Account(){}
     
    void setName(string n){
        name=n;
    }
    void setPass(string p){
        pass=p;
    }
    void setPhone(string h){
        Phonenum=h;
    }
    void signup(){
        string p , s , h ;
        cout<<"Name : "; cin>>s;
        cout<<"Password : ";cin>>p;
        cout<<"Phone Number : ";cin>>h;
        x.user_name=s;
        x.insta_passwd=p;
        x.phone=h;
        //user.push_back(x);
        cout<<"Hello "<<s<<endl;
    }

    void login(){
        string s , p , h ;
        int flag=0;
        cout<<"User name : "; cin>>s;
        cout<<"Password : ";cin>>p;
        cout<<"Phone Number : ";cin>>h;
        for(int i=0;i<user.size();i++){
            if(user[i].user_name==s){
                if(user[i].insta_passwd==p){
                    if(user[i].phone==h){
                        cout<<"successful login"<<endl;
                        flag=1;
                        break;

                    }
                }
            }
        }
        if(flag==0){
            cout<<"User not found , be sure name and password and phone number are correct"<<endl;
        } 
    }

    void CardData(string Bname , string PIN , double b){
        x.pin=PIN;
        x.balance=b;
        x.bankName=Bname;
        user.push_back(x);
    }

    void EditAccount(User x){
        int choice ;
        cout<<"Choose which do you want to change : "<<endl;
        cout<<"     1   Password"<<endl;////
        cout<<"     2   Phone number"<<endl;////
        cout<<endl;
        cout<<"enter the number of your choice : ";////
        cin>>choice;
        if(choice==1){
            string s , v ;
            cout<<"Enter Old Password : "; cin>>s;
            if(s==x.insta_passwd){
                cout<<"Enter new password : "; cin>>s;
                cout<<"Confirm password : "; cin>>v;
                if(s==v){
                    x.insta_passwd=s;
                    cout<<"Password changed "<<endl;
                }
                else cout<<"Password not the same"<<endl;
            }
        }
        else if(choice==2){
            string s;
            cout<<"Enter new phone number : "; cin>>s;
            x.phone=s;
            cout<<"Phone number changed"<<endl;
        }
    }
};


class MyCards{
public:
    double Money;
    virtual void TransferMoney(User x)=0;
    virtual void LoadMoney(User x)=0;
   // virtual void CheckBalance(User x)=0;
    virtual void PayBills(User x)=0;
};

class BankAccount:public MyCards{
public:
    double cost=5/100;

    void TransferMoney(User x){
        int Money , flag=0;
        string password , phone , pin , username ;
        cout<<"Enter amount of money you want to transter :";
        cin>>Money;
        Money=Money+cost*Money;
        for(int i=0;i<user.size();i++){
            if(x.pin==user[i].pin && x.insta_passwd==user[i].insta_passwd){
                x.balance=user[i].balance;
                break;
            }
        }
        if(x.balance>=Money){
            cout<<"Enter password :";
            cin>>password;
            if(x.insta_passwd==password){
                cout<<"Enter card pin :";
                cin>>pin;
                if(pin==x.pin){
                    int choice;
                    cout<<endl;
                    cout<<"     1   Use Favorite List"<<endl;////
                    cout<<"     2   Write User Name"<<endl;////
                    cout<<endl;
                    cout<<"enter the number of your choice : ";////
                    cin>>choice;
                    if(choice==1){
                        cout<<"User_Name"<<endl;
                        for(int i=0;i<x.FavList.size();i++){
                            cout<<x.FavList[i]<<endl;
                        }
                        cout<<"Enter user name of the reciever : ";
                        cin>>username;
                        for(int i=0;i<user.size();i++){
                            if(user[i].user_name==username){
                                user[i].balance=user[i].balance+Money;
                                flag++;
                            }
                            else if(user[i].user_name==x.user_name){
                                user[i].balance=user[i].balance-Money;
                                flag++;
                            }
                        }
                        if(flag==0) cout<<"User not found"<<endl;
                        else if(flag==2) cout<<"Successful Transaction Process "<<endl;
                    }
                    else if(choice==2){
                        cout<<"Enter user name of the reciever : ";
                        cin>>username;
                        for(auto i:user){
                            if(username==i.user_name){
                                flag=1;
                                break;
                            }
                        }
                        if(flag==0) cout<<"User not found"<<endl;
                        else{
                            for(int i=0;i<user.size();i++){
                                if(user[i].user_name==username){
                                    user[i].balance=user[i].balance+Money;
                                }
                                else if(user[i].user_name==x.user_name){
                                    user[i].balance=user[i].balance-Money;
                                    cout<<"Successful Transaction Process , Your balance is "<<x.balance<<endl;
                                }
                            }
                        }
                    }
                }
                else{
                    cout<<"Wrong Pin , Try again !!!"<<endl;
                }
            }
            else{
                cout<<"Wrong Passowrd , Try again !!!"<<endl;
            }
        }
        else{
            cout<<"You do not have enough money , Try to load money to your card"<<endl;
        }
    }
    void LoadMoney(User x){
        string password , pin ;
        cout<<"Enter amount of money you want to load : ";
        cin>>Money;
        cout<<"Enter password :";
        cin>>password;
        if(x.insta_passwd==password){
            cout<<"Enter card pin :";
            cin>>pin;
            if(pin==x.pin){
                
                for(int i=0;i<user.size();i++){
                    if(x.pin==user[i].pin && x.insta_passwd==user[i].insta_passwd){
                        int zz=user[i].balance+Money;
                        user[i].balance=zz;
                        cout<<"Successful Transaction Process , Your balance now is "<<user[i].balance<<endl;
                        break;
                    }
                }
                
            }
            else{
                cout<<"Wrong Pin , Try again !!!"<<endl;
            }
        }
        else{
            cout<<"Wrong Passowrd , Try again !!!"<<endl;
        }
    }
    void PayBills(User x){
        string password , pin ;
        cout<<"Enter amount of money you want to pay : ";
        cin>>Money;
        cout<<"Enter password :";
        cin>>password;
        if(x.insta_passwd==password){
            cout<<"Enter card pin :";
            cin>>pin;
            if(pin==x.pin){
                for(int i=0;i<user.size();i++){
                    if(x.pin==user[i].pin && x.insta_passwd==user[i].insta_passwd){
                        if(user[i].balance>=Money){
                            user[i].balance=user[i].balance-Money;
                            cout<<"Thanks for paying for our services "<<endl;
                        }
                        else{
                            cout<<"You Do not have enough money , Try to load more money "<<endl;
                        }
                        break;
                    }
                }
            }
            else{
                cout<<"Wrong Pin , Try again !!!"<<endl;
            }
        }
        else{
            cout<<"Wrong Passowrd , Try again !!!"<<endl;
        }
    }
};

class VisaCard:public MyCards{
public:
    double cost=1/100;

void TransferMoney(User x){
        int Money , flag=0;
        string password , phone , pin , username ;
        cout<<"Enter amount of money you want to transter :";
        cin>>Money;
        Money=Money+cost*Money;
        for(int i=0;i<user.size();i++){
            if(x.pin==user[i].pin && x.insta_passwd==user[i].insta_passwd){
                x.balance=user[i].balance;
                break;
            }
        }
        if(x.balance>=Money){
            cout<<"Enter password :";
            cin>>password;
            if(x.insta_passwd==password){
                cout<<"Enter card pin :";
                cin>>pin;
                if(pin==x.pin){
                    int choice;
                    cout<<endl;
                    cout<<"     1   Use Favorite List"<<endl;////
                    cout<<"     2   Write User Name"<<endl;////
                    cout<<endl;
                    cout<<"enter the number of your choice : ";////
                    cin>>choice;
                    if(choice==1){
                        cout<<"User_Name"<<endl;
                        for(int i=0;i<x.FavList.size();i++){
                            cout<<x.FavList[i]<<endl;
                        }
                        cout<<"Enter user name of the reciever : ";
                        cin>>username;
                        for(int i=0;i<user.size();i++){
                            if(user[i].user_name==username){
                                user[i].balance=user[i].balance+Money;
                                flag++;
                            }
                            else if(user[i].user_name==x.user_name){
                                user[i].balance=user[i].balance-Money;
                                flag++;
                            }
                        }
                        if(flag==0) cout<<"User not found"<<endl;
                        else if(flag==2) cout<<"Successful Transaction Process "<<endl;
                    }
                    else if(choice==2){
                        cout<<"Enter user name of the reciever : ";
                        cin>>username;
                        for(auto i:user){
                            if(username==i.user_name){
                                flag=1;
                                break;
                            }
                        }
                        if(flag==0) cout<<"User not found"<<endl;
                        else{
                            for(int i=0;i<user.size();i++){
                                if(user[i].user_name==username){
                                    user[i].balance=user[i].balance+Money;
                                }
                                else if(user[i].user_name==x.user_name){
                                    user[i].balance=user[i].balance-Money;
                                    cout<<"Successful Transaction Process , Your balance is "<<x.balance<<endl;
                                }
                            }
                        }
                    }
                }
                else{
                    cout<<"Wrong Pin , Try again !!!"<<endl;
                }
            }
            else{
                cout<<"Wrong Passowrd , Try again !!!"<<endl;
            }
        }
        else{
            cout<<"You do not have enough money , Try to load money to your card"<<endl;
        }
    }
    void LoadMoney(User x){
        string password , pin ;
        cout<<"Enter amount of money you want to load : ";
        cin>>Money;
        cout<<"Enter password :";
        cin>>password;
        if(x.insta_passwd==password){
            cout<<"Enter card pin :";
            cin>>pin;
            if(pin==x.pin){
                
                for(int i=0;i<user.size();i++){
                    if(x.pin==user[i].pin && x.insta_passwd==user[i].insta_passwd){
                        int zz=user[i].balance+Money;
                        user[i].balance=zz;
                        cout<<"Successful Transaction Process , Your balance now is "<<user[i].balance<<endl;
                        break;
                    }
                }
                
            }
            else{
                cout<<"Wrong Pin , Try again !!!"<<endl;
            }
        }
        else{
            cout<<"Wrong Passowrd , Try again !!!"<<endl;
        }
    }
    void PayBills(User x){
        string password , pin ;
        cout<<"Enter amount of money you want to pay : ";
        cin>>Money;
        cout<<"Enter password :";
        cin>>password;
        if(x.insta_passwd==password){
            cout<<"Enter card pin :";
            cin>>pin;
            if(pin==x.pin){
                for(int i=0;i<user.size();i++){
                    if(x.pin==user[i].pin && x.insta_passwd==user[i].insta_passwd){
                        if(user[i].balance>=Money){
                            user[i].balance=user[i].balance-Money;
                            cout<<"Thanks for paying for our services "<<endl;
                        }
                        else{
                            cout<<"You Do not have enough money , Try to load more money "<<endl;
                        }
                        break;
                    }
                }
            }
            else{
                cout<<"Wrong Pin , Try again !!!"<<endl;
            }
        }
        else{
            cout<<"Wrong Passowrd , Try again !!!"<<endl;
        }
    }
};

class MasterCard:public MyCards{
    public:
    double cost=2/100;

    void TransferMoney(User x){
        int Money , flag=0;
        string password , phone , pin , username ;
        cout<<"Enter amount of money you want to transter :";
        cin>>Money;
        Money=Money+cost*Money;
        for(int i=0;i<user.size();i++){
            if(x.pin==user[i].pin && x.insta_passwd==user[i].insta_passwd){
                x.balance=user[i].balance;
                break;
            }
        }
        if(x.balance>=Money){
            cout<<"Enter password :";
            cin>>password;
            if(x.insta_passwd==password){
                cout<<"Enter card pin :";
                cin>>pin;
                if(pin==x.pin){
                    int choice;
                    cout<<endl;
                    cout<<"     1   Use Favorite List"<<endl;////
                    cout<<"     2   Write User Name"<<endl;////
                    cout<<endl;
                    cout<<"enter the number of your choice : ";////
                    cin>>choice;
                    if(choice==1){
                        cout<<"User_Name"<<endl;
                        for(int i=0;i<x.FavList.size();i++){
                            cout<<x.FavList[i]<<endl;
                        }
                        cout<<"Enter user name of the reciever : ";
                        cin>>username;
                        for(int i=0;i<user.size();i++){
                            if(user[i].user_name==username){
                                user[i].balance=user[i].balance+Money;
                                flag++;
                            }
                            else if(user[i].user_name==x.user_name){
                                user[i].balance=user[i].balance-Money;
                                flag++;
                            }
                        }
                        if(flag==0) cout<<"User not found"<<endl;
                        else if(flag==2) cout<<"Successful Transaction Process "<<endl;
                    }
                    else if(choice==2){
                        cout<<"Enter user name of the reciever : ";
                        cin>>username;
                        for(auto i:user){
                            if(username==i.user_name){
                                flag=1;
                                break;
                            }
                        }
                        if(flag==0) cout<<"User not found"<<endl;
                        else{
                            for(int i=0;i<user.size();i++){
                                if(user[i].user_name==username){
                                    user[i].balance=user[i].balance+Money;
                                }
                                else if(user[i].user_name==x.user_name){
                                    user[i].balance=user[i].balance-Money;
                                    cout<<"Successful Transaction Process , Your balance is "<<user[i].balance<<endl;
                                }
                            }
                        }
                    }
                }
                else{
                    cout<<"Wrong Pin , Try again !!!"<<endl;
                }
            }
            else{
                cout<<"Wrong Passowrd , Try again !!!"<<endl;
            }
        }
        else{
            cout<<"You do not have enough money , Try to load money to your card"<<endl;
        }
    }
    void LoadMoney(User x){
        string password , pin ;
        cout<<"Enter amount of money you want to load : ";
        cin>>Money;
        cout<<"Enter password :";
        cin>>password;
        if(x.insta_passwd==password){
            cout<<"Enter card pin :";
            cin>>pin;
            if(pin==x.pin){
                
                for(int i=0;i<user.size();i++){
                    if(x.pin==user[i].pin && x.insta_passwd==user[i].insta_passwd){
                        int zz=user[i].balance+Money;
                        user[i].balance=zz;
                        cout<<"Successful Transaction Process , Your balance now is "<<user[i].balance<<endl;
                        break;
                    }
                }
                
            }
            else{
                cout<<"Wrong Pin , Try again !!!"<<endl;
            }
        }
        else{
            cout<<"Wrong Passowrd , Try again !!!"<<endl;
        }
    }
    void PayBills(User x){
        string password , pin ;
        cout<<"Enter amount of money you want to pay : ";
        cin>>Money;
        cout<<"Enter password :";
        cin>>password;
        if(x.insta_passwd==password){
            cout<<"Enter card pin :";
            cin>>pin;
            if(pin==x.pin){
                for(int i=0;i<user.size();i++){
                    if(x.pin==user[i].pin && x.insta_passwd==user[i].insta_passwd){
                        if(user[i].balance>=Money){
                            user[i].balance=user[i].balance-Money;
                            cout<<"Thanks for paying for our services "<<endl;
                        }
                        else{
                            cout<<"You Do not have enough money , Try to load more money "<<endl;
                        }
                        break;
                    }
                }
            }
            else{
                cout<<"Wrong Pin , Try again !!!"<<endl;
            }
        }
        else{
            cout<<"Wrong Passowrd , Try again !!!"<<endl;
        }
    }
};


int main(){
    int choice;
    int counter=0;
    bool flag=0;
    char CNames[]={'A','B','X','G','Y','M','Z','S','V','H'};
    string Code[]={"789645","026513","798643","162145","357789","032155","541268","789465","321951","547864"};
    for(int i=0;i<10;i++){
        company[CNames[i]]=Code[i];
    }
    while(true){
        menu1();
        cin>>choice;
        Account A1 ;
        MyCards *card ;
        if(choice==1){
            A1.login();
        }
        else if(choice==2){
            A1.signup();
            cout<<"which card you will use :"<<endl;
            menu3();
            cin>>choice;
            if(choice==1){
                card=new BankAccount();
            }
            else if(choice==2){
                card=new VisaCard();
            }
            else if(choice==3){
                card=new MasterCard();
            }
            string bankname , paypin ;
            double bal;
            cout<<"Enter Bank name :" ;cin>>bankname;
            cout<<"Enter pin : ";cin>>paypin;
            cout<<"Enter balance : ";cin>>bal;
            A1.CardData(bankname,paypin,bal);
        }

         User v;
           /* v.balance=user[counter].balance;
            v.bankName=user[counter].bankName;
            v.insta_passwd=user[counter].insta_passwd;
            v.phone=user[counter].phone;
            v.pin=user[counter].pin;
            v.user_name=user[counter].user_name;*/
            v=user[counter];

        while(true){
            menu2();
            cin>>choice;
            if(choice==1){
                //card->CheckBalance(v);
                cout<<"Your Balance is "<<user[counter].balance<<endl;
            }
            else if(choice==2){
                card->TransferMoney(v);
            }
            else if(choice==3){
                card->LoadMoney(v);
            }
            else if(choice==4){
                string x ;
                char s ;
                cout<<"Company      Code"<<endl;
                for(auto i:company){
                    cout<<i.first<<"        "<<i.second<<endl;
                }
                cout<<"Enter company name : "; cin>>s;
                cout<<"Enter payment code : "; cin>>x;
                if(company[s]==x) card->PayBills(v);
                else cout<<"Wrong Code or Company Name"<<endl;
            }
            else if(choice==5){
                menu4();
                cin>>choice;
                if(choice==1){
                    string s;
                    cout<<"Enter user_name : ";
                    cin>>s;
                    v.FavList.push_back(s);
                }
                else if(choice==2){
                    string s;
                    cout<<"Enter user_name : ";
                    cin>>s;
                    int i=0;
                    while(i<v.FavList.size()){
                        if(v.FavList[i]==s){
                            vector<string>::iterator it;
                            it=v.FavList.begin()+i;
                            v.FavList.erase(it);
                            break;
                        }
                        i++;
                    }
                    cout<<"Delete is Done"<<endl;
                }
                else if(choice==3){
                    cout<<"User_Name"<<endl;
                    for(int i=0;i<v.FavList.size();i++){
                        cout<<v.FavList[i]<<endl;
                    }
                }
            }
            else if(choice==6){
                A1.EditAccount(v);
            }
            else if(choice==7){
                break;
            }
            else if(choice==8){
                flag=1;
                break;
            }
        }
        if(flag==1) break;
        counter++;
    }
    /*User v;
    v.balance=50;
    user.push_back(v);
    //v.balance=80;
    user[0].balance=80;
    cout<<user[0].balance;*/
}

void menu1(){
    cout<<"     1 login"<<endl;////
    cout<<"     2 sign up"<<endl;////
    cout<<endl;
    cout<<"enter the number of your choice : ";////
}

void menu2(){
    cout<<endl;
    cout<<"     1   Check my balance"<<endl;////
    cout<<"     2   Transfer money to"<<endl;////
    cout<<"     3   Load money to me"<<endl;
    cout<<"     4   Pay Bills"<<endl;
    cout<<"     5   Favorite list"<<endl;////
    cout<<"     6   Edit account"<<endl;// 
    cout<<"     7   logout"<<endl;////
    cout<<"     8   Exit "<<endl;////
    cout<<endl;
    cout<<"enter the number of your choice : ";////
}

void menu3(){
    cout<<endl;
    cout<<"     1   Bank Account"<<endl;////
    cout<<"     2   Visa Card"<<endl;////
    cout<<"     3   Master Card"<<endl;////
    cout<<endl;
    cout<<"enter the number of your choice : ";////
}

void menu4(){
    cout<<endl;
    cout<<"     1   Add user"<<endl;////
    cout<<"     2   Delete user"<<endl;////
    cout<<"     3   Print user"<<endl;////
    cout<<endl;
    cout<<"enter the number of your choice : ";////
}








