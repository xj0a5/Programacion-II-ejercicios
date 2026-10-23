""""Ejercicio2"""
import pandas as pd
import matplotlib.pyplot as plt


def valoresvacios(df):
    """"Retorna lista de de temperaturas"""
    df["rssi_vacio"] = df["rssi"].isna()

    # Creo columnas de mascaras booleanas que detectan los \
    # vacios con el metodo isna
    df["temp_vacia"] = df["temperatura"].isna()
    rssi_temp = df.groupby("estacion")[["rssi_vacio", "temp_vacia"]].sum()
    return rssi_temp


def porcentaje_ausentes(df):
    """"Porcentaje de ausentes en la lista"""
    porcentaje_directo = df.isna().mean() * 100
    porcentaje_simbolo = porcentaje_directo.map(lambda x: f"{x:.2f}%")
    return porcentaje_simbolo


def graficarfaltantes(df):
    """"Función graficadora"""
    df["rssi_vacio"] = df["rssi"].isna()
    faltantes_rssi = df.groupby("estacion")["rssi_vacio"].sum()

    plt.figure(figsize=(10, 6))  # Ancho x Alto
    plt.bar(faltantes_rssi.index, faltantes_rssi.values, color="skyblue",
            edgecolor="black")
    plt.title("Cantidad de datos RSSI faltantes por Estación")
    plt.xlabel("Estación")
    plt.ylabel("Cantidad de valores perdidos")
    plt.show()


def main():
    """Función principal del ejercicio"""

    df = pd.read_csv("telemetria.csv", parse_dates=["timestamp"])

    # Declaramos el objeto tipo dataframe
    print("Faltantes por estación:")
    print(valoresvacios(df))
    print("="*40)

    print("Porcentaje de datos perdidos por columna ")
    print(porcentaje_ausentes(df))
    print("="*40)

    graficarfaltantes(df)


main()
