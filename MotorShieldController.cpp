#include <Arduino.h>
#include "MotorShieldController.h"

MotorShieldController::MotorShieldController(int leftDirectionPin,
                                             int rightDirectionPin,
                                             int enablePinLeft,
                                             int enablePinRight)
    : _leftDir(leftDirectionPin), _rightDir(rightDirectionPin),
      _leftEnable(enablePinLeft), _rightEnable(enablePinRight), _lastLeftPWM(0),
      _lastRightPWM(0) {
    pinMode(_leftDir, OUTPUT);
    pinMode(_rightDir, OUTPUT);
}

void MotorShieldController::setLeftVelocity(int pwm) {
    _lastLeftPWM = pwm;
}

void MotorShieldController::setRightVelocity(int pwm) {
    _lastRightPWM = pwm;
}

void MotorShieldController::floatStop() {
    setLeftVelocity(0);
    setRightVelocity(0);
}

void MotorShieldController::go() const {
    if (_lastLeftPWM < 0) {
        digitalWrite(_leftDir, HIGH);
        analogWrite(_leftEnable, -_lastLeftPWM);
    } else {
        digitalWrite(_leftDir, LOW);
        analogWrite(_leftEnable, _lastLeftPWM);
    }

    if (_lastRightPWM < 0) {
        digitalWrite(_rightDir, LOW);
        analogWrite(_rightEnable, -_lastRightPWM);
    } else {
        digitalWrite(_rightDir, HIGH);
        analogWrite(_rightEnable, _lastRightPWM);
    }
}
