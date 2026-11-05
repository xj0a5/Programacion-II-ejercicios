""""Guia7, ejercicio 4 inciso b)"""
import numpy as np
import matplotlib.pyplot as plt

# 1. Crear el plano complejo (enfocado entre x=-2 y x=3 para ver el salto)
x = np.linspace(-2, 3, 400)
y = np.linspace(-2, 2, 400)
X, Y = np.meshgrid(x, y)
Z = X + 1j * Y

# 2. Calcular la función interna W = 1 - z y su ángulo (parte imaginaria del Log)
W = 1 - Z
Arg_W = np.angle(W)

# 3. Coordenadas del contorno C (el cuadrado de vértices +-0.5 +-0.5i)
cuadrado_x = [-0.5, 0.5, 0.5, -0.5, -0.5]
cuadrado_y = [-0.5, -0.5, 0.5, 0.5, -0.5]

# 4. Levantar el gráfico 3D
fig = plt.figure(figsize=(12, 8))
ax = fig.add_subplot(111, projection='3d')

# Graficar la superficie del Logaritmo
ax.plot_surface(X, Y, Arg_W, cmap='twilight', edgecolor='none', alpha=0.8)

# Dibujar el contorno C flotando un poco más abajo para que se vea claro
ax.plot(cuadrado_x, cuadrado_y, -3, color='red', linewidth=3, label='Contorno C (Seguro)')

ax.set_title("Corte de rama de Log(1-z) y el Contorno C")
ax.set_xlabel("Eje Real (x)")
ax.set_ylabel("Eje Imaginario (y)")
ax.set_zlabel("Ángulo Arg(1-z)")
ax.legend()

plt.show()