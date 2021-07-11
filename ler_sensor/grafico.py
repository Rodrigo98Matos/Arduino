

import matplotlib.pyplot as plt
import numpy as np
import time
import serial
import random
leitura = list()
fig, ax = plt.subplots()
ser = serial.Serial('COM3') #Porta a ser lida

contador = 0
eixo_x = 50
while True:
    while(ser.inwaiting()==0):
        pass
        dados = int(ser.readline()[:-1])
        print(dados)
        ax.clear()
        ax.set_xlim([0,eixo_x])
        ax.set_ylim([0,1023])
        leitura.append(random.randint(0,1023))
        #leitura.append(dados)

        ax.plot(leitura)
        plt.pause(.000001)
        contador += 1
        if (contador > eixo_x):
            leitura.pop(0)

ser.close()
