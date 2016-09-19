import xml.etree.ElementTree as ET
import sqlite3

connector=sqlite3.connect('trackdb.sqlite');
cur=connector.cursor();
cur.executescript('''
    DROP TABLE IF EXISTS Artist;
    DROP TABLE IF EXISTS Genre;
    DROP TABLE IF EXISTS Album;
    DROP TABLE IF EXISTS Track;
    CREATE TABLE Artist(
        id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
        name TEXT UNIQUE);
    CREATE TABLE Genre(
        id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
        name TEXT UNIQUE);
    CREATE TABLE Album(
        id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
        artist_id INTEGER,
        title TEXT UNIQUE);
    CREATE TABLE Track(
        id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
        title TEXT UNIQUE,
        album_id INTEGER,
        genre_id INTEGER,
        len INTEGER,
        rating INTEGER,
        count INTEGER);
''');
f=open("./MultiTableSQL/tracks/Library.xml");
XmlContents=ET.parse(f);
def lookup(d,key):
    flag=False;
    for child in d:
        if flag: return child.text;
        if child.tag == "key" and child.text == key:
            flag=True;
    return None;
Tracks=XmlContents.findall("dict/dict/dict");
for Track in Tracks:
    if (lookup(Track,"Track ID") is None): continue;
    
    name = lookup(Track, 'Name');
    artist = lookup(Track, 'Artist');
    album = lookup(Track, 'Album');
    count = lookup(Track, 'Play Count');
    rating = lookup(Track, 'Rating');
    length = lookup(Track, 'Total Time');
    genre = lookup(Track, 'Genre');
    if name is None or artist is None or album is None or genre is None: continue;
    
    cur.execute("INSERT OR IGNORE INTO Artist(name) VALUES(?)",(artist,));"""IGNORE is for duplicated Artist insert"""
    cur.execute("SELECT id FROM Artist WHERE name = ?",(artist,));
    artist_id=cur.fetchone()[0];
    
    cur.execute("INSERT OR IGNORE INTO Genre(name) VALUES(?)",(genre,));
    cur.execute("SELECT id FROM Genre WHERE name = ?",(genre,));
    genre_id=cur.fetchone()[0];
    
    cur.execute("INSERT OR IGNORE INTO Album(artist_id,title) VALUES(?,?)",(artist_id,album,));
    cur.execute("SELECT id FROM Album WHERE title = ?",(album,));
    album_id=cur.fetchone()[0];
    
    cur.execute("INSERT OR REPLACE INTO Track(title,album_id,genre_id,len,rating,count) VALUES(?,?,?,?,?,?)",(name,album_id,genre_id,length,rating,count));
    
connector.commit();
print "Track|","Artist|","Album|","Genre";
for tuple in cur.execute('''
    SELECT Track.title, Artist.name, Album.title, Genre.name 
    FROM Track JOIN Genre JOIN Album JOIN Artist 
    ON Track.genre_id = Genre.id and Track.album_id = Album.id 
        AND Album.artist_id = Artist.id
    ORDER BY Artist.name,Track.title LIMIT 3
    '''):
    print tuple[0],'|',tuple[1],'|',tuple[2],'|',tuple[3];