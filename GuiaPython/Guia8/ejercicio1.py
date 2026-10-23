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

def tono_dtmf(tecla,t):
    """Generador de señal"""
    señalesfrec={
        "1" : 697+1209,
        "4" : 770+1209,
        "7" : 852+1209,
        "*" : 941+1209,
        "2" : 697+1336,
        "5" : 770+1336,
        "8" : 852+1336,
        "0" : 941+1336,
        "3" : 697+1477,
        "6" : 770+1477,
        "9" : 852+1477,
        "#" : 941+1477
    }
    if (tecla in señalesfrec):
        frecuencia = señalesfrec[tecla]
        amplitud = np.arange(0,1,1/frecuencia)
        senal = np.sin(2* np.pi * frecuencia * amplitud)
        return senal,t
    else:
        print("No existe la tecla")

def main():
    plt.figure()
    senal, tiempo =tono_dtmf("5",0.1) 
    plt.plot(tiempo,senal)
    plt.grid(True)
    plt.show()
main()