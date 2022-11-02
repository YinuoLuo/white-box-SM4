========================================================================
 White-box - SM4 Project Overview
========================================================================

This document outlines the contents of each of the files that make up the white-box-SM4 application.


SM4_equivalent.cpp
    This is the document which implements the first round of the SM4 algorithm using the equivalent structure.

SM4.h
    This is the declaration of the function used in the implementation of the SM4 algorithm.

SM4.c
    This is the main application source file and the function file for the SM4 implementation. The SM4 algorithm is implemented in the main file as well as our white-box SM4 algorithm.

generateTable.h
    This is the function declaration used in the white-box SM4 implementation.

generateTable.c
    This is the function file for the SM4 white-box implementation, including the function to build the lookup tables.


***Note:
    Before run "SM4.c", please generate the file of "p" and "p8" with Matlab software and save them in E disk. The codes are as follows:

Generate p:

fid=fopen('e:\p.txt','a+');
for i=1:1000
a=randsrc(128,128)/2+1/2;
b=gf(a,1);
if det(b)==0
continue
else
c=inv(b);
for i1=1:128
    for j1=1:128
        fprintf(fid,'%e ',a(i1,j1));
    end
end
fprintf(fid,'\n');
cx=c.x;
d=double(cx);
for i2=1:128
    for j2=1:128
        fprintf(fid,'%e ',d(i2,j2));
    end
end
fprintf(fid,'\n');
end
end
fclose(fid);

Generate p8:
fid=fopen('e:\p8.txt','a+');
for i=1:10000
a=randsrc(8,8)/2+1/2;
b=gf(a,1);
if det(b)==0
continue
else
c=inv(b);
for i1=1:8
    for j1=1:8
        fprintf(fid,'%e ',a(i1,j1));
    end
end
fprintf(fid,'\n');
cx=c.x;
d=double(cx);
for i2=1:8
    for j2=1:8
        fprintf(fid,'%e ',d(i2,j2));
    end
end
fprintf(fid,'\n');
end
end
fclose(fid);