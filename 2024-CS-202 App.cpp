#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;

const int animalTypes = 6;          
const int ageLevels = 4;            
const int genders = 2;              

string animalNames[animalTypes] = {"Cow","Ox", "Buffalo", "Camel", "Sheep", "Goat"};
string ageNames[ageLevels] = {"Newborn", "Juvenile", "Adolescent", "Adult"};
string genderNames[genders] = {"Female", "Male"};

int soldStock[animalTypes][ageLevels][genders] = {
                                                    { {5, 3}, {5, 3}, {5, 3}, {5, 3} },  
                                                    { {5, 3}, {5, 3}, {5, 3}, {5, 3} },  
                                                    { {5, 3}, {5, 3}, {5, 3}, {5, 3} },  
                                                    { {5, 3}, {5, 3}, {5, 3}, {5, 3} },  
                                                    { {5, 3}, {5, 3}, {5, 3}, {5, 3} },  
                                                    { {5, 3}, {5, 3}, {5, 3}, {5, 3} }   
                                                 };

int animalPrices[animalTypes][ageLevels][genders] = {
                                                        { {150000, 125000}, {100000, 175000}, {185000, 200000}, {225000, 250000} }, 
                                                        { {150000, 125000}, {100000, 175000}, {185000, 200000}, {225000, 250000} }, 
                                                        { {125000, 100000}, {175000, 185000}, {200000, 225000}, {250000, 275000} }, 
                                                        { {220000, 225000}, {250000, 285000}, {300000, 325000}, {300000, 350000} }, 
                                                        { {50000 , 60000 }, {65000 , 80000 }, {85000 , 100000}, {100000, 125000} }, 
                                                        { {45000 , 50000 }, {50000 , 60000 }, {65000 , 80000 }, {85000 , 100000} }  
                                                    };

int totalBalance = soldStock[animalTypes][ageLevels][genders]*animalPrices[animalTypes][ageLevels][genders];

int stock[animalTypes][ageLevels][genders] = {
                                                { {15, 10}, {15, 10}, {15, 10}, {15, 10} },  
                                                { {15, 10}, {15, 10}, {15, 10}, {15, 10} },  
                                                { {15, 10}, {15, 10}, {15, 10}, {15, 10} },  
                                                { {15, 10}, {15, 10}, {15, 10}, {15, 10} },  
                                                { {15, 10}, {15, 10}, {15, 10}, {15, 10} },  
                                                { {15, 10}, {15, 10}, {15, 10}, {15, 10} }   
                                             };

void displayHeader();
int displayMainMenu();
void exitApp();
int signupMenu();
int loginMenu();
int adminMenu();
int userlogin();
int usersignup();
int sellerMenu();
int buyerMenu();
void deleteUserAccount();
void viewUserAccount();
void addAnimal();
void sellAnimal();
void deleteAnimal();
void viewAnimals();
void buyAnimal();
void viewPrices();
void updatePrices();
void viewSalesSummary();
bool isValidName(string input);
bool isValidPass(string input);
void clearScreen();

string sellerID[50]={"Amber"};
string sellerPASS[50]={"seller001"};
string buyerID[50]={"Juliet"};
string buyerPASS[50]={"buyer001"};

int total_sellers=1;
int total_buyers=1;

bool RegisteredBuyer[50]={true};
bool RegisteredSeller[50]={true};

