#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import matplotlib.pyplot as plt
import matplotlib as mpl
import csv

def save(name='', fmt='png'):
    plt.savefig('chars/%s.%s' % (name, fmt), fmt='png')

timesList = []
temperatureList = []
humidityList = []
targetTemperatureList = []
targetHumidityList = []
humidification_relayList = []
heating_relayList = []
cooling_relayList = []


# currentSeconds	temperature	humidity	targetTemperature	targetHumidity	humidification_relay	heating_relay	cooling_relay
with open('output', 'r') as f:
    reader = csv.reader(f, delimiter='\t')
    # your_list = list(reader)
    # print (reader.fieldnames)
    reader.__next__()
    for row in reader:
       # print(row)
        timesList.append(row[0])
        temperatureList.append(row[1])
        humidityList.append(row[2])
        targetTemperatureList.append(row[3])
        targetHumidityList.append(row[4])
        humidification_relayList.append(row[5])
        heating_relayList.append(row[6])
        cooling_relayList.append(row[7])
# print(your_list)


#print ('Current version on matplotlib library is', mpl.__version__)

fig = plt.figure()

ttp = fig.add_subplot(111)
#ttp.set_figheight(50)
ttp.plot(timesList, temperatureList, color='r', linewidth=4.0,label='temperature')
ttp.plot(timesList, targetTemperatureList, color='g', linewidth=4, label='targetTemperature')
ttp.plot(timesList, cooling_relayList, color='g', linewidth=4, label='cooling')
ttp.plot(timesList, heating_relayList, color='blue', linewidth=4, label='heating')



#ttp.plot(timesList, humidityList, color='blue', linewidth=4, label='humidity')
#ttp.plot(timesList, targetHumidityList, color='blue', linewidth=4, label='targetHumidity')
#ttp.plot(timesList, humidification_relayList, color='blue', linewidth=4, label='humidification')




ttp.grid(True)
ttp.legend()

#tp.grid(True)
#tp.legend()
#print (fig.axes)
#rint (type(fig))

# save(name='pic_1_4_1', fmt='png')

plt.show()
