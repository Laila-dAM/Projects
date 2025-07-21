ᴄᴏᴅᴇ 👾

---

# Network Simulator

## What is it?

A C-based console application that simulates a basic computer network by initializing routers and devices. It serves as a foundational tool for testing traffic flows, routing behaviors, and network structures. Additional Python scripts enhance the simulation by generating traffic and visualizing the network.

## How to use?

1. Make sure you have a C compiler installed (e.g., `gcc`).

2. Open a terminal in the project folder and compile the project:

```bash
gcc network_simulator.c router.c device.c utils.c -o network_simulator
```

3. Run the simulator:

```bash
./network_simulator
```

4. Use the provided Python scripts to simulate traffic or visualize the network:

```bash
python3 traffic_generator.py      # Optional: Simulate network traffic
python3 visualizer.py             # Optional: Visualize network structure
```

## Features

- Initializes routers and devices with simple function calls
- Modular structure for routers, devices, and utility functions
- Uses a JSON configuration file for customizable setup
- Python integration for traffic simulation and graphical visualization
- Easy to extend for more advanced networking behavior

## Folder Structure

```bash
📁 Network Simulator/
├── network_simulator.c         # Main application logic (entry point)
├── router.c / router.h         # Router logic
├── device.c / device.h         # Device initialization
├── utils.c / utils.h           # Utility functions
├── config.json                 # Network configuration
├── traffic_generator.py        # Python script to simulate network traffic
├── visualizer.py               # Python script to visualize the network
└── README.md                   # Project documentation
```

## Demo

📹 [Watch it run](link)

---

<p align="center">૮ ˙Ⱉ˙ ა learn or perish</p>
