import math

def ganancia_parabolica(diametro_m:float, frecuencia_hz: float, eficiencia: float):
    vluz = 299792458
    long_onda = vluz / (frecuencia_hz*(10**9))
    ganancia_dbi= 10*math.log10(eficiencia*((math.pi*diametro_m)/long_onda)**2)
    return ganancia_dbi

class Antena:
    diametro: float
    frecuencia: float
    def __init__(self,frec:float,medida:float):
        self.diametro = medida
        self.frecuencia = frec

def main():
    eficencia = 0.55
    antenas_5_8g = []
    antenas_11g = []
    medidas = [0.3,0.6,1.2]
    for medida in medidas:                  #Va iterando por cada medida de "medidas" el nombre de medida es arbitrario
        celda5g=Antena(5.8,medida)          #A la primera iteracion medida sera 0.3 y no digamos "0" 
        antenas_5_8g.append(celda5g)

        celda_11g=Antena(11,medida)
        antenas_11g.append(celda_11g)

    for antena in antenas_5_8g:
        print(f"Con una medida de {antena.diametro} y una frecuencia de {antena.frecuencia}")
        print(f"La ganancia es {ganancia_parabolica(antena.diametro,antena.frecuencia,eficencia):.3f} dBi")

    for antena in antenas_11g:
            print(f"Con una medida de {antena.diametro} y una frecuencia de {antena.frecuencia}")
            print(f"La ganancia es {ganancia_parabolica(antena.diametro,antena.frecuencia,eficencia):.3f} dBi")
    print(f"===============================================")

#Cuadrilla hecha por gemini

    print(f"{'Medida (m)':<12} | {'Frecuencia (GHz)':<18} | {'Ganancia (dBi)':<15}")
    
    print("-" * 52)

    todas_las_antenas = antenas_5_8g + antenas_11g

    for antena in todas_las_antenas:
        ganancia = ganancia_parabolica(antena.diametro, antena.frecuencia, eficencia)
        print(f"{antena.diametro:<12} | {antena.frecuencia:<18} | {ganancia:<15.3f}")
main()