int main() 
{
    int idx;
    string adminUsername, adminPassword;
    adminUsername="Wareesha";
    adminPassword="admin001";
    string sellerUsername, sellerPassword;
    string buyerUsername, buyerPassword;
    string username, password;

    bool isAdminLoggedIn = false;
    bool isSellerLoggedIn = false;
    bool isBuyerLoggedIn = false;

    while (true) 
    {
        system("cls");
        displayHeader();
        int main_menu = displayMainMenu();
        cout << "Loading..." << endl;

        if (main_menu == 1) 
        {
            clearScreen();
            int signup = signupMenu();
            cout << "Loading..." << endl;

            while (true) 
            {
                if (signup == 1) 
                {
                    clearScreen();
                    cout << "Set Admin Username (5 to 16 characters): ";
                    string name;
                    cin >> name;
                    if(isValidName(name))
                    {
                        if(name.length()>=5 && name.length()<=16)
                        {
                            adminUsername = name;
                            cout << "Enter Password (8+ characters, alphanumeric): ";
                            string pass;
                            cin >> pass;

                            if(isValidPass(pass))
                            {
                                if(pass.length() >= 8)
                                {
                                    adminPassword = pass;
                                    cout << "Admin account created successfully!\n";
                                }
                                else
                                {
                                    cout<<"Password must contain more than 8 characters.";
                                    clearScreen();
                                    signup=signupMenu();
                                    continue;
                                }
                            }
                            else
                            {
                                cout<<"Password must contain both alphabets and numbers without space.";
                                clearScreen();
                                signup=signupMenu();
                                continue;
                            }
                        } 
                        else
                        {
                            cout<<"Username must contain 5 to 16 characters.";
                            clearScreen();
                            signup=signupMenu();
                            continue;
                        }
                    }
                    else
                    {
                        cout<<"Username cannot contain numbers & space.";
                        clearScreen();
                        signup=signupMenu();
                        continue;
                    }
                    clearScreen();
                    break; 
                } 
                else if (signup == 2) 
                {
                    clearScreen();
                    int user = usersignup();
                    while (true) 
                    {
                        if (user == 1) 
                        {
                            clearScreen();
                            cout << "Set Seller Username (5 to 16 characters): ";
                            string name;
                            cin >> name;
                            if(isValidName(name))
                            {
                                if(name.length()>=5 && name.length()<=16)
                                {
                                    cout << "Enter Password (8+ characters, alphanumeric): ";
                                    string pass;
                                    cin >> pass;

                                    if(isValidPass(pass))
                                    {
                                        if(pass.length() >= 8)
                                        {
                                            sellerID[total_sellers] = name;
                                            sellerPASS[total_sellers] = pass;
                                            total_sellers=total_sellers+1;
                                            cout << "Seller account created successfully!\n";
                                        }
                                        else
                                        {
                                            cout<<"Password must contain more than 8 characters.";
                                            clearScreen();
                                            user=usersignup();
                                            continue;
                                        }
                                    }
                                    else
                                    {
                                        cout<<"Password must contain both alphabets and numbers without space.";
                                        clearScreen();
                                        user=usersignup();
                                        continue;
                                    }
                                } 
                                else
                                {
                                    cout<<"Username must contain 5 to 16 characters.";
                                    clearScreen();
                                    user=usersignup();
                                    continue;
                                }
                            }
                            else
                            {
                                cout<<"Username cannot contain numbers & space.";
                                clearScreen();
                                user=usersignup();
                                continue;
                            }

                            clearScreen();
                            break; 
                        } 

                        else if (user == 2) 
                        {
                            clearScreen();
                            cout << "Set Buyer Username (5 to 16 characters): ";
                            string name;
                            cin >> name;
                            if(isValidName(name))
                            {
                                if(name.length()>=5 && name.length()<=16)
                                {
                                    cout << "Enter Password (8+ characters, alphanumeric): ";
                                    string pass;
                                    cin >> pass;

                                    if(isValidPass(pass))
                                    {
                                        if(pass.length() >= 8)
                                        {
                                            buyerID[total_buyers] = name;
                                            buyerPASS[total_buyers] = pass;
                                            total_buyers=total_buyers+1;
                                            cout << "Buyer account created successfully!\n";
                                        }
                                        else
                                        {
                                            cout<<"Password must contain more than 8 characters.";
                                            clearScreen();
                                            user=usersignup();
                                            continue;
                                        }
                                    }
                                    else
                                    {
                                        cout<<"Password must contain both alphabets and numbers without space.";
                                        clearScreen();
                                        user=usersignup();
                                        continue;
                                    }
                                } 
                                else
                                {
                                    cout<<"Username must contain 5 to 16 characters.";
                                    clearScreen();
                                    user=usersignup();
                                    continue;
                                }
                            }
                            else
                            {
                                cout<<"Username cannot contain numbers & space.";
                                clearScreen();
                                user=usersignup();
                                continue;
                            }

                            clearScreen();
                            break; 
                        } 
                        else 
                        {
                            cout << "Invalid option. Try again.";
                            clearScreen();
                            user = usersignup();
                        }
                    }
                    break; 
                } 
                else if (signup == 3) 
                {
                    clearScreen();
                    break; 
                } 
                else 
                {
                    cout << "Invalid option! Please try again.\n";
                    clearScreen();
                    signup = signupMenu();
                }
            }
        } 
        else if (main_menu == 2) 
        {
            clearScreen();
            int login = loginMenu();
            cout << "Loading..." << endl;

            while (true) 
            {
                if (login == 1) 
                {
                    clearScreen();
                    while (true) 
                    {
                        clearScreen();
                            cout << "Enter Admin Username: ";
                            cin >> username;
                            cout << "Enter Admin Password (without spaces): ";
                            cin >> password;
                            cout << "Loading..." << endl;

                            if ((username == adminUsername) && (password == adminPassword)) 
                            {
                                isAdminLoggedIn= true; 
                                clearScreen(); 
                                int admin = adminMenu(); 
                                cout << "Loading..." << endl;

                                while (true) 
                                {
                                    clearScreen();
                                    if (admin == 1) 
                                    {
                                        viewUserAccount(); 
                                        cout << "Press any key to go back! ";
                                        _getch();
                                        cout << endl;
                                        cout << "Loading..." << endl;
                                        clearScreen();
                                        admin = adminMenu();
                                    } 
                                    else if (admin == 2) 
                                    {
                                        deleteUserAccount(); 
                                        cout << "Press any key to go back! ";
                                        _getch();
                                        cout << endl;
                                        cout << "Loading..." << endl;
                                        clearScreen();
                                        admin = adminMenu();
                                    } 
                                    else if (admin == 3) 
                                    {
                                        viewAnimals(); 
                                        cout << "Press any key to go back! ";
                                        _getch();
                                        cout << endl;
                                        cout << "Loading..." << endl;
                                        clearScreen();
                                        admin = adminMenu();
                                    } 
                                    else if (admin == 4)
                                    {
                                        viewSalesSummary();
                                        cout << "Press any key to go back! ";
                                        _getch();
                                        cout << endl;
                                        cout << "Loading..." << endl;
                                        clearScreen();
                                        admin = adminMenu();
                                    } 
                                    else if (admin == 5) 
                                    {
                                        viewPrices();
                                        cout << "Press any key to go back! ";
                                        _getch();
                                        cout << endl;
                                        cout << "Loading..." << endl;
                                        clearScreen();
                                        admin = adminMenu();
                                    } 
                                    else if (admin == 6) 
                                    {
                                        updatePrices();
                                        cout << "Press any key to go back! ";
                                        _getch();
                                        cout << endl;
                                        cout << "Loading..." << endl;
                                        clearScreen();
                                        admin = adminMenu();
                                    } 
                                    else if (admin == 7) 
                                    {
                                        deleteAnimal();
                                        cout << "Press any key to go back! ";
                                        _getch();
                                        cout << endl;
                                        cout << "Loading..." << endl;
                                        clearScreen();
                                        admin = adminMenu();
                                    } 
                                    else if (admin == 8) 
                                    {
                                        isAdminLoggedIn = false;  
                                        clearScreen();
                                        main_menu=displayMainMenu();
                                        cout<<"Loading...";
                                        clearScreen();
                                        break;
                                    } 
                                    else 
                                    {
                                        cout << "Invalid option! Please try again.\n"; 
                                        clearScreen();
                                        admin=adminMenu();
                                        continue;
                                    }
                                }
                                break; 
                            } 
                            else 
                            {
                                cout << "Invalid credentials! Try again." << endl;
                                clearScreen();
                            }
                        break;
                    }
                    break; 
                } 
                else if (login == 2) 
                {
                    clearScreen();
                    int user = userlogin();
                    while (true) 
                    {
                        clearScreen();
                        if (user == 1) 
                        {
                            bool found = false; 
                            clearScreen();
                            cout << "Enter Seller Username: ";
                            cin >> username;
                            cout << "Enter Seller Password (without spaces): ";
                            cin >> password;
                            cout << "Loading..." << endl;

                            for (idx = 0; idx < total_sellers; idx++) 
                            {   
                                if (username == sellerID[idx] && password == sellerPASS[idx]) 
                                {
                                    isSellerLoggedIn = true;
                                    found = true;
                                    clearScreen();
                                    int seller = sellerMenu();
                                    cout << "Loading..." << endl;
                    
                                    while (true) 
                                    {
                                        if (seller == 1) 
                                        {
                                            addAnimal();
                                            cout << "Press any key to go back! ";
                                            _getch();
                                            cout << endl;
                                            cout << "Loading..." << endl;
                                            clearScreen();
                                            seller = sellerMenu();
                                        } 
                                        else if (seller == 2) 
                                        {
                                            sellAnimal();
                                            cout << "Press any key to go back! ";
                                            _getch();
                                            cout << endl;
                                            cout << "Loading..." << endl;
                                            clearScreen();
                                            seller = sellerMenu();
                                        } 
                                        else if (seller == 3) 
                                        {
                                            viewAnimals();
                                            cout << "Press any key to go back! ";
                                            _getch();
                                            cout << endl;
                                            cout << "Loading..." << endl;
                                            clearScreen();
                                            seller = sellerMenu();
                                        } 
                                        else if (seller == 4) 
                                        {
                                            viewSalesSummary();
                                            cout << "Press any key to go back! ";
                                            _getch();
                                            cout << endl;
                                            cout << "Loading..." << endl;
                                            clearScreen();
                                            seller = sellerMenu();
                                        } 
                                        else if (seller == 5) 
                                        {
                                            viewPrices();
                                            cout << "Press any key to go back! ";
                                            _getch();
                                            cout << endl;
                                            cout << "Loading..." << endl;
                                            clearScreen();
                                            seller = sellerMenu();
                                        } 
                                        else if (seller == 6) 
                                        {
                                            isSellerLoggedIn = false;
                                            clearScreen();
                                            main_menu=displayMainMenu();
                                            cout << "Loading..." << endl;
                                            clearScreen();
                                            break;
                                        } 
                                        else 
                                        {
                                            cout << "Invalid option! Please try again.\n";
                                            clearScreen();
                                            seller=sellerMenu();
                                            continue;
                                        }
                                    } 
                                    break;
                                }
                            }

                            if (!found) 
                            {
                                cout << "Invalid credentials! Try again." << endl;
                                clearScreen();
                            }
                            break;
                        }

                        else if (user == 2) 
                        {
                            bool found = false;
                            clearScreen();
                            cout << "Enter Buyer Username: ";
                            cin >> username;
                            cout << "Enter Buyer Password (without spaces): ";
                            cin >> password;
                            cout << "Loading..." << endl;

                            for (idx = 0; idx < total_buyers; idx++) 
                            {                        
                                if (username == buyerID[idx] && password == buyerPASS[idx]) 
                                {
                                    isBuyerLoggedIn = true;
                                    found = true;
                                    clearScreen();
                                    int buyer = buyerMenu();
                                    cout << "Loading..." << endl;
                        
                                    while (true) 
                                    {
                                        if (buyer == 1) 
                                        {
                                            buyAnimal();
                                            cout << "Press any key to go back! ";
                                            _getch();
                                            cout << endl;
                                            cout << "Loading..." << endl;
                                            clearScreen();
                                            buyer = buyerMenu();
                                        } 
                                        else if (buyer == 2) 
                                        {
                                            viewAnimals();
                                            cout << "Press any key to go back! ";
                                            _getch();
                                            cout << endl;
                                            cout << "Loading..." << endl;
                                            clearScreen();
                                            buyer = buyerMenu();
                                        } 
                                        else if (buyer == 3) 
                                        {
                                            viewPrices();
                                            cout << "Press any key to go back! ";
                                            _getch();
                                            cout << endl;
                                            cout << "Loading..." << endl;
                                            clearScreen();
                                            buyer = buyerMenu();
                                        } 
                                        else if (buyer == 4) 
                                        {
                                            isBuyerLoggedIn = false;
                                            clearScreen();
                                            main_menu=displayMainMenu();
                                            cout << "Loading..." << endl;
                                            clearScreen();
                                            break;
                                        } 
                                        else 
                                        {
                                            cout << "Invalid option! Please try again.\n";
                                            clearScreen();
                                            buyer=buyerMenu();
                                            continue;
                                        }
                                    }
                                    break;
                                }
                            }

                            if (!found) 
                            {
                                cout << "Invalid credentials! Try again." << endl;
                                clearScreen();
                            }
                            break;
                        }
                        break;
                    }
                }
                else if (login == 3) 
                {
                    clearScreen();
                    break; 
                } 
                else 
                {
                    cout << "Invalid Option. Please try Again.";
                    clearScreen();
                    login=loginMenu();
                    continue;
                }
                break;
            }
        }
            else if (main_menu == 3) 
            {
                clearScreen();
                exitApp();
            } 
            else 
            {
                cout << "Invalid option! Please try again.\n";
                clearScreen();
            }  
        }
    }

