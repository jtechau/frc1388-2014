// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "DriveForward.h"
DriveForward::DriveForward(float power, float time = 1) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	m_power = power;
	m_time = time;
}
// Called just before this Command runs the first time
void DriveForward::Initialize() {
	SetTimeout(m_time);
	
}
// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute() {
	RobotMap::driveTrainMyRobotDrive->TankDrive(m_power,m_power,false);
	
}
// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished() {
	return IsTimedOut();
}
// Called once after isFinished returns true
void DriveForward::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted() {
}
