# Traffic Simulator

Bare-metal embedded C firmware for the **STM32L476RG** (Nucleo board) that simulates two traffic light control scenarios using physical switches, LEDs, and a 74HC595D shift register chain over SPI.

![Hardware Setup](docs/hardware-setup.jpg)

---

## Scenarios

**Pedestrian Crossing** — Cars get green by default. When a pedestrian presses the button (SW7/SW8), the sequence transitions through orange, all-red, pedestrian green, then back to cars.

**4-Way Intersection** — Reads car presence on 4 lane switches (SW1–SW4) and decides which street (West/East or North/South) gets the green light, with full orange transitions between changes.

The active scenario is selected via `run_task` in `main.c`. Setting `run_test = true` runs the hardware test suite for that scenario instead.

---

## Hardware

| | |
|---|---|
| MCU | STM32L476RG (Cortex-M4) |
| Board | Nucleo-L476RG |
| Output | 3× 74HC595D shift registers (24-bit LED chain via SPI3) |
| Input | 4 toggle switches (car presence) + 1 push button (pedestrian) |

---

## Stack

- Bare-metal C with STM32 HAL
- SPI for shift register control
- GPIO abstraction layer over HAL
- State machine design per scenario
- Hardware-in-the-loop test suites (no test framework required)

---

## Build

Open in **STM32CubeIDE**, build with `Ctrl+B`, flash with `F11`.
