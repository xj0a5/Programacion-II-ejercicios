import numpy as np

def main():
    vluz = 299792458
    lista_frechz = np.array([5.8, 5.8, 5.8, 2.4, 2.4, 2.4, 5.8, 2.4]) * (10**9)
    lista_frecmhz = np.array([5.8, 5.8, 5.8, 2.4, 2.4, 2.4, 5.8, 2.4])
    lista_dism = np.array([2.5, 8.0, 12.0, 3.0, 15.0, 20.0, 6.5, 28.0]) * 1000
    lista_diskm = np.array([2.5, 8.0, 12.0, 3.0, 15.0, 20.0, 6.5, 28.0])
    lista_tx = np.array([23.0,23.0,23.0,23.0,23.0,23.0,23.0,23.0])
    lista_gx = np.array([15.0,15.0,15.0,15.0,15.0,15.0,15.0,15.0])

    lista_fspl = 20 * np.log10((4 * np.pi * lista_dism * lista_frechz) / vluz)
    lista_fspl_redondeada = np.round(lista_fspl,2)
    
    print(f"Fspl:")
    print(lista_fspl_redondeada)

    lista_px= lista_tx + 2*lista_gx - lista_fspl
    lista_margen = lista_px - -75
    lista_margen_redondeada = np.round(lista_margen, 2)
    
    print(f"Margen:")
    print(lista_margen_redondeada)          #porque no muestra los ultimos decimales

    lista_aprobados = np.where(lista_margen_redondeada > 0 , "OK","FALLA")

    print(f"Estado de los enlaces:")
    print(lista_aprobados)

    print("|Distancia[Km]\t|Frecuencia[MHz]|FSPL[dB]\t|Margen\t|Estado")
    for dis,frec,fspl,margen,estado in zip(lista_diskm, lista_frecmhz, lista_fspl_redondeada,lista_margen_redondeada,lista_aprobados):
        print(f"|{dis}\t\t|{frec}\t\t|{fspl}\t\t|{margen}\t|{estado}")

main()