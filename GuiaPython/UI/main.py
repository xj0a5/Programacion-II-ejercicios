import sys
import os

# Configurar la variable de entorno para que Matplotlib sepa que debe usar PySide6
os.environ['QT_API'] = 'pyside6'

import numpy as np
import matplotlib
# Indicarle a Matplotlib que el motor de renderizado gráfico será Qt
matplotlib.use('QtAgg')

# Importar la clase que convierte la figura de Matplotlib en un widget compatible con Qt
from matplotlib.backends.backend_qtagg import FigureCanvasQTAgg as FigureCanvas
# Importar la clase que crea el lienzo o contenedor gráfico general
from matplotlib.figure import Figure

# Importar las herramientas base de PySide6 para la ventana y el diseño
from PySide6.QtWidgets import QApplication, QMainWindow, QVBoxLayout
# Importar la clase visual generada desde el archivo .ui compilado
from ui_analizador import Ui_MainWindow


class AnalizadorApp(QMainWindow, Ui_MainWindow):
# QMainWindow: Es una clase base de PySide6 que representa una ventana principal
# de la interfaz gráfica (con soporte para barra de menú, barra de estado, widgets
# centrales, etc.).

# Ui_MainWindow: Es una clase de diseño creada en Python por la herramienta pyside6-uic
# a partir del archivo analizador.ui. Contiene la definición y estructura de todos los
# componentes gráficos como los botones, cajas de texto y etiquetas, etc.

# AnalizadorApp: Es una nueva clase hija que hereda todas las propiedades y métodos
# de ambas clases madres.

    def __init__(self):
        super().__init__()
        # Cargar los componentes visuales de la interfaz en esta ventana
        self.setupUi(self)

        # Establecer los valores predeterminados en las cajas de texto de la interfaz
        self.textEdit_Amplitud.setPlainText("1.0")
        self.textEdit.setPlainText("2.0")

        # Crear la figura gráfica con fondo blanco
        self.figure = Figure(facecolor="#FFFFFF00")
        # Empaquetar la figura en un lienzo/canvas integrable con Qt
        self.canvas = FigureCanvas(self.figure)

        self.canvas.setStyleSheet("background: transparent;")
        # Añadir un sistema de ejes cartesiano 2D sobre la figura
        self.ax = self.figure.add_subplot(111)

        # Crear un layout vertical dentro del widget contenedor asignado en el diseño
        layout = QVBoxLayout(self.widget)
        # Eliminar márgenes alrededor del lienzo para aprovechar todo el espacio
        layout.setContentsMargins(0, 0, 0, 0)
        # Insertar el gráfico de Matplotlib dentro del layout del widget
        layout.addWidget(self.canvas)

        # Enlazar la señal del clic del botón con el método de actualización del gráfico
        self.pushButton_Actualizar.clicked.connect(self.actualizar_grafico)

        # Renderizar la gráfica inicial al abrir la aplicación
        self.actualizar_grafico()

    def actualizar_grafico(self):
        # Intentar obtener y convertir la amplitud ingresada; si falla o está vacía, usar 1.0
        try:
            amplitud = float(self.textEdit_Amplitud.toPlainText().strip())
        except ValueError:
            amplitud = 1.0

        # Intentar obtener y convertir la frecuencia ingresada; si falla o está vacía, usar 2.0
        try:
            frecuencia = float(self.textEdit.toPlainText().strip())
        except ValueError:
            frecuencia = 2.0

        # Generar vector de tiempo de 0 a 2 segundos con 1000 puntos
        t = np.linspace(0, 2, 1000)
        # Calcular los valores de la onda senoidal: y(t) = A * sin(2 * pi * f * t)
        y = amplitud * np.sin(2 * np.pi * frecuencia * t)

        # Limpiar los trazos y ejes de la gráfica anterior
        self.ax.clear()
        # Establecer el color de fondo del área de trazado en blanco
        self.ax.set_facecolor("#FFFFFF00")
        # Trazar la señal senoidal con una línea azul brillante de grosor 2.5
        self.ax.plot(t, y, color='#00a2ff', linewidth=2.5)

        # Definir texto y color de las etiquetas de los ejes X e Y
        self.ax.set_xlabel('Tiempo (s)', color='white', fontsize=11)
        self.ax.set_ylabel('Amplitud', color='white', fontsize=11)
        # Configurar en negro los números y marcas de los ejes
        self.ax.tick_params(colors='white')
        # Activar la rejilla punteada gris semitransparente
        self.ax.grid(True, linestyle='--', alpha=0.5, color='gray')

        # Recorrer los cuatro bordes del gráfico y pintarlos de negro
        for spine in self.ax.spines.values():
            spine.set_color('white')

        # Reajustar automáticamente los márgenes internos para no cortar textos
        self.figure.tight_layout()
        # Redibujar la figura visualmente en la pantalla
        self.canvas.draw()


if __name__ == "__main__":
    # Inicializar el administrador de la aplicación Qt pasándole los argumentos del sistema
    app = QApplication(sys.argv)
    # Crear una instancia de la ventana principal
    window = AnalizadorApp()
    # Mostrar la ventana en pantalla
    window.show()
    # Iniciar el bucle de eventos y asegurar un cierre limpio del proceso
    sys.exit(app.exec())