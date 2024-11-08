import unittest
from pathlib import Path

import sys

import os, sys
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..', '..', '05_overall', '05_fcs_dimensioning_model')))


import basic_physics


class TestConvert(unittest.TestCase):
    def test_degC_to_K(self):
        self.assertEqual(round(basic_physics.convert(0, 'degC', 'K'),2), 273.15)
        self.assertEqual(round(basic_physics.convert(100, 'degC', 'K'), 2), 373.15)
        self.assertEqual(round(basic_physics.convert(-273.15, 'degC', 'K'), 2), 0)

    def test_K_to_degC(self):
        self.assertEqual(round(basic_physics.convert(273.15, 'K', 'degC'),2), 0)
        self.assertEqual(round(basic_physics.convert( 373.15, 'K', 'degC'), 2), 100)
        self.assertEqual(round(basic_physics.convert(0, 'K', 'degC'), 2), -273.15)


    def test_kg_s_to_l_min(self):
        self.assertEqual(round(basic_physics.convert(1, 'kg_s', 'l_min', fluid="Air", temperature=293.15, pressure=101325 , relative_humidity=0.5), 2), 50076.21 )
        self.assertEqual(round(basic_physics.convert(0.5, 'kg_s', 'l_min', fluid="Air", temperature=303.15, pressure=101325 , relative_humidity=0.7), 2), 26068.27)
        self.assertEqual(round(basic_physics.convert(2, 'kg_s', 'l_min', fluid="Air", temperature=313.15, pressure=100000  , relative_humidity=0.8), 2), 110393.79)
        self.assertEqual(round(basic_physics.convert(0, 'kg_s', 'l_min', fluid="Air", temperature=293.15, pressure=101325   , relative_humidity=0.5), 2), 0)

    def test_l_min_to_kg_s(self):
        self.assertEqual(round(basic_physics.convert(50076.21 , 'l_min', 'kg_s', fluid="Air", temperature=293.15, pressure=101325 , relative_humidity=0.5), 2), 1 )
        self.assertEqual(round(basic_physics.convert(26068.27, 'l_min', 'kg_s', fluid="Air", temperature=303.15, pressure=101325 , relative_humidity=0.7), 2), 0.5)
        self.assertEqual(round(basic_physics.convert(110393.79, 'l_min', 'kg_s', fluid="Air", temperature=313.15, pressure=100000  , relative_humidity=0.8), 2),2)
        self.assertEqual(round(basic_physics.convert(0, 'l_min', 'kg_s', fluid="Air", temperature=293.15, pressure=101325   , relative_humidity=0.5), 2), 0)

    def test_kg_s_to_m3_min(self):
        self.assertEqual(round(basic_physics.convert(1, 'kg_s', 'm3_min', fluid="Air", temperature=293.15, pressure=101325 , relative_humidity=0.5), 2), 50.08)
        self.assertEqual(round(basic_physics.convert(0.5, 'kg_s', 'm3_min', fluid="Air", temperature=303.15, pressure=101325 , relative_humidity=0.7), 2), 26.07)
        self.assertEqual(round(basic_physics.convert(2, 'kg_s', 'm3_min', fluid="Air", temperature=313.15, pressure=100000  , relative_humidity=0.8), 2), 110.39)
        self.assertEqual(round(basic_physics.convert(0, 'kg_s', 'm3_min', fluid="Air", temperature=293.15, pressure=101325   , relative_humidity=0.5), 2), 0)


    def test_m3_min_to_kg_s(self):
        self.assertEqual(round(basic_physics.convert(50.08, 'm3_min', 'kg_s', fluid="Air", temperature=293.15, pressure=101325 , relative_humidity=0.5), 2), 1)
        self.assertEqual(round(basic_physics.convert(26.07, 'm3_min', 'kg_s', fluid="Air", temperature=303.15, pressure=101325 , relative_humidity=0.7), 2), 0.5)
        self.assertEqual(round(basic_physics.convert(110.39, 'm3_min', 'kg_s', fluid="Air", temperature=313.15, pressure=100000  , relative_humidity=0.8), 2), 2)
        self.assertEqual(round(basic_physics.convert(0, 'm3_min', 'kg_s', fluid="Air", temperature=293.15, pressure=101325   , relative_humidity=0.5), 2), 0)


if __name__ == '__main__':
    unittest.main() 