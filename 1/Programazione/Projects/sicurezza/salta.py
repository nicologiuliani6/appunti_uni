import pyautogui
from PIL import ImageGrab
import time

# Usa le coordinate che hai ottenuto
x, y = 2810, 904

def is_grey(color):
    # Definisci una soglia di tolleranza per determinare se il colore è grigio
    tolerance = 12
    return abs(color[0] - color[1]) < tolerance and abs(color[1] - color[2]) < tolerance and sum(color) < 100

while True:
    # Cattura lo schermo
    screenshot = ImageGrab.grab()

    # Ottieni il colore del pixel alle coordinate specificate
    pixel_color = screenshot.getpixel((x, y))

    # Controlla se il colore è grigio
    if is_grey(pixel_color):
        # Se il pixel è grigio, clicca con il tasto sinistro nella stessa posizione
        pyautogui.click(x, y)

    # Attendi un po' prima di controllare nuovamente
    time.sleep(0.1)