void displayHeader() 
{
    cout << "       |######      |###      |##  ##            |###      |##    ##    |######     |##     ##    |###    |##       /######        |###    |######   |######" << endl;
    cout << "       |##   ##    /## ##     |## ##            /## ##     |###   ##      |##       |###   ###   /## ##   |##      |##            /## ##   |##  ##   |##  ##" << endl;
    cout << "       |######    |#######    |####            |#######    |## ## ##      |##       |#### ####  |#######  |##       \\#####       |#######  |######   |######" << endl;
    cout << "       |##        |##   ##    |## ##           |##   ##    |##   ###      |##       |## ### ##  |##   ##  |##           |##      |##   ##  |##       |##    " << endl;
    cout << "       |##        |##   ##    |##  ##          |##   ##    |##    ##    |######     |##  #  ##  |##   ##  |######  |######       |##   ##  |##       |##    " << endl;
    cout << " ------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
    cout << "                                                                   'Qurbani App'                                                                                 " << endl;
    cout << endl << endl;
}

int displayMainMenu()
{
    int choice;
        cout << "\n1. Sign Up\n2. Login\n3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        return choice;
}

void exitApp()
{
    int option;

    cout<<"Are you sure to exit app? ";
    cout<<"\n\t 1)Yes \t 2)No \n"<<endl;
    cout<<"Choose option: ";
    cin>>option;
    cout<<"Loading...";
    if(option==1)
    {
        clearScreen();
        cout<<"Exiting App...";
        Sleep(2000);
        system("cls");
        exit(0);
    }
    else if(option==2)
    {
        clearScreen();
        displayMainMenu();
        cout<<"Loading..."<<endl;
    }
    else
    {
        cout<<"\nInvalid Option! Try again.\n";
        clearScreen();
        exitApp();
    }
}

