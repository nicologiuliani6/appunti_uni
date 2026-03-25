import pyautogui
from PIL import ImageGrab
from pynput.mouse import Listener
import time

# Variabili globali per le coordinate del pixel da monitorare
x, y = None, None

# Funzione per verificare se un colore è grigio scuro
def is_dark_grey(color):
    tolerance = 10
    return abs(color[0] - color[1]) < tolerance and abs(color[1] - color[2]) < tolerance and sum(color) < 100

# Funzione per monitorare il colore del pixel e cliccare se diventa grigio scuro
def monitor_and_click():
    while True:
        if x is not None and y is not None:
            # Cattura lo schermo
            screenshot = ImageGrab.grab()

            # Ottieni il colore del pixel alle coordinate specificate
            pixel_color = screenshot.getpixel((x, y))

            # Controlla se il colore è grigio scuro
            if is_dark_grey(pixel_color):
                # Se il pixel è grigio scuro, clicca con il tasto sinistro nella stessa posizione
                pyautogui.click(x, y)

        # Attendi un po' prima di controllare nuovamente
        time.sleep(0.1)

# Funzione che cattura la posizione del click del mouse
def on_click(mouse_x, mouse_y, button, pressed):
    global x, y
    if pressed:
        # Registra le coordinate del click
        x, y = mouse_x, mouse_y
        print(f"Click registrato a ({x}, {y})")
        # Termina l'ascolto del mouse dopo il primo click
        return False

# Inizia l'ascolto per ottenere le coordinate del click del mouse
print("Clicca su una posizione dello schermo per monitorare il colore...")
with Listener(on_click=on_click) as listener:
    listener.join()

# Dopo aver ottenuto le coordinate, inizia a monitorare il pixel e fare click se necessario
print(f"Inizio il monitoraggio del pixel a ({x}, {y})...")
monitor_and_click()

