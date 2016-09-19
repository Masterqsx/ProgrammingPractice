#-*- coding: utf-8 -*-


import re
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

  return count


f1 = open("test.txt");
print analyzer(f1)      
f1.close();

