#include "WPILib.h"

class Robot: public IterativeRobot
{
private:
	CANTalon *TalonSRX1;
	CANTalon *TalonSRX2;
	CANTalon *TalonSRX3;
	CANTalon *TalonSRX4;

	RobotDrive *DriveSystem;

	Joystick *LeftStick;
	float LeftStickInput = 0.0;
	Joystick *RightStick;
	float RightStickInput = 0.0;
	Joystick *XBoxPlayer1;

	Talon *LiftMotor;

	DoubleSolenoid *ArmSolenoid;

	//Servo *servocam;

	void RobotInit()
	{
		TalonSRX1 = new CANTalon(1);
		TalonSRX2 = new CANTalon(2);
		TalonSRX3 = new CANTalon(3);
		TalonSRX4 = new CANTalon(4);

		DriveSystem = new RobotDrive(TalonSRX1, TalonSRX2, TalonSRX3, TalonSRX4);


		LeftStick = new Joystick(0);
		RightStick = new Joystick(1);
		XBoxPlayer1 = new Joystick(2);

		LiftMotor = new Talon(0);

		ArmSolenoid = new DoubleSolenoid(5, 7, 6);

		//servocam = new Servo(0);
	} //End RobotInit

	void AutonomousInit()
	{

	} //End AutonomousInit

	void AutonomousPeriodic()
	{

	} //End AutonomousPeriodic
	void TeleopInit()
	{

	} //End TeleopInit

	void TeleopPeriodic()
	{
		DriveSystem->SetSafetyEnabled(false);

		if(abs(LeftStick->GetY()) + .05 < abs(LeftStickInput)){ //--Set a Maximum deceleration speed.
			LeftStickInput *= 0.9;
		}else{
			LeftStickInput = LeftStick->GetY();
		}
		if(abs(RightStick->GetY()) + .05 < abs(RightStickInput)){
			RightStickInput *= 0.9;
		}else{
			RightStickInput = RightStick->GetY();
		}


		if(abs(RightStickInput) < 0.115){
			RightStickInput = 0;
		}
		if(abs(LeftStickInput) < 0.115){
			LeftStickInput = 0;
		}




		LeftStickInput *= -1;
		RightStickInput *= -1;

		if (RightStick->GetRawButton(1) == true)
		{
			LeftStickInput = RightStick->GetY();
		}
		if (LeftStick->GetRawButton(1) == true)
		{
			LeftStickInput = LeftStickInput / 2;
			RightStickInput = RightStickInput / 2;
		}

		DriveSystem->TankDrive(LeftStickInput, RightStickInput, false); //KAWAII :3


		if(XBoxPlayer1->GetRawButton(5) == true) LiftMotor->Set(-1);
		if(XBoxPlayer1->GetRawButton(6) == true) LiftMotor->Set(1);
		if(XBoxPlayer1->GetRawButton(5) != true and XBoxPlayer1->GetRawButton(6) != true) LiftMotor->Set(0.0);

		if (XBoxPlayer1->GetRawButton(1) == true) ArmSolenoid->Set(DoubleSolenoid::Value::kForward);
		if (XBoxPlayer1->GetRawButton(2) == true) ArmSolenoid->Set(DoubleSolenoid::Value::kReverse);
		if (XBoxPlayer1->GetRawButton(1) != true and XBoxPlayer1->GetRawButton(2) != true) ArmSolenoid->Set(DoubleSolenoid::Value::kOff);

		//servocam->SetAngle(RightStick->GetRawAxis(3));*/
	}//End TeleopPeriodic

	float abs(float f){
		if(f < 0){
			return f * -1;
		}else{
			return f;
		}
	}
}; //End Robot Class

START_ROBOT_CLASS(Robot);
