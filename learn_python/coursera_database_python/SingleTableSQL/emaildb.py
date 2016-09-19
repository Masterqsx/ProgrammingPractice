import sqlite3
connector=sqlite3.connect("emaildb.sqlite");
cur=connector.cursor();
cur.execute("DROP TABLE IF EXISTS Counts");
cur.execute("CREATE TABLE Counts(org TEXT, count INTEGER)");
f=open("./SingleTableSQL/mbox.txt");
for line in f:
    if not line.startswith("From:"): continue;
    words=line.split();
    org=words[1].split("@")[1];
    result=cur.execute("SELECT count FROM Counts WHERE org=?",(org,));
    hit_row=result.fetchone();
    if hit_row!=None:
        cur.execute("UPDATE Counts SET count=count+1 WHERE org=?",(org,));
    else:
        cur.execute("INSERT INTO Counts(org,count) VALUES(?,1)",(org,));
connector.commit();
for line in cur.execute("SELECT * FROM Counts ORDER BY count DESC LIMIT 10"):
    print line[0],line[1];

f.close();
cur.close();