import matplotlib.pyplot as plt
import matplotlib.animation as animation

from collections import deque
import random 

data_queue = deque(maxlen=20)

fig, ax = plt.subplots()
line, ax.plot([], [], lw=2)
ax.set_ylim(0, 1500)
ax.set_xlim(0, 20)
ax.grid()

def init():
    line.set_data([], [])
    return line,

def update(frame):
    data_queue.append(rando.randint(64, 1500))
    line.set_data(range(len(data_queue)), data_queue)
    return line, 

ani = animation.FuncAnimation(fig, update, init_func=init, blit=True, interval=1000)
plt.show()