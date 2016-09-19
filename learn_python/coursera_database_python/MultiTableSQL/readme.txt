Assignment 2:
1. Parse the "Traks" dict in "Library.xml" into database
2. The schema of database is:
    Artist: |id(INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE)|name(TEXT UNIQUE)|
    Genre:  |id(INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE)|name(TEXT UNIQUE)|
    Album:  |id(INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE)|artist_id(INTEGER)|title(TEXT UNIQUE)|
    Track:  |id(INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE)|title(TEXT UNIQUE)|album_id(INTEGER)|
            |genre_id(INTEGER)|len(INTEGER)|rating(INTEGER)|count(INTEGER)|
3. Combine all the table into table:
    |Track|Artist|Album|Genre|