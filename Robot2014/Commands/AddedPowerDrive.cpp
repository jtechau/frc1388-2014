// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "AddedPowerDrive.h"
#include "Math.h"
#define STICKTION_BREAK_FACTOR 0.25
AddedPowerDrive::AddedPowerDrive() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void AddedPowerDrive::Initialize() {
	
}
// Called repeatedly when this Command is scheduled to run
void AddedPowerDrive::Execute() {
	
	float addedLeftPower;
	float addedRightPower;
	
	float leftEncoderRate = Robot::driveTrain->leftEncoder->GetRate();
	float rightEncoderRate = Robot::driveTrain->rightEncoder->GetRate();
	
	float leftPower = Robot::JoystickDeadband(Robot::oi->getLeftYAxis());
	float rightPower = Robot::JoystickDeadband(Robot::oi->getRightYAxis());
		
//	If the encoders are not moving and power is applied to the joystick then apply a flat voltage
//		with the stick value to break stickion.
	if(fabs(rightEncoderRate < 1) && fabs(rightPower > 0.1))
	{
		//0.25 is still subject to change
		addedLeftPower = leftPower + (Robot::SignOf(leftPower) * STICKTION_BREAK_FACTOR);
	}
	else
	{
		addedLeftPower = leftPower;
	}
	
	if(fabs(leftEncoderRate < 1) && fabs(leftPower > 0.1))
	{
		addedRightPower = rightPower + (Robot::SignOf(rightPower) * STICKTION_BREAK_FACTOR);
	}
	else
	{
		addedRightPower = rightPower;
	}
		
	Robot::driveTrain->myRobotDrive->TankDrive(addedLeftPower, addedRightPower, false);		
}
// Make this return true when this Command no longer needs to run execute()
bool AddedPowerDrive::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void AddedPowerDrive::End() {
	Robot::driveTrain->myRobotDrive->TankDrive(0.0, 0.0, false);
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AddedPowerDrive::Interrupted() {
	End();
}
