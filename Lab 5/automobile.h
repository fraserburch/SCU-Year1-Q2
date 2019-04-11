#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H
#include <string>
class Automobile
{
public:
    Automobile();
    Automobile(std::string imake, std::string imodel, int iyear, double iprice, int istall);
    bool park(bool lot[], int size);
    std::string getMake(){return make_;}
    std::string getModel(){return model_;}
    int getYear(){return year_;}
    double getPrice(){return price_;}
    int getStall(){return stall_;}
    void setStall(int s){stall_ = s;}
private:
    std::string make_;
    std::string model_;
    int year_;
    double price_;
    int stall_;
};




#endif // AUTOMOBILE_H