int signupMenu()
{
    int choice;
        cout << "\n1. Sign Up as Admin(It will delete previous account)\n2. Sign Up as User\n3. Back to Main Menu\n";
        cout << "Choose an option: ";
        cin >> choice;
    return choice;
}

int loginMenu() 
{
    int choice;
        cout << "\n1. Login as Admin\n2. Login as User\n3. Back to Main Menu\n";
        cout << "Choose an option: ";
        cin >> choice;
        return choice;
}

int adminMenu()
{
    int choice;
    cout << "\nAdmin Menu:\n";
    cout << "1. View User Accounts\n";
    cout << "2. Delete User Accounts\n";
    cout << "3. View Stock\n";
    cout << "4. View Sales Reports\n";
    cout << "5. View Prices\n";
    cout << "6. Update Prices\n";
    cout << "7. Delete Stock\n";
    cout << "8. Logout\n";
    cout << "Choose an option: ";
    cin >> choice;

    return choice;      
}

int userlogin()
{
    int choice;
        cout << "\nWho are you?\n1. Seller\n2. Buyer\n";
        cout << "Choose an option: ";
        cin >> choice;
        return choice;
}

int usersignup()
{
    int choice;
        cout << "\nSignup as:\n1. Seller\n2. Buyer\n";
        cout << "Choose an option: ";
        cin >> choice;
        return choice;
}

