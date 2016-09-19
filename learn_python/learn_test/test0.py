# -*- coding: utf-8 -*-
"""
Created on Mon Mar  7 18:28:18 2016

@author: qianshengxin
"""
import numpy as np 
import matplotlib.pyplot as plt
import re
print "================================================="

print "hello world"

x = np.arange(1,10,0.1);
y = np.sin(x);
z = np.cos(x);
plt.plot(x,y,"-o",label="$sin(x)$",color="black",linewidth=2)
plt.plot(x,z,"-o",label="$sin(x)$",color="green",linewidth=2)
plt.xlabel("Time(s)")
plt.ylabel("Volt")
plt.title("PyPlot First Example")
plt.legend()
plt.grid()
plt.show()

