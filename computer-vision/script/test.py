# # import cv2

# # # Leia o vídeo de entrada
# # video = cv2.VideoCapture('Walk1.mpg')

# # # Configure a contagem de quadros
# # frame_count = 0
# # frame_rate = video.get(cv2.CAP_PROP_FPS)

# # # Determine o índice do quadro desejado (2 segundos)
# # desired_frame_index = int(frame_rate * 2)

# # while True:
# #     # Leia o próximo quadro
# #     ret, frame = video.read()

# #     if not ret:
# #         break

# #     # Incrementar a contagem de quadros
# #     frame_count += 1

# #     if frame_count == 1:
# #         # Use o primeiro frame como fundo fixo
# #         bg_subtractor = cv2.createBackgroundSubtractorMOG2()
# #         bg_subtractor.apply(frame)
# #     elif frame_count == desired_frame_index:
# #         # Remova o fundo a partir do frame desejado
# #         mask = bg_subtractor.apply(frame)

# #         # Exibir o resultado
# #         cv2.imshow('Mask', mask)
# #         cv2.imshow('Video', frame)
# #         cv2.waitKey(0)  # Aguarde a tecla 'q' ser pressionada para continuar

# # # Libere os recursos e feche as janelas
# # video.release()
# # cv2.destroyAllWindows()


# import cv2

# # Parâmetros
# start_time = 2  # Tempo inicial em segundos
# num_frames = 30  # Número de quadros a serem usados para calcular o fundo médio

# # Leia o vídeo de entrada
# video = cv2.VideoCapture('Walk1.mpg')

# # Calcule o índice do quadro inicial e final
# frame_rate = video.get(cv2.CAP_PROP_FPS)
# start_frame_index = int(start_time * frame_rate)
# end_frame_index = start_frame_index + num_frames

# # Calcule o fundo médio
# background = None
# frame_count = 0
# while True:
#     ret, frame = video.read()

#     if not ret or frame_count > end_frame_index:
#         break

#     if start_frame_index <= frame_count < end_frame_index:
#         if background is None:
#             background = frame.astype('float32')
#         else:
#             background += frame

#     frame_count += 1

# if background is not None:
#     background /= num_frames
#     background = background.astype('uint8')

# # Volte para o início do vídeo
# video.set(cv2.CAP_PROP_POS_FRAMES, 0)

# # Crie o objeto BackgroundSubtractorMOG2 com o fundo médio
# bg_subtractor = cv2.createBackgroundSubtractorMOG2()
# bg_subtractor.apply(background)

# # Leia o frame desejado
# video.set(cv2.CAP_PROP_POS_FRAMES, start_frame_index)
# ret, frame = video.read()

# if not ret:
#     print('Erro ao ler o frame desejado.')
#     exit()

# # Remova o fundo utilizando o modelo de fundo médio
# mask = bg_subtractor.apply(frame)

# # Subtraia o fundo do quadro atual
# foreground = cv2.absdiff(frame, background)

# # Exibir o resultado
# cv2.imshow('Video', frame)
# cv2.imshow('Mask', mask)
# cv2.imshow('Foreground', foreground)
# cv2.waitKey(0)

# # Libere os recursos e feche as janelas
# video.release()
# cv2.destroyAllWindows()


import cv2
import numpy as np

# Parâmetros
start_time = 2  # Tempo inicial em segundos
num_frames = 30  # Número de quadros a serem usados para calcular o fundo mediano

# Leia o vídeo de entrada
video = cv2.VideoCapture('Walk1.mpg')

# Calcule o índice do quadro inicial e final
frame_rate = video.get(cv2.CAP_PROP_FPS)
start_frame_index = int(start_time * frame_rate)
end_frame_index = start_frame_index + num_frames

# Calcule o fundo mediano
backgrounds = []
frame_count = 0
while True:
    ret, frame = video.read()

    if not ret or frame_count > end_frame_index:
        break

    if start_frame_index <= frame_count < end_frame_index:
        backgrounds.append(frame)

    frame_count += 1

if len(backgrounds) > 0:
    background = np.median(backgrounds, axis=0).astype('uint8')
else:
    print('Erro ao calcular o fundo mediano.')
    exit()

# Volte para o início do vídeo
video.set(cv2.CAP_PROP_POS_FRAMES, 0)

# Crie o objeto BackgroundSubtractorMOG2 com o fundo mediano
bg_subtractor = cv2.createBackgroundSubtractorMOG2()
bg_subtractor.apply(background)

# Leia o frame desejado
video.set(cv2.CAP_PROP_POS_FRAMES, start_frame_index)
ret, frame = video.read()

if not ret:
    print('Erro ao ler o frame desejado.')
    exit()

# Remova o fundo utilizando o modelo de fundo mediano
mask = bg_subtractor.apply(frame)

# Subtraia o fundo do quadro atual
foreground = cv2.absdiff(frame, background)

# Exibir o resultado
cv2.imshow('Video', frame)
cv2.imshow('Mask', mask)
cv2.imshow('Foreground', foreground)
cv2.waitKey(0)

# Libere os recursos e feche as janelas
video.release()
cv2.destroyAllWindows()
