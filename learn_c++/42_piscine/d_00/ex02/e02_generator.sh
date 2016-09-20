#!/bin/sh
rm -rf test0;
mkdir test0;
touch -t 06012047 test0;
chmod u=rwx,g=x,o=rx test0;

rm -f test1;
mkfile 4 test1;
touch -t 06012146 test1;
chmod u=rwx,g=x,o=r test1;

rm -rf test2;
mkdir test2;
touch -t 06012245 test2;
chmod u=rx,g=,o=r test2;

rm -f test3;
mkfile 1 test3;
touch -t 06012344 test3;
chmod u=r,g=,o=r test3;

rm -f test4;
mkfile 2 test4;
touch -t 06012343 test4;
chmod u=rw,g=r,o=x test4;

rm -f test5;
ln test3 test5;

rm -rf test6;
ln -s test0 test6;
touch -h -t 06012220 test6;



