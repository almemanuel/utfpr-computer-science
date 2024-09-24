import cv2

# Leia o vídeo de entrada
video = cv2.VideoCapture('Walk1.mpg')

while True:
    # Leia o próximo quadro
    ret, frame = video.read()

    if not ret:
        break

    # Exiba o quadro
    cv2.imshow('Video', frame)

    # Verifique se a tecla 'q' foi pressionada para interromper o loop
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Libere os recursos e feche as janelas
video.release()
cv2.destroyAllWindows()
