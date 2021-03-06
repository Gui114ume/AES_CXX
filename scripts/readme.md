This directory contains some scripts to test the correctness of the program
Each test is composed as follow:
    - Shell script to launch the program and compare result/expected
    - Clear-text files as input
    - Encrypted version of each input file

Input files will have different sizes
Encrypted files will be made by using each available mode
Comparaison result/expected using their respective sha1 hash