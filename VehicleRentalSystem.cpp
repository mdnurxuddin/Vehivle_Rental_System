#include<iostream>
#include<string>
using namespace std;
// Base class

class Vehicle {
private:
string registrationNumber;
string brand;

protected:
float rentalRate;

public:
Vehicle(string regNum,string br,float rate) : registrationNumber(regNum), brand(br),
rentalRate(rate){}

virtual void displayDetails(){
cout<<"Registration Number: "<<registrationNumber<<endl;
cout<<"Brand: " <<brand<<endl;
cout<<"Rental Rate: $" <<rentalRate<<endl;
}


};
// Derived class Car

class Car : public Vehicle
{

private:
int numberOfDoors;

public:
Car(string regNum, string br, float rate, int doors) : Vehicle(regNum, br,
rate),numberOfDoors(doors){}

void displayDetails(){

Vehicle::displayDetails();
cout<<"Number of Doors: "<<numberOfDoors<<endl;
}


float calculateRentalCost(int days){
    return days*rentalRate;
}

};
// Derived class Bike

class Bike : public Vehicle {

private:
bool isElectric;

public:
Bike(string regNum,string br,float rate,bool electric) : Vehicle(regNum, br,
rate),isElectric(electric){}

void displayDetails(){

Vehicle::displayDetails();
cout<<"Is Electric: "<<(isElectric ? "Yes" : "No")<<endl;
}

float calculateRentalCost(int hours){

return hours*(rentalRate / 24);

}

};

//-----------------------//

int main() {
Car c1("RH1234", "Tesla", 50.0, 4);
cout<<"Car Details:"<<endl;

c1.displayDetails();
cout << "Car Rental Cost: " <<c1.calculateRentalCost(5) <<endl<<endl;
Bike b1("TNE5678", "Honda", 30.0, true);
cout << "Bike Details:" << endl;

b1.displayDetails();
cout << "Bike Rental Cost: " << b1.calculateRentalCost(10)<<endl;

return 0;
}
