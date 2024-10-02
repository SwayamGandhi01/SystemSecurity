#include<iostream>
#include<sstream>
#include <fstream>
// used for file handling operation and making the use of list of open files
#include<string>
using namespace std;
int main()
{
	int a, i=0;
	string text, old, password1, password2, name, pass, password0, page ,user, word, word1,age;
	string creds[2],cp[2];
	cout<<"Security System"<<endl;
	cout<<"________________________________________             "<<endl<<endl;
	cout<<"|           1. Register                |"<<endl;
	cout<<"|           2. Login                   |"<<endl;
	cout<<"|           3. Change Password         |"<<endl;
	cout<<"|           4. end Program             |"<<endl;
	cout<<"|______________________________________|"<<endl;
	//taking input from the user
	do
	{
		cout<<endl<<endl;
		cout<<"Enter your choice: ";
		cin>>a;
		switch(a)
		{
			case 1:
				{
					cout<<"____________________________"<<endl<<endl;
					cout<<"|_____________Register______"<<endl;
					cout<<"|_____________              "<<endl<<endl;;
					cout<<"Please enter your username: ";
					cin>>name;
					cout<<"Please enter your password: ";
					cin>>password0;
					cout<<"Please enter your age: ";
					cin>>age;
					// storing the data in some file
					ofstream of1;
					of1.open("file.txt");
					if(of1.is_open())
					{
						of1<<name<<"\n";
						of1<<password0;
						cout<<"Sucessfull registeration"<<endl;		
					}			
					break;
				}
				case 2:
					{
						i=0;
						cout<<"___________________"<<endl<<endl;
						cout<<"|_____Login________"<<endl;
						cout<<"______________"<<endl<<endl;
						ifstream of2;
						of2.open("file.txt");
						cout<<"Please neter your name: ";
						cin>>user;
						cout<<"Please neter your password: ";
						cin>>pass;
						if(of2.is_open()) 
						{
							while(!of2.eof())
							//eof=end of file
							{
								while(getline(of2,text))
								{
									istringstream iss(text);
									iss>>word;
									creds[i]=word;
									i++;
								}
								if(user==creds[0]&& pass==creds[1])
								{
									cout<<"Sucesfull login";
									cout<<endl<<endl;
									cout<<"Details: "<<endl;
									cout<<"Username: "+ name<<endl;
									cout<<"Password: "+ pass<<endl;
									cout<<"Age: "+ age<<endl;
								}
								else
								{
									cout<<endl<<endl;
									cout<<"Incorrect credentials"<<endl;
									cout<<"___1. Press2 to login___"<<endl;
									cout<<"___2. Press3 to change password___"<<endl;
									break;
								}
							}
						}
						break;
					}
					case 3:
						{
							i=0;
							cout<<"_______Change password_______"<<endl<<endl;
							ifstream of0;
							of0.open("file.txt");
							cout<<"Enter your old password: ";
							cin>>old;
							if(of0.is_open())
							{
								while(of0.eof())
								{
								while(getline(of0,text))
								{
									istringstream iss(text);
									iss>>word1;
									cp[i]=word1;
									i++;
								}
								if(old==cp[1])
								{
									of0.close();
									ofstream of1;
									if(of1.is_open())
									{
										cout<<"Enter your new password: ";
										cin>>password1;
										cout<<"Enter your password again: ";
										cin>>password2;
										if(password1==password2)
										{
											of1<<cp[0]<<"\n";
											of1<<password1;
											cout<<"Password changed sucessfully"<<endl;
										}
										else
										{
											of1<<cp[0]<<"\n";
											of1<<old;
											cout<<"Password donot match"<<endl;
										}
									}
								}
								else
								{
									cout<<"Please enter a valid password: ";
									break;
								}
							}
						}
						break;
		}
		case 4:
			{
				cout<<"_________Thank you_________";
				break;
			}
			default:
				cout<<"Enter a vlaid choice: ";
	}
}
while(a!=4);
//return0;
}
