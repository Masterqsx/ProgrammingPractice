#-*- coding: utf-8 -*-


import re,os,glob
import matplotlib.pyplot as plt
import numpy as np
def analyzer(f1):
  pos_words=['love','wonderful','best','great','superb','stil','beautiful']
  neg_words=['bad','worst','stupid','waste','boring','\?','\!']
  count=[0,0]
  for line in f1:
    for p_word in pos_words :
      ma = re.findall(p_word,line)  
      if len(ma)!=0 :
        count[0] = count[0] + len(ma)

    for n_word in neg_words :
      ma = re.findall(n_word,line) 
      if len(ma)!=0 :
        count[1] = count[1] + len(ma)

  return (count[0]-count[1])
nu_0 = 0;
nu_1 = 0;
co_0 = 0.0;
co_1 = 0.0;
tie = 0;
for root, dirs, files in os.walk("./review0"):
  it = glob.glob(os.path.join(root,"*.txt"))
  flag = 1.0
  if re.search("neg",root) :
    flag = -1.0
  if len(it)==0:
    continue
  for path in it :
    with open(path) as f_input:
      if flag == 1.0 :
        co_1 = co_1 + 1
      else :
        co_0 = co_0 + 1

      result = analyzer(f_input)*flag;
      if result >0 :
        if flag == 1.0 :
          nu_1 = nu_1 + 1
        else :
          nu_0 = nu_0 + 1
      elif result  == 0 :
        tie = tie + 1

print (nu_0+nu_1)/(co_0+co_1), tie/(co_0+co_1)
print nu_1/co_1,nu_0/co_0
