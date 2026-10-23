import numpy as np
import math

def dbm_a_mw(pot_dbi):
    pot_mw = 10**(pot_dbi/10)
    return pot_mw

def mw_a_dbm(pot_mw):
    pot_dbm = 10*math.log10(pot_mw)
    return pot_dbm

def encontrarargumento(valor,lista):
    contador=0
    deteccion = -1
    for medida in lista:
        if(valor == medida):
            deteccion = 1
            break
        contador += 1

    if(deteccion==1):
        return contador
    else:
        print(f"No se encuentra el valor en la lista")
        return -1

def contadordeargumentos(valor,lista,lista2):
    contador=0
    i = 0
    for medida in lista:
        if(medida == True):
            contador +=1
            print(f"En la hora {i}:00 se registro {lista2[i]} dBi")
        i += 1
    return contador

def contadorargumentos(valor,lista):
    contador=0
    for medida in lista:
         if(medida == True):
            contador +=1
    return contador
    

def main():
    rssi = np.array([-68.2, -67.9, -67.5, -67.8, -68.0, -68.9,
-70.4, -72.8, -74.1, -75.6, -76.3, -75.9,
-74.8, -75.2, -76.8, -77.1, -75.4, -73.9,
-72.2, -70.8, -69.9, -69.1, -68.7, -68.4])

    rssi_mw = []    
    for potdbi in rssi:
        rssi_mw.append(dbm_a_mw(potdbi))

    prom_mw = np.mean(rssi_mw)
    prom_dbm = mw_a_dbm(prom_mw)

    print(f"Promedio = {prom_dbm:.3f} dBm")
    minimo = np.argmin(rssi)
    maximo = np.argmax(rssi)
    print(f"Minimo: {rssi[minimo]} dBi, ocurrido a las {encontrarargumento(rssi[minimo],rssi)}:00 Horas")
    print(f"Minimo: {rssi[maximo]} dBi, ocurrido a las {encontrarargumento(rssi[maximo],rssi)}:00 Horas")

    mascara = rssi <-75

    print(f"Estuvo {contadordeargumentos(True,mascara,rssi)} horas por debajo de -75 dBi")

    mascara2 = (rssi >=-75)& (rssi <-72)

    print(f"Estuvo {contadorargumentos(True,mascara2)} horas en la zona de riesgo")
    print(f"================================================")
    #CON TODA LA LIBRERIA NUMPY

    rssi_mw = 10 ** (rssi / 10)
    prom_mw = np.mean(rssi_mw)
    prom_dbm = 10 * np.log10(prom_mw)

    print(f"Promedio de potencia = {prom_dbm:.3f} dBm\n")

    print(f"Mínimo: {np.min(rssi)} dBm, ocurrido a las {np.argmin(rssi)}:00 Horas")
    print(f"Máximo: {np.max(rssi)} dBm, ocurrido a las {np.argmax(rssi)}:00 Horas")

    mascara_baja = rssi < -75
    
    cantidad_baja = np.sum(mascara_baja)
    
    horas_bajas = np.where(mascara_baja)[0] 

    print(f"Estuvo {cantidad_baja} horas por debajo de -75 dBm")
    print(f"Fueron exactamente en las horas: {horas_bajas}\n")

    mascara_riesgo = (rssi >= -75) & (rssi < -72)
    
    print(f"Estuvo {np.sum(mascara_riesgo)} horas en la zona de riesgo")

main()