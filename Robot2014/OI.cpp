// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AddedPowerDrive.h"
#include "Commands/ArcadeDrive.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/AutonomousGroup.h"
#include "Commands/CockShooter.h"
#include "Commands/CockShooterGroup.h"
#include "Commands/Drive.h"
#include "Commands/DriveForward.h"
#include "Commands/FeedIn.h"
#include "Commands/FeedOff.h"
#include "Commands/FeedOut.h"
#include "Commands/GoToUp.h"
#include "Commands/HalfCockShooter.h"
#include "Commands/LoadShooter.h"
#include "Commands/PickUp.h"
#include "Commands/PositionDrive.h"
#include "Commands/RestorePosition.h"
#include "Commands/RotateClaw.h"
#include "Commands/SavePosition.h"
#include "Commands/Shoot.h"
#include "Commands/SpeedDrive.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/DriveForward.h"
OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	opStick = new Joystick(3);
	
	feedInNow = new JoystickButton(opStick, 12);
	feedInNow->WhileHeld(new FeedIn());
	stopFeed = new JoystickButton(opStick, 10);
	stopFeed->WhileHeld(new FeedOff());
	feedOutNow = new JoystickButton(opStick, 8);
	feedOutNow->WhileHeld(new FeedOut());
	halfCock = new JoystickButton(opStick, 2);
	halfCock->WhenPressed(new HalfCockShooter());
	buttonPos4 = new JoystickButton(opStick, 5);
	buttonPos4->WhileHeld(new RestorePosition());
	buttonPos3 = new JoystickButton(opStick, 4);
	buttonPos3->WhileHeld(new RestorePosition());
	buttonPos2 = new JoystickButton(opStick, 3);
	buttonPos2->WhileHeld(new RestorePosition());
	buttonUp = new JoystickButton(opStick, 3);
	buttonUp->WhileHeld(new GoToUp());
	pickUpButton = new JoystickButton(opStick, 2);
	pickUpButton->WhenPressed(new PickUp());
	saveButton = new JoystickButton(opStick, 1);
	saveButton->WhenPressed(new SavePosition());
	rightDriverStick = new Joystick(2);
	
	shootButton2 = new JoystickButton(rightDriverStick, 1);
	shootButton2->WhenPressed(new Shoot());
	leftDriverStick = new Joystick(1);
	
	addDrivePower = new JoystickButton(leftDriverStick, 11);
	addDrivePower->WhenPressed(new AddedPowerDrive());
	positionDriveNow = new JoystickButton(leftDriverStick, 3);
	positionDriveNow->WhileHeld(new PositionDrive());
	speedDriveNow = new JoystickButton(leftDriverStick, 9);
	speedDriveNow->WhenPressed(new SpeedDrive());
	driveNow = new JoystickButton(leftDriverStick, 10);
	driveNow->WhenPressed(new Drive());
	shootButton1 = new JoystickButton(leftDriverStick, 1);
	shootButton1->WhenPressed(new Shoot());
     
        // SmartDashboard Buttons
	SmartDashboard::PutData("DriveForward", new DriveForward());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
Joystick* OI::getOpStick() {
	return opStick;
}
Joystick* OI::getRightDriverStick() {
	return rightDriverStick;
}
Joystick* OI::getLeftDriverStick() {
	return leftDriverStick;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
float OI::getRightXAxis()
{
	return Robot::JoystickDeadband(rightDriverStick->GetAxis(Joystick::kXAxis));
}
float OI::getRightYAxis()
{
	return Robot::JoystickDeadband(rightDriverStick->GetAxis(Joystick::kYAxis));
}
float OI::getRightZAxis()
{
	return Robot::JoystickDeadband(rightDriverStick->GetAxis(Joystick::kZAxis));
}
float OI::getLeftYAxis()
{
	return Robot::JoystickDeadband(leftDriverStick->GetAxis(Joystick::kYAxis));
}
