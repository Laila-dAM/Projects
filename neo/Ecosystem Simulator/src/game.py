import pygame

ASCII_BG = " "
ASCII_PLAYER = "@"
ASCII_WALL = "#"


class Game:
    def __init__(self, window_surface, screen_width, screen_height, cell_size):
        self.window = window_surface
        self.screen_width = screen_width
        self.screen_height = screen_height
        self.cell_size = cell_size

        self.cols = screen_width // cell_size
        self.rows = screen_height // cell_size

        self.player_x = self.cols // 2
        self.player_y = self.rows // 2

        self.map = self.generate_map()

        self.move_delay = 120
        self.last_move = 0

    def generate_map(self):
        game_map = []
        for row in range(self.rows):
            line = []
            for col in range(self.cols):
                if row == 0 or row == self.rows - 1 or col == 0 or col == self.cols - 1:
                    line.append(ASCII_WALL)
                else:
                    line.append(ASCII_BG)
            game_map.append(line)
        return game_map

    def update(self, dt, keys):
        self.last_move += dt
        if self.last_move < self.move_delay:
            return

        new_x = self.player_x
        new_y = self.player_y

        if keys[pygame.K_w] or keys[pygame.K_UP]:
            new_y -= 1
        if keys[pygame.K_s] or keys[pygame.K_DOWN]:
            new_y += 1
        if keys[pygame.K_a] or keys[pygame.K_LEFT]:
            new_x -= 1
        if keys[pygame.K_d] or keys[pygame.K_RIGHT]:
            new_x += 1

        if self.map[new_y][new_x] != ASCII_WALL:
            self.player_x = new_x
            self.player_y = new_y

        self.last_move = 0

    def draw(self):
        for row in range(self.rows):
            for col in range(self.cols):
                char = self.map[row][col]
                color = (180, 180, 180) if char == ASCII_WALL else (0, 0, 0)

                rect = pygame.Rect(
                    col * self.cell_size,
                    row * self.cell_size,
                    self.cell_size,
                    self.cell_size,
                )
                pygame.draw.rect(self.window, color, rect)

        px = self.player_x * self.cell_size
        py = self.player_y * self.cell_size
        player_rect = pygame.Rect(px, py, self.cell_size, self.cell_size)
        pygame.draw.rect(self.window, (255, 255, 0), player_rect)
