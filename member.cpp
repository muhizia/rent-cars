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
bool member::login(customer &user, const std::string *username, const std::string *password)
{
    int id;
    std::string line;
    std::ifstream fin;
    std::stringstream to_int;
    bool returnvalue = false;
    if(username->length()<=0 || password->length()<=0)
        return returnvalue;
    fin.open("users.txt");
    //check if user exists.
    while (fin) {
        // Read a Line from File
        std::getline(fin, line);
        std::stringstream iss(line);
        std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                         std::istream_iterator<std::string>());
        if(results.at(3)==*username && results.at(4)==*password)
        {
            to_int << results.at(0);
            to_int >> id;
            member m(results.at(1), results.at(2), id);
            user = m;
            returnvalue = true;
            break;
        }
    }
    fin.close();
    return returnvalue;
}
bool member::logout()
{
    return false;
}
void member::editProfile(customer &cstm, std::string &fn, std::string &ln, std::string &dob)
{
    cstm.setLastName(ln);
    cstm.setFirstName(fn);
    cstm.setDof(dob);
//    cstm
}
void member::viewProfile(customer &cg)
{
    std::cout<<"Firstname: " << cg.getFirstName() <<std::endl;
    std::cout<<"Lastname: " << cg.getLastName() <<std::endl;
    std::cout<<"Lastname: " << cg.getDof() <<std::endl;
}
bool member::signUp(customer &user, std::string *username, std::string *password, std::string *fname, std::string *lname, std::string *dof)
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
void member::calcAmount(std::vector<car> &cars)
{
    customer::calcAmount(cars);
}
std::string member::toString()
{
    return customer::getFirstName() + " " + customer::getLastName();
}
member::~member(){}
