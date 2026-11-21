import numpy as np
from scipy import signal
from scipy.fft import fft, fftfreq
import matplotlib.pyplot as plt


def generar_senal_telefonica(duracion=0.5, fs=16000):
    # Vector de tiempo para 0.5 segundos con fs = 16000 Hz
    t = np.arange(0, duracion, 1 / fs)
    
    # Componentes de la señal de prueba según la consigna:
    # - 400 Hz (amplitud 1)
    # - 1000 Hz (amplitud 1)
    # - 3000 Hz (amplitud 1)
    # - Interferencia de 5500 Hz (amplitud 0.8)
    senal = (1.0 * np.sin(2 * np.pi * 400 * t) +
             1.0 * np.sin(2 * np.pi * 1000 * t) +
             1.0 * np.sin(2 * np.pi * 3000 * t) +
             0.8 * np.sin(2 * np.pi * 5500 * t))
             
    return t, senal

def espectro(senal, fs):
    """Analizador de espectro por software.
    Recibe: senal (array de muestras) y fs (frecuencia de muestreo [Hz]).
    Devuelve: frecuencias [Hz] y amplitudes (solo frecuencias positivas).
    """
    n = len(senal)
    amplitudes = 2 * np.abs(fft(senal))[: n // 2] / n
    frecuencias = fftfreq(n, 1 / fs)[: n // 2]
    return frecuencias, amplitudes

def filtrar_senal(senal, fs=16000):
    """
    Aplica un filtro pasa-bajos Butterworth de orden 6 
    con frecuencia de corte de 3400 Hz a la señal.
    """
    orden = 6
    fc = 3400          # Frecuencia de corte en Hz
    
    # (coeficientes b y a)
    b, a = signal.butter(N=orden, Wn=fc, btype='low', fs=fs)
    
    senal_filtrada = signal.filtfilt(b, a, senal)
    
    return senal_filtrada

def graficar_resultados(t, senal_orig, senal_filt, fs):
    # Calculamos los espectros
    freqs_orig, amps_orig = espectro(senal_orig, fs)
    freqs_filt, amps_filt = espectro(senal_filt, fs)
    
    # Máscara para recortar el tiempo a solo 10 ms (0.01 segundos)
    mask_tiempo = t <= 0.01
    t_zoom = t[mask_tiempo] * 1000  # Pasamos a milisegundos para el eje X
    orig_zoom = senal_orig[mask_tiempo]
    filt_zoom = senal_filt[mask_tiempo]

    # Creamos la figura de 2x2
    fig, axs = plt.subplots(2, 2, figsize=(12, 8))

    # --- 1. TIEMPO: ANTES (Solo 10 ms) ---
    axs[0, 0].plot(t_zoom, orig_zoom, color="crimson")
    axs[0, 0].set_title("Señal Original (Primeros 10 ms)")
    axs[0, 0].set_xlabel("Tiempo [ms]")
    axs[0, 0].set_ylabel("Amplitud")
    axs[0, 0].grid(True)

    # --- 2. FRECUENCIA: ANTES ---
    axs[0, 1].plot(freqs_orig, amps_orig, color="orange", alpha=0.8)
    axs[0, 1].set_title("Espectro Original (con interferencia a 5500 Hz)")
    axs[0, 1].set_xlabel("Frecuencia [Hz]")
    axs[0, 1].set_ylabel("Amplitud")
    axs[0, 1].set_xlim(0, 8000)
    axs[0, 1].grid(True)

    # --- 3. TIEMPO: DESPUÉS (Solo 10 ms) ---
    axs[1, 0].plot(t_zoom, filt_zoom, color="forestgreen")
    axs[1, 0].set_title("Señal Filtrada (Primeros 10 ms)")
    axs[1, 0].set_xlabel("Tiempo [ms]")
    axs[1, 0].set_ylabel("Amplitud")
    axs[1, 0].grid(True)

    # --- 4. FRECUENCIA: DESPUÉS ---
    axs[1, 1].plot(freqs_filt, amps_filt, color="dodgerblue", alpha=0.8)
    axs[1, 1].set_title("Espectro Filtrado (Pasabajos fc = 3400 Hz)")
    axs[1, 1].set_xlabel("Frecuencia [Hz]")
    axs[1, 1].set_ylabel("Amplitud")
    axs[1, 1].set_xlim(0, 8000)
    axs[1, 1].grid(True)

    plt.tight_layout()
    plt.show()

def calcular_atenuaciones(freqs, amps_orig, amps_filt):
    # Las frecuencias que nos importan evaluar según la consigna
    frecuencias_interes = [400, 1000, 3000, 5500]
    
    print("--- INFORME DE AMPLITUDES Y ATENUACIÓN ---")
    print(f"{'Frecuencia':<12} | {'A. Antes':<10} | {'A. Después':<10} | {'Atenuación [dB]':<15}")
    print("-" * 55)
    
    for f_objetivo in frecuencias_interes:
        # Buscamos el índice de la frecuencia más cercana en el array de frecuencias
        idx = np.argmin(np.abs(freqs - f_objetivo))
        
        a_antes = amps_orig[idx]
        a_despues = amps_filt[idx]
        
        # Evitamos divisiones por cero o logaritmos de cero si la amplitud es ínfima
        if a_despues < 1e-6:
            atenuacion_db = -100.0 # Valor de corte representativo para atenuación total
        else:
            atenuacion_db = 20 * np.log10(a_despues / a_antes)
            
        print(f"{f_objetivo} Hz      | {a_antes:.4f}     | {a_despues:.4f}     | {atenuacion_db:.2f} dB")

def main():
    fs = 16000
    duracion = 0.5

    t, senal = generar_senal_telefonica(duracion, fs)

    senal_filtrada = filtrar_senal(senal, fs)

    graficar_resultados(t, senal, senal_filtrada, fs)

    freqs_orig, amps_orig = espectro(senal, fs)
    freqs_filt, amps_filt = espectro(senal_filtrada, fs)

    calcular_atenuaciones(freqs_orig, amps_orig, amps_filt)

if __name__ == '__main__':

    main()

