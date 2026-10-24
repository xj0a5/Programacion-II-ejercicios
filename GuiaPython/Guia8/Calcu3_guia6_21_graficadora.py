import numpy as np
import matplotlib.pyplot as plt

# 1. Definir los límites del rectángulo original
# x va de 0 a pi/2, y va de 0 a pi
x = np.linspace(0, np.pi/2, 50)
y = np.linspace(0, np.pi, 50)

# 2. Crear la malla de puntos en el plano complejo
X, Y = np.meshgrid(x, y)
Z = X + 1j * Y

# 3. Aplicar la transformación de Möbius: w = i / (z + 2i)
W = 1j / (Z + 2j)

# 4. Configurar el lienzo
plt.figure(figsize=(12, 5))

# --- Gráfico del Plano Z (Original) ---
plt.subplot(1, 2, 1)
plt.title("Plano Z (Rectángulo Original)")
# Dibujamos las líneas de la cuadrícula
plt.plot(X, Y, color='blue', alpha=0.4)      # Líneas verticales
plt.plot(X.T, Y.T, color='red', alpha=0.4)   # Líneas horizontales
plt.xlabel("Eje Real (x)")
plt.ylabel("Eje Imaginario (y)")
plt.grid(True)
plt.axis('equal') # Mantiene la proporción 1:1 de los ejes

# --- Gráfico del Plano W (Transformado) ---
plt.subplot(1, 2, 2)
plt.title("Plano W (Imagen Transformada)")
# Dibujamos las mismas líneas pero pasadas por la matriz W
plt.plot(W.real, W.imag, color='blue', alpha=0.4)    
plt.plot(W.real.T, W.imag.T, color='red', alpha=0.4) 
plt.xlabel("Eje Real (u)")
plt.ylabel("Eje Imaginario (v)")
plt.grid(True)
plt.axis('equal')

plt.tight_layout()
plt.show()