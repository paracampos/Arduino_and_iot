import numpy as np
import pandas as pd
import random

df = pd.DataFrame()

f = open("fakefile.txt", "w")
text = ""

for i in range(48):
	line = str(i)+"\t"+str(random.uniform(10,30))+"\t"+str(random.uniform(30,60))+"\n"
	text+=line

file = open("fakefile.txt", "a")
f.write(text)
f.close()
	
	