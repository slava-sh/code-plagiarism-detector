{$mode delphi}
var
n,m,i,j,k,ii,jj:integer;
trytnext:boolean;
num,c,nu:array[1..100] of int64;
cod,code:array[1..100,1..100] of int64;
code1:array[1..100,1..100,1..100] of int64;
procedure ou(a,b:int64) ;
var i,c:integer;
begin
b:=11-b;
c:=1;

for i:=1 to b do
        c:=c*10;
a:=a mod c;
c:=a;

if b=3 then writeln(c);
if (b=4) or (b=5) then writeln(c div 100,'-',c mod 100);
if (b=6) or (b=7) then writeln(c div 10000,'-', (c mod 10000) div 100,'-',c mod 100);
end;
begin
assign(input,'numbers.in');
assign(output,'numbers.out');
reset(input);
rewrite(output);
read(n);
for i:=1 to n do
        begin
        read(c[i],nu[i]);
        for j:=1 to nu[i] do
                read(cod[i][j]);
        end;
read(m);
for i:=1 to m do
        begin
        trytnext:=true;
        read(num[i]);
        code[i][1]:=num[i] div 10000000000;
        code[i][2]:=num[i] div 1000000000;
        code[i][3]:=num[i] div 100000000;
        code1[i][1][1]:=(num[i]-code[i][1]*10000000000) div 10000000;
        code1[i][1][2]:=(num[i]-code[i][1]*10000000000) div 1000000;
        code1[i][1][3]:=(num[i]-code[i][1]*10000000000) div 100000;
        code1[i][2][1]:=(num[i]-code[i][2]*1000000000) div 1000000;
        code1[i][2][2]:=(num[i]-code[i][2]*1000000000) div 100000;
        code1[i][2][3]:=(num[i]-code[i][2]*1000000000) div 10000;
        code1[i][3][1]:=(num[i]-code[i][3]*100000000) div 100000;
        code1[i][3][2]:=(num[i]-code[i][3]*100000000) div 10000;
        code1[i][3][3]:=(num[i]-code[i][3]*100000000) div 1000;
        for jj:=1 to 3 do
        begin
        if (trytnext=true) then
        for j:=1 to n do
                begin
                if (code[i][jj]=c[j]) and (trytnext=true) then
                        for k:=1 to nu[j] do
                                begin
                                if (trytnext=true) then
                                for ii:=1 to 3 do
                                        if (code1[i][jj][ii]=cod[j][k]) and (trytnext=true) then
                                                begin
                                                write('+',code[i][jj],'(',code1[i][jj][ii],')');
                                                ou(num[i],2+jj+ii);
                                                trytnext:=false;
                                                end;
                                end;
                end;
        end;
        if trytnext=true then writeln('Incorrect');
        end;
close(input);
close(output);
end.


