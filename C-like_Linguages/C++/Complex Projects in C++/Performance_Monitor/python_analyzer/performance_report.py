import os
def generate_report(data):
    report = "Performance Report\n\n"
    for i, (cpu, memory, network) in enumerate(data):
     report += f"Time {i+1}: CPU {cpu}%, Memory {memory}%, Network {network}kb/s\n"

with open("performance_report.txt", "w") as file:
    file.write(report)
    
