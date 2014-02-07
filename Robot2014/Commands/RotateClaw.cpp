 // RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "RotateClaw.h"
#include "../Subsystems/Claw.h"
#define OPSTICK_CONVERSION_FACTOR 10
RotateClaw::RotateClaw() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::claw);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void RotateClaw::Initialize() {
	Robot::claw->Enable();//enable PID Controller
	}
// Called repeatedly when this Command is scheduled to run
void RotateClaw::Execute() {
	if (Robot::claw->initializedPosition == false){	
		//TODO: verify code
		if(Robot::claw->backLimitSwitch->Get() != Robot::claw->backSwitchInit ){
			//This code resets the pid controller and the claw encoder so they will function  
			Robot::claw->Disable();//Disable PID Controller
			Robot::claw->quadClawEncoder->Reset();
			Robot::claw->SetSetpoint(POSITION_UP);
			Robot::claw->Reset();
			Robot::claw->Enable();//enable PID Controller
			Robot::claw->initializedPosition = true;
		}	
		while(Robot::claw->backLimitSwitch->Get() == false){
			Robot::claw->SetSetpointRelative(-SMALL_MOVEMENT);
		}
	} else {
		//absolute value
		if (Robot::oi->getOpStick()->GetY() > 0.1)
		{
			Robot::claw->SetSetpoint(Robot::claw->quadClawEncoder->Get());
		}
		Robot::claw->SetSetpoint(
				Robot::claw->quadClawEncoder->Get() 
				+ ((Robot::oi->getOpStick()->GetY()) * OPSTICK_CONVERSION_FACTOR));
	}                                                       
}                                                             
// Make this return true when this Command no longer needs to run execute()
bool RotateClaw::IsFinished() {                                 
	return false;                                                
}                                                                 
// Called once after isFinished returns true                       
void RotateClaw::End() {                                                                                                       
                                                                    	
}                                                                     
// Called when another command which requires one or more of the same   
// subsystems is scheduled to run
void RotateClaw::Interrupted() {
}
