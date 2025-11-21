import pygame
from entity import Entity
from config import ASCII_PLAYER


class Player(Entity):
    def __init__(self, x, y, color=(255, 255, 0)):
        super().__init__(x, y, ASCII_PLAYER, color)
        self.move_delay = 120
        self.last_move = 0

    def update(self, dt, keys, game_map):
        self.last_move += dt
        if self.last_move < self.move_delay:
            return

        dx, dy = 0, 0

        if keys[pygame.K_w] or keys[pygame.K_UP]:
            dy = -1
        elif keys[pygame.K_s] or keys[pygame.K_DOWN]:
            dy = 1
        elif keys[pygame.K_a] or keys[pygame.K_LEFT]:
            dx = -1
        elif keys[pygame.K_d] or keys[pygame.K_RIGHT]:
            dx = 1

        if dx != 0 or dy != 0:
            self.move(dx, dy, game_map)
            self.last_move = 0
