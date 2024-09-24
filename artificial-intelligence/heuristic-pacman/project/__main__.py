
import copy
from board import boards1, boards2, boards3
import pygame
import math

pygame.init()

GHOST_START = {
    'pinky': {
        'x': 490,
        'y': 440
    },
    'blinky': {
        'x': 490,
        'y': 390
    },
    'inky': {
        'x': 370,
        'y': 440
    },
    'clyde': {
        'x': 370,
        'y': 390
    }
}
LARGURA = 900
ALTURA = 950
TELA = pygame.display.set_mode([LARGURA, ALTURA])
TIMER = pygame.time.Clock()
FPS = 60
FONTE = pygame.font.Font('freesansbold.ttf', 20)
FASE_1 = copy.deepcopy(boards1)
FASE_2 = copy.deepcopy(boards2)
FASE_3 = copy.deepcopy(boards3)
FASES = [FASE_1, FASE_2, FASE_3]
LEVEL = FASES[0]
CONTADOR_FASE = 0
COR = 'blue'
PI = math.pi
PACMAN = []
for i in range(1, 5):
    PACMAN.append(pygame.transform.scale(pygame.image.load(
        f'project/assets/player_images/{i}.png'), (45, 45)))
blinky_img = pygame.transform.scale(pygame.image.load(
    f'project/assets/ghost_images/red.png'), (45, 45))
pinky_img = pygame.transform.scale(pygame.image.load(
    f'project/assets/ghost_images/pink.png'), (45, 45))
inky_img = pygame.transform.scale(pygame.image.load(
    f'project/assets/ghost_images/blue.png'), (45, 45))
clyde_img = pygame.transform.scale(pygame.image.load(
    f'project/assets/ghost_images/orange.png'), (45, 45))
spooked_img = pygame.transform.scale(pygame.image.load(
    f'project/assets/ghost_images/powerup.png'), (45, 45))
dead_img = pygame.transform.scale(pygame.image.load(
    f'project/assets/ghost_images/dead.png'), (45, 45))
player_x = 450
player_y = 663
direction = 0
blinky_x = GHOST_START['blinky']['x']
blinky_y = GHOST_START['blinky']['y']
blinky_direction = 0
inky_x = GHOST_START['inky']['x']
inky_y = GHOST_START['inky']['y']
inky_direction = 0
pinky_x = GHOST_START['pinky']['x']
pinky_y = GHOST_START['pinky']['y']
pinky_direction = 0
clyde_x = GHOST_START['clyde']['x']
clyde_y = GHOST_START['clyde']['y']
clyde_direction = 0
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
targets = [(player_x, player_y), (player_x, player_y),
           (player_x, player_y), (player_x, player_y)]
blinky_dead = False
inky_dead = False
clyde_dead = False
pinky_dead = False
blinky_box = False
inky_box = False
clyde_box = False
pinky_box = False
moving = False
ghost_speeds = [1, 1, 1, 1]
startup_counter = 0
lives = 3
game_over = False
game_won = False


