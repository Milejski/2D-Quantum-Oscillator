# 2D-Quantum-Oscillator
Numerical problem solved using imaginary time propagation method.

This project was completed during studies, as a part of Computational methods of physics and engineering course.
More information abous course (unfortunately, mostly in Polish):
http://syllabuskrk.agh.edu.pl/2012-2013/en/magnesite/study_plans/stacjonarne-fizyka-techniczna/module/jft-1-709-s-computational-methods-of-physics-and-engineering-2

To run successfully, program requires labp_data.txt file with user input. First and second line should contain parameters of potencial field used in calculations (wx and wy, both in eV units, ranging from 0.005eV to 0.05eV). Next line contains propagation constant. Third and fourth lines contain number of rows and columns (Nx and Ny) of table, in which function values are being stored. For bigger table calculations take much more time, but energy and function values are more precise. Last line contains number of aditional states, for which calculations must be performed: if the number equals zero, only the lowest energy state is calculated.
Included labp_data.txt file for quick calculations and testing.

Program output is saved in three files:
labp_V file contains potencial values in chosen points.
labp_E file contains energy values in eV.
labp_f file contains function values.
