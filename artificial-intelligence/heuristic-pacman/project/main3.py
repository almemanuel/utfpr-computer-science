import pygame
from pygame.locals import *
from board import boards1
import time

# Inicialize o Pygame
pygame.init()

# Defina as cores
BLUE = (22, 41, 135)
BLACK = (0, 0, 0)
CELL_SIZE = 30
YELLOW = (255, 255, 0)

# Defina o tamanho da tela e do bloco
BLOCK_SIZE = 30
SCREEN_WIDTH = len(boards1[0]) * BLOCK_SIZE
SCREEN_HEIGHT = len(boards1) * BLOCK_SIZE

current_direction = "RIGHT"
last_move_time = time.time()

# Defina um intervalo de tempo entre os movimentos (em segundos)
MOVE_INTERVAL = 0.2


# Inicialize a tela
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Pac-Man")

class PacManGame:
    def __init__(self, board):
        self.board = board
        self.height = len(board)
        self.width = len(board[0])
        self.pacman = PacMan(self.find_pacman_position())
        self.ghosts = []  # Adicionaremos os fantasmas aqui
        self.score = 0

    def find_pacman_position(self):
        for i in range(self.height):
            for j in range(self.width):
                if self.board[i][j] == 0:  # Assumindo que 0 representa a posição inicial do Pac-Man
                    return (i, j)

    def move_pacman(self, direction):
        new_position = self.pacman.move(direction)
        if self.is_valid_move(new_position):
            self.pacman.position = new_position
            if self.board[new_position[0]][new_position[1]] == 1:
                self.score += 10
                self.board[new_position[0]][new_position[1]] = 0
            elif self.board[new_position[0]][new_position[1]] == 2:
                self.score += 50
                self.board[new_position[0]][new_position[1]] = 0
        else:
            print("Movimento inválido!")

    def is_valid_move(self, position):
        i, j = position
        return 0 <= i < self.height and 0 <= j < self.width and self.board[i][j] != 3

    def print_board(self):
        for row in self.board:
            print(' '.join(str(cell) for cell in row))


    def draw(self):
        # Limpa a tela
        screen.fill(BLACK)

        # Desenha o labirinto
        for i in range(self.height):
            for j in range(self.width):
                if self.board[i][j] == 3:  # 3 representa as paredes
                    pygame.draw.rect(screen, BLUE, (j*CELL_SIZE, i*CELL_SIZE, CELL_SIZE, CELL_SIZE))

        # Desenha o Pac-Man
        pacman_position = self.pacman.position
        pygame.draw.circle(screen, YELLOW, (pacman_position[1]*CELL_SIZE + CELL_SIZE//2, pacman_position[0]*CELL_SIZE + CELL_SIZE//2), CELL_SIZE//2)

        # Atualiza a tela
        pygame.display.flip()

class PacMan:
    def __init__(self, position, width):
        self.position = position
        self.width = width

    def move(self, direction):
        i, j = self.position
        if direction == "UP":
            return (i - 1, j)
        elif direction == "DOWN":
            return (i + 1, j)
        elif direction == "LEFT":
            return (i, j - 1)
        elif direction == "RIGHT":
            return (i, j + 1)

    def is_valid_move(self, position):
        i, j = position
        return 0 <= i < len(boards1) and 0 <= j < len(boards1[0]) and boards1[i][j] != 3

    def move_pacman(self, direction):
        new_position = self.move(direction)
        if self.is_valid_move(new_position):
            # Verifica se o Pac-Man atingiu a borda esquerda
            if new_position[1] < 0:
                new_position = (new_position[0], self.width - 1)
            # Verifica se o Pac-Man atingiu a borda direita
            elif new_position[1] >= self.width:
                new_position = (new_position[0], 0)
            return new_position  # Retorna a nova posição
        else:
            print("Movimento inválido!")
            return self.position  # Retorna a posição atual se o movimento for inválido

# Função para converter eventos do Pygame para direções
def event_to_direction(event):
    if event.type == KEYDOWN:
        if event.key == K_UP:
            return "UP"
        elif event.key == K_DOWN:
            return "DOWN"
        elif event.key == K_LEFT:
            return "LEFT"
        elif event.key == K_RIGHT:
            return "RIGHT"
    return None

# Criar uma instância do jogo
game = PacManGame(boards1)

# Loop principal do jogo
game_running = True

while game_running:
    for event in pygame.event.get():
        if event.type == QUIT:
            game_running = False

        direction = event_to_direction(event)
        if direction:
            current_direction = direction  # Atualiza a direção quando uma tecla de direção é pressionada

    current_time = time.time()
    if current_time - last_move_time > MOVE_INTERVAL:
        new_position = game.pacman.move_pacman(current_direction)
        if new_position != game.pacman.position:  # Verifica se houve um movimento válido
            game.pacman.position = new_position
            if game.board[new_position[0]][new_position[1]] == 1:
                game.score += 10
                game.board[new_position[0]][new_position[1]] = 0
            elif game.board[new_position[0]][new_position[1]] == 2:
                game.score += 50
                game.board[new_position[0]][new_position[1]] = 0
            last_move_time = current_time

    game.draw()


# Encerre o Pygame
pygame.quit()