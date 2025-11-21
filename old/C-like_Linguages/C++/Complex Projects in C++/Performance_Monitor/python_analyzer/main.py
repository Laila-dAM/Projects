import time 
import csv
from data_processor import process_data
from graph_generator import generate_graph
from performance_report import generate_report 

def main():
    while True:
        with open('data/performance_data.csv', 'r') as file:
            data = process_data(file)
            generate_graph(data)
            generate_report(data)

time.sleep(1)
if __name__ == "__main__":
main()
