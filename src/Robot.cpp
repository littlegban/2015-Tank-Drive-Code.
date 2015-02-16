#include "WPILib.h"

class Robot: public IterativeRobot
{
private:
	CANTalon *Talon1;
	CANTalon *Talon2;
	CANTalon *Talon3;
	CANTalon *Talon4;
	RobotDrive *Drive;
	Joystick *Leftstick;
	Joystick *Rightstick;

	void RobotInit()
	{
		Talon1 = new CANTalon(1);
		Talon2 = new CANTalon(2);
		Talon3 = new CANTalon(3);
		Talon4 = new CANTalon(4);
		Drive = new RobotDrive(Talon1, Talon2, Talon3, Talon4);
		Drive->SetSafetyEnabled(false);
		Leftstick = new Joystick(0);
		Rightstick = new Joystick(1);
	}
	void debug()

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		Drive->MecanumDrive_Cartesian(Leftstick->GetX(), Leftstick->GetY(), Rightstick->GetX());
	}

	void TestPeriodic()
	{

	}
};

START_ROBOT_CLASS(Robot);
