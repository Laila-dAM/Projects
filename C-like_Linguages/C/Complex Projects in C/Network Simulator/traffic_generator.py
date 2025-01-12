import time
import random
import json

def load_config(config_file = "config.json"):
    with open(config_file, "r") as file:
        return json.load(file)

def generate_traffic(devices):
    print("Starting traffic generation...")
    while True:
        src, dest = random.sample(devices, 2)
        packet_size = random.randint(64, 1500)
        print(f"Packet from {src} to {dest}, Size: {packet_size} bytes")
        time.sleep(1)

if __name__ == "__main__":
    config = load_config()
    devices = config.get("devices", [])
    if not devices:
        print("No devices found in config!")
        else:
            generate_traffic(devices)