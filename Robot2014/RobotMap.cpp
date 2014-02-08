// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
Encoder* RobotMap::clawQuadClawEncoder = NULL;
SpeedController* RobotMap::clawArmMotor = NULL;
DigitalInput* RobotMap::clawFrontLimitSwitch = NULL;
DigitalInput* RobotMap::clawBackLimitSwitch = NULL;
DigitalInput* RobotMap::clawZeroSwitch = NULL;
Encoder* RobotMap::driveTrainRightEncoder = NULL;
Encoder* RobotMap::driveTrainLeftEncoder = NULL;
SpeedController* RobotMap::driveTrainLeftMotor = NULL;
SpeedController* RobotMap::driveTrainRightMotor = NULL;
RobotDrive* RobotMap::driveTrainMyRobotDrive = NULL;
SpeedController* RobotMap::shooterLoadingMotor = NULL;
Relay* RobotMap::shooterLatch = NULL;
DigitalInput* RobotMap::shooterLatchingLimitSwitch = NULL;
DigitalInput* RobotMap::shooterCockedLimitSwitch = NULL;
SpeedController* RobotMap::feederFeedMotor = NULL;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();
	clawQuadClawEncoder = new Encoder(1, 7, 1, 8, false, Encoder::k1X);
	lw->AddSensor("Claw", "QuadClawEncoder", clawQuadClawEncoder);
	clawQuadClawEncoder->SetDistancePerPulse(1.0);
        clawQuadClawEncoder->SetPIDSourceParameter(Encoder::kDistance);
        clawQuadClawEncoder->Start();
	clawArmMotor = new Talon(1, 8);
	lw->AddActuator("Claw", "ArmMotor", (Talon*) clawArmMotor);
	
	clawFrontLimitSwitch = new DigitalInput(1, 9);
	lw->AddSensor("Claw", "FrontLimitSwitch", clawFrontLimitSwitch);
	
	clawBackLimitSwitch = new DigitalInput(1, 10);
	lw->AddSensor("Claw", "BackLimitSwitch", clawBackLimitSwitch);
	
	clawZeroSwitch = new DigitalInput(1, 5);
	lw->AddSensor("Claw", "ZeroSwitch", clawZeroSwitch);
	
	driveTrainRightEncoder = new Encoder(1, 3, 1, 4, false, Encoder::k4X);
	lw->AddSensor("DriveTrain", "RightEncoder", driveTrainRightEncoder);
	driveTrainRightEncoder->SetDistancePerPulse(0.0280499);
        driveTrainRightEncoder->SetPIDSourceParameter(Encoder::kRate);
        driveTrainRightEncoder->Start();
	driveTrainLeftEncoder = new Encoder(1, 1, 1, 2, false, Encoder::k4X);
	lw->AddSensor("DriveTrain", "LeftEncoder", driveTrainLeftEncoder);
	driveTrainLeftEncoder->SetDistancePerPulse(0.0280499);
        driveTrainLeftEncoder->SetPIDSourceParameter(Encoder::kRate);
        driveTrainLeftEncoder->Start();
	driveTrainLeftMotor = new Talon(1, 3);
	lw->AddActuator("DriveTrain", "LeftMotor", (Talon*) driveTrainLeftMotor);
	
	driveTrainRightMotor = new Talon(1, 1);
	lw->AddActuator("DriveTrain", "RightMotor", (Talon*) driveTrainRightMotor);
	
	driveTrainMyRobotDrive = new RobotDrive(driveTrainLeftMotor, driveTrainRightMotor);
	
	driveTrainMyRobotDrive->SetSafetyEnabled(true);
        driveTrainMyRobotDrive->SetExpiration(0.1);
        driveTrainMyRobotDrive->SetSensitivity(0.5);
        driveTrainMyRobotDrive->SetMaxOutput(1.0);
        
	shooterLoadingMotor = new Talon(1, 2);
	lw->AddActuator("Shooter", "LoadingMotor", (Talon*) shooterLoadingMotor);
	
	shooterLatch = new Relay(1, 1);
	lw->AddActuator("Shooter", "Latch", shooterLatch);
	
	shooterLatchingLimitSwitch = new DigitalInput(1, 11);
	lw->AddSensor("Shooter", "LatchingLimitSwitch", shooterLatchingLimitSwitch);
	
	shooterCockedLimitSwitch = new DigitalInput(1, 6);
	lw->AddSensor("Shooter", "CockedLimitSwitch", shooterCockedLimitSwitch);
	
	feederFeedMotor = new Talon(1, 4);
	lw->AddActuator("Feeder", "FeedMotor", (Talon*) feederFeedMotor);
	
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
