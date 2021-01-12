//
//  car.cpp
//  CarRent
//
//  Created by Muhizi Aristide on 08/01/2021.
//

#include <stdio.h>
#include "header/car.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

car car::getCar(const std::vector<car> &c, const std::string &pN)
{
    std::vector<std::string> crV;
    auto it = c.begin();
    for(it = c.begin();it != c.end(); ++it)
    {
        if(it->_carPlateNo.compare(pN))
        {
            crV.push_back(it->_carMake);
            crV.push_back(it->_carType);
            crV.push_back(it->_carModel);
            crV.push_back(it->_carColour);
            crV.push_back(it->_carPlateNo);
            crV.push_back(std::to_string(it->_carPrice));
            break;
        }
            
    }
    if(it == c.end())
    {
        crV.push_back(NULL);
        crV.push_back(NULL);
        crV.push_back(NULL);
        crV.push_back(NULL);
        crV.push_back(NULL);
        crV.push_back(NULL);
    }
    car cr(crV);
    return cr;
}
std::vector<car> car::getCars()
{
    std::vector<car> cars{};
    std::string line;
    std::ifstream fin;
    
    fin.open("cars.txt");
    // Read a Line from File
    while (std::getline(fin, line)) {
        // spliting the string value
        std::stringstream iss(line);
        std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                         std::istream_iterator<std::string>());
        car c(results);
        cars.push_back(c);
    }
    fin.close();
    return cars;
}
car car::rentCar(const car & c)
{
    return c;
}
std::vector<car> car::searchCar(const std::vector<car> &c, const std::string &pN)
{
    std::vector<car> crV{};
    auto it = c.begin();
    for(it = c.begin();it != c.end(); ++it)
    {
        if(it->_carPlateNo == pN || it->_carColour == pN || it->_carMake == pN || it->_carModel == pN || std::to_string(it->_carPrice) == pN || it->_carType == pN)
        {
            crV.push_back(*it);
        }
            
    }
    return crV;
}

void car::viewCars(std::vector<car> & list)
{
    int i = 0;
    for(auto it = list.begin(); it!=list.end(); ++it)
    {
        i++;
        std::cout<< i <<". "<< it->_carPlateNo << " " << it->_carMake << " " << it->_carType << " " << it->_carColour << " " << it->_carPrice <<std::endl;
    }
}
std::string car::toString()
{
    return "Car make = " + _carMake + " Car type = " + _carType + " Car model = " + _carModel + " Car colour = " + _carColour + " Car plate = " + _carPlateNo + " Car price = " + std::to_string (_carPrice);
}
car::~car(){}
