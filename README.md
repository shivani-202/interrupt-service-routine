



# ESP32 ISR Button & LED Control System

This project demonstrates how to handle **button inputs using interrupts (ISRs)** on the **ESP32** microcontroller, with **software debouncing** and **LED control**. It uses the **Wokwi simulator** for testing and also generates **waveform analysis** using `.vcd` files.

---

## Features

-  4 Push Button inputs using GPIOs with Interrupt Service Routines (ISRs)
-  Software debounce logic using `millis()`
-  LED toggles based on valid button press or release
-  Wokwi simulation-ready
-  Waveform analysis with `.vcd` output

---

## ESP32 Pins Used

| GPIO Pin | Component | Direction | Purpose                     |
|----------|-----------|-----------|-----------------------------|
| GPIO33   | Button 1  | Input     | Interrupt + Debounce        |
| GPIO32   | Button 2  | Input     | Interrupt + Debounce        |
| GPIO35   | Button 3  | Input     | Input-only + Interrupt      |
| GPIO34   | Button 4  | Input     | Input-only + Interrupt      |
| GPIO17   | LED       | Output    | ON when button pressed      |

>  Note: GPIO 34 & 35 are **input-only** on the ESP32, but fully support interrupts.

---

## How It Works

1. Each button has an **interrupt on CHANGE**.
2. When the button changes state, its ISR is triggered.
3. A **software debounce** routine in `loop()` validates the signal using a delay of ~10ms.
4. If the button state is confirmed as changed, the **LED toggles** and the **status is printed** over serial.

---

## Sample Serial Output

```text
Setup complete
Button 4 is ACTIVE
Button 4 is IDLE
Button 2 is ACTIVE
Button 2 is IDLE
Button 1 is ACTIVE
Button 1 is IDLE
Button 3 is ACTIVE
Button 3 is IDLE
