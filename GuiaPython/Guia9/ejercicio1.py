""""Tablilla de frecuencias y potencias"""
import pandas as pd
import numpy as np
V_LUZ = 299792458


def comprobar_cambios(df):
    """Comprueba si hubo algún cambio de valor en frecuencia o potencia en \
        los datos de cada estación"""
    conteo_unicos = df.groupby("estacion")[["frecuencia",
                                            "potencia"]].nunique()

    # El values.any() hace la pregunta ¿Hay almenos un true en toda la tabla?
    hay_cambios = (conteo_unicos > 1).values.any()

    # Retorna True si hubo cambios, o False si todo se mantuvo en 1
    return hay_cambios


def promediodbmporbanda(df):
    """"Convertir,promediar y convertir para obtener la \
        potencia promedio por banda"""
    potencia_mw = 10 ** (df["potencia"] / 10)
    promedio_mw_por_banda = potencia_mw.groupby(df["frecuencia"]).mean()
    promedio_dbm_por_banda = 10 * np.log10(promedio_mw_por_banda)
    return promedio_dbm_por_banda


def longitudesdeonda(df):
    """"Calcular los λ de cada frecuencia"""
    frecuencias = df["frecuencia"] * (10**6)
    lambdas = (V_LUZ / frecuencias) * 100
    return np.round(lambdas, 4)


def main():
    """"funcion principal"""
    df = pd.read_csv("telemetria.csv", parse_dates=["timestamp"])

    frecandpot = df.groupby("estacion")[["frecuencia", "potencia"]].first()
    frecandpot["longitud_onda (cm)"] = longitudesdeonda(frecandpot)
    print("=== Tabla final con longitudes de onda ===")
    print(frecandpot)
    if comprobar_cambios(df):
        print("Hubo cambios de configuración en la red durante la semana.")
    else:
        print("Ninguna estación cambió su frecuencia ni potencia.")

    conteo_bandas = frecandpot.groupby("frecuencia").size()
    print("Estaciones por banda:")
    print(conteo_bandas)
    print("-" * 40)
    print("===Promedio por banda dBm===")
    print(promediodbmporbanda(frecandpot))


main()
