""""Ejercicio 3"""
import pandas as pd
import numpy as np

def main():
    """Función principal del ejercicio"""
    df = pd.read_csv("telemetria.csv", parse_dates=["timestamp"])

# Definimos la lista de condiciones (cada una entre paréntesis y separada por comas)
    condiciones = [
        (df["rssi"] >= -60),
        (df["rssi"] >= -67) & (df["rssi"] < -60),
        (df["rssi"] >= -75) & (df["rssi"] < -67),
        (df["rssi"] < -75)
    ]

# Definimos los resultados para cada condición (en el mismo orden)
    resultados = ["Excelente", "Buena", "Regular", "Mala"]

# Aplicamos np.select y guardamos el resultado en la nueva columna
    df["calidad"] = np.select(condiciones, resultados, default="Sin Datos")

# Mostramos resultado:
    print(df[["estacion", "rssi", "calidad"]].head(15))

main()
