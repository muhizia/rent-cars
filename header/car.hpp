//
//  Header.h
//  CarRent
//
//  Created by Muhizi Aristide on 08/01/2021.
//

#ifndef Header_h
#define Header_h

#include <string>
#include <vector>

const std::string _default = "_default";
const float _dp = 0.0;
class car
{
private:
    std::string _carMake;
    std::string _carType;
    std::string _carModel;
    std::string _carColour;
    std::string _carPlateNo;
    float _carPrice;
    
public:
    car(): _carMake(_default), _carType(_default), _carModel(_default), _carColour(_default), _carPlateNo(_default), _carPrice(_dp){}
    car(std::vector<std::string> &cr):_carMake(cr.at(1)), _carType(cr.at(2)), _carModel(cr.at(3)), _carColour(cr.at(4)), _carPlateNo(cr.at(5)){
        _carPrice = atof(cr.at(6).c_str());
    }
    car(std::string &cM, std::string &cT, std::string &cMd, std::string &cC, std::string &cP, float &cPr):_carMake(cM), _carType(cT), _carModel(cMd), _carColour(cC), _carPlateNo(cP), _carPrice(cPr){}
    ~car();
    car getCar(const std::vector<car> &, const std::string &);
    std::vector<car> getCars();
    std::vector<car> searchCar(const std::vector<car> &, const std::string &);
    
    car rentCar(const car & c);
    void viewCars(std::vector<car> &);
    /* admin side **/
    void deleteCar(const car & c);
    void deleteCar(const std::string & pN);
    void registerCar(const car & c);
    void registerCar(std::string _carMake,
                     std::string _carType,
                     std::string _carModel,
                     std::string _carColour,
                     std::string _carPlateNo,
                     float _carPrice);
    void editcar(const car & c);
    /* getters and setters **/
    void setPrice(float price);
    
    float getPrice();
    
    std::string getCarMake();
    std::string getCarType();
    std::string getCarModel();
    std::string getCarColour();
    std::string getCarPlateNo();
    
    std::string toString();
};

#endif /* Header_h */
