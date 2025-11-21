import sys
import matplotlib.pyplot as plt

def generate_visualization(filename):
    with open(filename, 'r') as file:
        code = file.read()

complexity = calculate_complexity(code)
plt.plot(complexity)
plt.title("Code Complexity")
plt.xlabel("Line Number")
plt.ylabel("Complexity")
plt.savefig(f"{filename}_complexity.png")

def calculate_complexity(code):
    return [line.count('def') for line in code.split('\n')]

if __name__ == "__main__":
    generate_visualization(sys.argv[1])
    