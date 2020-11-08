import numpy as np
import pandas as pd
import random
import datetime

f = open("fakefile.txt", "w")
text = ""

def convertToHex(decNumber):
	hexNumber = hex(decNumber).split('x')[1]
	return str(hexNumber)

def generateCustomTimeStamp():
	nowtime = datetime.datetime.now()
	year = str(nowtime.year)[2:]
	month = nowtime.month
	day = nowtime.day
	hour = nowtime.hour
	minute = nowtime.minute
	return year+str(month)+str(day)+str(hour)+str(minute)

def generateFakeData(initial,final):
	number = round(random.uniform(initial,final), 2)
	integer, decimal = str(number).split('.')
	convertToHex(integer)
	return a,b

for i in range(48):
	#line = str(i) + generateCustomTimeStamp() +"\t"+generateFakeData(10,30)+"\t"+generateFakeData(30,60)+"\n"
	print(generateFakeData(2,9))
	#text+=line

file = open("fakefile.txt", "a")
f.write(text)
f.close()

print(text)
	
	