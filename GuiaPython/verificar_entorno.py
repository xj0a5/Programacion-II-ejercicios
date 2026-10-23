"""
verificar_entorno.py
====================

Programación II (5002) - Ingeniería en Telecomunicaciones
Unidad: Librerías aplicadas en Ingeniería

Verifica que el entorno de trabajo esté listo para la unidad:

    1. Versión de Python (3.10 o superior).
    2. Que el script se ejecute dentro de un entorno virtual (.venv).
    3. Que estén instaladas las librerías NumPy, Matplotlib, SciPy y Pandas.
    4. Que cada librería funcione (se hace una prueba breve con cada una).
    5. Que Matplotlib pueda abrir una ventana con un gráfico.

Uso:
    python verificar_entorno.py              # verificación completa con gráfico
    python verificar_entorno.py --sin-grafico  # sin abrir la ventana del gráfico

El programa está escrito con programación estructurada: funciones y un main().
"""

import sys
import importlib

# Versión mínima de Python requerida para la unidad
VERSION_MINIMA = (3, 10)

# Librerías externas de la unidad: (nombre para importar, nombre para pip)
LIBRERIAS = [
    ("numpy", "numpy"),
    ("matplotlib", "matplotlib"),
    ("scipy", "scipy"),
    ("pandas", "pandas"),
]


def imprimir_titulo(texto):
    """Imprime un título subrayado para separar las secciones del informe."""
    print()
    print(texto)
    print("-" * len(texto))


def verificar_version_python():
    """Devuelve True si la versión de Python es suficiente."""
    version = sys.version_info
    texto_version = f"{version.major}.{version.minor}.{version.micro}"

    if (version.major, version.minor) >= VERSION_MINIMA:
        print(f"[OK]    Python {texto_version}")
        return True

    minima = f"{VERSION_MINIMA[0]}.{VERSION_MINIMA[1]}"
    print(f"[ERROR] Python {texto_version}: se necesita {minima} o superior")
    return False


def verificar_entorno_virtual():
    """
    Informa si el script corre dentro de un entorno virtual.

    Dentro de un entorno virtual, sys.prefix (carpeta del entorno) es distinto
    de sys.base_prefix (carpeta de la instalación original de Python).
    No es un error grave, por eso solo se emite una advertencia.
    """
    if sys.prefix != sys.base_prefix:
        print(f"[OK]    Entorno virtual activo: {sys.prefix}")
        return True

    print("[AVISO] No se detectó un entorno virtual activo.")
    print("        Revisá el paso 'Activar el entorno virtual' de la guía.")
    return False


def verificar_librerias():
    """
    Intenta importar cada librería de la lista.

    Devuelve una lista con los nombres de pip de las librerías que faltan.
    """
    faltantes = []

    for nombre_modulo, nombre_pip in LIBRERIAS:
        try:
            modulo = importlib.import_module(nombre_modulo)
            print(f"[OK]    {nombre_modulo:<11} versión {modulo.__version__}")
        except ImportError:
            print(f"[ERROR] {nombre_modulo:<11} no está instalada")
            faltantes.append(nombre_pip)

    return faltantes


def probar_numpy():
    """Prueba NumPy: promedio de un vector de RSSI en dBm."""
    import numpy as np

    rssi = np.array([-70.0, -72.0, -68.0])
    return abs(np.mean(rssi) - (-70.0)) < 1e-9


def probar_scipy():
    """Prueba SciPy: el espectro de un tono de 50 Hz debe tener su pico en 50 Hz."""
    import numpy as np
    from scipy.fft import fft, fftfreq

    fs = 1000                                  # frecuencia de muestreo [Hz]
    t = np.arange(0, 1, 1 / fs)                # 1 segundo de muestras
    senal = np.sin(2 * np.pi * 50 * t)         # tono de 50 Hz

    n = len(senal)
    amplitudes = np.abs(fft(senal))[: n // 2]
    frecuencias = fftfreq(n, 1 / fs)[: n // 2]
    frecuencia_pico = frecuencias[np.argmax(amplitudes)]

    return abs(frecuencia_pico - 50) < 1e-9


def probar_pandas():
    """Prueba Pandas: promedio de RSSI agrupado por estación."""
    import pandas as pd

    datos = pd.DataFrame({
        "estacion": ["E01", "E01", "E02"],
        "rssi": [-70.0, -72.0, -65.0],
    })
    promedios = datos.groupby("estacion")["rssi"].mean()
    return abs(promedios["E01"] - (-71.0)) < 1e-9


def ejecutar_pruebas():
    """Ejecuta las pruebas de funcionamiento. Devuelve True si todas pasan."""
    pruebas = [
        ("NumPy  - estadística de un vector", probar_numpy),
        ("SciPy  - espectro de un tono", probar_scipy),
        ("Pandas - agrupamiento por estación", probar_pandas),
    ]

    todas_ok = True
    for descripcion, funcion_prueba in pruebas:
        try:
            resultado = funcion_prueba()
        except Exception as error:          # cualquier falla inesperada
            print(f"[ERROR] {descripcion}: {error}")
            todas_ok = False
            continue

        if resultado:
            print(f"[OK]    {descripcion}")
        else:
            print(f"[ERROR] {descripcion}: resultado incorrecto")
            todas_ok = False

    return todas_ok


def mostrar_grafico_prueba():
    """
    Abre una ventana con un gráfico de prueba (un tono de 5 Hz).

    Si la ventana aparece, Matplotlib está funcionando.
    El programa queda detenido hasta que se cierra la ventana.
    """
    import numpy as np
    import matplotlib.pyplot as plt

    t = np.linspace(0, 1, 500)
    senal = np.sin(2 * np.pi * 5 * t)

    plt.figure()
    plt.plot(t, senal)
    plt.title("Entorno listo - cerrá esta ventana para terminar")
    plt.xlabel("Tiempo [s]")
    plt.ylabel("Amplitud")
    plt.grid()
    plt.show()


def main():
    """Organiza la verificación completa e informa el resultado final."""
    sin_grafico = "--sin-grafico" in sys.argv

    print("=" * 60)
    print("Verificación del entorno - Librerías aplicadas en Ingeniería")
    print("=" * 60)

    imprimir_titulo("1. Python")
    python_ok = verificar_version_python()

    imprimir_titulo("2. Entorno virtual")
    verificar_entorno_virtual()        # solo advierte, no impide continuar

    imprimir_titulo("3. Librerías")
    faltantes = verificar_librerias()

    if not python_ok or faltantes:
        imprimir_titulo("Resultado")
        print("El entorno NO está listo.")
        if faltantes:
            print("Instalá lo que falta con:")
            print(f"    pip install {' '.join(faltantes)}")
        sys.exit(1)

    imprimir_titulo("4. Pruebas de funcionamiento")
    pruebas_ok = ejecutar_pruebas()

    imprimir_titulo("Resultado")
    if not pruebas_ok:
        print("El entorno tiene librerías instaladas pero alguna prueba falló.")
        print("Consultá la sección 'Problemas frecuentes' de la guía.")
        sys.exit(1)

    print("El entorno está listo para la unidad.")

    if not sin_grafico:
        print("Abriendo un gráfico de prueba...")
        mostrar_grafico_prueba()


main()