def process_data(file):
    data = []
    for line in file:
        cpu, memory, network = map(float, line.strip().split(','))
        data.append((cpu, memory, network))
        return data
        
