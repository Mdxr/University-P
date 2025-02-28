#include <iostream>
using namespace std;

class Vehicle{
    private:
        int modelNo;
        string color, licensePlateNo, type;
    public:
        Vehicle();
        Vehicle(string lNo, int modelNo, string color, string type);
        // i think no argument && default constructors are same so....

        //setters
        void setModelNo(int modelNo);
        void setLicensePlateNo(string lNo);
        void setColor(string color);
        void setType(string type);

        //getters
        int getModelNo();
        string getLicensePlateNo();
        string getColor();
        string getType();

        //other methods
        void RegisterVehicle(int &modelNo, string &licenseNo, string &color, string &type, int size, Vehicle vehicles[]);
        void UpdateVehicle(int &modelNo, string &color, string &type);
        void DeleteVehicle(Vehicle vehicles[], int size, int index);
        void SearchVehicle();
};

//constructors
Vehicle::Vehicle(){
    modelNo = 0;
    color = licensePlateNo = type = "";
}
Vehicle::Vehicle(string lNo, int modelNo, string color, string type){
    licensePlateNo = lNo;
    this->modelNo = modelNo;
    this->color = color;
    this->type = type;
}

//setters
void Vehicle::setModelNo(int modelNo){
    this->modelNo = modelNo;
}
void Vehicle::setLicensePlateNo(string lNo){
    licensePlateNo = lNo;
}
void Vehicle::setColor(string color){
    this->color = color;
}
void Vehicle::setType(string type){
    this->type = type;
}

//getters
string Vehicle::getColor(){
    return color;
}
string Vehicle::getLicensePlateNo(){
    return licensePlateNo;
}
int Vehicle::getModelNo(){
    return modelNo;
}
string Vehicle::getType(){
    return type;
}

//misc methods
void Vehicle::RegisterVehicle(int &modelNo, string &licenseNo, string &color, string &type, int size, Vehicle vehicles[]){
    //passed these by refrence as almost all of these variables will be used in update method too, so it's better to use same variables to temporary store the data

    bool registered = false;
    cout << "Enter Vehicle License Plate No : ";
    cin >> licenseNo;

    for(int i = 0; i < size; i++){
        if(vehicles[i].licensePlateNo == licenseNo){
            cout << "Vehicle has already been registered!\n";
            registered = true;
            return;
        }
    }
    if(!registered){
        cout << "Enter Vehicle Model No : ";
        cin >> modelNo;
        cout << "Enter Vehicle Color : ";
        cin >> color;
        cout << "Enter Vehicle Type : ";
        cin >> type;

        setModelNo(modelNo);
        setLicensePlateNo(licenseNo);
        setColor(color);
        setType(type);

        cout << "Vehicle Registered Successfully!\n";
    }
}

void Vehicle::UpdateVehicle(int &modelNo, string &color, string &type){
    cout << "---------------------------------------------\nPrevious Data :\nLicense No \tModel No \tColor \tType\n---------------------------------------------\n";
    cout << this->licensePlateNo << "\t\t" << this->modelNo << "\t\t" << this->color << "\t" << this->type << "\n---------------------------------------------\n";
    cout << "Enter New Data: \n";
    cout << "New Vehicle Model No : ";
    cin >> modelNo;
    cout << "New Vehicle Color : ";
    cin >> color;
    cout << "New Vehicle Type : ";
    cin >> type;

    setModelNo(modelNo);
    setColor(color);
    setType(type);

    cout << "Vehicle Updated Successfully!\n";
}

void Vehicle::DeleteVehicle(Vehicle vehicles[], int size, int index){
    for(int i = index; i < size; i++){
        vehicles[i] = vehicles[i+1];
    }
    cout << "Vehicle Deleted Successfully!\n";
}

void Vehicle::SearchVehicle(){
    cout << "License No \tModel No \tColor \tType\n---------------------------------------------\n";
    cout << this->licensePlateNo << "\t\t" << this->modelNo << "\t\t" << this->color << "\t" << this->type << "\n---------------------------------------------\n";
}

// registered vehicles array size
int registeredArraySize(Vehicle vehs[]){
    //using a little trick to determine the size of 'only regisreted vehicles' the array.
    int size = 0;
    while(vehs[size].getModelNo() != 0){
        size++;
    }
    return size;
}

// i made this for testing of register and update vehicle methods, but keeping it now...
void displayAllVehicles(Vehicle vehs[], int size){
    cout << "License No \tModel No \tColor \tType\n---------------------------------------------\n";
    for(int i = 0; i < size; i++){
        cout << vehs[i].getLicensePlateNo() << "\t\t" << vehs[i].getModelNo() << "\t\t" << vehs[i].getColor() << "\t" << vehs[i].getType() << "\n---------------------------------------------\n";
    }
}

int main(){
    // temp variables to hold data for register, update && some other methods
    int modelNo;
    string licenseNo, color, type;

    // array to hold Vehicle objects
    Vehicle vehicles[100] = {
        {"MX-205", 2020, "red", "SUV"},
        {"IS-164", 1996, "black", "Sedan"},
        {"TR-235", 2025, "grey", "Truck"},
    };

    int choice; 
    do{
        cout << "1. Register Vehicle\n2. Update Vehicle\n3. Search Vehicle\n4. Delete Vehicle\n5. Display Vehicles\n6. Exit\n-> Enter choice : ";
        cin >> choice;
        bool found = false; // for update, delete && search
        switch(choice){
            case 1:
                // calling register method from the next unassigned object (vehicles[regSize]) from array
                vehicles[registeredArraySize(vehicles)].RegisterVehicle(modelNo, licenseNo, color, type, registeredArraySize(vehicles), vehicles);
                break;
            case 2:
                // checking if the vehicle exists
                found = false;
                cout << "Enter License Plate No : ";
                cin >> licenseNo;
                for(int i = 0; i < registeredArraySize(vehicles); i++){
                    if(licenseNo == vehicles[i].getLicensePlateNo()){
                        vehicles[i].UpdateVehicle(modelNo, color, type);
                        found = true;
                        break;
                    }
                }
                if(!found){ cout << "Vehicle not found!\n"; }
                break;
            case 3:
                found = false;
                cout << "Enter License Plate No : ";
                cin >> licenseNo;
                for(int i = 0; i < registeredArraySize(vehicles); i++){
                    if(licenseNo == vehicles[i].getLicensePlateNo()){
                        vehicles[i].SearchVehicle();
                        found = true;
                        break;
                    }
                }
                if(!found){ cout << "Vehicle not found!\n"; }
                break;
            case 5:
                displayAllVehicles(vehicles, registeredArraySize(vehicles));
                break;
            case 6:
                cout << "Exited!\n";
                break;
            default:
                cout << "Invalid Choice, try again!\n";
        }
    } while(choice != 6);   
}
