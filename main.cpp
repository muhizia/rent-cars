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


void login(customer *cstm)
{
    std::string username;
    std::string password;
    
    std::cout << "Enter\nUsername: >>";
    std::cin>>username;
    std::cout << "Password: >>";
    std::cin>>password;
    cstm->login(*cstm, &username, &password);
}
void signUp(customer *cstm)
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
    cstm->signUp(&username, &password, &fname, &lname, &dob);
}
void menu(int &choice)
{
    
    std::cout << "Choose from the menu\n";
    std::cout << "\n1. View cars: ";
    std::cout << "\n2. Search cars: ";
    if(choice!=3)
    {
        std::cout << "\n3. Rented cars: ";
        std::cout << "\n4. Profile: ";
        std::cout << "\n5. Logout: \n";
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

int main(int argc, const char * argv[]) {
    int choice = 0;
    int customerObj;
    customer* cg;
    customerFactory cstmF;
    car c;
    std::cout << "Choose from options\n\n";
    std::cout << "1. Login \n2. Register\n3. Continue as a guest\n>>";
    std::cin>>choice;
    switch(choice)
    {
        case 1:
            customerObj = 1;
            cg = cstmF.getCustomer(customerObj);
            login(cg);
            break;
        case 2:
            customerObj = 1;
            cg = cstmF.getCustomer(customerObj);
            signUp(cg);
            break;
        default:
            customerObj = 2;
            cg = cstmF.getCustomer(customerObj);//do something;
            break;
    }
    menu(choice);
    std::vector<car> searchV{};
    auto list = c.getCars();
    if(choice == 1)
    {
        std::cout<<"Choose from the list\n";
        c.viewCars(list);
        std::cout<<"0. back\n";
    }
    else if(choice == 2)
    {
        search(list, searchV, c);
        std::cout<<"-------------------------------\n";
        std::cout<<"Choose from the list\n";
        c.viewCars(searchV);
        std::cout<<"0. back\n";
        std::cout<<"-------------------------------\n";
    }
    else if(choice == 3)
    {
        //View rented cars
    }
    else if(choice == 4)
    {
        std::cout<<"Firstname: " << cg->getFirstName() <<std::endl;
        std::cout<<"Lastname: " << cg->getLastName() <<std::endl;
    }
//    rentCar(choice);
    
    
    delete cg;
    return 0;
}