int sellerMenu() 
{
    int choice;
        cout << "\nSeller Menu:\n1. Add Animal\n2. Sell Animal\n3. View Stock\n4. View Sales Summary\n5. View Prices\n6. Logout\n";
        cout << "Choose an option: ";
        cin >> choice;
        return choice;
}

int buyerMenu() 
{
    int choice;
        cout << "\nBuyer Menu:\n1. Buy Animal\n2. View Stock\n3. View Prices\n4. Logout\n";
        cout << "Choose an option: ";
        cin >> choice;
        return choice;
}

void viewUserAccount() 
{
    cout << "\nSeller Accounts:\n";
    if (total_sellers != 0)
    {
        for (int i = 0; i < total_sellers; i++)
        {
            cout << "Seller" << i + 1 << ": " << sellerID[i] << endl;
            cout << "Password: " << sellerPASS[i] << endl;
            cout << endl;
        }
    } 
    else 
    {
        cout << "No seller account registered.\n" << endl;
    }

    cout << "\nBuyer Accounts:\n";
    if (total_buyers != 0) 
    {
        for (int j = 0; j < total_buyers; j++)
        {
            cout << "Username" << j + 1 << ": " << buyerID[j] << endl;
            cout << "Password: " << buyerPASS[j] << endl;
            cout << endl;
        }
    } 
    else 
    {
        cout << "No buyer account registered.\n" << endl;
    }
}

void deleteUserAccount() 
{
    int choice1, choice2, i, j;
    cout << "\nDelete User Account:\n";
    cout << "1. Delete Seller Account\n";
    cout << "2. Delete Buyer Account\n";
    cout << "Choose an option: ";
    cin >> choice1;
    cout << endl << endl;

    if (choice1 == 1)
    {
        if (total_sellers != 0)
        {
            for (i = 0; i < total_sellers; i++)
            {
                cout << "Seller" << i + 1 << ")  " << sellerID[i] << endl;
            }

            cout << "Choose an option: ";
            cin >> choice2;
            j = choice2 - 1;

            sellerID[j]="";
            sellerPASS[j]="";
            RegisteredSeller[j]=false;

            for (int k = j; k < total_sellers - 1; k++)
            {
                sellerID[k] = sellerID[k + 1];
                sellerPASS[k] = sellerPASS[k + 1];
                RegisteredSeller[k] = RegisteredSeller[k + 1];
            }

            total_sellers--;
            cout << "Seller account deleted successfully!\n";
        }
        else
        {
            cout << "No seller account registered.\n";
        }
    }
    else if (choice1 == 2)
    {
        if (total_buyers != 0)
        {
            for (i = 0; i < total_buyers; i++)
            {
                cout << "Buyer" << i + 1 << ")  " << buyerID[i] << endl;
            }

            cout << "Choose an option: ";
            cin >> choice2;
            j = choice2 - 1;

            buyerID[j]="";
            buyerPASS[j]="";
            RegisteredBuyer[j]=false;

            for (int k = j; k < total_buyers - 1; k++)
            {
                buyerID[k] = buyerID[k + 1];
                buyerPASS[k] = buyerPASS[k + 1];
                RegisteredBuyer[k] = RegisteredBuyer[k + 1];
            }

            total_buyers--;
            cout << "Buyer account deleted successfully!\n";
        }
        else
        {
            cout << "No buyer account registered.\n";
        }
    }
    else
    {
        cout << "Invalid option! Please try again.\n";
    }
}

