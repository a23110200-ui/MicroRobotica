#include <webots/Robot.hpp>
#include <webots/PositionSensor.hpp>
#include <webots/Motor.hpp>
#include <iostream>


// All the webots classes are defined in the "webots" namespace
using namespace webots;
using namespace std;
int main(int argc, char **argv) {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();

  // You should insert a getDevice-like function in order to get the
  // instance of a device of the robot. Something like:
  Motor *motor = robot->getMotor("motor_1");
  PositionSensor *ds = robot->getPositionSensor("sensor_1");
   ds->enable(timeStep);

  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(timeStep) != -1) {
    // Read the sensors:
    // Enter here functions to read sensor data, like:
    double val = ds->getValue();

    // Process sensor data here.

    // Enter here functions to send actuator commands, like:
     motor->setForce(0.0);
     motor->setPosition(INFINITY);
     cout << "poscicion actual" << val << endl;
  };

  // Enter here exit cleanup code.

  delete robot;
  return 0; 
  system("cls");
  ;
}
