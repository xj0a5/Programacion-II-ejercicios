""""Guia 6, ejercicio 22: Graficadora del disco |z+i|>=1"""
import numpy as np
import matplotlib.pyplot as plt

# 1. Definir el dominio polar para el disco |z + i| <= 1
# r va de 0 a 1 (radio), theta va de 0 a 2*pi (ángulo completo)
r = np.linspace(0, 1, 30)
theta = np.linspace(0, 2*np.pi, 60)
R, Theta = np.meshgrid(r, theta)

# 2. Construir la malla compleja centrada en z = -i (0, -1)
Z = R * np.exp(1j * Theta) - 1j

# 3. Aplicar la transformación (Inciso que corresponda)
# Para los próximos incisos, solo tenés que modificar esta línea
W = np.exp(Z)

# 4. Configurar el lienzo de Matplotlib
plt.figure(figsize=(12, 6))

# --- Plano Z (Disco Original) ---
plt.subplot(1, 2, 1)
plt.title("Plano Z: Disco |z + i| ≤ 1")
# Dibujamos las circunferencias concéntricas y las líneas radiales
plt.plot(Z.real, Z.imag, color='blue', alpha=0.5)      # Líneas radiales
plt.plot(Z.real.T, Z.imag.T, color='red', alpha=0.5)   # Circunferencias
plt.xlabel("Eje Real (x)")
plt.ylabel("Eje Imaginario (y)")
plt.axhline(0, color='black', linewidth=1)
plt.axvline(0, color='black', linewidth=1)
plt.grid(True)
plt.axis('equal')

# --- Plano W (Imagen Transformada) ---
plt.subplot(1, 2, 2)
plt.title("Plano W: Transformación w = -z + i")
# Dibujamos la malla transformada
plt.plot(W.real, W.imag, color='blue', alpha=0.5)
plt.plot(W.real.T, W.imag.T, color='red', alpha=0.5)
plt.xlabel("Eje Real (u)")
plt.ylabel("Eje Imaginario (v)")
plt.axhline(0, color='black', linewidth=1)
plt.axvline(0, color='black', linewidth=1)
plt.grid(True)
plt.axis('equal')

plt.tight_layout()
plt.show()