void addAnimal() 
{
    int species, age, gender, qty;

    while (true) 
    {
        cout << "\nSelect Animal Type to Add Stock:\n";
        for (int i = 0; i < animalTypes; i++) 
        {
            cout << i + 1 << ". " << animalNames[i] << endl;
        }

        cout << "Choose an animal type: ";
        cin >> species;

        if (species > 0 && species <= animalTypes) 
        {
            species--;
            break;
        } 
        else 
        {
            cout << "Invalid animal type! Please try again.\n";
        }
    }

    while (true) 
    {
        cout << "Select Age Level:\n";
        for (int i = 0; i < ageLevels; i++) 
        {
            cout << i + 1 << ". " << ageNames[i] << endl;
        }

        cout << "Choose age level: ";
        cin >> age;

        if (age > 0 && age <= ageLevels) 
        {
            age--;
            break;
        } 
        else 
        {
            cout << "Invalid age! Please try again.\n";
        }
    }

    while (true) 
    {
        cout << "Select Gender:\n1. Female\n2. Male\nChoose gender: ";
        cin >> gender;

        if (gender > 0 && gender <= genders) 
        {
            gender--;
            break;
        } 
        else 
        {
            cout << "Invalid gender! Please try again.\n";
        }
    }

    cout << "Enter quantity to add: ";
    cin >> qty;
    stock[species][age][gender] += qty;
    cout << qty << " " << animalNames[species] << " (" << ageNames[age] << ", " << genderNames[gender] << ") added to stock.\n";
}

void sellAnimal() 
{
    int species, age, gender, qty;

    while (true) 
    {
        cout << "\nSelect Animal Type to Sell:\n";
        for (int i = 0; i < animalTypes; i++) 
        {
            cout << i + 1 << ". " << animalNames[i] << endl;
        }

        cout << "Choose an animal type: ";
        cin >> species;

        if (species > 0 && species <= animalTypes) 
        {
            species--;  
            break;  
        } 
        else 
        {
            cout << "Invalid animal type! Please try again.\n";
        }
    }

    while (true) 
    {
        cout << "Select Age Level:\n";
        for (int i = 0; i < ageLevels; i++) 
        {
            cout << i + 1 << ". " << ageNames[i] << endl;
        }

        cout << "Choose age level: ";
        cin >> age;

        if (age > 0 && age <= ageLevels) 
        {
            age--;  
            break;  
        } 
        else 
        {
            cout << "Invalid age! Please try again.\n";
        }
    }

    while (true) 
    {
        cout << "Select Gender:\n1. Female\n2. Male\nChoose gender: ";
        cin >> gender;

        if (gender > 0 && gender <= genders) 
        {
            gender--;  
            break;  
        } 
        else 
        {
            cout << "Invalid gender! Please try again.\n";
        }
    }

    while (true) 
    {
        cout << "Enter quantity to sell: ";
        cin >> qty;

        if (stock[species][age][gender] == 0) 
        {
            cout << "No stock available for " << animalNames[species] << " (" << ageNames[age] << ", " << genderNames[gender] << ").\n";
            break;  
        }
        else if (qty <= stock[species][age][gender]) 
        {
            double revenue = qty * animalPrices[species][age][gender];
            stock[species][age][gender] -= qty;
            soldStock[species][age][gender] += qty;
            totalBalance += revenue;

            cout << "Sold " << qty << " " << animalNames[species] << " ("  << ageNames[age] << ", " << genderNames[gender] << ") for Rs."  << revenue << ".\n";

            break;
        } 
        else 
        {
            cout << "Not enough stock to sell! \nOnly " << stock[species][age][gender] << " available.\n";
        }
    }
}

