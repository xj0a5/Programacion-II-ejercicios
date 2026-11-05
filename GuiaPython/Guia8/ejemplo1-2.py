import numpy as np
import matplotlib.pyplot as plt


def main():
    rssi = np.array([-72.3, -68.1, -75.4, -70.2, -67.8 ,
    -71.4, -73.2, -69.8, -80.1, -76.4])

    rssi_prom = np.mean(rssi)

    plt.figure()
    plt.plot(rssi, marker="o", label="RSSI medido")
    plt.axhline(-75, color="red",
    linestyle="--" ,
    label="Umbral -75 dBm")
    #Esta mal porque necesitamos pasar primero de dBm a mW y despues promediar.

    plt.axhline(rssi_prom, color="yellow",
        linestyle="--" ,
        label="Promedio rssi")

    plt.title("Ejemplo - 1")
    plt.xlabel("Muestra") 
    plt.ylabel("RSSI [dBm]")
    plt.grid()
    plt.legend()

    plt.show()

main()
