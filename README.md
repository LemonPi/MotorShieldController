## Arduino library for a H-Bridge motor controller (driver) of a single motor

Two ways to use this:
1. Drop directory directly inside sketch

or

1. Move directory under Arudino libraries directory
2. In Arduino IDE with sketch open select Sketch > Include Library > WheelEncoder (should be under Contributed Libraries)

## Usage

Connect pins according to data sheet

```c++
#include <Arduino.h>
#include <MotorShieldController.h>

// shield pins
constexpr auto DIR_LEFT = 13;
constexpr auto ENABLE_LEFT = 11;

constexpr auto DIR_RIGHT = 12;
constexpr auto ENABLE_RIGHT = 10;

MotorShieldController mc(DIR_LEFT, DIR_RIGHT, ENABLE_LEFT, ENABLE_RIGHT);

void setup() {
}

void loop() {
    mc.setLeftVelocity(50);
    mc.setRightVelocity(-50);
    mc.go();
}
```
