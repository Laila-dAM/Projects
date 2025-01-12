import sys

def process_command(command):
    if command == "create_process":
        print("Creating process...")
    elif command == "terminate_process":
        print("Terminating process...")
    elif command == "read_file":
        print("Reading file...")
    elif command == "write_file":
        print("Writing to file...")
    elif command == "exit":
        print("Exiting shell...")
        sys.exit(0)
    else:
        print(f"Unknown command: {command}")

def main():
    while True:
        try:
            command = input("OS Command > ").strip()
            process_command(command)
        except KeyboardInterrupt:
            print("\nExiting shell...")
            sys.exit(0)

if __name__ == "__main__":
    main()
