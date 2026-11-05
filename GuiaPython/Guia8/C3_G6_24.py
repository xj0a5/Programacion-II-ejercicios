import numpy as np
import matplotlib.pyplot as plt

# 1. Definir el dominio del rectángulo semi-infinito
# x arranca desde un negativo grande (-6) hasta 1, y va de 0 a pi
x = np.linspace(-6, 1, 60)
y = np.linspace(0, np.pi, 60)
X, Y = np.meshgrid(x, y)

# 2. Construir la malla en el plano Z
Z = X + 1j * Y

# 3. Aplicar la transformación: w = -2 * (e^(z-i) + i)
W = -2 * (np.exp(Z - 1j) + 1j)

# 4. Configurar el lienzo
plt.figure(figsize=(12, 6))

# --- Plano Z (Franja original) ---
plt.subplot(1, 2, 1)
plt.title("Plano Z: Rectángulo semi-infinito")
plt.plot(Z.real, Z.imag, color='blue', alpha=0.5)      # Líneas horizontales
plt.plot(Z.real.T, Z.imag.T, color='red', alpha=0.5)   # Líneas verticales
plt.xlabel("Eje Real (x)")
plt.ylabel("Eje Imaginario (y)")
plt.axhline(0, color='black', linewidth=1)
plt.axvline(0, color='black', linewidth=1)
plt.grid(True)
plt.axis('equal')

# --- Plano W (Imagen Transformada) ---
plt.subplot(1, 2, 2)
plt.title("Plano W: Sector circular")
plt.plot(W.real, W.imag, color='blue', alpha=0.5)      # Curvas mapeadas
plt.plot(W.real.T, W.imag.T, color='red', alpha=0.5)   # Rayos radiales
plt.xlabel("Eje Real (u)")
plt.ylabel("Eje Imaginario (v)")
plt.axhline(0, color='black', linewidth=1)
plt.axvline(0, color='black', linewidth=1)
plt.grid(True)
plt.axis('equal')

plt.tight_layout()
plt.show()