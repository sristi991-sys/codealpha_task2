#include <iostream>
#include <fstream>
using namespace std;

void registerUser()
{
    string username, password;
    string filename;

    cout<<"\n===== REGISTER =====\n";

    cout<<"Enter Username: ";
    cin>>username;

    filename = username + ".txt";

    ifstream checkFile(filename);

    if(checkFile)
    {
        cout<<"Username already exists!\n";
        checkFile.close();
        return;
    }

    cout<<"Enter Password: ";
    cin>>password;

    ofstream file(filename);

    file<<username<<endl;
    file<<password<<endl;

    file.close();

    cout<<"Registration Successful!\n";
}

void loginUser()
{
    string username,password;
    string storedUser, storedPass;
    string filename;

    cout<<"\n===== LOGIN =====\n";

    cout<<"Username: ";
    cin>>username;

    cout<<"Password: ";
    cin>>password;

    filename = username + ".txt";

    ifstream file(filename);

    if(!file)
    {
        cout<<"User not found!\n";
        return;
    }

    getline(file, storedUser);
    getline(file, storedPass);

    file.close();

    if(username==storedUser && password==storedPass)
        cout<<"Login Successful!\n";
    else
        cout<<"Incorrect Password!\n";
}

int main()
{
    int choice;

    do
    {
        cout<<"\n1. Register\n2. Login\n3. Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout<<"Goodbye!\n"; break;
            default: cout<<"Invalid Choice!\n";
        }

    }while(choice!=3);

    return 0;
}
