/*Name: Lucas Allen, 5004607031, assignment #2 
Description: This program uses the myElevator class to simulate the calling and moving of a set of elevators. 
Input: The only input is a series of integers from an outside .txt file. 
Output: Will output the status of elevators, when they are toggled, which ones are on the right floor, when they're moving, the distance between them, and the closet elevator to the user. 
*/
#include <iostream>
#include <cstdlib> //For Absolute value use abs() ie: abs(-5) will return 5
using namespace std;
//Skeleton Program by Jorge Fonseca
//Class Declaration (Design)

class myElevator {
  private:
     static int count; //keeps track of how many elevators  there are
     int id; //elevator id gets increased every time an elevator is added
     int currentFloor; //location of elevator
     int maxFloor; //Maximum Floor of Elevator
     bool inUse; //Whether elevator is in service
  public:
     myElevator(int = 1, int = 50); //constructor
     int getElevatorID() const;
     int getElevatorCurrentFloor() const;
     int getCount() const;
     bool canReach(int) const;
     void ToggleElevator(); //Toggle elevator on or off
     void printElevator() const; //Print information on elevator
     void moveElevator(int);  //Moves elevator to the requested floor
};
//Class Implementation
int myElevator::count = 0;
myElevator::myElevator(int floor, int max) {
  this->id = count++;
  this->currentFloor = floor;
  this->inUse = false;
  this->maxFloor = max;
}
//This function returns the private member: id; 
//No parameters passed. 
//Returns id.
int myElevator::getElevatorID() const {
  
 return id;
  
}
int myElevator::getElevatorCurrentFloor() const {
  return currentFloor;
}
int myElevator::getCount() const {
  return myElevator::count;
}
bool myElevator::canReach(int floor) const {
  if(maxFloor >= floor) return true;
  else return false;
}

//This function toggles the inUse variable to false if it is true, else it toggles to true and outputs which elevator is now in service. 
//inUse is taken from the myElevstor class
//Void function: no return value. 
void myElevator::ToggleElevator() {

  if(inUse==true){
    inUse=false;

  }else{
    inUse=true;
    cout<<"Toggled Elevator"<<endl;
    
  }
  
}
void myElevator::printElevator() const {
  cout << "Elevator: " << id << " is";
  if(!inUse) cout << " not";
  cout << " in service." << endl;
  cout << "Floor Location: " << currentFloor << endl;
  cout << "Max Floor for Elevator: " << maxFloor << endl;
}

//This function checks if the elevator is in use, if the elevator can reach the requested floor(output an error if not), moves the elevator and updates it's current floor. 
//Parameters passed:floor
//Void function: no return value. 
void myElevator::moveElevator(int floor) {
  bool floorValid;
  bool levelMet; 
  
  
  if(inUse==true){
 

  //Checking if floor is within the MaxFloor range. 
  if(canReach(floor)==true)
  {
    floorValid=true; 

  }else
  {
    floorValid=false; 
    cout<<"Error: Elevator Cannot Reach Floor "<<floor<<"! "<<endl;
    return;
  }
  //If the elevator is already on the right floor do nothing. 
  if(currentFloor==floor)
  {
    return;

  }else{
    cout<<"Elevator Request Recieved for Elevator "<<id<<"."<<endl;
    cout<<"Moving from Floor "<<currentFloor<<" to "<<floor<<"."<<endl;
    //Updating current floor. 
    currentFloor=floor;
    cout<<"Arrived at Floor "<<currentFloor<<"."<<endl;
  }
  }else{
    //if inUse !=true the elevator is not in service. 
    cout<<"elevator "<<id<<" is not in service."<<endl;
  }

 
 }


//This function gets the current floor for two elevators and subtracts them to find the difference in # of floors. 
//Parameters passed: myElevator A, myElevator B, floor.
//Returns the elevator ID of the closest elevator.
int closestElevatorID(myElevator A, myElevator B, int floor) {
    int aDistance; 
    int bDistance;
    int finalADistance; 
    int finalBDistance; 

    //finding distances by finding the floor the elevator is on and subtracting it from the
    //requested floor. 
    aDistance=A.getElevatorCurrentFloor()-floor;
    bDistance=B.getElevatorCurrentFloor()-floor; 

    //converting distances found to absolute value. 
    finalADistance=abs(aDistance); 
    finalBDistance=abs(bDistance);

    if(finalADistance>finalBDistance)
    {
      return B.getElevatorID(); 
    }else{
      return A.getElevatorID();
    }

}
//This function finds the distance(in floors)between two elevators. 
//Parameters passed: myelevator A, my Elevator B
//Returns the distance between the two elevators. 
int elevatorDistance(myElevator A, myElevator B) {
  int elevator_Distance; 

  elevator_Distance= abs(A.getElevatorCurrentFloor()-B.getElevatorCurrentFloor()); //Absolute value used in case of negative numbers. 
  return elevator_Distance; 




} 

// Client Code to test the functionality of the class myElevator
int main() {
  // Input: 1, 10, 11, 4, 2, 3
  int a,b,c,d,e,f;
  cin >> a; cin >> b; cin >> c; cin>> d; cin >> e; cin >> f;
  myElevator A; // declare 1 object of type Elevator
  myElevator B;
  myElevator C(a,b); //a=1,b=10
  C.printElevator();
  C.ToggleElevator();
  C.moveElevator(c);//c=11
  A.ToggleElevator();
  A.moveElevator(d);//d=4
  B.moveElevator(e);//e=2
  B.ToggleElevator();
  A.printElevator();
  B.printElevator();
  cout << "Closest Elevator to Floor "<< f << " is Elevator ID: "
       << closestElevatorID(A,B, f) << endl; //f=3
  cout << "Elevator Distance between Elevator " << A.getElevatorID()
       << " and " << B.getElevatorID() << " is "
       << elevatorDistance(A,B) << " Floors." << endl;

cout << "Total Elevators in Existence: " << A.getCount() << endl;
return 0; }