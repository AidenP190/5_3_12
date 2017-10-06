/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: aparsons
 *
 * Created on October 2, 2017, 12:50 PM
 */

#include <iostream> 

using namespace std;

class FarmAnimal{ 
public:
    FarmAnimal() {}
    FarmAnimal(double water_consumption) : waterConsumption(water_consumption) {}
    double getWaterConsumption(){return waterConsumption;}
    void setWaterConsumption(double water_consumption){this->waterConsumption = water_consumption;}
private:
    double waterConsumption;
};

class ConsumptionAccumulator {
public:
    ConsumptionAccumulator();
    double getTotalConsumption();
    void addConsumption(FarmAnimal animal);
private:
    double total_consumption;
};
ConsumptionAccumulator::ConsumptionAccumulator() : 
    total_consumption(0)
{ 

}
double ConsumptionAccumulator::getTotalConsumption() {
    return total_consumption; 
}
void ConsumptionAccumulator::addConsumption(FarmAnimal animal) {
    total_consumption += animal.getWaterConsumption();
}

class Cow:public FarmAnimal
{
public:
    Cow(double weight)
    {
        FarmAnimal::setWaterConsumption((weight * 8.6)/100);
    }
};

class Horse:public FarmAnimal
{
public:
    Horse(double weight)
    {
        weight = (weight * 6.8) / 100;
        FarmAnimal::setWaterConsumption(weight);
    }
};

class Sheep:public FarmAnimal
{
public:
    Sheep(double weight)
    {
        FarmAnimal::setWaterConsumption((weight * 1.1)/10);
    }
};

int main() {
    ConsumptionAccumulator accumulator;
    double weight = 0;
    string animal;
    do
    {
        cout<<"Enter Animal then Weight" <<endl;
    getline(cin, animal);
    if(1 == sscanf(animal.c_str(),"Cow %lf", &weight))
    {
        Cow cow(weight);
        accumulator.addConsumption(cow);
        cout<<"Cow Added!"<<endl;
        cout<<"-----------------"<<endl;
    }
    else if(1 == sscanf(animal.c_str(),"Horse %lf", &weight)) 
    {
        Horse horse(weight);
        accumulator.addConsumption(horse);
        cout<<"Horse Added!"<<endl;
        cout<<"-----------------"<<endl;
    }
    else if(1 == sscanf(animal.c_str(),"Sheep %lf", &weight))
    {
        Sheep sheep(weight);
        accumulator.addConsumption(sheep);
        cout<<"Sheep Added!"<<endl;
        cout<<"-----------------"<<endl;
    }
    else
    {
        cout<<"No Match"<<endl;
        cout<<"------------"<<endl;
    }
    }
    while(animal != "");
    
    cout << accumulator.getTotalConsumption();
}

