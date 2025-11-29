import sys

def generate_report(filename):
    with open(filename, 'r') as file:
        code = file.read()
    errors = ["Error: Missing semicolon on line 10", "Warning: Unused variable 'x'"]
    with open(f"{filename}_report.txt", 'w') as report:
        for error in errors:
            report.write(f"{error}\n")

if __name__ == "__main__":
    generate_report(sys.argv[1])