class Ghost:
    def __init__(self, x_coord, y_coord, target, speed, img, direct, dead, box, id):
        self.x_pos = x_coord
        self.y_pos = y_coord
        self.center_x = self.x_pos + 22
        self.center_y = self.y_pos + 22
        self.target = target
        self.speed = speed
        self.img = img
        self.direction = direct
        self.dead = dead
        self.in_box = box
        self.id = id
        self.turns, self.in_box = self.check_collisions()
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

    def check_collisions(self):
        # R, L, U, D
        num1 = ((ALTURA - 50) // 32)
        num2 = (LARGURA // 30)
        num3 = 15
        self.turns = [False, False, False, False]
        if 0 < self.center_x // 30 < 29:
            if LEVEL[(self.center_y - num3) // num1][self.center_x // num2] == 9:
                self.turns[2] = True
            if LEVEL[self.center_y // num1][(self.center_x - num3) // num2] < 3 \
                    or (LEVEL[self.center_y // num1][(self.center_x - num3) // num2] == 9 and (
                    self.in_box or self.dead)):
                self.turns[1] = True
            if LEVEL[self.center_y // num1][(self.center_x + num3) // num2] < 3 \
                    or (LEVEL[self.center_y // num1][(self.center_x + num3) // num2] == 9 and (
                    self.in_box or self.dead)):
                self.turns[0] = True
            if LEVEL[(self.center_y + num3) // num1][self.center_x // num2] < 3 \
                    or (LEVEL[(self.center_y + num3) // num1][self.center_x // num2] == 9 and (
                    self.in_box or self.dead)):
                self.turns[3] = True
            if LEVEL[(self.center_y - num3) // num1][self.center_x // num2] < 3 \
                    or (LEVEL[(self.center_y - num3) // num1][self.center_x // num2] == 9 and (
                    self.in_box or self.dead)):
                self.turns[2] = True

            if self.direction == 2 or self.direction == 3:
                if 12 <= self.center_x % num2 <= 18:
                    if LEVEL[(self.center_y + num3) // num1][self.center_x // num2] < 3 \
                            or (LEVEL[(self.center_y + num3) // num1][self.center_x // num2] == 9 and (
                            self.in_box or self.dead)):
                        self.turns[3] = True
                    if LEVEL[(self.center_y - num3) // num1][self.center_x // num2] < 3 \
                            or (LEVEL[(self.center_y - num3) // num1][self.center_x // num2] == 9 and (
                            self.in_box or self.dead)):
                        self.turns[2] = True
                if 12 <= self.center_y % num1 <= 18:
                    if LEVEL[self.center_y // num1][(self.center_x - num2) // num2] < 3 \
                            or (LEVEL[self.center_y // num1][(self.center_x - num2) // num2] == 9 and (
                            self.in_box or self.dead)):
                        self.turns[1] = True
                    if LEVEL[self.center_y // num1][(self.center_x + num2) // num2] < 3 \
                            or (LEVEL[self.center_y // num1][(self.center_x + num2) // num2] == 9 and (
                            self.in_box or self.dead)):
                        self.turns[0] = True

            if self.direction == 0 or self.direction == 1:
                if 12 <= self.center_x % num2 <= 18:
                    if LEVEL[(self.center_y + num3) // num1][self.center_x // num2] < 3 \
                            or (LEVEL[(self.center_y + num3) // num1][self.center_x // num2] == 9 and (
                            self.in_box or self.dead)):
                        self.turns[3] = True
                    if LEVEL[(self.center_y - num3) // num1][self.center_x // num2] < 3 \
                            or (LEVEL[(self.center_y - num3) // num1][self.center_x // num2] == 9 and (
                            self.in_box or self.dead)):
                        self.turns[2] = True
                if 12 <= self.center_y % num1 <= 18:
                    if LEVEL[self.center_y // num1][(self.center_x - num3) // num2] < 3 \
                            or (LEVEL[self.center_y // num1][(self.center_x - num3) // num2] == 9 and (
                            self.in_box or self.dead)):
                        self.turns[1] = True
                    if LEVEL[self.center_y // num1][(self.center_x + num3) // num2] < 3 \
                            or (LEVEL[self.center_y // num1][(self.center_x + num3) // num2] == 9 and (
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

    def move_blinky_ai(self):
        
        def heuristic(current_x, current_y, target_x, target_y):
            return abs(current_x - target_x) + abs(current_y - target_y)
        
        target_x, target_y = self.target
        
        directions = [(1, 0), (-1, 0), (0, -1), (0, 1)]

        best_direction = None
        best_distance = float('inf')

        for i, direction in enumerate(directions):

            if self.turns[i]:
                new_x = self.x_pos + direction[0] * self.speed // 2
                new_y = self.y_pos + direction[1] * self.speed // 2
                distance = math.sqrt((new_x - target_x)**2 + (new_y - target_y)**2) 
                + heuristic(new_x, new_y, target_x, target_y)

                if distance < best_distance:
                    best_distance = distance
                    best_direction = direction

        if best_direction is not None:
            self.x_pos += best_direction[0] * self.speed // 2
            self.y_pos += best_direction[1] * self.speed // 2

        if self.x_pos < -30:
            self.x_pos = 900
        elif self.x_pos > 900:
            self.x_pos -= 30

        if self.x_pos in [400, 402] and self.y_pos == 482 and not self.in_box:
            self.x_pos = 410
            self.y_pos = 500

        return self.x_pos, self.y_pos, self.direction

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
            self.x_pos = 900
        elif self.x_pos > 900:
            self.x_pos -= 30

        if self.x_pos in [400, 402] and self.y_pos == 482 and not self.in_box:
            self.x_pos = 410
            self.y_pos = 500

        return self.x_pos, self.y_pos, self.direction

    def move_inky_ai(self, blinky_x, blinky_y, pinky_x, pinky_y):
        # Função de heurística usando a distância de Manhattan
        def heuristic(current_x, current_y, blinky_x, blinky_y, pinky_x, pinky_y):
            # Calcule a heurística para o próximo movimento, considerando o destino e a posição intermediária
            return math.sqrt((current_x - ((blinky_x + pinky_x) // 2)) **
                                 2 + (current_y - ((blinky_y + pinky_y) // 2))**2)

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
                    new_x, new_y, blinky_x, blinky_y, pinky_x, pinky_y)

                if distance < best_distance:
                    best_distance = distance
                    best_direction = direction

        # Atualize a posição do Clyde com base na direção escolhida
        if best_direction is not None:
            self.x_pos += best_direction[0] * self.speed // 2
            self.y_pos += best_direction[1] * self.speed // 2

        if self.x_pos < -30:
            self.x_pos = 900
        elif self.x_pos > 900:
            self.x_pos -= 30

        if self.x_pos in [400, 402] and self.y_pos == 482 and not self.in_box:
            self.x_pos = 410
            self.y_pos = 500

        return self.x_pos, self.y_pos, self.direction
        # target_x, target_y = self.target

        # # Direções possíveis (r, l, u, d)
        # directions = [(1, 0), (-1, 0), (0, -1), (0, 1)]

        # best_direction = None
        # best_distance = float('inf')
        # for direction in directions:
        #     new_x = self.x_pos + direction[0] * self.speed // 2
        #     new_y = self.y_pos + direction[1] * self.speed // 2

        #     # Calcule a posição intermediária com base nas posições de Blinky e Pinky
        #     intermediate_x = (blinky_x + pinky_x) // 2
        #     intermediate_y = (blinky_y + pinky_y) // 2

        #     # Calcule a heurística para o próximo movimento, considerando o destino e a posição intermediária
        #     distance = math.sqrt((new_x - intermediate_x) **
        #                          2 + (new_y - intermediate_y)**2)

        #     if distance < best_distance:
        #         best_distance = distance
        #         best_direction = direction

        # # Atualize a posição de Inky com base na direção escolhida
        # if best_direction is not None:
        #     self.x_pos += best_direction[0] * self.speed // 2
        #     self.y_pos += best_direction[1] * self.speed // 2

        # if self.x_pos < -30:
        #     self.x_pos = 900
        # elif self.x_pos > 900:
        #     self.x_pos -= 30

        # if self.x_pos in [400, 402] and self.y_pos == 482 and not self.in_box:
        #     self.x_pos = 410
        #     self.y_pos = 500

        # return self.x_pos, self.y_pos, self.direction

    def move_pinky_ai(self):
        # Função de heurística usando a distância de Manhattan
        def heuristic(current_x, current_y, target_x, target_y, vel):
            return abs(current_x - (target_x + 4 * vel)) + abs(current_y - (target_y + 4 * vel))

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
                    new_x, new_y, self.target[0], self.target[1], self.speed)

                if distance < best_distance:
                    best_distance = distance
                    best_direction = direction

        # Atualize a posição do Clyde com base na direção escolhida
        if best_direction is not None:
            self.x_pos += best_direction[0] * self.speed // 2
            self.y_pos += best_direction[1] * self.speed // 2

        if self.x_pos < -30:
            self.x_pos = 900
        elif self.x_pos > 900:
            self.x_pos -= 30

        if self.x_pos in [400, 402] and self.y_pos == 482 and not self.in_box:
            self.x_pos = 410
            self.y_pos = 500

        return self.x_pos, self.y_pos, self.direction
        # target_x, target_y = self.target

        # # Direções possíveis (r, l, u, d)
        # directions = [(1, 0), (-1, 0), (0, -1), (0, 1)]

        # best_direction = None
        # best_distance = float('inf')

        # for direction in directions:
        #     new_x = self.x_pos + direction[0] * self.speed // 2
        #     new_y = self.y_pos + direction[1] * self.speed // 2

        #     # Calcule a heurística para o próximo movimento
        #     distance = math.sqrt((new_x - target_x)**2 + (new_y - target_y)**2)

        #     if distance < best_distance:
        #         best_distance = distance
        #         best_direction = direction

        # # Atualize a posição do Pinky com base na direção escolhida
        # if best_direction is not None:
        #     self.x_pos += best_direction[0] * self.speed // 2
        #     self.y_pos += best_direction[1] * self.speed // 2

        # if self.x_pos < -30:
        #     self.x_pos = 900
        # elif self.x_pos > 900:
        #     self.x_pos -= 30

        # if self.x_pos in [400, 402] and self.y_pos == 482 and not self.in_box:
        #     self.x_pos = 410
        #     self.y_pos = 500

        # return self.x_pos, self.y_pos, self.direction


def draw_misc():
    score_text = FONTE.render(f'Score: {score}', True, 'white')
    TELA.blit(score_text, (10, ALTURA - 50))
    if powerup:
        pygame.draw.circle(TELA, 'blue', (140, 930), 15)
    for i in range(lives):
        TELA.blit(pygame.transform.scale(
            PACMAN[0], (30, 30)), (650 + i * 40, 915))

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
            'Game over! \nAperte espaço!', True, 'red')
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


def check_collisions(scor, power, power_count, eaten_ghosts):
    num1 = (ALTURA - 50) // 32
    num2 = LARGURA // 30
    if 0 < player_x < 870:
        if LEVEL[center_y // num1][center_x // num2] == 1:
            LEVEL[center_y // num1][center_x // num2] = 0
            scor += 10
        if LEVEL[center_y // num1][center_x // num2] == 2:
            LEVEL[center_y // num1][center_x // num2] = 0
            scor += 50
            power = True
            power_count = 0
            eaten_ghosts = [False, False, False, False]
    return scor, power, power_count, eaten_ghosts


def draw_board():
    num1 = ((ALTURA - 50) // 32)
    num2 = (LARGURA // 30)
    for i in range(len(LEVEL)):
        for j in range(len(LEVEL[i])):
            if LEVEL[i][j] == 1:
                pygame.draw.circle(
                    TELA, 'white', (j * num2 + (0.5 * num2), i * num1 + (0.5 * num1)), 4)
            if LEVEL[i][j] == 2 and not flicker:
                pygame.draw.circle(
                    TELA, 'white', (j * num2 + (0.5 * num2), i * num1 + (0.5 * num1)), 10)
            if LEVEL[i][j] == 3:
                pygame.draw.line(TELA, COR, (j * num2 + (0.5 * num2), i * num1),
                                 (j * num2 + (0.5 * num2), i * num1 + num1), 3)
            if LEVEL[i][j] == 4:
                pygame.draw.line(TELA, COR, (j * num2, i * num1 + (0.5 * num1)),
                                 (j * num2 + num2, i * num1 + (0.5 * num1)), 3)
            if LEVEL[i][j] == 5:
                pygame.draw.arc(TELA, COR, [(j * num2 - (num2 * 0.4)) - 2, (i * num1 + (0.5 * num1)), num2, num1],
                                0, PI / 2, 3)
            if LEVEL[i][j] == 6:
                pygame.draw.arc(TELA, COR,
                                [(j * num2 + (num2 * 0.5)), (i * num1 + (0.5 * num1)), num2, num1], PI / 2, PI, 3)
            if LEVEL[i][j] == 7:
                pygame.draw.arc(TELA, COR, [(j * num2 + (num2 * 0.5)), (i * num1 - (0.4 * num1)), num2, num1], PI,
                                3 * PI / 2, 3)
            if LEVEL[i][j] == 8:
                pygame.draw.arc(TELA, COR,
                                [(j * num2 - (num2 * 0.4)) - 2, (i * num1 -
                                                                 (0.4 * num1)), num2, num1], 3 * PI / 2,
                                2 * PI, 3)
            if LEVEL[i][j] == 9:
                pygame.draw.line(TELA, 'white', (j * num2, i * num1 + (0.5 * num1)),
                                 (j * num2 + num2, i * num1 + (0.5 * num1)), 3)


def draw_player():
    # 0-RIGHT, 1-LEFT, 2-UP, 3-DOWN
    if direction == 0:
        TELA.blit(PACMAN[counter // 5], (player_x, player_y))
    elif direction == 1:
        TELA.blit(pygame.transform.flip(
            PACMAN[counter // 5], True, False), (player_x, player_y))
    elif direction == 2:
        TELA.blit(pygame.transform.rotate(
            PACMAN[counter // 5], 90), (player_x, player_y))
    elif direction == 3:
        TELA.blit(pygame.transform.rotate(
            PACMAN[counter // 5], 270), (player_x, player_y))


def check_position(centerx, centery):
    turns = [False, False, False, False]
    num1 = (ALTURA - 50) // 32
    num2 = (LARGURA // 30)
    num3 = 15
    # check collisions based on center x and center y of player +/- fudge number
    if centerx // 30 < 29:
        if direction == 0:
            if LEVEL[centery // num1][(centerx - num3) // num2] < 3:
                turns[1] = True
        if direction == 1:
            if LEVEL[centery // num1][(centerx + num3) // num2] < 3:
                turns[0] = True
        if direction == 2:
            if LEVEL[(centery + num3) // num1][centerx // num2] < 3:
                turns[3] = True
        if direction == 3:
            if LEVEL[(centery - num3) // num1][centerx // num2] < 3:
                turns[2] = True

        if direction == 2 or direction == 3:
            if 12 <= centerx % num2 <= 18:
                if LEVEL[(centery + num3) // num1][centerx // num2] < 3:
                    turns[3] = True
                if LEVEL[(centery - num3) // num1][centerx // num2] < 3:
                    turns[2] = True
            if 12 <= centery % num1 <= 18:
                if LEVEL[centery // num1][(centerx - num2) // num2] < 3:
                    turns[1] = True
                if LEVEL[centery // num1][(centerx + num2) // num2] < 3:
                    turns[0] = True
        if direction == 0 or direction == 1:
            if 12 <= centerx % num2 <= 18:
                if LEVEL[(centery + num1) // num1][centerx // num2] < 3:
                    turns[3] = True
                if LEVEL[(centery - num1) // num1][centerx // num2] < 3:
                    turns[2] = True
            if 12 <= centery % num1 <= 18:
                if LEVEL[centery // num1][(centerx - num3) // num2] < 3:
                    turns[1] = True
                if LEVEL[centery // num1][(centerx + num3) // num2] < 3:
                    turns[0] = True
    else:
        turns[0] = True
        turns[1] = True

    return turns


def move_player(play_x, play_y):
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
    if player_x < 450:
        runaway_x = 900
    else:
        runaway_x = 0
    if player_y < 450:
        runaway_y = 900
    else:
        runaway_y = 0
    return_target = (380, 400)
    if powerup:
        if not blinky.dead and not eaten_ghost[0]:
            blink_target = (runaway_x, runaway_y)
        elif not blinky.dead and eaten_ghost[0]:
            if 340 < blink_x < 560 and 340 < blink_y < 500:
                blink_target = (400, 100)
            else:
                blink_target = (player_x, player_y)
        else:
            blink_target = return_target
        if not inky.dead and not eaten_ghost[1]:
            ink_target = (runaway_x, player_y)
        elif not inky.dead and eaten_ghost[1]:
            if 340 < ink_x < 560 and 340 < ink_y < 500:
                ink_target = (400, 100)
            else:
                ink_target = (player_x, player_y)
        else:
            ink_target = return_target
        if not pinky.dead:
            pink_target = (player_x, runaway_y)
        elif not pinky.dead and eaten_ghost[2]:
            if 340 < pink_x < 560 and 340 < pink_y < 500:
                pink_target = (400, 100)
            else:
                pink_target = (player_x, player_y)
        else:
            pink_target = return_target
        if not clyde.dead and not eaten_ghost[3]:
            clyd_target = (450, 450)
        elif not clyde.dead and eaten_ghost[3]:
            if 340 < clyd_x < 560 and 340 < clyd_y < 500:
                clyd_target = (400, 100)
            else:
                clyd_target = (player_x, player_y)
        else:
            clyd_target = return_target
    else:
        if not blinky.dead:
            if 340 < blink_x < 560 and 340 < blink_y < 500:
                blink_target = (400, 100)
            else:
                blink_target = (player_x, player_y)
        else:
            blink_target = return_target
        if not inky.dead:
            if 340 < ink_x < 560 and 340 < ink_y < 500:
                ink_target = (400, 100)
            else:
                ink_target = (player_x, player_y)
        else:
            ink_target = return_target
        if not pinky.dead:
            if 340 < pink_x < 560 and 340 < pink_y < 500:
                pink_target = (400, 100)
            else:
                pink_target = (player_x, player_y)
        else:
            pink_target = return_target
        if not clyde.dead:
            if 340 < clyd_x < 560 and 340 < clyd_y < 500:
                clyd_target = (400, 100)
            else:
                clyd_target = (player_x, player_y)
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
    draw_board()
    center_x = player_x + 23
    center_y = player_y + 24
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
        # if score < 200: #if 1 in level[i] or 2 in level[i]: #deixei o score < 200 apenas para testes
        game_won = False

    player_circle = pygame.draw.circle(
        TELA, 'black', (center_x, center_y), 20, 2)
    draw_player()
    blinky = Ghost(blinky_x, blinky_y, targets[0], ghost_speeds[0], blinky_img, blinky_direction, blinky_dead,
                   blinky_box, 0)
    inky = Ghost(inky_x, inky_y, targets[1], ghost_speeds[1], inky_img, inky_direction, inky_dead,
                 inky_box, 1)
    pinky = Ghost(pinky_x, pinky_y, targets[2], ghost_speeds[2], pinky_img, pinky_direction, pinky_dead,
                  pinky_box, 2)
    clyde = Ghost(clyde_x, clyde_y, targets[3], ghost_speeds[3], clyde_img, clyde_direction, clyde_dead,
                  clyde_box, 3)
    draw_misc()
    targets = get_targets(blinky_x, blinky_y, inky_x,
                          inky_y, pinky_x, pinky_y, clyde_x, clyde_y)

    turns_allowed = check_position(center_x, center_y)
    if moving:
        player_x, player_y = move_player(player_x, player_y)
        if not blinky_dead and not blinky.in_box:
            # blinky_x, blinky_y, blinky_direction = blinky.move_blinky()
            blinky_x, blinky_y, blinky_direction = blinky.move_blinky_ai()

        else:
            #    blinky_x, blinky_y, blinky_direction = blinky.move_clyde()
            blinky_x, blinky_y, blinky_direction = blinky.move_clyde_ai()

        if not pinky_dead and not pinky.in_box:
            # pinky_x, pinky_y, pinky_direction = pinky.move_pinky()
            pinky_x, pinky_y, pinky_direction = pinky.move_pinky_ai()

        else:
            # pinky_x, pinky_y, pinky_direction = pinky.move_clyde()
            pinky_x, pinky_y, pinky_direction = pinky.move_clyde_ai()

        if not inky_dead and not inky.in_box:
            # inky_x, inky_y, inky_direction = inky.move_inky()
            inky_x, inky_y, inky_direction = inky.move_inky_ai(blinky_x, blinky_y, pinky_x, pinky_y)
        else:
            # inky_x, inky_y, inky_direction = inky.move_clyde()
            inky_x, inky_y, inky_direction = inky.move_clyde_ai()

        # clyde_x, clyde_y, clyde_direction = clyde.move_clyde()
        clyde_x, clyde_y, clyde_direction = clyde.move_clyde_ai()
    score, powerup, power_counter, eaten_ghost = check_collisions(
        score, powerup, power_counter, eaten_ghost)
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
                player_x = 450
                player_y = 663
                direction = 0
                direction_command = 0
                blinky_x = GHOST_START['blinky']['x']
                blinky_y = GHOST_START['blinky']['y']
                blinky_direction = 0
                inky_x = GHOST_START['inky']['x']
                inky_y = GHOST_START['inky']['y']
                inky_direction = 2
                pinky_x = GHOST_START['pinky']['x']
                pinky_y = GHOST_START['pinky']['y']
                pinky_direction = 2
                clyde_x = GHOST_START['clyde']['x']
                clyde_y = GHOST_START['clyde']['y']
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
            player_x = 450
            player_y = 663
            direction = 0
            direction_command = 0
            blinky_x = 56
            blinky_y = 58
            blinky_direction = 0
            inky_x = 440
            inky_y = 388
            inky_direction = 2
            pinky_x = 440
            pinky_y = 438
            pinky_direction = 2
            clyde_x = 440
            clyde_y = 438
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
            player_x = 450
            player_y = 663
            direction = 0
            direction_command = 0
            blinky_x = 56
            blinky_y = 58
            blinky_direction = 0
            inky_x = 440
            inky_y = 388
            inky_direction = 2
            pinky_x = 440
            pinky_y = 438
            pinky_direction = 2
            clyde_x = 440
            clyde_y = 438
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
            player_x = 450
            player_y = 663
            direction = 0
            direction_command = 0
            blinky_x = 56
            blinky_y = 58
            blinky_direction = 0
            inky_x = 440
            inky_y = 388
            inky_direction = 2
            pinky_x = 440
            pinky_y = 438
            pinky_direction = 2
            clyde_x = 440
            clyde_y = 438
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
            player_x = 450
            player_y = 663
            direction = 0
            direction_command = 0
            blinky_x = 56
            blinky_y = 58
            blinky_direction = 0
            inky_x = 440
            inky_y = 388
            inky_direction = 2
            pinky_x = 440
            pinky_y = 438
            pinky_direction = 2
            clyde_x = 440
            clyde_y = 438
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
                player_x = 450
                player_y = 663
                direction = 0
                direction_command = 0
                blinky_x = 56
                blinky_y = 58
                blinky_direction = 0
                inky_x = 440
                inky_y = 388
                inky_direction = 2
                pinky_x = 440
                pinky_y = 438
                pinky_direction = 2
                clyde_x = 440
                clyde_y = 438
                clyde_direction = 2
                eaten_ghost = [False, False, False, False]
                blinky_dead = False
                inky_dead = False
                clyde_dead = False
                pinky_dead = False
                score = 0
                lives = 3
                if game_won:
                    CONTADOR_FASE += 1
                    if CONTADOR_FASE == 3:
                        print('vocÊ ganhou')
                    else:
                        LEVEL = FASES[CONTADOR_FASE]
                        print(f'proxima fase: {CONTADOR_FASE}')
                if game_over:
                    LEVEL = FASES[CONTADOR_FASE]
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

    if player_x > 900:
        player_x = -47
    elif player_x < -50:
        player_x = 897

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


# sound effects, restart and winning messages