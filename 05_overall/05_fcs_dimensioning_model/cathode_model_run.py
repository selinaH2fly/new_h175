class PressureParameters:
    def __init__(self):
        self.PTC001_p_bara = 0.7  # Ambient pressure for FL270
        self.PTC211_p_bara = 2.6  # Pressure after compressor stage 2
        self.PTC301_p_bara = 2.5  # Pressure after intercooler, air-air, warm side
        self.PTC311_p_bara = 2.4  # Pressure after intercooler, air-liq
        self.PTC401_p_bara = 2.3  # Pressure after humidifier
        self.PTC501_p_bara = 2.1  # Pressure after stack
        self.PTC601_p_bara = 1.8  # Pressure after water separator
        self.p_8 = 1.7           # Pressure at intercooler, air-air, cold side
