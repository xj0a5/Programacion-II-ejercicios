import matplotlib.pyplot as plt
import numpy as np

# ==========================================
# 1. DATOS DE LAS TABLAS
# ==========================================

# Tabla 1: R = 1000 ohm (frecuencia en kHz, corriente en A)
freq_1000 = np.array(
    [1, 2, 3, 4, 4.5, 4.8, 5, 5.11015, 5.2, 5.5, 6, 7, 8, 9, 10]
)
curr_1000 = np.array([
    0.000227,
    0.000509,
    0.000957,
    0.001834,
    0.00247,
    0.002761,
    0.002825,
    0.002801,
    0.002753,
    0.0025,
    0.002,
    0.00133,
    0.000984,
    0.000777,
    0.00064,
])

# Tabla 2: R = 3900 ohm (en la captura figura V_R; estimación I = V_R / 3900)
freq_3900_raw = np.array(
    [1, 2, 3, 4, 4.5, 4.8, 5.05, 5, 5.1, 5.2, 5.5, 6, 7, 8, 9, 10]
)
volt_3900_raw = np.array([
    0.84,
    1.69,
    2.48,
    3.03,
    3.17,
    3.20,
    3.214,
    3.21,
    3.21,
    3.21,
    3.18,
    3.09,
    2.83,
    2.53,
    2.25,
    2.01,
])

idx_sort = np.argsort(freq_3900_raw)
freq_3900 = freq_3900_raw[idx_sort]
curr_3900_est = volt_3900_raw[idx_sort] / 3900.0

# Pasamos a miliamperios (mA) para que los números del eje Y sean más legibles
curr_1000_ma = curr_1000 * 1000
curr_3900_ma = curr_3900_est * 1000

# ==========================================
# GRÁFICA 1: Corriente con R = 1000 ohm
# ==========================================
plt.figure(figsize=(8, 5))
plt.plot(
    freq_1000,
    curr_1000_ma,
    marker="o",
    linestyle="-",
    color="tab:blue",
    label="R = 1000 Ω (medida)",
)
plt.xscale("log")
plt.xticks(
    [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
    ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10"],
)
plt.title("Corriente vs. Frecuencia — R = 1000 Ω")
plt.xlabel("Frecuencia (kHz) [Escala Logarítmica]")
plt.ylabel("Corriente I (mA)")
plt.grid(True, which="both", linestyle="--", alpha=0.5)
plt.legend()
plt.tight_layout()

# ==========================================
# GRÁFICA 2: Corriente con R = 3900 ohm
# ==========================================
plt.figure(figsize=(8, 5))
plt.plot(
    freq_3900,
    curr_3900_ma,
    marker="s",
    linestyle="-",
    color="tab:orange",
    label="R = 3900 Ω (estimada V_R / R)",
)
plt.xscale("log")
plt.xticks(
    [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
    ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10"],
)
plt.title("Corriente vs. Frecuencia — R = 3900 Ω")
plt.xlabel("Frecuencia (kHz) [Escala Logarítmica]")
plt.ylabel("Corriente I (mA)")
plt.grid(True, which="both", linestyle="--", alpha=0.5)
plt.legend()
plt.tight_layout()

# ==========================================
# GRÁFICA 3: COMPARACIÓN (MISMAS ESCALAS)
# ==========================================
plt.figure(figsize=(9, 5.5))
plt.plot(
    freq_1000,
    curr_1000_ma,
    marker="o",
    linestyle="-",
    color="tab:blue",
    label="R = 1000 Ω",
)
plt.plot(
    freq_3900,
    curr_3900_ma,
    marker="s",
    linestyle="-",
    color="tab:orange",
    label="R = 3900 Ω (más baja y achatada)",
)

plt.xscale("log")
plt.xlim(0.9, 11)
plt.ylim(0, 3.2)  # Misma escala vertical en mA
plt.xticks(
    [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
    ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10"],
)
plt.title("Comparación de Corriente: R = 1000 Ω vs. R = 3900 Ω")
plt.xlabel("Frecuencia (kHz) [Escala Logarítmica]")
plt.ylabel("Corriente I (mA)")
plt.grid(True, which="both", linestyle="--", alpha=0.5)
plt.legend()
plt.tight_layout()

plt.show()