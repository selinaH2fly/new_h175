class PressureParameters:
    def __init__(self):
        # Pressure initialization in bar (bara)
        self.PTC001_p_bara = 0.7  # Ambient pressure for FL270
        self.PTC211_p_bara = 2.6  # Pressure after compressor stage 2
        self.PTC301_p_bara = 2.5  # Pressure after intercooler, air-air, warm side
        self.PTC311_p_bara = 2.4  # Pressure after intercooler, air-liq
        self.PTC401_p_bara = 2.3  # Pressure after humidifier
        self.PTC501_p_bara = 2.1  # Pressure after stack
        self.PTC601_p_bara = 1.8  # Pressure after water separator
        self.p_8 = 1.7  # Pressure at intercooler, air-air, cold side

        # Convert from bara to Pa manually
        self.PTC001_p_Pa = self.PTC001_p_bara * 1e5  # 1 bara = 100000 Pa
        self.PTC211_p_Pa = self.PTC211_p_bara * 1e5
        self.PTC301_p_Pa = self.PTC301_p_bara * 1e5
        self.PTC311_p_Pa = self.PTC311_p_bara * 1e5
        self.PTC401_p_Pa = self.PTC401_p_bara * 1e5
        self.PTC501_p_Pa = self.PTC501_p_bara * 1e5
        self.PTC601_p_Pa = self.PTC601_p_bara * 1e5
        self.p_8_Pa = self.p_8 * 1e5

    def print_pressures(self):
        print("Pressure Values:")
        print(f"PTC001: {self.PTC001_p_bara} bara = {self.PTC001_p_Pa:.2f} Pa")


# Example usage
if __name__ == "__main__":
    pressures = PressureParameters()
    pressures.print_pressures()  # Call the print method to display the pressure values
