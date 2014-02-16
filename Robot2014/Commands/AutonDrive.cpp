// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "AutonDrive.h"
#include "C:/Windriver/workspace/frc1388-2014/Robot2014/Subsystems/DriveTrain.h"
#include "math.h"
#define STOP_DISTANCE_MARGIN 0.0833 //0.0833 feet is 1.0 inches
#define P_VALUE 0.3 //proportional constant
AutonDrive::AutonDrive(float setpoint, float maxPower = 0.5) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	m_setpoint = setpoint;
	m_maxPower = maxPower;
}
// Called just before this Command runs the first time
void AutonDrive::Initialize() {
	RobotMap::driveTrainLeftEncoder->Reset();
	RobotMap::driveTrainRightEncoder->Reset();
	m_distanceReached = false;
}
// Called repeatedly when this Command is scheduled to run
void AutonDrive::Execute() {
	// get current distance from the encoders
	float leftPosition = RobotMap::driveTrainLeftEncoder->GetDistance();
	float rightPosition = RobotMap::driveTrainRightEncoder->GetDistance();
	printf("distances: setpoint %f | leftpos %f | rightpos %f |\n\n", m_setpoint, leftPosition, rightPosition);
	float signedMaxPower = m_maxPower;
	// set power
	float leftPower = (m_setpoint - leftPosition) * P_VALUE;
	float rightPower = (m_setpoint - rightPosition) * P_VALUE;
	//Set the sign of our max power depending on the direction the robot needs to move
	signedMaxPower = Robot::SignOf(leftPower) * m_maxPower;
	//limit to max power passed into the constructor
	leftPower = (fabs(leftPower) > fabs(m_maxPower)) ? signedMaxPower : leftPower;
	rightPower = (fabs(rightPower) > fabs(m_maxPower)) ? signedMaxPower : rightPower;
	
	// set power to zero if within our stop margin
	if(fabs(leftPosition - m_setpoint) < STOP_DISTANCE_MARGIN) leftPower = 0;
	if(fabs(rightPosition - m_setpoint) < STOP_DISTANCE_MARGIN) rightPower = 0;
	leftPower = (rightPower == 0) ? 0 : leftPower;
	rightPower = (leftPower == 0) ? 0 : rightPower;
	if(leftPower == 0 && rightPower == 0) m_distanceReached = true;
	if (m_distanceReached) 	printf("==================================\nIsFinished\n==========================================\n");
	
	// drive robot
	// 	left encoder doesn't work right. 
	// 	setting power * p_value causes robot to give more power to left than right when reaching setpoint. 
	// 	for now use rightPower for left and right.
//	RobotMap::driveTrainMyRobotDrive->TankDrive(leftPower, rightPower, false);
	RobotMap::driveTrainMyRobotDrive->TankDrive(rightPower, rightPower, false);
}
// Make this return true when this Command no longer needs to run execute()
																
bool AutonDrive::IsFinished(){
		return m_distanceReached;
}
// Called once after isFinished returns true
void AutonDrive::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonDrive::Interrupted() {
}
