# src/main.py
"""
EcoMon - main.py
Entry point of the project. Initializes Pygame, creates the window,
loads the main Game class, and runs the main loop.

If game.py is not available yet, a fallback demo (FallbackGame)
is used so development can start immediately.

Usage:
    python main.py
    python main.py --width 800 --height 600 --fps 60
"""

from __future__ import annotations
import sys
import argparse
import logging
import time
from dataclasses import dataclass
from typing import Tuple

# Try loading the real Game implementation (to be created later)
try:
    from game import Game  # type: ignore
    GAME_IMPORT_OK = True
except Exception:
    GAME_IMPORT_OK = False

import pygame

# ---------------------------------------------------------
# App Configuration
# ---------------------------------------------------------
APP_TITLE = "EcoMon - Ecosystem Simulator (Prototype)"
DEFAULT_WIDTH = 960
DEFAULT_HEIGHT = 640
DEFAULT_FPS = 60
BACKGROUND_COLOR = (30, 30, 40)

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(message)s",
    handlers=[logging.StreamHandler(sys.stdout)]
)
logger = logging.getLogger("ecomon")

# ---------------------------------------------------------
# ASCII Banner
# ---------------------------------------------------------
ASCII_BANNER = r"""
  ______  _      ____  _   _  _   _  _   _ 
 |  ____|| |    / __ \| \ | || \ | || \ | |
 | |__   | |   | |  | |  \| ||  \| ||  \| |
 |  __|  | |   | |  | | . ` || . ` || . ` |
 | |     | |___| |__| | |\  || |\  || |\  |
 |_|     |______\____/|_| \_||_| \_||_| \_|
 
        Ecosystem Simulator - Prototype
"""

# ---------------------------------------------------------
# Simple vector object
# ---------------------------------------------------------
@dataclass
class Vec2:
    x: float
    y: float

    def as_int(self) -> Tuple[int, int]:
        return int(self.x), int(self.y)


# ---------------------------------------------------------
# Fallback Game (used before real game is implemented)
# ---------------------------------------------------------
class FallbackGame:
    """
    Minimal temporary game to test controls, window, input, and loop.
    The player is a moving square controlled by arrow keys or WASD.
    """

    PLAYER_SIZE = 28
    PLAYER_SPEED = 180  # pixels per second

    def __init__(self, width: int, height: int, surface: pygame.Surface):
        self.width = width
        self.height = height
        self.surface = surface
        self.player_pos = Vec2(width // 2, height // 2)
        self.player_color = (200, 200, 60)
        self.background_color = BACKGROUND_COLOR
        self.font = pygame.font.Font(None, 20)
        self.running = True

    # --------------------------
    # Event Handling
    # --------------------------
    def handle_events(self) -> None:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                logger.info("QUIT event received.")
                self.running = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    logger.info("ESC pressed — closing.")
                    self.running = False

    # --------------------------
    # Logic Update
    # --------------------------
    def update(self, dt: float) -> None:
        keys = pygame.key.get_pressed()

        dx = 0.0
        dy = 0.0
        if keys[pygame.K_LEFT] or keys[pygame.K_a]:
            dx -= 1.0
        if keys[pygame.K_RIGHT] or keys[pygame.K_d]:
            dx += 1.0
        if keys[pygame.K_UP] or keys[pygame.K_w]:
            dy -= 1.0
        if keys[pygame.K_DOWN] or keys[pygame.K_s]:
            dy += 1.0

        # Normalize diagonal speed
        if dx != 0 and dy != 0:
            diagonal_factor = 2 ** 0.5
            dx /= diagonal_factor
            dy /= diagonal_factor

        # Movement with delta time
        self.player_pos.x += dx * self.PLAYER_SPEED * dt
        self.player_pos.y += dy * self.PLAYER_SPEED * dt

        half = self.PLAYER_SIZE // 2
        self.player_pos.x = max(half, min(self.width - half, self.player_pos.x))
        self.player_pos.y = max(half, min(self.height - half, self.player_pos.y))

    # --------------------------
    # Drawing
    # --------------------------
    def draw(self, surface: pygame.Surface, fps: float) -> None:
        surface.fill(self.background_color)
        self._draw_grid(surface)

        # Draw player
        rect_center = self.player_pos.as_int()
        rect = pygame.Rect(0, 0, self.PLAYER_SIZE, self.PLAYER_SIZE)
        rect.center = rect_center
        pygame.draw.rect(surface, self.player_color, rect)

        # HUD
        fps_text = self.font.render(f"FPS: {fps:.1f}", True, (200, 200, 200))
        surface.blit(fps_text, (8, 8))

        controls_text = "Move: WASD / arrows — ESC to quit"
        text_surf = self.font.render(controls_text, True, (180, 180, 180))
        surface.blit(text_surf, (8, self.height - 26))

    def _draw_grid(self, surface: pygame.Surface, tile_size: int = 32):
        w, h = surface.get_size()
        color = (40, 40, 50)
        for x in range(0, w, tile_size):
            pygame.draw.line(surface, color, (x, 0), (x, h))
        for y in range(0, h, tile_size):
            pygame.draw.line(surface, color, (0, y), (w, y))


# ---------------------------------------------------------
# Helper Functions
# ---------------------------------------------------------
def parse_args(argv):
    parser = argparse.ArgumentParser(description="EcoMon - Ecosystem Simulator Prototype")
    parser.add_argument("--width", type=int, default=DEFAULT_WIDTH)
    parser.add_argument("--height", type=int, default=DEFAULT_HEIGHT)
    parser.add_argument("--fps", type=int, default=DEFAULT_FPS)
    parser.add_argument("--no-banner", action="true")
    return parser.parse_args(argv)


def init_pygame(title: str, width: int, height: int) -> pygame.Surface:
    pygame.mixer.pre_init(44100, -16, 2, 512)
    pygame.init()
    pygame.display.set_caption(title)
    return pygame.display.set_mode((width, height), pygame.RESIZABLE)


# ---------------------------------------------------------
# Main Entry Point
# ---------------------------------------------------------
def main(argv=None):
    args = parse_args(argv or sys.argv[1:])

    if not args.no_banner:
        print(ASCII_BANNER)

    logger.info("Initializing Pygame...")
    surface = init_pygame(APP_TITLE, args.width, args.height)

    # Try instantiating real game
    if GAME_IMPORT_OK:
        try:
            game = Game(args.width, args.height, surface)  # type: ignore
            logger.info("Loaded Game class from game.py")
        except Exception as e:
            logger.exception("Error instantiating Game(). Using fallback instead.")
            game = FallbackGame(args.width, args.height, surface)
    else:
        logger.warning("game.py not found. Using fallback preview mode.")
        game = FallbackGame(args.width, args.height, surface)

    clock = pygame.time.Clock()
    target_fps = max(10, args.fps)
    last_time = time.perf_counter()

    logger.info("Entering main loop. Press ESC to exit.")

    while getattr(game, "running", True):
        now = time.perf_counter()
        dt = now - last_time
        last_time = now

        game.handle_events()
        game.update(dt)

        fps = clock.get_fps() if clock.get_fps() > 0 else float(target_fps)
        game.draw(surface, fps)

        pygame.display.flip()
        clock.tick(target_fps)

        if hasattr(game, "running") and not game.running:
            break

    logger.info("Shutting down Pygame.")
    pygame.quit()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