void deleteAnimal() 
{
    int species, age, gender, qty;

    while (true) 
    {
        cout << "\nSelect Animal Type to Delete:\n";
        for (int i = 0; i < animalTypes; i++) 
        {
            cout << i + 1 << ". " << animalNames[i] << endl;
        }

        cout << "Choose an animal type: ";
        cin >> species;

        if (species > 0 && species <= animalTypes) 
        {
            species--;  
            break;  
        } 
        else 
        {
            cout << "Invalid animal type! Please try again.\n";
        }
    }

    while (true) 
    {
        cout << "Select Age Level:\n";
        for (int i = 0; i < ageLevels; i++) 
        {
            cout << i + 1 << ". " << ageNames[i] << endl;
        }

        cout << "Choose age level: ";
        cin >> age;

        if (age > 0 && age <= ageLevels) 
        {
            age--;  
            break;  
        } 
        else 
        {
            cout << "Invalid age! Please try again.\n";
        }
    }

    while (true) 
    {
        cout << "Select Gender:\n1. Female\n2. Male\nChoose gender: ";
        cin >> gender;

        if (gender > 0 && gender <= genders) 
        {
            gender--;  
            break;  
        } 
        else 
        {
            cout << "Invalid gender! Please try again.\n";
        }
    }

    while (true) 
    {
        cout << "Enter quantity to delete: ";
        cin >> qty;

        if (stock[species][age][gender] == 0) 
        {
            cout << "No stock available for " << animalNames[species] << " (" << ageNames[age] << ", " << genderNames[gender] << ").\n";
            break;  
        }
        else if (qty <= stock[species][age][gender]) 
        {
            stock[species][age][gender] -= qty;

            cout << qty << " " << animalNames[species] << " ("  << ageNames[age] << ", " << genderNames[gender] << ") deleted successfully.\n";

            break;
        } 
        else 
        {
            cout << "Not enough stock! \nOnly " << stock[species][age][gender] << " available.\n";
        }
    }
}

void viewAnimals() 
{
    int maleTotal, femaleTotal;
    int overallTotal=0;

    cout << "\nAnimal Stock Table:\n";
    cout << left << setw(15) << "Animal Type" << setw(15) << "Age Level" << setw(15) << "Gender" << "Quantity\n";
    cout << "-------------------------------------------------------------\n";
    
    for (int i = 0; i < animalTypes; i++) 
    {
        for (int j = 0; j < ageLevels; j++) 
        {
            for (int k = 0; k < genders; k++) 
            {
                cout << left << setw(15) << animalNames[i] << setw(15) << ageNames[j] << setw(15) << genderNames[k] << stock[i][j][k] << endl;
                overallTotal += stock[i][j][k]; 
                cout << "-------------------------------------------------------------\n";
            }
        }
    }

      cout << "\nSummary of Stock:\n";
    cout << left << setw(15) << "Animal Type" << setw(10) << "Gender" << "Total Quantity\n";
    cout << "------------------------------------------------\n";

    for (int i = 0; i < animalTypes; i++) 
    {
        maleTotal = 0, femaleTotal = 0;
        for (int j = 0; j < ageLevels; j++) 
        {
            femaleTotal += stock[i][j][0];   
            maleTotal += stock[i][j][1]; 
        }

        cout << left << setw(10) << animalNames[i] << setw(15) << genderNames[0] << femaleTotal << endl;
        cout << left << setw(10) << animalNames[i] << setw(15) << genderNames[1] << maleTotal << endl;
    }

    cout << "\nOverall Total Number of Animals in Stock: " << overallTotal << endl;
}

void viewPrices()
{
    cout << "\nAnimal Prices Table:\n";
    cout << left << setw(15) << "Animal Type" << setw(15) << "Age Level" << setw(15) << "Gender" << "Price(in Rs.)\n";
    cout << "-------------------------------------------------------------\n";
    
    for (int i = 0; i < animalTypes; i++) 
    {
        for (int j = 0; j < ageLevels; j++) 
        {
            for (int k = 0; k < genders; k++) 
            {
                cout << left << setw(15) << animalNames[i] << setw(15) << ageNames[j] << setw(15) << genderNames[k] <<"Rs."<< animalPrices[i][j][k] << endl; 
                cout << "-------------------------------------------------------------\n";
            }
        }
    }
}

void updatePrices()
{
    int species, age, gender, price;

    while (true) 
    {
        cout << "\nSelect Animal Type to Sell:\n";
        for (int i = 0; i < animalTypes; i++) 
        {
            cout << i + 1 << ". " << animalNames[i] << endl;
        }

        cout << "Choose an animal type: ";
        cin >> species;

        if (species > 0 && species <= animalTypes) 
        {
            species--;  
            break;  
        } 
        else 
        {
            cout << "Invalid animal type! Please try again.\n";
        }
    }

    while (true) 
    {
        cout << "Select Age Level:\n";
        for (int i = 0; i < ageLevels; i++) 
        {
            cout << i + 1 << ". " << ageNames[i] << endl;
        }

        cout << "Choose age level: ";
        cin >> age;

        if (age > 0 && age <= ageLevels) 
        {
            age--;  
            break;  
        } 
        else 
        {
            cout << "Invalid age! Please try again.\n";
        }
    }

    while (true) 
    {
        cout << "Select Gender:\n1. Female\n2. Male\nChoose gender: ";
        cin >> gender;

        if (gender > 0 && gender <= genders) 
        {
            gender--;  
            break;  
        } 
        else 
        {
            cout << "Invalid gender! Please try again.\n";
        }
    }
    
        cout << "Enter new price: ";
        cin >> price;

    animalPrices[species][age][gender]=price;

    cout << "\nPrice of " << animalNames[species] << "(" <<ageNames[age] << "," << genderNames[gender] << ")" << "updated successfully.\n";

}

