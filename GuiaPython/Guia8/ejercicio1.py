import numpy as np
from scipy.fft import fft, fftfreq
import matplotlib.pyplot as plt

def espectro(senal, fs):
    """Analizador de espectro por software.
    Recibe: senal (array de muestras) y fs (frecuencia de muestreo [Hz]).
    Devuelve: frecuencias [Hz] y amplitudes (solo frecuencias positivas).
    """
    n = len(senal)
    amplitudes = 2 * np.abs(fft(senal))[: n // 2] / n
    frecuencias = fftfreq(n, 1 / fs)[: n // 2]
    return frecuencias, amplitudes

def tono_dtmf(tecla, duracion=0.1, fs=8000):
    """Generador de DTMF para una tecla dada durante un tiempo de duración."""
    
    FILAS = {
    "1": 697, "2": 697, "3": 697,
    "4": 770, "5": 770, "6": 770,
    "7": 852, "8": 852, "9": 852,
    "*": 941, "0": 941, "#": 941
}
    COLUMNAS = {
    "1": 1209, "2": 1336, "3": 1477,
    "4": 1209, "5": 1336, "6": 1477,
    "7": 1209, "8": 1336, "9": 1477,
    "*": 1209, "0": 1336, "#": 1477
}
    
    if tecla in FILAS and tecla in COLUMNAS:
        f_fila = FILAS[tecla]
        f_col = COLUMNAS[tecla]
        
        # Vector de tiempo
        t = np.arange(0, duracion, 1 / fs)
        
        # La señal DTMF es la suma de los senos de la fila y la columna
        senal = np.sin(2 * np.pi * f_fila * t) + np.sin(2 * np.pi * f_col * t)
        return senal, t
    else:
        print("La tecla no existe en el teclado DTMF.")
        return None, None

def main():
    fs = 8000
    duracion = 0.1
    
    # Generamos las señales para las teclas 1 y 9
    senal_1, t_1 = tono_dtmf("1", duracion, fs)
    senal_9, t_9 = tono_dtmf("9", duracion, fs)
    
    # Filtramos los índices correspondientes solo a los primeros 20 ms (0.02 s)
    limite_idx = int(0.02 * fs)
    
    plt.figure(figsize=(10, 6))
    
    # Subplot 1: Tecla 1
    plt.subplot(2, 1, 1)
    plt.plot(t_1[:limite_idx] * 1000, senal_1[:limite_idx], color="purple") # en milisegundos
    plt.title("Tono DTMF - Tecla 1 (Primeros 20 ms)")
    plt.ylabel("Amplitud")
    plt.grid(True)
    
    # Subplot 2: Tecla 9
    plt.subplot(2, 1, 2)
    plt.plot(t_9[:limite_idx] * 1000, senal_9[:limite_idx], color="teal")
    plt.title("Tono DTMF - Tecla 9 (Primeros 20 ms)")
    plt.xlabel("Tiempo [ms]")
    plt.ylabel("Amplitud")
    plt.grid(True)
    
    plt.tight_layout()
    plt.show()

main()
