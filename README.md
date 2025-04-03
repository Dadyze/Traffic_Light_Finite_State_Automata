
# Traffic Light Finite State Automata in C++

This project implements a traffic light system using Finite State Automata (FSA) in C++. It models the traffic light behavior for a main road and a side road, including sensor-based detection and state transitions based on real-world conditions. The system is designed to simulate real-time traffic control using basic keyboard inputs.

## Description

```
Welcome to the Implementation of the Traffic Light as a Finite Automaton  
Author: Adin Jahic  
Field: Automata and Formal Languages  
Date of Creation: 29.04.2024  
-------------------------------------------------------------------------------
Rules and Assumptions:
1. The main road and side road have 4 states:
   - S1) MainRoadGreen (Side Road Red)
   - S2 MainRoadYellow (Side Road Red)
   - S3) SideRoadGreen (Main Road Red)
   - S4) SideRoadYellow (Main Road Red)
2. As long as a car is not detected by the sensor on the side road, the main road stays in State S1.
3. Car detection on the side road is simulated by pressing the 'c' key.
4. While the key is pressed, the states change from S1-S2-S3-S4
5. The duration of the states (green/red and yellow lights) is determined by timers.
6. Pressing the 'v' key removes the car from the side road and returns to State S1.
7. Pressing the 'q' key terminates the simulation.

```

## Features

- **Finite State Machine (FSM) for Traffic Lights**: Implements a traffic control system with four distinct states.
- **Main and Side Road Logic**: The main road remains green until a car is detected on the side road.
- **User Interaction**: Simulates car detection and state transitions via keyboard inputs (`c`, `v`, `q`).
- **Real-time Transition**: State durations (for green, yellow, and red lights) are controlled by timers, reflecting real-world traffic light behavior.

## Getting Started

### Prerequisites

To build and run this project, you will need:

- A C++ compiler supporting C++11 or later (e.g., GCC, Clang, MSVC).

### Building the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/Dadyze/Traffic-Light-Finite-State-Automata-in-Cpp.git
   cd Traffic-Light-Finite-State-Automata-in-Cpp
   ```
2. Building
#### Windows
    1. Open the project in Visual Studio.
    2. Use the "Build" button to compile the project.
    3. Use the "Run" button to execute the compiled program.
#### Linux
To build and run the project, run:
```bash
make run
```
To build, execute:
```bash
make build
```
### Usage

- Press **`c`** to simulate detecting a car on the side road and initiate state transitions.
- Press **`v`** to clear the side road detection and return to the main road being green.
- Press **`q`** to quit the simulation.

### Customization

The duration of each traffic light state (green, yellow, red) can be adjusted by modifying the timers in the source code.


## Contributing

Contributions are welcome! If you find a bug or have a feature request, feel free to open an issue or submit a pull request.


## Acknowledgments

This project was inspired by the concept of finite state automata and its application to real-world traffic control systems.
