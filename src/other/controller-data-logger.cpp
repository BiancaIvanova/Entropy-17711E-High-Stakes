#include "liblvgl/extra/widgets/span/lv_span.h"
#include "main.h"
#include "config.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "driver-control.h"
#include "data-logger.h"

// Global variable to store the log
std::vector<ControllerState> controllerLogs;
int log_timestamp = 0;

void log_controller()
{
    int leftX = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
    int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    bool RIGHT = controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT);
    bool DOWN = controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
    bool Y = controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y);
    bool B = controller.get_digital(pros::E_CONTROLLER_DIGITAL_B);
    bool L1 = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
    bool L2 = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
    bool R1 = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
    bool R2 = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);

    // Using the constructor to properly initialize ControllerState
    controllerLogs.push_back({log_timestamp, leftX, leftY, rightX, rightY,
                                             RIGHT, DOWN, Y, B,
                                             L1, L2, R1, R2});

    std::cout << "Timestamp: " << log_timestamp
              << " LeftX: " << leftX << " LeftY: " << leftY
              << " RightX: " << rightX << " RightY: " << rightY
              << " Right: " << RIGHT << " Down: " << DOWN
              << " Y: " << Y << " B: " << B
              << " L1: " << L1 << " L2: " << L2
              << " R1: " << R1 << " R2: " << R2
              << std::endl;

    log_timestamp += 20;
}

void save_logs_to_file()
{
    FILE* logFile = fopen("/usd/controller_logs.txt", "w");

    if (logFile != nullptr)
    {
        for (const auto& log : controllerLogs)
        {
            fprintf(logFile, "%d %d %d %d %d %d %d %d %d %d %d %d %d\n",
                    log.timestamp, log.leftX, log.leftY, log.rightX, log.rightY,
                    log.RIGHT, log.DOWN, log.Y, log.B,
                    log.L1, log.L2, log.R1, log.R2);
        }
        fclose(logFile);
        pros::lcd::print(1, "Logs saved to file: /usd/controller_logs.txt");
    }
    else
    {
        pros::lcd::print(1, "Error: Could not open file for writing.");
    }
}

void read_logs_from_file()
{
    FILE *file = fopen("/usd/controller_logs.txt", "r");

    if (file == nullptr) {
        pros::lcd::print(0, "Failed to open log file.");
        return;
    }

    while (!feof(file)) {
        int timestamp, leftX, leftY, rightX, rightY;
        int RIGHT, DOWN, Y, B;
        int L1, L2, R1, R2;

        int result = fscanf(file, "%d %d %d %d %d %d %d %d %d %d %d %d %d\n",
                            &timestamp, &leftX, &leftY, &rightX, &rightY,
                            &RIGHT, &DOWN, &Y, &B,
                            &L1, &L2, &R1, &R2);

        if (result == 13) {
            controllerLogs.push_back(ControllerState(timestamp, leftX, leftY, rightX, rightY,
                                                     RIGHT, DOWN, Y, B,
                                                     L1, L2, R1, R2));
        }
    }

    fclose(file);
    pros::lcd::print(0, "Done.");
}


// Function to replay the controller log
void replay_logs()
{
    if (controllerLogs.empty()) {
        pros::lcd::print(0, "No logs available for replay.");
        return;
    }

    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);

    for (const auto& log : controllerLogs)
    {
        double leftY = log.leftY;
        double rightX = log.rightX;

        double curveGain = 10;
        chassis.curvature(leftY, rightX, curveGain);

        intake_control(log.R2, log.R1);
        arm_control(log.Y, log.RIGHT);
        stake_clamp_control(log.L2);
        left_doinker_control(log.B);

        pros::delay(20);
    }

    pros::lcd::print(1, "Replay complete.");
}

/*

LOGGER

    intake_controlled(0);

	while (true)
	{
		split_curvature();
		log_controller();
		pros::delay(TASK_DELAY_MS);

		if (controller.get_digital(DIGITAL_LEFT))
		{
			break;
		}
	}
	
	controller.rumble("---");
	save_logs_to_file();
	controller.rumble("-");
*/

/*
PLAYER

    intake_controlled(0);

	read_logs_from_file();
	replay_logs();

*/