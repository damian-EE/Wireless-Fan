# Wireless Automatic Fan

A battery-powered fan that turns itself on when someone comes within about 2 feet, built for the **2024 CSU Bakersfield Summer Research Program** by Damian Delgado Ayon and Diego Excontitta.

An ultrasonic sensor measures the distance to whatever is in front of the fan. When a person or object is within range, the Arduino switches on a 12V DC motor through an L298N motor driver. When they move away, the fan turns off.

## Hardware

| Part | Purpose |
|---|---|
| Arduino Uno R3 | Reads the sensor and controls the motor |
| Ultrasonic distance sensor | Detects people or objects in front of the fan |
| L298N motor driver | Lets the Arduino switch the 12V motor |
| 12V DC motor | Spins the fan blade |
| Dual battery holder | Wireless power |
| 3D-printed fan blade and holder | Designed in OnShape |

**CAD model:** [Final propeller design in OnShape](https://cad.onshape.com/documents/08690a043dd87ee2207aafcf/w/44276339f57fa33514bd3049/e/ecd49e6c93ce8dfc462a4968)

## Wiring

| Arduino pin | Connects to |
|---|---|
| 7 | Ultrasonic sensor TRIG |
| 6 | Ultrasonic sensor ECHO |
| 10 | L298N IN1 |

With a single control pin, the L298N is typically wired with **IN2 to GND** and the **ENA jumper in place**, so IN1 alone turns the motor on and off. The motor connects to the L298N's OUT1/OUT2 terminals and the battery pack to its 12V input, with a shared ground to the Arduino.

## How it works

1. The Arduino sends a short pulse to the sensor's TRIG pin.
2. The sensor sends out an ultrasonic ping and holds ECHO high until the echo returns.
3. The code converts that time into a distance in centimeters.
4. If the distance is 61 cm (about 2 feet) or less, the motor turns on. Otherwise it turns off.

## Running it

Open `wireless_fan/wireless_fan.ino` in the Arduino IDE, select **Arduino Uno** as the board, and upload. To change how close someone has to be, edit `TRIGGER_DISTANCE_CM`.

## Notes on this version

This is a cleaned-up copy of the original project sketch. Comments were added and the trigger distance is now a named constant set to **61 cm** to match the 2-foot range shown in the final demo; the saved original file used 10 cm. The logic is otherwise unchanged.

## Acknowledgements

Thanks to Ivan, Bri, and the FabLab student assistants; Dr. Brown and Dr. Jafarzadeh; and Luis Morales and Jeff Deguia.
