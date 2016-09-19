import re
email="abc";
m=re.match("(.*)@(.*)",email);
if m!=None:
    print m.group(1)