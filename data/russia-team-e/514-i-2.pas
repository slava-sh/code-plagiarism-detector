{$mode delphi}
var
k,sec,thi,n,d,len:int64;
j,i:integer;
a:array[1..200000] of integer;
procedure qsort(l,r:integer);
var
m,t,i,j:integer;
begin
i:=l;
j:=r;
m:=a[l+random(r-l+1)];
while i<j do
        begin
        while a[i]>m do inc(i);
        while a[j]<m do dec(j);
        if i<=j then
                begin
                t:=a[i];
                a[i]:=a[j];
                a[j]:=t;
                inc(i);
                dec(j);
                end;
        end;
if i<r then qsort(i,r);
if j>l then qsort(l,j);
end;

begin
assign(input,'sochi.in');
assign(output,'sochi.out');
reset(input);
rewrite(output);
read(n,d);
for i:=1 to n do
        read(a[i]);
a[n+1]:=-1;
a[n+2]:=-1;
qsort(1,n+2);
i:=1;
len:=a[1];
while a[i]>=3*d do inc(i);
if i>=n+1 then begin
   for j:=2 to n do len:=len + a[j] -2*d;
   end
else if i=n then begin
     for j:=2 to n-1 do len:=len + a[j] -2*d;
     if a[i]>2*d  then len:=len +a[i] -2*d;
     end
else if i=1 then begin
     if a[i+1]>2*d then len:= len + a[i+1] - 2*d;
     end
else begin
     for j:=2 to i-1 do len:=len + a[j] -2*d;
     if a[i]>2*d  then len:=len +a[i] -2*d;
     if a[i+1]>2*d  then len:=len +a[i+1] -2*d;
end;
writeln(len);
close(input);
close(output);
end.
