import sys
import numpy as np
from scipy.fft import fft, fftfreq
import matplotlib.pyplot as plt
from matplotlib.backends.backend_qtagg import FigureCanvasQTAgg
from PySide6.QtWidgets import QApplication, QMainWindow, QVBoxLayout
from ui_analizador_ejercicio2 import Ui_MainWindow


def espectro(senal, fs):
    """Analizador de espectro por software.
    Recibe: senal (array de muestras) y fs (frecuencia de muestreo [Hz]).
    Devuelve: frecuencias [Hz] y amplitudes (solo frecuencias positivas).
    """
    n = len(senal)
    amplitudes = 2 * np.abs(fft(senal))[: n // 2] / n
    frecuencias = fftfreq(n, 1 / fs)[: n // 2]
    return frecuencias, amplitudes

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        # Inicializamos los componentes visuales del .ui
        self.setupUi(self)
        
        # 1. Definimos un valor inicial por defecto en la caja de texto SNR
        self.textEdit_SNR.setPlainText("20")

        # 2. Configuramos el gráfico de Matplotlib
        self.fig, self.ax = plt.subplots(figsize=(6, 4))
        self.fig.patch.set_facecolor('none')  # Fondo de la figura transparente
        self.ax.set_facecolor('none')         # Fondo de los ejes transparente
        
        self.canvas = FigureCanvasQTAgg(self.fig)
        
        # 3. Insertamos el canvas dentro del widget con degradado que armaste en el UI (self.widget)
        if self.widget.layout() is None:
            layout_widget = QVBoxLayout(self.widget)
            layout_widget.addWidget(self.canvas)
        else:
            self.widget.layout().addWidget(self.canvas)

        # 4. Conectamos el botón con la función de procesamiento
        self.pushButton_Actualizar.clicked.connect(self.procesar_y_graficar)

        # 5. Ejecutamos el gráfico por primera vez al arrancar la app
        self.procesar_y_graficar()

    def procesar_y_graficar(self):
        try:
            # 3. Identificamos y leemos el valor dinámico de la casilla de SNR
            texto_snr = self.textEdit_SNR.toPlainText().strip()
            snr_db = float(texto_snr) # Convertimos el texto a número
            
            # 4. Parámetros fijos
            fs = 8000
            t = np.arange(0, 1.0, 1 / fs)
            senal_limpia = 1 * np.sin(2 * np.pi * 1000 * t)
            
            # 5. Cálculo del desvío de ruido
            p_senal = np.mean(senal_limpia ** 2)
            sigma = np.sqrt(p_senal / (10 ** (snr_db / 10)))
            
            # Generación de ruido y suma en el tiempo
            rng = np.random.default_rng(7)
            ruido = rng.normal(0, sigma, len(senal_limpia))
            senal_con_ruido = senal_limpia + ruido
            
            # 6. Cálculo del espectro
            frecuencias, amplitudes = espectro(senal_con_ruido, fs)
            
            # 7. Actualizamos el gráfico en la interfaz
            self.ax.clear()
            self.ax.plot(frecuencias, amplitudes, color="cyan", linewidth=1.5)
            self.ax.set_xlim(800, 1200)
            self.ax.set_title(f"Espectro con SNR = {snr_db} dB", color="black", fontweight="bold")
            self.ax.set_xlim(800, 1200) # Zoom cerca del tono de 1 kHz
            self.ax.set_xlabel("Frecuencia [Hz]", color="white")
            self.ax.set_ylabel("Amplitud", color="white")
            self.ax.tick_params(colors='white')
            self.ax.grid(True, linestyle="--", alpha=0.5)
            
            self.canvas.draw()
            
        except ValueError:
            print("Error: Por favor ingresa un número válido para la SNR.")

if __name__ == "__main__":
    app = QApplication(sys.argv)
    ventana = MainWindow()
    ventana.show()
    sys.exit(app.exec())