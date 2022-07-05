/*

---------- File Managment System ----------

*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

bool login()
{
     string username, password, un, pswd;
     cout << "Please enter username : ";
     cin >> username;

     cout << "Please enter password : ";
     cin >> password;

     ifstream read("data\\" + username + ".txt");

     getline(read, un);
     // cout << "username : " + username;
     getline(read, pswd);
     // cout << "password : " + password;

     if (un == username && pswd == password)
     {

          return true;
     }
     else
     {
          return false;
     }
     return 0;
}

// class new_user
class new_user
{
public:
     string username, password1, password2, choice2, ans3;

     // function 1 : check_choice1
     void check_choice1()
     {
          cout << endl
               << "----------------------------------------------------------------" << endl
               << endl;

          cout << setw(50) << "----- Fill below details to verify -----" << endl
               << endl;
          bool status = login();

          if (!status)
          {
               cout << endl
                    << "----- Login Failed ! -----" << endl
                    << endl;
               // exit(0);

               cout << endl
                    << "Do you want to try again?" << endl
                    << endl;
               cin >> ans3;

               if (ans3 == "yes")
               {
                    void check_choice1();
               }
          }
          else
          {
               cout << endl
                    << endl
                    << "----- Successfully logged In -----" << endl
                    << endl;

               cout << endl
                    << "----------------------------------------------------------------" << endl;
               //  exit(0);
          }
     }

     // function 2 : check_choice2
     void check_choice2()
     {
          string username, password1, password2;
          char ans;
          cout << "Set username : ";
          cin >> username;

          cout << "Set Password : ";
          cin >> password1;

          cout << "Confirm your entered Password : ";
          cin >> password2;

          cout << endl
               << "----------------------------------------------------------------" << endl;

          if (password1 == password2)
          {
               ofstream file;
               file.open("data\\" + username + ".txt");

               file << username << endl
                    << password1;
               file.close();

               cout << endl
                    << "----- Mr. / Mrs. " << username << " Your Account is Successfully created -----" << endl;

               cout << endl
                    << "----------------------------------------------------------------" << endl;
          }
          else
          {
               cout << endl
                    << "----- Sorry! You again entered wrong Password -----" << endl;
               exit(0);
          }
     }
};

// class user_data
class user_data
{
public:
     int choice1;
     string file_name, input_data, choice, file_name2;
     void check_choice3()
     {
          cout << "Press 1 to create new file" << endl;
          cout << "Press 2 to edit created file" << endl;
          cout << "Press 3 to display content of file" << endl;
          cout << "Press 0 to exit" << endl;

          cout << endl
               << "----------------------------------------------------------------" << endl;

          cout << "Enter your choice : ";
          cin >> choice1;

          cout << "----------------------------------------------------------------" << endl
               << endl;

          switch (choice1)
          {
          case 1:
          {
               cout << "Create file named as : ";
               cin >> file_name;

               cout << "Enter data : ";
               cin >> input_data;

               cout << endl
                    << "In which format do you want to save file ?" << endl;
               cin >> choice;

               if (choice == "text")
               {

                    ofstream file_open(file_name + ".txt", ios ::out);
                    file_open << "----- Your Data is saved in '.txt' format -----" << endl;
                    file_open << input_data;
                    file_open.close();
               }
               else if (choice == "binary")
               {

                    ofstream file_open(file_name + ".bin", ios ::binary);
                    file_open << "----- Your Data is saved in 'binary' format -----" << endl;
                    file_open << input_data;
                    file_open.write((char *)&input_data, sizeof(input_data));
                    file_open.close();
               }
               else
               {
                    cout << "I think you entered anything wrong!";
               }

               cout << endl
                    << "----------------------------------------------------------------" << endl;

               cout << endl
                    << "----- File is Successfully created -----" << endl
                    << endl;

               break;
          }

          case 2:
          {

               cout << "Enter file name : ";
               cin >> file_name;

               string input1;
               ofstream updated_data;
               updated_data.open(file_name + ".txt", ios::out);
               cout << "Enter data : ";
               cin >> input1;

               updated_data << "----- Your data -----" << endl;
               updated_data << input1;

               updated_data.close();

               cout << endl
                    << "----- Successfully Modified -----" << endl
                    << endl;

               // }
               // else{
               //     cout << "----- File not found -----" << endl;
               // }

               break;
          }

          case 3:
          {
               cout << "Enter file name : ";
               cin >> file_name;

               string output;
               ifstream file_display;
               file_display.open(file_name + ".txt", ios::in);
               cout << endl
                    << "----- Displaying your file's contents -----" << endl
                    << endl;
               cout << "----------------------------------------------------------------" << endl
                    << endl;

               while (getline(file_display, output))
               {
                    cout << output << endl
                         << endl;
               }

               file_display.close();

               break;
          }

          default:
          {
               exit(0);
          }
          }
     }
};

int main()
{
     string choice1, choice2, choice3, choice4, ans3;

     cout << endl
          << "Welcome! Type 'yes' if you are new user or type 'no' if you are old user." << endl;
     cin >> choice1;

     cout << endl
          << "----------------------------------------------------------------" << endl
          << endl;

     new_user obj1;
     user_data obj2;

     if (choice1 == "yes")
     {

          obj1.check_choice2();
          cout << endl
               << "Do you want to verify your Details?" << endl;
          cin >> ans3;

          if (ans3 == "yes")
          {
               obj1.check_choice1();

               cout << endl
                    << "Do you want to continue ?" << endl;
               cin >> choice3;
               if (choice3 == "yes")
               {
                    cout << endl
                         << "----------------------------------------------------------------" << endl
                         << endl;
                    obj2.check_choice3();
               }
               else
               {
                    exit(0);
               }
          }
          else
          {
               exit(0);
          }
     }

     else if (choice1 == "no")
     {
          cout << setw(50) << "----- Welcome Dear, Nice to see you :) -----" << endl
               << endl;
          bool status = login();

          if (!status)
          {
               cout << endl
                    << "----------------------------------------------------------------" << endl
                    << endl;

               cout << "----- Login Failed ! -----" << endl;

               cout << endl
                    << "----------------------------------------------------------------" << endl
                    << endl;

               cout << "Do you want to re-enter your details ? " << endl;
               cin >> choice4;
               if (choice4 == "yes")
               {
                    cout << endl
                         << "----------------------------------------------------------------" << endl
                         << endl;

                    bool status = login();

                    cout << endl
                         << "----------------------------------------------------------------" << endl;

                    cout << endl
                         << "----- Successfully logged In -----" << endl;

                    cout << endl
                         << "----------------------------------------------------------------" << endl
                         << endl;

                    cout << endl
                         << "Do you want to continue ?" << endl;
                    cin >> choice3;
                    if (choice3 == "yes")
                    {
                         cout << endl
                              << "----------------------------------------------------------------" << endl
                              << endl;
                         obj2.check_choice3();
                    }
                    else
                    {
                         exit(0);
                    }
               }
          }
          else
          {
               cout << endl
                    << "----------------------------------------------------------------" << endl;

               cout << endl
                    << "----- Successfully logged In -----" << endl;

               cout << endl
                    << "----------------------------------------------------------------" << endl
                    << endl;

               cout << "Do you want to continue ?" << endl;
               cin >> choice2;

               if (choice2 == "yes")
               {
                    cout << endl
                         << "----------------------------------------------------------------" << endl
                         << endl;

                    obj2.check_choice3();
               }
          }
     }
     else
     {
          string choice2;
          cout << endl
               << "----- WARNING! Please select proper choice. -----" << endl
               << endl;
          cout << "Do you want to continue?" << endl;
          cin >> choice2;

          cout << endl;

          if (choice2 == "yes")
          {
               main();
          }
          else
          {
               cout <<  "----------------------------------------------------------------" << endl
                    << endl;

               cout << "----- Program ended -----" << endl << endl;
               exit(0);
          }
     }

     return 0;
}