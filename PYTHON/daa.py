import numpy as np
import matplotlib.pyplot as plt
import heapq
import random

GRID_SIZE = 20
OBSTACLE_COUNT = 40
ITERATIONS = 30
NUM_PARTICLES = 30

goal = (19, 19)
start = (0, 0)

# === Generate Grid with Static Obstacles ===
def generate_grid():
    grid = np.zeros((GRID_SIZE, GRID_SIZE))
    obstacle_positions = set()
    while len(obstacle_positions) < OBSTACLE_COUNT:
        i, j = np.random.randint(0, GRID_SIZE, 2)
        if (i, j) not in [start, goal]:
            grid[i][j] = 1
            obstacle_positions.add((i, j))
    return grid

grid = generate_grid()

# === A* Pathfinding ===
def astar(grid, start, goal):
    def heuristic(a, b): return abs(a[0]-b[0]) + abs(a[1]-b[1])
    open_set = [(0 + heuristic(start, goal), 0, start, [])]
    visited = set()

    while open_set:
        est_total, cost, current, path = heapq.heappop(open_set)
        if current in visited: continue
        visited.add(current)
        path = path + [current]
        if current == goal: return path
        for dx, dy in [(-1,0),(1,0),(0,-1),(0,1)]:
            nx, ny = current[0]+dx, current[1]+dy
            if 0 <= nx < GRID_SIZE and 0 <= ny < GRID_SIZE and grid[nx][ny] == 0:
                heapq.heappush(open_set, (cost+1+heuristic((nx,ny),goal), cost+1, (nx,ny), path))
    return []

# === PSO-Based Path Planning ===
class Particle:
    def __init__(self):
        self.position = [start]
        self.velocity = []
        self.best_position = self.position
        self.best_score = float('inf')

    def fitness(self):
        score = 0
        last = self.position[-1]
        score += np.linalg.norm(np.array(last) - np.array(goal))  # distance to goal
        for p in self.position:
            if grid[p[0]][p[1]] == 1:
                score += 100  # obstacle penalty
        return score

    def update(self, gbest):
        if len(self.position) >= GRID_SIZE: return
        options = [(-1,0),(1,0),(0,-1),(0,1)]
        current = self.position[-1]
        next_pos = tuple(np.array(current) + np.array(random.choice(options)))
        if 0 <= next_pos[0] < GRID_SIZE and 0 <= next_pos[1] < GRID_SIZE:
            self.position.append(next_pos)
        score = self.fitness()
        if score < self.best_score:
            self.best_score = score
            self.best_position = self.position[:]

def pso():
    particles = [Particle() for _ in range(NUM_PARTICLES)]
    gbest_position = None
    gbest_score = float('inf')

    for _ in range(ITERATIONS):
        for p in particles:
            p.update(gbest_position)
            if p.best_score < gbest_score:
                gbest_score = p.best_score
                gbest_position = p.best_position[:]
    return gbest_position

# === Plotting ===
def plot_path(grid, a_star_path, pso_path, title):
    plt.figure(figsize=(8, 8))
    plt.imshow(grid, cmap='gray_r')
    plt.title(title)
    plt.scatter(start[1], start[0], color='blue', s=100, label='Start')
    plt.scatter(goal[1], goal[0], color='green', s=100, label='Goal')
    if a_star_path:
        y, x = zip(*a_star_path)
        plt.plot(x, y, color='orange', label='A* Path')
    if pso_path:
        y, x = zip(*pso_path)
        plt.plot(x, y, color='purple', label='PSO Path')
    plt.legend()
    plt.grid(True)
    plt.show()

# === Static Environment ===
a_star_path_static = astar(grid, start, goal)
pso_path_static = pso()
plot_path(grid, a_star_path_static, pso_path_static, "Static Environment: A* vs PSO")

# === Dynamic Environment (Add a new obstacle) ===
grid[10][10] = 1  # simulate dynamic change
a_star_path_dynamic = astar(grid, start, goal)  # A* needs full re-run
pso_path_dynamic = pso()  # PSO can continue adapting

plot_path(grid, a_star_path_dynamic, pso_path_dynamic, "Dynamic Environment: A* vs PSO")
