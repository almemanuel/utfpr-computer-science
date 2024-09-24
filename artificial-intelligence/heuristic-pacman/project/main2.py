import copy
from board import boards
import pygame
import math
import random

pygame.init()

LARGURA = 600  # Múltiplo de 30
ALTURA = 594 + 50  # Múltiplo de 33
LARGURA_LINHA = (ALTURA - 50) // 33  # 18
LARGURA_COLUNA = LARGURA // 30  # 20
TELA = pygame.display.set_mode([LARGURA, ALTURA])
TIMER = pygame.time.Clock()
FPS = 60
FONTE = pygame.font.Font('freesansbold.ttf', 25)
LEVEL = copy.deepcopy(boards)
COR = 'red'
PI = math.pi
RAIO_CIRCULO_MENOR = 3
RAIO_CIRCULO_MAIOR = 6
PACMAN = []
for i in range(1, 5):
    PACMAN.append(pygame.transform.scale(pygame.image.load(
        f'project/assets/player_images/{i}.png'), (LARGURA_LINHA + 3, LARGURA_COLUNA + 3)))
blinky_img = pygame.transform.scale(pygame.image.load(
    f'project/assets/ghost_images/red.png'), (LARGURA_LINHA + 2, LARGURA_LINHA + 2))
pinky_img = pygame.transform.scale(pygame.image.load(
    f'project/assets/ghost_images/pink.png'), (LARGURA_LINHA + 2, LARGURA_LINHA + 2))
inky_img = pygame.transform.scale(pygame.image.load(
    f'project/assets/ghost_images/blue.png'), (LARGURA_LINHA + 2, LARGURA_LINHA + 2))
clyde_img = pygame.transform.scale(pygame.image.load(
    f'project/assets/ghost_images/orange.png'), (LARGURA_LINHA + 2, LARGURA_LINHA + 2))
spooked_img = pygame.transform.scale(pygame.image.load(
    f'project/assets/ghost_images/powerup.png'), (LARGURA_LINHA + 2, LARGURA_LINHA + 2))
dead_img = pygame.transform.scale(pygame.image.load(
    f'project/assets/ghost_images/dead.png'), (LARGURA_LINHA + 2, LARGURA_LINHA + 2))
DEFAULT_PACMAN_X = int(LARGURA_COLUNA * 13)
DEFAULT_PACMAN_Y = int(LARGURA_LINHA * 21)
PACMAN_X = DEFAULT_PACMAN_X
PACMAN_Y = DEFAULT_PACMAN_Y
direction = 0

# BLINKY - Vermelho
DEFAULT_BLINKY_X = int(LARGURA_COLUNA * 14 + (LARGURA_COLUNA / 2))
DEFAULT_BLINKY_Y = int(LARGURA_LINHA * 12)
BLINKY_X = DEFAULT_BLINKY_X
BLINKY_Y = DEFAULT_BLINKY_Y
blinky_direction = 0

# INKY - Azul
DEFAULT_INKY_X = int(LARGURA_COLUNA * 12 + (LARGURA_COLUNA / 2))
DEFAULT_INKY_Y = int(LARGURA_LINHA * 15)
INKY_X = DEFAULT_INKY_X
INKY_Y = DEFAULT_INKY_Y
inky_direction = 2

# PINKY - Rosa
DEFAULT_PINKY_X = int(LARGURA_COLUNA * 14 + (LARGURA_COLUNA / 2))
DEFAULT_PINKY_Y = int(LARGURA_LINHA * 15)
PINKY_X = DEFAULT_PINKY_X
PINKY_Y = DEFAULT_PINKY_Y
pinky_direction = 2

# CLYDE - Laranja
DEFAULT_CLYDE_X = int(LARGURA_COLUNA * 16 + (LARGURA_COLUNA / 2))
DEFAULT_CLYDE_Y = int(LARGURA_LINHA * 15)
CLYDE_X = DEFAULT_CLYDE_X
CLYDE_Y = DEFAULT_CLYDE_Y
clyde_direction = 2
counter = 0
flicker = False
# R, L, U, D
turns_allowed = [False, False, False, False]
direction_command = 0
player_speed = 2
score = 0
powerup = False
power_counter = 0
eaten_ghost = [False, False, False, False]
targets = [(PACMAN_X, PACMAN_Y), (PACMAN_X, PACMAN_Y),
           (PACMAN_X, PACMAN_Y), (PACMAN_X, PACMAN_Y)]
blinky_dead = False
inky_dead = False
clyde_dead = False
pinky_dead = False
blinky_box = False
inky_box = False
clyde_box = False
pinky_box = False
moving = False
ghost_speeds = [2, 2, 2, 2]
startup_counter = 0
lives = 2
game_over = False
game_won = False


