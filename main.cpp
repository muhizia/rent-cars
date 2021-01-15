//
//  main.cpp
//  CarRent
//
//  Created by Muhizi Aristide on 08/01/2021.
//

#include <iostream>
#include "header/customer.hpp"
#include "header/guest.hpp"
#include "header/member.hpp"
#include "header/car.hpp"
#include "header/customerFactory.hpp"
#include <termios.h>
#include <unistd.h>


void login(customer *cstm, bool &sessionOn)
{
    
    
    std::string username;
    std::string password;
    
    std::cout << "Enter\nUsername: >>";
    std::cin>>username;
    std::cout << "Password: >>";
    std::cin>>password;
    sessionOn = cstm->login(*cstm, &username, &password);
}
void signUp(customer *cstm, bool &sessionOn)
{
    std::string fname;
    std::string lname;
    std::string username;
    std::string password;
    std::string dob;
    
    std::cout << "Enter\n1. Firstname: ";
    std::cin>>fname;
    std::cout << "2. Lastname: >>";
    std::cin>>lname;
    std::cout << "3. Username: >>";
    std::cin>>username;
    std::cout << "4. Password: >>";
    std::cin>>password;
    std::cout << "5. Date of birth: >>";
    std::cin>>dob;
    sessionOn = cstm->signUp(*cstm, &username, &password, &fname, &lname, &dob);
}
void menu(int &choice, const bool sessionOn)
{
    
    std::cout << "Choose from the menu\n";
    std::cout << "\n1. View cars: ";
    std::cout << "\n2. Search cars: ";
    if(sessionOn)
    {
        std::cout << "\n3. Rented cars: ";
        std::cout << "\n4. View profile: ";
        std::cout << "\n5. Edit profile: ";
        std::cout << "\n6. Logout: \n";
    }
    std::cout << "\n>>";
    std::cin>>choice;
}
void search(std::vector<car>& list, std::vector<car>& sch, car& c)
{
    std::string key;
    std::cout << "Search: >>";
    std::cin>>key;
    sch = c.searchCar(list, key);
}
void rentCar(int &key)
{
    std::cout << ">>";
    std::cin>>key;
}
void editProfile(customer *cstm)
{
    std::string fname;
    std::string lname;
    std::string username;
    std::string password;
    std::string dob;
    
    std::cout << "Enter\n1. Firstname: ";
    std::cin>>fname;
    std::cout << "2. Lastname: >>";
    std::cin>>lname;
    std::cout << "5. Date of birth: >>";
    std::cin>>dob;
    
    std::cout<<fname<<" - "<<lname<<" - "<<std::endl;
    cstm->editProfile(*cstm, fname, lname, dob);
}
int chooseCar(std::vector<car> & cars, customer *cstm, int &choice)
{
    if(cars.size()==0)
        return 0;
    std::cout << "Choose a car\n>>";
    std::cin>>choice;
    if(choice <= 0 && choice > cars.size())
        return 0;
    cstm -> rentCar(cars.at(choice - 1));
    return  1;
}
void viewRentedCar(customer *cstm, car &c)
{
    std::vector<car> *crs = cstm->getRentedCars();
    c.viewCars(*crs);
}
void viewProfile(customer *cstm)
{
    cstm->viewProfile(*cstm);
}
void logout(bool &sessionKilled)
{
    sessionKilled = true;
}
int main(int argc, const char * argv[]) {
    int choice = 0;
    bool sessionOn = false;
    bool isApplicationKilled = false;
    int customerObj;
    customer* cg = NULL;
    customerFactory cstmF;
    car c;
    std::cout << "Choose from options\n\n";
    
    while(cg==NULL || (!sessionOn && (choice== 1 || choice == 2)))
    {
        std::cout << "1. Login \n2. Register\n3. Continue as a guest\n>>";
        std::cin>>choice;
        switch(choice)
        {
            case 1:
                customerObj = 1;
                cg = cstmF.getCustomer(customerObj);
                login(cg, sessionOn);
                break;
            case 2:
                customerObj = 1;
                cg = cstmF.getCustomer(customerObj);
                signUp(cg, sessionOn);
                break;
            default:
                customerObj = 2;
                cg = cstmF.getCustomer(customerObj);
                break;
        }
    }
    std::vector<car> searchV{};
    auto list = c.getCars();
    menu(choice, sessionOn);
    while(!isApplicationKilled)
    {
        if(choice == 1) //view all cars
        {
            std::cout<<"Choose from the list\n";
            c.viewCars(list);
            std::cout<<"0. back\n";
            /* choose car to rent **/
            chooseCar(list, cg, choice);
        }
        else if(choice == 2) //search for cars
        {
            search(list, searchV, c);
            std::cout<<"Choose from the list\n";
            c.viewCars(searchV);
            std::cout<<"0. back\n";
            /* choose car to rent **/
            chooseCar(searchV, cg, choice);
        }
        else if(choice == 3) // view rented cars
        {
            //View rented cars
            viewRentedCar(cg, c);
        }
        else if(choice == 4) //view profile
        {
            viewProfile(cg);
        }
        else if(choice == 5) //Edit profile
        {
            editProfile(cg);
        }
//        rentCar(choice);
        std::cout<<"----------------------------------------------\n";
        menu(choice, sessionOn);
    }
    
    delete cg;
    return 0;
}
