from ejercicio1 import tono_dtmf
from ejercicio1 import espectro
import numpy as np
from scipy.fft import fft, fftfreq
import matplotlib.pyplot as plt

def decodificar_senal(senal, fs):

    frecuencias, amplitudes = espectro(senal, fs)

    mask_fila = (frecuencias >= 650) & (frecuencias <= 1000)
    mask_col = (frecuencias >= 1150) & (frecuencias <= 1550)

    #filtrar mascaras
    freqs_fila = frecuencias[mask_fila]
    amps_fila = amplitudes[mask_fila]

    freqs_col = frecuencias[mask_col]
    amps_col = amplitudes[mask_col]

    idx_max_fila = np.argmax(amps_fila)
    idx_max_col = np.argmax(amps_col)
    
    frecuencia_fila = freqs_fila[idx_max_fila]
    frecuencia_col = freqs_col[idx_max_col]
    
    return frecuencia_fila, frecuencia_col

def main():
    fs = 8000
    duracion = 0.1
    sigma = 0.8

    # Generamos las señales para las teclas 8
    senal_8, t_1 = tono_dtmf("2", duracion, fs)

    #Añadimos ruido
    rng = np.random.default_rng(3)
    ruido = rng.normal(loc=0.0, scale=sigma, size=len(senal_8))

    senal_con_ruido = senal_8 + ruido
    frecuencias, amplitudes = espectro(senal_con_ruido, fs)

    freq_fila,freq_col = decodificar_senal(senal_con_ruido, fs)

    plt.plot(frecuencias, amplitudes, color="orange", alpha=0.7, label="Señal con ruido)")

    # --- ACERCAMIENTO (ZOOM) ---
    plt.xlim() 
    plt.ylim()   
    # ---------------------------
    plt.title(f"Decodificación DTMF -> Fila: {freq_fila:.1f} Hz | Col: {freq_col:.1f} Hz")

    plt.xlabel("Frecuencia [Hz]")  # <--- El eje X son los Hz
    plt.ylabel("Amplitud")
    plt.xlim(0, 2000)
    plt.grid(True)
    plt.legend()
    plt.show()


if __name__ == '__main__':

    main()
