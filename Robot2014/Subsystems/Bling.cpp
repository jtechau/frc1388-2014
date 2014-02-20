// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Bling.h"
#include "../Robotmap.h"
Bling::Bling() : Subsystem("Bling") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	blingLEDs = RobotMap::blingBlingLEDs;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	
	// NOTE:
	// The LEDs are connected to a Spike relay with a common anode.
	// This means that you control the negative terminal of the LED.
	// When you set a Spike relay output 'on', you're connecting it to 12V,
	// which will actually turn the LED off.  And vice versa.
	// We initialize the relay here so that the LEDs are off.
	blingLEDs->Set(Relay::kOn);
}
    
void Bling::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

void Bling::SetLEDsToAllianceColor() {
	// get the alliance color from the DriverStation object
	DriverStation::Alliance allianceColor;
	allianceColor = DriverStation::GetInstance()->GetAlliance();

	switch (allianceColor) {
	case DriverStation::kRed:
		blingLEDs->Set(Relay::kForward);	// TODO:  verify this setting
		break;
	case DriverStation::kBlue:
		blingLEDs->Set(Relay::kReverse);	// TODO:  verify this setting
		break;
	default:
		blingLEDs->Set(Relay::kOn);			// Turn LEDs off (kOn == 'off')
	}
}
