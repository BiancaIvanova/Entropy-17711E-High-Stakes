class PIDController {
public:
    double kP, kI, kD;
    double prevError = 0;
    double integral = 0;

    PIDController(double kP, double kI, double kD) {
        : kP(kP), kI(kI), kD(kD) {}
    }

    double calculate(double error, double time_step) {
        // Calculate integral (sum of errors) 
        integral += (error * time_step);
        
        // Calculate derivative (change in error)
        double derivative = (error - prevError) / time_step;

        // Sum everything
        double output = (kP * error) + (kI * integral) + (kD * derivative);

        prevError = error;
        return output;
    }
};
