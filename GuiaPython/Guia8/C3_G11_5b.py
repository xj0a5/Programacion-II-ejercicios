import matplotlib.pyplot as plt
import numpy as np

# Definimos el eje de frecuencias omega (evitamos exactamente el 0 para el inciso b por la división)
omega = np.linspace(-15, 15, 1000)

# Parámetros simbólicos de prueba
A = 1.0
L = 2.0
a = 1.0

# --- Inciso a: Espectro Exponencial ---
# |F(omega)| = 1 / sqrt(a^2 + omega^2)
F_a = 1 / np.sqrt(a**2 + omega**2)

# --- Inciso b: Espectro Pulso Rectangular ---
# |F(omega)| = |2A * sin(omega * L) / omega|
# Usamos np.where para evitar división por cero en omega = 0
omega_safe = np.where(omega == 0, 1e-10, omega)
F_b = np.abs(2 * A * np.sin(omega_safe * L) / omega_safe)

# --- Graficando ---
fig, axes = plt.subplots(1, 2, figsize=(12, 5))

# Gráfico a
axes[0].plot(omega, F_a, color='b', lw=2)
axes[0].set_title('5.a) Espectro de Amplitud ($e^{-at}u(t)$)')
axes[0].set_xlabel('Frecuencia $\\omega$')
axes[0].set_ylabel('$|F(\\omega)|$')
axes[0].grid(True)
axes[0].axvline(0, color='gray', linestyle='--', lw=1)

# Gráfico b
axes[1].plot(omega, F_b, color='r', lw=2)
axes[1].set_title('5.b) Espectro de Amplitud (Pulso Rectangular)')
axes[1].set_xlabel('Frecuencia $\\omega$')
axes[1].set_ylabel('$|F(\\omega)|$')
axes[1].grid(True)
axes[1].axvline(0, color='gray', linestyle='--', lw=1)

plt.tight_layout()
plt.show()