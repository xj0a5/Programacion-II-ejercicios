import numpy as np
import matplotlib.pyplot as plt


def dBm_a_mW(dbm):
    """
    Convierte una señal expresada en dBm a Watts.
    
    Parámetros:
    -----------
    dbm : numpy.ndarray
        Array de NumPy con los valores de potencia en dBm.
        
    Retorna:
    --------
    numpy.ndarray
        Array con los valores convertidos a Watts.
    """
    return 10 ** (dbm / 10)

def main():
    rng =np.random.default_rng(7)
    rssi_simulado = rng.normal(-70.0, 4.0, 100)
    rssi_mw = dBm_a_mW(rssi_simulado)
    prom_mw = np.mean(rssi_mw)
    prom_dbm = 10 * np.log10(prom_mw)

    # 1- Conseguimos valores maximo y mínimo
    valor_max = rssi_simulado.max()
    valor_min = rssi_simulado.min()
    idx_max = rssi_simulado.argmax()
    idx_min = rssi_simulado.argmin()

    # 2- Calculamos la desviación
    desviacion = np.std(rssi_simulado, ddof=1) # ddof=1 calcula la desviación muestral (dividiendo por n-1)

    plt.figure(figsize=(10, 5))

    # 1- Graficamos desviación
    plt.axhspan(
        prom_dbm - desviacion, 
        prom_dbm + desviacion, 
        color="orange", 
        alpha=0.2, 
        label=f"±1 Desv. Estándar ({desviacion:.2f} dBm)"
    )

    # 2- Graficamos las muestras
    plt.plot(rssi_simulado, marker="o", label="RSSI simulados(100 muestras)")
    plt.axhline(prom_dbm, color="red",
        linestyle="--" ,
        label="Promedio [dBm]")

    # 3- Notamos maximo y minimo
    plt.scatter(idx_min, valor_min, color="red", s=80, label=f"Mín: {valor_min:.2f}")
    plt.scatter(idx_max, valor_max, color="green", s=80, label=f"Máx: {valor_max:.2f}")
    
    
    plt.legend(bbox_to_anchor=(1.05, 1), loc='upper center', borderaxespad=0.)
    plt.grid(True)
    plt.show()

main()