void buyAnimal() 
{
    int species, age, gender, qty;

    while (true) 
    {
        cout << "\nSelect Animal to Buy:\n";
        for (int i = 0; i < animalTypes; i++)
        {
            cout << i + 1 << ". " << animalNames[i] << endl;
        }

        cout << "Choose an animal: ";
        cin >> species;

        if (species > 0 && species <= animalTypes) 
        {
            species--;
            break;
        } 
        else 
        {
            cout << "Invalid animal type! Please try again.\n";
        }
    }

    while (true) 
    {
        cout << "Select Age Level:\n";
        for (int i = 0; i < ageLevels; i++) 
        {
            cout << i + 1 << ". " << ageNames[i] << endl;
        }

        cout << "Choose age level: ";
        cin >> age;

        if (age > 0 && age <= ageLevels) 
        {
            age--;
            break;
        } 
        else 
        {
            cout << "Invalid age! Please try again.\n";
        }
    }

    while (true) 
    {
        cout << "Select Gender:\n1. Male\n2. Female\nChoose gender: ";
        cin >> gender;

        if (gender > 0 && gender <= genders) 
        {
            gender--;
            cout<<"Price of 1 " << animalNames[species] << " (" << ageNames[age] << ", " << genderNames[gender] << "). is: " << animalPrices[species][age][gender] << endl << endl;
            break;
        } 
        else 
        {
            cout << "Invalid gender! Please try again.\n";
        }
    }

    while (true) 
    {
        cout << "Enter quantity to buy: ";
        cin >> qty;

        if (stock[species][age][gender] == 0) 
        {
            cout << "No stock available for " << animalNames[species] << " (" << ageNames[age] << ", " << genderNames[gender] << ").\n";
            break;  
        }
        else if (qty <= stock[species][age][gender]) 
        {
            double totalCost = qty * animalPrices[species][age][gender];
            stock[species][age][gender] -= qty;
            soldStock[species][age][gender] += qty;
            totalBalance += totalCost;

            cout << endl << "You bought " << qty << " " << animalNames[species] << " ("  << ageNames[age] << ", " << genderNames[gender] << ") for $"  << totalCost << ".\n";
            break;
        } 
        else 
        {
            cout << "Not enough stock available! Only " << stock[species][age][gender] << " available.\n";
        }
    }
}

void viewSalesSummary() 
{
    int totalSold = 0;
    cout << "\nSales Summary:\n";
    cout << left << setw(15) << "Animal Type" << setw(15) << "Age Level" << setw(15) << "Gender" << "Quantity Sold\n";
    cout << "-------------------------------------------------------------\n";
    
    for (int i = 0; i < animalTypes; i++) 
    {
        for (int j = 0; j < ageLevels; j++) 
        {
            for (int k = 0; k < genders; k++) 
            {
                if (soldStock[i][j][k] > 0) 
                {
                    cout << left << setw(15) << animalNames[i] << setw(15) << ageNames[j] << setw(15) << genderNames[k] << soldStock[i][j][k] << endl;
                    totalSold += soldStock[i][j][k];
                }
            }
        }
    }

    cout << "\nTotal Animals Sold: " << totalSold << endl;
    cout << "Current Balance: Rs." << totalBalance << endl;
}

bool isValidPass(string input)
{
    bool hasAlpha = false;
    bool hasNum = false;
    bool noSpace = false;

    for(int i=0; input[i]!='\0'; i++)
    {
        char c = input[i];

        if ( (c>='A' && c<='Z') || (c>='a' && c<='z') ) 
        {
            hasAlpha=true;
        }
        if (c>= '0' && c<='9') 
        {
            hasNum=true;
        }
        if(!(c == ' '))
        {
            noSpace = true;
        }
    }

    if(hasAlpha && hasNum && noSpace)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isValidName(string input)
{
    for(int i=0; input[i]!='\0'; i++)
    {
        char c = input[i];
        if( !( (c>='A' && c<='Z') || (c>='a' && c<='z') ) )
        {
            return false;
        }
        if((c ==' ') || (c>= '0' && c<='9'))
        {
            return false;
        }
    }

    return true;
}

void clearScreen() 
{
    Sleep(1000);   
    system("cls"); 
    displayHeader();
}