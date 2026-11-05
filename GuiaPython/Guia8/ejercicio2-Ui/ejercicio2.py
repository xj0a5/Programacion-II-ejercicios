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

def sigma_para_snr(senal,snr_db):
    """
    Calcula el desvío estándar (sigma) del ruido necesario para 
    alcanzar una Relación Señal a Ruido (SNR) dada en dB.
    """

    # 1. Calculamos la potencia de la señal
    p_senal = np.mean(senal ** 2)

    # 2. Aplicamos la fórmula
    sigma = np.sqrt(p_senal / (10 ** (snr_db / 10)))
    return sigma

def main():
    fs = 8000   # <--- Frecuencia de muestreo
    duracion = 1.0  # Toma 8mil muestras
    t = np.arange(0, duracion, 1 / fs)
    senal = 1 * np.sin(2 * np.pi * 1000 * t)
    snr = -5

    sigma = sigma_para_snr(senal,snr)
    rng = np.random.default_rng(7)
    ruido = rng.normal(loc=0.0, scale=sigma, size=len(senal))

    senal_con_ruido = senal + ruido

    frecuencias, amplitudes = espectro(senal_con_ruido, fs)
    freq_limpia, amp_limpia = espectro(senal, fs)

    plt.figure(figsize=(10, 4))
    plt.plot(freq_limpia, amp_limpia, color="blue", label="Señal limpia (1 kHz)")
    plt.plot(frecuencias, amplitudes, color="orange", alpha=0.7, label="Señal con ruido (SNR 20 dB)")

    # --- ACERCAMIENTO (ZOOM) ---
    plt.xlim(800, 1200)       # Muestra solo el rango de frecuencia entre 800 Hz y 1200 Hz
    plt.ylim(bottom=0)        # Forzar que el eje Y arranque desde 0
    # ---------------------------
    
    plt.title("Comparación de Espectros: Con y Sin Ruido")
    plt.xlabel("Frecuencia [Hz]")  # <--- El eje X son los Hz
    plt.ylabel("Amplitud")
    plt.grid(True)
    plt.show()

main()
