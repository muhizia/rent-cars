//
//  member.cpp
//  CarRent
//
//  Created by Muhizi Aristide on 08/01/2021.
//

#include "header/member.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<car> *member::getRentedCars()
{
    return customer::getRentedCars();
}
void member::getRentedCars(std::vector<car> &cars, int customer_id)
{
    if(customer::getRentedCars()!= 0)
        cars.insert(std::end(cars), std::begin(*customer::getRentedCars()), std::end(*customer::getRentedCars()));
    else
        cars = {};
}
void member::rentCar(car c)
{
    customer::rentCar(c);
}
void member::login(customer &user, const std::string *username, const std::string *password)
{
    int id;
    std::string line;
    std::ifstream fin;
    std::stringstream to_int;
    fin.open("users.txt");
    //check if user exists.
    while (fin) {
        // Read a Line from File
        std::getline(fin, line);
        std::stringstream iss(line);
        std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                         std::istream_iterator<std::string>());
        std::cout<<results.at(1)<< " " <<results.at(2)<<" " << results.at(0)<<std::endl;
        if(results.at(3)==*username && results.at(4)==*password)
        {
            to_int << results.at(0);
            to_int >> id;
            member m(results.at(1), results.at(2), id);
            user = m;
            break;
        }
    }
    fin.close();
}
bool member::logout()
{
    return false;
}
bool member::editProfile()
{
    return false;
}
void member::viewProfile()
{
    
}
bool member::signUp(std::string *username, std::string *password, std::string *fname, std::string *lname, std::string *dof)
{
    if(isExists(username))
    {
        return false;
    }
    else
    {
        int ID = 0;
        std::string line = "0";
        std::ifstream fin;
        std::stringstream ss;
        fin.open("lastId.txt");
        //check if user exists.
        while (fin) {
            // Read a Line from File
            std::getline(fin, line);
        }
        fin.close();
        
        ss << line;
        ss >> ID;
        ID++;
        std::ofstream fout;
        fout.open("users.txt", std::ios::in|std::ios::out|std::ios::app);
        // Execute a loop If file successfully opened
        while (fout)
        {
            // Write line in file
            fout <<ID <<" " << *fname <<" " << *lname <<" " << *username <<" " << *password << std::endl;
            break;
        }
        // Close the File
        fout.close();
        
        fout.open("lastId.txt");
        fout << ID;
        fout.close();
        std::cout<<"The user created\n" <<ID <<" " << *fname <<" " << *lname <<" " << *username <<" " << *password << std::endl;
        return true;
    }
}

bool member::isExists(std::string *username)
{
    std::string line;
    std::ifstream fin;
    fin.open("users.txt");
    //check if user exists.
    while (fin) {
        // Read a Line from File
        std::getline(fin, line);
        // Print line in Console
        std::cout << line << std::endl;
    }
    fin.close();
    return false;
}

std::string member::toString()
{
    return customer::getFirstName() + " " + customer::getLastName();
}
member::~member(){}
