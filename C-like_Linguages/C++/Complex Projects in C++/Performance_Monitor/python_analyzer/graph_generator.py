import matplotlib.pyplot as plt
def generate_graph(data):
    cpu_data, memory_data, network_data = zip(*data)

    plt.figure(figsize=(10, 6))
    plt.subplot(3, 1, 1)
    plt.plot(cpu_data, label="CPU Usage")
    plt.legend()

    plt.subplot(3, 1, 2)
    plt.plot(memory_data, label="Memory Usage")
    plt.legend()
    
    plt.subplot(3, 1, 3)
    plt.plot(network_data, label="Network Usage")
    plt.legend()
    
    plt.tight_layout()
    plt.show()
