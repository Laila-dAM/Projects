class Entity:
    def __init__(self, x, y, char, color=(255, 255, 255)):
        self.x = x
        self.y = y
        self.char = char
        self.color = color
        self.alive = True

    def move(self, dx, dy, game_map):
        new_x = self.x + dx
        new_y = self.y + dy

        if game_map[new_y][new_x] != "#":
            self.x = new_x
            self.y = new_y

    def update(self, dt):
        pass

    def draw(self, surface, cell_size):
        import pygame
        rect = pygame.Rect(self.x * cell_size, self.y * cell_size, cell_size, cell_size)
        pygame.draw.rect(surface, self.color, rect)
