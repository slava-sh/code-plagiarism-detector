{$mode delphi}
type azaza=array[1..1000] of int64;
var
x,n,m,i,j,k,ii,jj:integer;
trytnext:boolean;
az,az1:int64;
num,c,nu:array[1..1000] of int64;
cod,code:array[1..1000] of azaza;
code1:array[1..100,1..100,1..100] of int64;
procedure qsort(l,r:int64);
var
m,t,i,j:int64;
t1:azaza;
begin
i:=l;
j:=r;
m:=c[l+random(r-l+1)];
while i<j do
        begin
        while c[i]<m do inc(i);
        while c[j]>m do dec(j);
        if i<=j then
                begin
                t:=c[i];
                c[i]:=c[j];
                c[j]:=t;
                t:=nu[i];
                nu[i]:=nu[j];
                nu[j]:=t;
                t1:=cod[i];
                cod[i]:=cod[j];
                cod[j]:=t1;
                inc(i);
                dec(j);
                end;
        end;
if i<r then qsort(i,r);
if j>l then qsort(l,j);
end;

function binfind(l,r:integer):integer;
begin
if l=r then if code[i][jj]=c[l] then begin binfind:=l; exit; end
                                else begin binfind:=-1; exit; end;
m:=(l+r) div 2;
if code[i][jj]<c[m] then binfind:=binfind(l,m);
if code[i][jj]>c[m] then binfind:=binfind(m+1,r);
if code[i][jj]=c[m] then binfind:=m;
end;

procedure ou(a,b:int64) ;
var i,c:integer;
begin
b:=11-b;
c:=1;

for i:=1 to b do
        c:=c*10;
a:=a mod c;
c:=a;

if b=3 then
        begin
        if c div 100=0  then write(0);
          writeln(c);
        end;

if (b=4)  then begin
        if c div 1000=0 then write(0);
        if c div 100>0 then write(c div 100);
        write('-');
        if (c mod 100) div 10 =0 then write(0);
        writeln(c mod 100);
        end;
if (b=5)  then begin
        if c div 10000=0 then write(0);
        write(c div 100);
        write('-');
        if (c mod 100) div 10 =0 then write(0);
         writeln(c mod 100);
        end;
if (b=6) then
        begin
        if c div 100000=0 then write(0);
         write(c div 10000 );
        write('-');
        c:=c mod 10000;
        if c div 1000=0 then write(0);
        write( (c ) div 100);
        write('-');
        c:=c mod 100;
        if c div 10=0 then write(0);
        writeln(c mod 100);
        end;
if (b=7) then
        begin
        if c div 1000000=0 then write(0);
        write(c div 10000,'-' );
        c:=c mod 10000;
        if c div 1000=0 then write(0);
        write( (c ) div 100,'-');
        c:=c mod 100;
        if c div 10=0 then write(0);
        writeln(c mod 100);
        end;

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
qsort(1,n);
for i:=1 to m do
        begin
        trytnext:=true;
        read(num[i]);
        code[i][1]:=num[i] div 10000000000;

        code[i][2]:=num[i] div 1000000000;
        if code[i][2] div 10=0 then code[i][2]:=-1;
        code[i][3]:=num[i] div 100000000;
        if code[i][3] div 100 =0 then code[i][3]:=-1;
        code1[i][1][1]:=(num[i]-code[i][1]*10000000000) div 10000000;
        if code1[i][1][1] div 100=0 then code1[i][1][1]:=-1;
        code1[i][1][2]:=(num[i]-code[i][1]*10000000000) div 1000000;
        if code1[i][1][2] div 1000=0 then code1[i][1][2]:=-1;
        code1[i][1][3]:=(num[i]-code[i][1]*10000000000) div 100000;
        if code1[i][1][3] div 10000=0 then code1[i][1][3]:=-1;
        code1[i][2][1]:=(num[i]-code[i][2]*1000000000) div 1000000;
        if code1[i][2][1] div 100=0 then code1[i][2][1]:=-1;
        code1[i][2][2]:=(num[i]-code[i][2]*1000000000) div 100000;
        if code1[i][2][2] div 1000=0 then code1[i][2][2]:=-1;
        code1[i][2][3]:=(num[i]-code[i][2]*1000000000) div 10000;
        if code1[i][2][3] div 10000=0 then code1[i][2][3]:=-1;
        code1[i][3][1]:=(num[i]-code[i][3]*100000000) div 100000;
        if code1[i][3][1] div 100=0 then code1[i][3][1]:=-1;
        code1[i][3][2]:=(num[i]-code[i][3]*100000000) div 10000;
        if code1[i][3][2] div 1000=0 then code1[i][3][2]:=-1;
        code1[i][3][3]:=(num[i]-code[i][3]*100000000) div 1000;
        if code1[i][3][3] div 10000=0 then code1[i][3][3]:=-1;

        for jj:=1 to 3 do
        begin
        if (trytnext=true) then
        j:=binfind(1,n);
        if j<>-1 then
        begin
        repeat
                if (trytnext=true) then
                        for k:=1 to nu[j] do
                                begin
                                if (trytnext=true) then
                                for ii:=1 to 3 do
                                        if (code1[i][jj][ii]=cod[j][k]) and (trytnext=true) then
                                                begin
                                                az:=0;
                                                az1:=num[i];
                                                for x:=1 to 9-jj-ii do
                                                       begin
                                                       az:=az*10+az1 mod 10;
                                                       az1:=az1 div 10;
                                                       end;

                                                if az mod 10>0 then
                                                begin
                                                write('+',code[i][jj],'(',code1[i][jj][ii],')');
                                                ou(num[i],2+jj+ii);
                                                trytnext:=false;
                                                end;
                                                end;
                                end;
                 inc(j);
        until(c[j]<>c[j+1]);

                end;
        end;
        if trytnext=true then writeln('Incorrect');
        end;
close(input);
close(output);
end.


