class PIDController {
    public:
        double kP, kI, kD;
        double prevError = 0;
        double integral = 0;
    
        PIDController(double kP, double kI, double kD);
    
        double update(double error, double time_step);
    };
    