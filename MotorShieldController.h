#ifndef MOTOR_SHIELD_CONTROLLER_H
#define MOTOR_SHIELD_CONTROLLER_H

/**
 * @brief Control a dual motors connected to an Arduino motor shield.
 * Assumes left side is connected to MB and right is MA connected in
 * the same way (no pin relative position inversions).
 */
class MotorShieldController {
  public:
    /**
     * @brief Set up the pins of the H-bridge (for this motor)
     * @param leftDirectionPin Digital output pin
     * @param rightDirectionPin Digital output pin
     * @param enablePinLeft Analog output pin
     * @param enablePinRight Analog output pin
     */
    MotorShieldController(int leftDirectionPin, int rightDirectionPin, int enablePinLeft, int enablePinRight);

    /**
     * @brief Select how fast to turn.
     * @param pwm Pulse width modulation value [-255,255], with higher magnitude
     * corresponding to higher speed. Negative will turn it backwards.
     */
    void setLeftVelocity(int pwm);
    void setRightVelocity(int pwm);
    void floatStop();

    /**
     * @brief Rotate counterclockwise at last set speed.
     * Motor will continue rotating until another rotation command is sent.
     */
    void go() const;

  private:

    const int _leftDir, _rightDir, _leftEnable, _rightEnable;
    int _lastLeftPWM;
    int _lastRightPWM;
};

#endif // MOTOR_SHIELD_CONTROLLER_H
