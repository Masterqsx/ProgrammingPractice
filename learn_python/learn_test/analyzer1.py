#-*- coding: utf-8 -*-


import re,os,glob
from sklearn import datasets,svm
import numpy as np
def analyzer(f1):
  pos_words=['love','wonderful','best','great','superb','stil','beautiful']
  neg_words=['bad','worst','stupid','waste','boring','\?','\!']
  index=range(7)
  pos_words=zip(pos_words,index)
  neg_words=zip(neg_words,index)
  p_count=[0]*7
  n_count=[0]*7
  for line in f1:
    for p_word in pos_words :
      ma = re.findall(p_word[0],line)  
      if len(ma)!=0 :
        p_count[p_word[1]] = p_count[p_word[1]] + len(ma)

    for n_word in neg_words :
      ma = re.findall(n_word[0],line) 
      if len(ma)!=0 :
        n_count[n_word[1]] = n_count[n_word[1]] + len(ma)

  return p_count+n_count

nu = 0;
co = 0.0;
data = []
target = []
for root, dirs, files in os.walk("./review0"):
  it = glob.glob(os.path.join(root,"*.txt"))
  flag = 0
  if re.search("neg",root) :
    flag = 1
  if len(it)==0:
    continue
  for path in it :
    with open(path) as f_input:
      data.append(analyzer(f_input))
      target.append(flag)

data = np.array(data)
target = np.array(target)
index = np.arange(len(data))/4
np.random.shuffle(index)

sentiment = svm.NuSVC()
sentiment.fit(data,target)

for root, dirs, files in os.walk("./review1"):
  it = glob.glob(os.path.join(root,"*.txt"))
  flag = 1
  if re.search("neg",root) :
    flag = 0
  if len(it)==0:
    continue
  for path in it :
    with open(path) as f_input:
      co = co + 1
      test = np.array(analyzer(f_input))
      anay_re = sentiment.predict(test.reshape(1,-1))+flag;
      if anay_re == 1 :
        nu = nu + 1
print nu/co

