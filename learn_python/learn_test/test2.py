import os
import glob
for root, dirs, files in os.walk('./txt_sentoken'):
  it = glob.glob(os.path.join(root,"*.txt"))
  if len(it)!=0 :
    print it