class Ghost:
    def __init__(self, x_coord, y_coord, target, speed, img, direct, dead, box, id):
        self.x_pos = x_coord
        self.y_pos = y_coord
        self.center_x = self.x_pos + 10
        self.center_y = self.y_pos + 10
        self.target = target
        self.speed = speed
        self.img = img
        self.direction = direct
        self.dead = dead
        self.in_box = box
        self.id = id
        self.turns, self.in_box = self.fantasmaColisao()
        self.rect = self.draw()

    def draw(self):
        if (not powerup and not self.dead) or (eaten_ghost[self.id] and powerup and not self.dead):
            TELA.blit(self.img, (self.x_pos, self.y_pos))
        elif powerup and not self.dead and not eaten_ghost[self.id]:
            TELA.blit(spooked_img, (self.x_pos, self.y_pos))
        else:
            TELA.blit(dead_img, (self.x_pos, self.y_pos))
        ghost_rect = pygame.rect.Rect(
            (self.center_x - 18, self.center_y - 18), (36, 36))
        return ghost_rect

    def fantasmaColisao(self):
        # R, L, U, D
        num3 = 15
        self.turns = [False, False, False, False]
        if 0 < self.center_x // 30 < 29:
            if LEVEL[(self.center_y - num3) // LARGURA_LINHA][self.center_x // LARGURA_COLUNA] == 9:
                self.turns[2] = True
            if LEVEL[self.center_y // LARGURA_LINHA][(self.center_x - num3) // LARGURA_COLUNA] < 3 \
                    or (LEVEL[self.center_y // LARGURA_LINHA][(self.center_x - num3) // LARGURA_COLUNA] == 9 and (
                    self.in_box or self.dead)):
                self.turns[1] = True
            if LEVEL[self.center_y // LARGURA_LINHA][(self.center_x + num3) // LARGURA_COLUNA] < 3 \
                    or (LEVEL[self.center_y // LARGURA_LINHA][(self.center_x + num3) // LARGURA_COLUNA] == 9 and (
                    self.in_box or self.dead)):
                self.turns[0] = True
            if LEVEL[(self.center_y + num3) // LARGURA_LINHA][self.center_x // LARGURA_COLUNA] < 3 \
                    or (LEVEL[(self.center_y + num3) // LARGURA_LINHA][self.center_x // LARGURA_COLUNA] == 9 and (
                    self.in_box or self.dead)):
                self.turns[3] = True
            if LEVEL[(self.center_y - num3) // LARGURA_LINHA][self.center_x // LARGURA_COLUNA] < 3 \
                    or (LEVEL[(self.center_y - num3) // LARGURA_LINHA][self.center_x // LARGURA_COLUNA] == 9 and (
                    self.in_box or self.dead)):
                self.turns[2] = True

            if self.direction == 2 or self.direction == 3:
                if 12 <= self.center_x % LARGURA_COLUNA <= 18:
                    if LEVEL[(self.center_y + num3) // LARGURA_LINHA][self.center_x // LARGURA_COLUNA] < 3 \
                            or (LEVEL[(self.center_y + num3) // LARGURA_LINHA][self.center_x // LARGURA_COLUNA] == 9 and (
                            self.in_box or self.dead)):
                        self.turns[3] = True
                    if LEVEL[(self.center_y - num3) // LARGURA_LINHA][self.center_x // LARGURA_COLUNA] < 3 \
                            or (LEVEL[(self.center_y - num3) // LARGURA_LINHA][self.center_x // LARGURA_COLUNA] == 9 and (
                            self.in_box or self.dead)):
                        self.turns[2] = True
                if 12 <= self.center_y % LARGURA_LINHA <= 18:
                    if LEVEL[self.center_y // LARGURA_LINHA][(self.center_x - LARGURA_COLUNA) // LARGURA_COLUNA] < 3 \
                            or (LEVEL[self.center_y // LARGURA_LINHA][(self.center_x - LARGURA_COLUNA) // LARGURA_COLUNA] == 9 and (
                            self.in_box or self.dead)):
                        self.turns[1] = True
                    if LEVEL[self.center_y // LARGURA_LINHA][(self.center_x + LARGURA_COLUNA) // LARGURA_COLUNA] < 3 \
                            or (LEVEL[self.center_y // LARGURA_LINHA][(self.center_x + LARGURA_COLUNA) // LARGURA_COLUNA] == 9 and (
                            self.in_box or self.dead)):
                        self.turns[0] = True

            if self.direction == 0 or self.direction == 1:
                if 12 <= self.center_x % LARGURA_COLUNA <= 18:
                    if LEVEL[(self.center_y + num3) // LARGURA_LINHA][self.center_x // LARGURA_COLUNA] < 3 \
                            or (LEVEL[(self.center_y + num3) // LARGURA_LINHA][self.center_x // LARGURA_COLUNA] == 9 and (
                            self.in_box or self.dead)):
                        self.turns[3] = True
                    if LEVEL[(self.center_y - num3) // LARGURA_LINHA][self.center_x // LARGURA_COLUNA] < 3 \
                            or (LEVEL[(self.center_y - num3) // LARGURA_LINHA][self.center_x // LARGURA_COLUNA] == 9 and (
                            self.in_box or self.dead)):
                        self.turns[2] = True
                if 12 <= self.center_y % LARGURA_LINHA <= 18:
                    if LEVEL[self.center_y // LARGURA_LINHA][(self.center_x - num3) // LARGURA_COLUNA] < 3 \
                            or (LEVEL[self.center_y // LARGURA_LINHA][(self.center_x - num3) // LARGURA_COLUNA] == 9 and (
                            self.in_box or self.dead)):
                        self.turns[1] = True
                    if LEVEL[self.center_y // LARGURA_LINHA][(self.center_x + num3) // LARGURA_COLUNA] < 3 \
                            or (LEVEL[self.center_y // LARGURA_LINHA][(self.center_x + num3) // LARGURA_COLUNA] == 9 and (
                            self.in_box or self.dead)):
                        self.turns[0] = True
        else:
            self.turns[0] = True
            self.turns[1] = True
        if 350 < self.x_pos < 550 and 370 < self.y_pos < 480:
            self.in_box = True
        else:
            self.in_box = False
        return self.turns, self.in_box

    def move_clyde_ai(self):
        # Função de heurística usando a distância de Manhattan
        def heuristic(current_x, current_y, target_x, target_y):
            return abs(current_x - target_x) + abs(current_y - target_y)

        # Direções possíveis (r, l, u, d)
        directions = [(1, 0), (-1, 0), (0, -1), (0, 1)]

        best_direction = None
        best_distance = float('inf')

        for i, direction in enumerate(directions):
            # Verifique se o fantasma pode virar na direção atual (usando self.turns)
            if self.turns[i]:
                new_x = self.x_pos + direction[0] * self.speed // 2
                new_y = self.y_pos + direction[1] * self.speed // 2

                # Calcule a heurística para o próximo movimento
                distance = heuristic(
                    new_x, new_y, self.target[0], self.target[1])

                if distance < best_distance:
                    best_distance = distance
                    best_direction = direction

        # Atualize a posição do Clyde com base na direção escolhida
        if best_direction is not None:
            self.x_pos += best_direction[0] * self.speed // 2
            self.y_pos += best_direction[1] * self.speed // 2

        if self.x_pos < -30:
            self.x_pos = LARGURA
        elif self.x_pos > LARGURA + 30:
            self.x_pos -= 30

        if self.x_pos in [400, 402] and self.y_pos == 482 and not self.in_box:
            self.x_pos = 410
            self.y_pos = 500

        return self.x_pos, self.y_pos, self.direction

    def move_blinky_ai(self):
        target_x, target_y = self.target

        # Direções possíveis (r, l, u, d)
        directions = [(1, 0), (-1, 0), (0, -1), (0, 1)]

        best_direction = None
        best_distance = float('inf')

        for direction in directions:
            new_x = self.x_pos + direction[0] * self.speed // 2
            new_y = self.y_pos + direction[1] * self.speed // 2

            # Calcule a heurística para o próximo movimento
            distance = math.sqrt((new_x - target_x)**2 + (new_y - target_y)**2)

            if distance < best_distance:
                best_distance = distance
                best_direction = direction

        # Atualize a posição do Blinky com base na direção escolhida
        if best_direction is not None:
            self.x_pos += best_direction[0] * self.speed // 2
            self.y_pos += best_direction[1] * self.speed // 2

        if self.x_pos < -30:
            self.x_pos = LARGURA
        elif self.x_pos > LARGURA + 30:
            self.x_pos -= 30

        if self.x_pos in [400, 402] and self.y_pos == 482 and not self.in_box:
            self.x_pos = 410
            self.y_pos = 500

        return self.x_pos, self.y_pos, self.direction

    def move_inky_ai(self, BLINKY_X, BLINKY_Y, PINKY_X, PINKY_Y):
        target_x, target_y = self.target

        # Direções possíveis (r, l, u, d)
        directions = [(1, 0), (-1, 0), (0, -1), (0, 1)]

        best_direction = None
        best_distance = float('inf')

        for direction in directions:
            new_x = self.x_pos + direction[0] * self.speed // 2
            new_y = self.y_pos + direction[1] * self.speed // 2

            # Calcule a posição intermediária com base nas posições de Blinky e Pinky
            intermediate_x = (BLINKY_X + PINKY_X) // 2
            intermediate_y = (BLINKY_Y + PINKY_Y) // 2

            # Calcule a heurística para o próximo movimento, considerando o destino e a posição intermediária
            distance = math.sqrt((new_x - intermediate_x) **
                                 2 + (new_y - intermediate_y)**2)

            if distance < best_distance:
                best_distance = distance
                best_direction = direction

        # Atualize a posição de Inky com base na direção escolhida
        if best_direction is not None:
            self.x_pos += best_direction[0] * self.speed // 2
            self.y_pos += best_direction[1] * self.speed // 2

        if self.x_pos < -30:
            self.x_pos = LARGURA
        elif self.x_pos > LARGURA + 30:
            self.x_pos -= 30

        if self.x_pos in [400, 402] and self.y_pos == 482 and not self.in_box:
            self.x_pos = 410
            self.y_pos = 500

        return self.x_pos, self.y_pos, self.direction

    def move_pinky_ai(self):
        target_x, target_y = self.target

        # Direções possíveis (r, l, u, d)
        directions = [(1, 0), (-1, 0), (0, -1), (0, 1)]

        best_direction = None
        best_distance = float('inf')

        for direction in directions:
            new_x = self.x_pos + direction[0] * self.speed // 2
            new_y = self.y_pos + direction[1] * self.speed // 2

            # Calcule a heurística para o próximo movimento
            distance = math.sqrt((new_x - target_x)**2 + (new_y - target_y)**2)

            if distance < best_distance:
                best_distance = distance
                best_direction = direction

        # Atualize a posição do Pinky com base na direção escolhida
        if best_direction is not None:
            self.x_pos += best_direction[0] * self.speed // 2
            self.y_pos += best_direction[1] * self.speed // 2

        if self.x_pos < -30:
            self.x_pos = LARGURA
        elif self.x_pos > LARGURA + 30:
            self.x_pos -= 30

        if self.x_pos in [400, 402] and self.y_pos == 482 and not self.in_box:
            self.x_pos = 410
            self.y_pos = 500

        return self.x_pos, self.y_pos, self.direction


def draw_misc():
    score_text = FONTE.render(f'Score: {score}', True, 'white')
    TELA.blit(score_text, (10, ALTURA - 40))
    if powerup:
        pygame.draw.circle(TELA, 'blue', (140, ALTURA - 50), 15)
    for i in range(lives):
        TELA.blit(pygame.transform.scale(
            PACMAN[0], (25, 25)), (LARGURA * 0.8, ALTURA - 40))

    # Centralize o retângulo branco
    rect_width = LARGURA * 0.7
    rect_height = ALTURA * 0.35
    rect_x = (LARGURA - rect_width) / 2
    rect_y = (ALTURA - rect_height) / 2

    # Centralize o retângulo cinza escuro
    gray_rect_width = LARGURA * 0.65
    gray_rect_height = ALTURA * 0.3
    gray_rect_x = (LARGURA - gray_rect_width) / 2
    gray_rect_y = (ALTURA - gray_rect_height) / 2

    if game_over:

        pygame.draw.rect(TELA, 'white', [rect_x, rect_y,
                                         rect_width, rect_height], 0, 10)
        pygame.draw.rect(TELA, 'dark gray', [
            gray_rect_x, gray_rect_y, gray_rect_width, gray_rect_height], 0, 10)
        # Renderize o texto centralizado
        gameover_text = FONTE.render(
            'Game over! Aperte espaço!', True, 'red')
        text_width, text_height = gameover_text.get_size()
        text_x = (LARGURA - text_width) / 2
        text_y = (ALTURA - text_height) / 2
        TELA.blit(gameover_text, (text_x, text_y))

    if game_won:

        pygame.draw.rect(TELA, 'white', [rect_x, rect_y,
                                         rect_width, rect_height], 0, 10)
        pygame.draw.rect(TELA, 'dark gray', [
            gray_rect_x, gray_rect_y, gray_rect_width, gray_rect_height], 0, 10)
        gameover_text = FONTE.render(
            'Vitória! Aperte espaço!', True, 'green')
        text_width, text_height = gameover_text.get_size()
        text_x = (LARGURA - text_width) / 2
        text_y = (ALTURA - text_height) / 2
        TELA.blit(gameover_text, (text_x, text_y))


def check_collisions(scor, power, power_count, eaten_ghosts, center_x, center_y):
    if 0 < center_x < LARGURA:
        center_x = int(center_x)
        center_y = int(center_y)
        if LEVEL[center_y // LARGURA_LINHA][center_x // LARGURA_COLUNA] == 1:
            LEVEL[center_y // LARGURA_LINHA][center_x // LARGURA_COLUNA] = 0
            scor += 10
        if LEVEL[center_y // LARGURA_LINHA][center_x // LARGURA_COLUNA] == 2:
            LEVEL[center_y // LARGURA_LINHA][center_x // LARGURA_COLUNA] = 0
            scor += 50
            power = True
            power_count = 0
            eaten_ghosts = [False, False, False, False]
    return scor, power, power_count, eaten_ghosts


def desenharTabuleiro():
    for i in range(len(LEVEL)):
        for j in range(len(LEVEL[i])):
            if LEVEL[i][j] == 1:
                pygame.draw.circle(
                    TELA, 'white', (j * LARGURA_COLUNA + (0.5 * LARGURA_COLUNA), i * LARGURA_LINHA + (0.5 * LARGURA_LINHA)), RAIO_CIRCULO_MENOR)
            if LEVEL[i][j] == 2 and not flicker:
                pygame.draw.circle(
                    TELA, 'white', (j * LARGURA_COLUNA + (0.5 * LARGURA_COLUNA), i * LARGURA_LINHA + (0.5 * LARGURA_LINHA)), RAIO_CIRCULO_MAIOR)
            if LEVEL[i][j] == 3:
                pygame.draw.line(TELA, COR, (j * LARGURA_COLUNA + (0.5 * LARGURA_COLUNA), i * LARGURA_LINHA),
                                 (j * LARGURA_COLUNA + (0.5 * LARGURA_COLUNA), i * LARGURA_LINHA + LARGURA_LINHA), 3)
            if LEVEL[i][j] == 4:
                pygame.draw.line(TELA, COR, (j * LARGURA_COLUNA, i * LARGURA_LINHA + (0.5 * LARGURA_LINHA)),
                                 (j * LARGURA_COLUNA + LARGURA_COLUNA, i * LARGURA_LINHA + (0.5 * LARGURA_LINHA)), 3)
            if LEVEL[i][j] == 5:
                pygame.draw.arc(TELA, COR, [(j * LARGURA_COLUNA - (LARGURA_COLUNA * 0.4)) - 2, (i * LARGURA_LINHA + (0.5 * LARGURA_LINHA)), LARGURA_COLUNA, LARGURA_LINHA],
                                0, PI / 2, 3)
            if LEVEL[i][j] == 6:
                pygame.draw.arc(TELA, COR,
                                [(j * LARGURA_COLUNA + (LARGURA_COLUNA * 0.5)), (i * LARGURA_LINHA + (0.5 * LARGURA_LINHA)), LARGURA_COLUNA, LARGURA_LINHA], PI / 2, PI, 3)
            if LEVEL[i][j] == 7:
                pygame.draw.arc(TELA, COR, [(j * LARGURA_COLUNA + (LARGURA_COLUNA * 0.5)), (i * LARGURA_LINHA - (0.4 * LARGURA_LINHA)), LARGURA_COLUNA, LARGURA_LINHA], PI,
                                3 * PI / 2, 3)
            if LEVEL[i][j] == 8:
                pygame.draw.arc(TELA, COR,
                                [(j * LARGURA_COLUNA - (LARGURA_COLUNA * 0.4)) - 2, (i * LARGURA_LINHA -
                                                                                     (0.4 * LARGURA_LINHA)), LARGURA_COLUNA, LARGURA_LINHA], 3 * PI / 2,
                                2 * PI, 3)
            if LEVEL[i][j] == 9:
                pygame.draw.line(TELA, 'white', (j * LARGURA_COLUNA, i * LARGURA_LINHA + (0.5 * LARGURA_LINHA)),
                                 (j * LARGURA_COLUNA + LARGURA_COLUNA, i * LARGURA_LINHA + (0.5 * LARGURA_LINHA)), 3)


def desenharJogador():
    # 0-RIGHT, 1-LEFT, 2-UP, 3-DOWN
    if direction == 0:
        TELA.blit(PACMAN[counter // 5], (PACMAN_X, PACMAN_Y))
    elif direction == 1:
        TELA.blit(pygame.transform.flip(
            PACMAN[counter // 5], True, False), (PACMAN_X, PACMAN_Y))
    elif direction == 2:
        TELA.blit(pygame.transform.rotate(
            PACMAN[counter // 5], 90), (PACMAN_X, PACMAN_Y))
    elif direction == 3:
        TELA.blit(pygame.transform.rotate(
            PACMAN[counter // 5], 270), (PACMAN_X, PACMAN_Y))


def verificarPosicao(centerx, centery):
    turns = [False, False, False, False]
    num3 = 15

    if centerx // LARGURA_COLUNA < 20 and centery // LARGURA_LINHA < 18:
        if direction == 0:  # Right
            if LEVEL[centery // LARGURA_LINHA][(centerx + num3) // LARGURA_COLUNA] < 3:
                turns[0] = True
        elif direction == 1:  # Left
            if LEVEL[centery // LARGURA_LINHA][(centerx - num3) // LARGURA_COLUNA] < 3:
                turns[1] = True
        elif direction == 2:  # Up
            if LEVEL[(centery - num3) // LARGURA_LINHA][centerx // LARGURA_COLUNA] < 3:
                turns[2] = True
        elif direction == 3:  # Down
            if LEVEL[(centery + num3) // LARGURA_LINHA][centerx // LARGURA_COLUNA] < 3:
                turns[3] = True

        if direction == 2 or direction == 3:
            if 12 <= centerx % LARGURA_COLUNA <= 18:
                if LEVEL[(centery + num3) // LARGURA_LINHA][centerx // LARGURA_COLUNA] < 3:
                    turns[3] = True
                if LEVEL[(centery - num3) // LARGURA_LINHA][centerx // LARGURA_COLUNA] < 3:
                    turns[2] = True
            if 12 <= centery % LARGURA_LINHA <= 18:
                if LEVEL[centery // LARGURA_LINHA][(centerx - LARGURA_COLUNA) // LARGURA_COLUNA] < 3:
                    turns[1] = True
                if LEVEL[centery // LARGURA_LINHA][(centerx + LARGURA_COLUNA) // LARGURA_COLUNA] < 3:
                    turns[0] = True
        if direction == 0 or direction == 1:
            if 12 <= centerx % LARGURA_COLUNA <= 18:
                if LEVEL[(centery + LARGURA_LINHA) // LARGURA_LINHA][centerx // LARGURA_COLUNA] < 3:
                    turns[3] = True
                if LEVEL[(centery - LARGURA_LINHA) // LARGURA_LINHA][centerx // LARGURA_COLUNA] < 3:
                    turns[2] = True
            if 12 <= centery % LARGURA_LINHA <= 18:
                if LEVEL[centery // LARGURA_LINHA][(centerx - num3) // LARGURA_COLUNA] < 3:
                    turns[1] = True
                if LEVEL[centery // LARGURA_LINHA][(centerx + num3) // LARGURA_COLUNA] < 3:
                    turns[0] = True

    else:
        turns[0] = True
        turns[1] = True

    return turns


def movimentar(play_x, play_y):
    # r, l, u, d
    if direction == 0 and turns_allowed[0]:
        play_x += player_speed
    elif direction == 1 and turns_allowed[1]:
        play_x -= player_speed
    if direction == 2 and turns_allowed[2]:
        play_y -= player_speed
    elif direction == 3 and turns_allowed[3]:
        play_y += player_speed
    return play_x, play_y


def get_targets(blink_x, blink_y, ink_x, ink_y, pink_x, pink_y, clyd_x, clyd_y):
    if PACMAN_X < 450:
        runaway_x = 900
    else:
        runaway_x = 0
    if PACMAN_Y < 450:
        runaway_y = 900
    else:
        runaway_y = 0
    return_target = (380, 400)
    if powerup:
        if not blinky.dead and not eaten_ghost[0]:
            blink_target = (runaway_x, runaway_y)
        elif not blinky.dead and eaten_ghost[0]:
            if 340 < blink_x < 560 and 340 < blink_y < 500:
                blink_target = (DEFAULT_BLINKY_X, DEFAULT_BLINKY_Y)
            else:
                blink_target = (PACMAN_X, PACMAN_Y)
        else:
            blink_target = return_target
        if not inky.dead and not eaten_ghost[1]:
            ink_target = (runaway_x, PACMAN_Y)
        elif not inky.dead and eaten_ghost[1]:
            if 340 < ink_x < 560 and 340 < ink_y < 500:
                ink_target = (DEFAULT_BLINKY_X, DEFAULT_BLINKY_Y)
            else:
                ink_target = (PACMAN_X, PACMAN_Y)
        else:
            ink_target = return_target
        if not pinky.dead:
            pink_target = (PACMAN_X, runaway_y)
        elif not pinky.dead and eaten_ghost[2]:
            if 340 < pink_x < 560 and 340 < pink_y < 500:
                pink_target = (DEFAULT_BLINKY_X, DEFAULT_BLINKY_Y)
            else:
                pink_target = (PACMAN_X, PACMAN_Y)
        else:
            pink_target = return_target
        if not clyde.dead and not eaten_ghost[3]:
            clyd_target = (450, 450)
        elif not clyde.dead and eaten_ghost[3]:
            if 340 < clyd_x < 560 and 340 < clyd_y < 500:
                clyd_target = (DEFAULT_BLINKY_X, DEFAULT_BLINKY_Y)
            else:
                clyd_target = (PACMAN_X, PACMAN_Y)
        else:
            clyd_target = return_target
    else:
        if not blinky.dead:
            if 340 < blink_x < 560 and 340 < blink_y < 500:
                blink_target = (DEFAULT_BLINKY_X, DEFAULT_BLINKY_Y)
            else:
                blink_target = (PACMAN_X, PACMAN_Y)
        else:
            blink_target = return_target
        if not inky.dead:
            if 340 < ink_x < 560 and 340 < ink_y < 500:
                ink_target = (DEFAULT_BLINKY_X, DEFAULT_BLINKY_Y)
            else:
                ink_target = (PACMAN_X, PACMAN_Y)
        else:
            ink_target = return_target
        if not pinky.dead:
            if 340 < pink_x < 560 and 340 < pink_y < 500:
                pink_target = (DEFAULT_BLINKY_X, DEFAULT_BLINKY_Y)
            else:
                pink_target = (PACMAN_X, PACMAN_Y)
        else:
            pink_target = return_target
        if not clyde.dead:
            if 340 < clyd_x < 560 and 340 < clyd_y < 500:
                clyd_target = (DEFAULT_BLINKY_X, DEFAULT_BLINKY_Y)
            else:
                clyd_target = (PACMAN_X, PACMAN_Y)
        else:
            clyd_target = return_target
    return [blink_target, ink_target, pink_target, clyd_target]


run = True
while run:
    TIMER.tick(FPS)
    if counter < 19:
        counter += 1
        if counter > 3:
            flicker = False
    else:
        counter = 0
        flicker = True
    if powerup and power_counter < 600:
        power_counter += 1
    elif powerup and power_counter >= 600:
        power_counter = 0
        powerup = False
        eaten_ghost = [False, False, False, False]
    if startup_counter < 180 and not game_over and not game_won:
        moving = False
        startup_counter += 1
    else:
        moving = True

    TELA.fill('black')
    desenharTabuleiro()
    center_x = PACMAN_X + 10
    center_y = PACMAN_Y + 10
    if powerup:
        ghost_speeds = [1, 1, 1, 1]
    else:
        ghost_speeds = [2, 2, 2, 2]
    if eaten_ghost[0]:
        ghost_speeds[0] = 2
    if eaten_ghost[1]:
        ghost_speeds[1] = 2
    if eaten_ghost[2]:
        ghost_speeds[2] = 2
    if eaten_ghost[3]:
        ghost_speeds[3] = 2
    if blinky_dead:
        ghost_speeds[0] = 4
    if inky_dead:
        ghost_speeds[1] = 4
    if pinky_dead:
        ghost_speeds[2] = 4
    if clyde_dead:
        ghost_speeds[3] = 4

    game_won = True
    for i in range(len(LEVEL)):
        if 1 in LEVEL[i] or 2 in LEVEL[i]:
            game_won = False

    player_circle = pygame.draw.circle(
        TELA, 'red', (center_x, center_y), LARGURA_LINHA / 2, 1)
    desenharJogador()
    blinky = Ghost(BLINKY_X, BLINKY_Y, targets[0], ghost_speeds[0], blinky_img, blinky_direction, blinky_dead,
                   blinky_box, 0)
    inky = Ghost(INKY_X, INKY_Y, targets[1], ghost_speeds[1], inky_img, inky_direction, inky_dead,
                 inky_box, 1)
    pinky = Ghost(PINKY_X, PINKY_Y, targets[2], ghost_speeds[2], pinky_img, pinky_direction, pinky_dead,
                  pinky_box, 2)
    clyde = Ghost(CLYDE_X, CLYDE_Y, targets[3], ghost_speeds[3], clyde_img, clyde_direction, clyde_dead,
                  clyde_box, 3)
    draw_misc()
    targets = get_targets(BLINKY_X, BLINKY_Y, INKY_X,
                          INKY_Y, PINKY_X, PINKY_Y, CLYDE_X, CLYDE_Y)

    turns_allowed = verificarPosicao(center_x, center_y)
    if moving:
        PACMAN_X, PACMAN_Y = movimentar(PACMAN_X, PACMAN_Y)
        if not blinky_dead and not blinky.in_box:
            # BLINKY_X, BLINKY_Y, blinky_direction = blinky.move_blinky()
            BLINKY_X, BLINKY_Y, blinky_direction = blinky.move_blinky_ai()

        else:
            #    BLINKY_X, BLINKY_Y, blinky_direction = blinky.move_clyde()
            BLINKY_X, BLINKY_Y, blinky_direction = blinky.move_clyde_ai()

        if not pinky_dead and not pinky.in_box:
            # PINKY_X, PINKY_Y, pinky_direction = pinky.move_pinky()
            PINKY_X, PINKY_Y, pinky_direction = pinky.move_pinky_ai()

        else:
            # PINKY_X, PINKY_Y, pinky_direction = pinky.move_clyde()
            PINKY_X, PINKY_Y, pinky_direction = pinky.move_clyde_ai()

        if not inky_dead and not inky.in_box:
            INKY_X, INKY_Y, inky_direction = inky.move_inky_ai(
                BLINKY_X, BLINKY_Y, PINKY_X, PINKY_Y)
        else:
            # INKY_X, INKY_Y, inky_direction = inky.move_clyde()
            INKY_X, INKY_Y, inky_direction = inky.move_clyde_ai()

        # CLYDE_X, CLYDE_Y, clyde_direction = clyde.move_clyde()
        CLYDE_X, CLYDE_Y, clyde_direction = clyde.move_clyde_ai()
    score, powerup, power_counter, eaten_ghost = check_collisions(
        score, powerup, power_counter, eaten_ghost, center_x, center_y)
    # add to if not powerup to check if eaten ghosts
    if not powerup:
        if (player_circle.colliderect(blinky.rect) and not blinky.dead) or \
                (player_circle.colliderect(inky.rect) and not inky.dead) or \
                (player_circle.colliderect(pinky.rect) and not pinky.dead) or \
                (player_circle.colliderect(clyde.rect) and not clyde.dead):
            if lives > 0:
                lives -= 1
                startup_counter = 0
                powerup = False
                power_counter = 0
                PACMAN_X = DEFAULT_PACMAN_X
                PACMAN_Y = DEFAULT_PACMAN_Y
                direction = 0
                direction_command = 0
                BLINKY_X = DEFAULT_BLINKY_X
                BLINKY_Y = DEFAULT_BLINKY_Y
                blinky_direction = 0
                INKY_X = DEFAULT_INKY_X
                INKY_Y = DEFAULT_INKY_Y
                inky_direction = 2
                PINKY_X = DEFAULT_PINKY_X
                PINKY_Y = DEFAULT_PINKY_Y
                pinky_direction = 2
                CLYDE_X = DEFAULT_CLYDE_X
                CLYDE_Y = DEFAULT_CLYDE_Y
                clyde_direction = 2
                eaten_ghost = [False, False, False, False]
                blinky_dead = False
                inky_dead = False
                clyde_dead = False
                pinky_dead = False
            else:
                game_over = True
                moving = False
                startup_counter = 0
    if powerup and player_circle.colliderect(blinky.rect) and eaten_ghost[0] and not blinky.dead:
        if lives > 0:
            powerup = False
            power_counter = 0
            lives -= 1
            startup_counter = 0
            PACMAN_X = DEFAULT_PACMAN_X
            PACMAN_Y = DEFAULT_PACMAN_Y
            direction = 0
            direction_command = 0
            BLINKY_X = DEFAULT_BLINKY_X
            BLINKY_Y = DEFAULT_BLINKY_Y
            blinky_direction = 0
            INKY_X = DEFAULT_INKY_X
            INKY_Y = DEFAULT_INKY_Y
            inky_direction = 2
            PINKY_X = DEFAULT_PINKY_X
            PINKY_Y = DEFAULT_PINKY_Y
            pinky_direction = 2
            CLYDE_X = DEFAULT_CLYDE_X
            CLYDE_Y = DEFAULT_CLYDE_Y
            clyde_direction = 2
            eaten_ghost = [False, False, False, False]
            blinky_dead = False
            inky_dead = False
            clyde_dead = False
            pinky_dead = False
        else:
            game_over = True
            moving = False
            startup_counter = 0
    if powerup and player_circle.colliderect(inky.rect) and eaten_ghost[1] and not inky.dead:
        if lives > 0:
            powerup = False
            power_counter = 0
            lives -= 1
            startup_counter = 0
            PACMAN_X = DEFAULT_PACMAN_X
            PACMAN_Y = DEFAULT_PACMAN_Y
            direction = 0
            direction_command = 0
            BLINKY_X = DEFAULT_BLINKY_X
            BLINKY_Y = DEFAULT_BLINKY_Y
            blinky_direction = 0
            INKY_X = DEFAULT_INKY_X
            INKY_Y = DEFAULT_INKY_Y
            inky_direction = 2
            PINKY_X = DEFAULT_PINKY_X
            PINKY_Y = DEFAULT_PINKY_Y
            pinky_direction = 2
            CLYDE_X = DEFAULT_CLYDE_X
            CLYDE_Y = DEFAULT_CLYDE_Y
            clyde_direction = 2
            eaten_ghost = [False, False, False, False]
            blinky_dead = False
            inky_dead = False
            clyde_dead = False
            pinky_dead = False
        else:
            game_over = True
            moving = False
            startup_counter = 0
    if powerup and player_circle.colliderect(pinky.rect) and eaten_ghost[2] and not pinky.dead:
        if lives > 0:
            powerup = False
            power_counter = 0
            lives -= 1
            startup_counter = 0
            PACMAN_X = DEFAULT_PACMAN_X
            PACMAN_Y = DEFAULT_PACMAN_Y
            direction = 0
            direction_command = 0
            BLINKY_X = DEFAULT_BLINKY_X
            BLINKY_Y = DEFAULT_BLINKY_Y
            blinky_direction = 0
            INKY_X = DEFAULT_INKY_Y
            INKY_Y = DEFAULT_INKY_X
            inky_direction = 2
            PINKY_X = DEFAULT_PINKY_X
            PINKY_Y = DEFAULT_PINKY_Y
            pinky_direction = 2
            CLYDE_X = DEFAULT_CLYDE_X
            CLYDE_Y = DEFAULT_CLYDE_Y
            clyde_direction = 2
            eaten_ghost = [False, False, False, False]
            blinky_dead = False
            inky_dead = False
            clyde_dead = False
            pinky_dead = False
        else:
            game_over = True
            moving = False
            startup_counter = 0
    if powerup and player_circle.colliderect(clyde.rect) and eaten_ghost[3] and not clyde.dead:
        if lives > 0:
            powerup = False
            power_counter = 0
            lives -= 1
            startup_counter = 0
            PACMAN_X = DEFAULT_PACMAN_X
            PACMAN_Y = DEFAULT_PACMAN_Y
            direction = 0
            direction_command = 0
            BLINKY_X = DEFAULT_BLINKY_X
            BLINKY_Y = DEFAULT_BLINKY_Y
            blinky_direction = 0
            INKY_X = DEFAULT_INKY_X
            INKY_Y = DEFAULT_INKY_Y
            inky_direction = 2
            PINKY_X = DEFAULT_PINKY_X
            PINKY_Y = DEFAULT_PINKY_Y
            pinky_direction = 2
            CLYDE_X = DEFAULT_CLYDE_X
            CLYDE_Y = DEFAULT_CLYDE_Y
            clyde_direction = 2
            eaten_ghost = [False, False, False, False]
            blinky_dead = False
            inky_dead = False
            clyde_dead = False
            pinky_dead = False
        else:
            game_over = True
            moving = False
            startup_counter = 0
    if powerup and player_circle.colliderect(blinky.rect) and not blinky.dead and not eaten_ghost[0]:
        blinky_dead = True
        eaten_ghost[0] = True
        score += (2 ** eaten_ghost.count(True)) * 100
    if powerup and player_circle.colliderect(inky.rect) and not inky.dead and not eaten_ghost[1]:
        inky_dead = True
        eaten_ghost[1] = True
        score += (2 ** eaten_ghost.count(True)) * 100
    if powerup and player_circle.colliderect(pinky.rect) and not pinky.dead and not eaten_ghost[2]:
        pinky_dead = True
        eaten_ghost[2] = True
        score += (2 ** eaten_ghost.count(True)) * 100
    if powerup and player_circle.colliderect(clyde.rect) and not clyde.dead and not eaten_ghost[3]:
        clyde_dead = True
        eaten_ghost[3] = True
        score += (2 ** eaten_ghost.count(True)) * 100

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_RIGHT:
                direction_command = 0
            if event.key == pygame.K_LEFT:
                direction_command = 1
            if event.key == pygame.K_UP:
                direction_command = 2
            if event.key == pygame.K_DOWN:
                direction_command = 3
            if event.key == pygame.K_SPACE and (game_over or game_won):
                powerup = False
                power_counter = 0
                lives -= 1
                startup_counter = 0
                PACMAN_X = int(LARGURA_COLUNA * 13)
                PACMAN_Y = int(LARGURA_LINHA * 21 + (LARGURA_LINHA / 2))
                direction = 0
                direction_command = 0
                BLINKY_X = DEFAULT_BLINKY_X
                BLINKY_Y = DEFAULT_BLINKY_Y
                blinky_direction = 0
                INKY_X = DEFAULT_INKY_X
                INKY_Y = DEFAULT_INKY_Y
                inky_direction = 2
                PINKY_X = DEFAULT_PINKY_X
                PINKY_Y = DEFAULT_PINKY_Y
                pinky_direction = 2
                CLYDE_X = DEFAULT_CLYDE_X
                CLYDE_Y = DEFAULT_CLYDE_Y
                clyde_direction = 2
                eaten_ghost = [False, False, False, False]
                blinky_dead = False
                inky_dead = False
                clyde_dead = False
                pinky_dead = False
                score = 0
                lives = 3
                LEVEL = copy.deepcopy(boards)
                game_over = False
                game_won = False

        if event.type == pygame.KEYUP:
            if event.key == pygame.K_RIGHT and direction_command == 0:
                direction_command = direction
            if event.key == pygame.K_LEFT and direction_command == 1:
                direction_command = direction
            if event.key == pygame.K_UP and direction_command == 2:
                direction_command = direction
            if event.key == pygame.K_DOWN and direction_command == 3:
                direction_command = direction

    if direction_command == 0 and turns_allowed[0]:
        direction = 0
    if direction_command == 1 and turns_allowed[1]:
        direction = 1
    if direction_command == 2 and turns_allowed[2]:
        direction = 2
    if direction_command == 3 and turns_allowed[3]:
        direction = 3

    if PACMAN_X > LARGURA:
        PACMAN_X = -50
    elif PACMAN_X < -50:
        PACMAN_X = LARGURA

    if blinky.in_box and blinky_dead:
        blinky_dead = False
    if inky.in_box and inky_dead:
        inky_dead = False
    if pinky.in_box and pinky_dead:
        pinky_dead = False
    if clyde.in_box and clyde_dead:
        clyde_dead = False

    pygame.display.flip()
pygame.quit()
