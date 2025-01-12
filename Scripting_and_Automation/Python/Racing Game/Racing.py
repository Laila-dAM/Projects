import pygame
import random

pygame.init()
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
LIGHT_GREEN = (144, 238, 144)
BLUE = (0, 0, 255)

SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600

screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Obstacle Course Game with Kaomojis")

kaomojis_player = "─=≡Σ(((  •̀ω•́)"
kaomojis_obstacle = "( ´O` )"
kaomojis_speed = "ᓚ₍ ^. .^₎"
kaomojis_after_speed = ".𖥔 ݁ ˖.𖥔 ݁ ˖.𖥔 ݁ ˖. ݁₊ ⊹ . ݁˖ . ݁.𖥔 ݁ ˖"

def draw_player(x, y, has_speed_item):
    kaomoji = kaomojis_after_speed if has_speed_item else kaomojis_player
    font = pygame.font.SysFont("Arial", 36)
    text = font.render(kaomoji, True, LIGHT_GREEN)
    screen.blit(text, (x, y))

def create_obstacle():
    return pygame.Rect(Screen_WIDTH, random.randint(300, 500), 40, 40)

def create_speed_item():
    return pygame.Rect(SCREEN_WIDTH, random.randint(300, 500), 30, 30)

def game_loop():
    player_x = 100
    player_y = SCREEN_HEIGHT - 100
    player_rect = pygame.Rect(player_x, player_y, 40, 40)
    has_speed_item = False

obstacles = []
speed_items = []
score = 0
game_over = False
speed = 5

clock = pygame.time.Clock()

while not game_over:
    screen.fill(BLACK)

for event in pygame.event.get():
    if event.type == pygame.QUIT:
        game_over = True

keys = pygame.key.get_pressed()
if keys[pygame.K_UP] and player_rect.top > 0:
    player_rect.y -= 10
if keys[pygame.k_DOWN] and player_rect.bottom < SCREEN_HEIGHT:
    player_rect.y += 10

if random.randint(1, 20) == 1:
    obstacles.append(create_obstacle())
if random.randint(1, 50) == 1:
    speed_items.append(create_speed_item())

for obstacle in obstacles:
    obstacle.x -= speed
    if obstacle.colliderect(player_rect):
        game_over = True

for speed_item in speed_items:
    speed_item.x -= speed
    if speed_item.colliderect(player_rect):
        has_speed_item = True

obstacles = [obstacle for obstacle in obstacles if obstacle.x > 0]
speed_items = [item for item in speed_items if item.x > 0]

for obstacle in obstacles:
    font = pygame.font.SysFont("Arial", 36)
    text = font.render(kaomojis_obstacle, True, RED)
    screen.blit(text, (obstacle.x, obstacle.y))
    
for speed_item in speed_items:
    font = pygame.font.SysFont("Arial", 36)
    text = font.render(kaomojis_speed, True, BLUE)
    screen.blit(text, (speed_item.x, speed_item.y))

draw_player(player_rect.x, player_rect.y, has_speed_item)

score += 1

font = pygame.font.SysFont("Arial", 24)
score_text = font.render(f"Score: {score}", True, GREEN)
screen.blit(score_text, (10, 10))

pygame.display.flip()

clock.tick(60)

pygame.quit()

game_loop()
