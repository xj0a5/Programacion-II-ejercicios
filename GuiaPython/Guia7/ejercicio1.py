""""Mostrar informacion ejercicio1"""
import math


def w_adm(p_w):
    """Convertidor de watt a dBm"""
    p_m = 10*math.log10(p_w*1000)
    return p_m


def dmb_a_w(p_dbm):
    """Convertidor de dBm a W"""
    p_w = 10**(p_dbm/10)/1000
    return p_w


def dbm_a_dbw(p_dbm):
    """"Convertidor de dBm a dBw"""
    p_dbw = p_dbm - 30
    return p_dbw


class Transmisores: # pylint: disable=too-few-public-methods
    """Clase transmisores que contiene nombre y potencia"""
    nombre: str
    potencia: float

    def __init__(self, mote: str, pot: float):
        self.nombre = mote
        self.potencia = pot

    def mostrar(self):
        """"Mostrar Informacion: Nombre;PotenciaW;PotenciadBw"""
        print(f"Transmisor: {self.nombre}")
        print(f"Potencia(W): {self.potencia}    \
              Potencia(dBm): {w_adm(self.potencia):.3f}")
        print(f"Potencia(dBW): \
              {dbm_a_dbw(w_adm(self.potencia)):.3f}")
        print("=" * 40)


def main():
    """"Funcion main"""
    ap_wifi = Transmisores("Punto de acceso WiFi", 0.1)
    celu = Transmisores("Telefono Celular", 2)
    estacion_base = Transmisores("Estacion Base Celular", 40)
    emisor_fm = Transmisores("Emisora de FM", 10000)

    ap_wifi.mostrar()
    celu.mostrar()
    estacion_base.mostrar()
    emisor_fm.mostrar()


main()
