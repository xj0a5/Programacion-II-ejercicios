from scipy.fft import fft, fftfreq
import numpy as np


def espectro(senal, fs):
    """Analizador de espectro por software.
    Recibe: senal (array de muestras) y fs (frecuencia de muestreo [Hz]).
    Devuelve: frecuencias [Hz] y amplitudes (solo frecuencias positivas).
    """
    n = len(senal)
    amplitudes = 2 * np.abs(fft(senal))[: n // 2] / n
    frecuencias = fftfreq(n, 1 / fs)[: n // 2]
    return frecuencias, amplitudes

def generar_tono(frecuencia, duracion=0.1, fs=10000):
    """Genera un tono puro de una frecuencia dada con fs = 10 kHz."""
    t = np.arange(0, duracion, 1 / fs)
    senal = np.sin(2 * np.pi * frecuencia * t)
    return t, senal

