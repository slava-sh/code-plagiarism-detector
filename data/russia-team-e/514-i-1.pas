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
qsort(1,n);
k:=1;
while (a[k]>=3*d) do
                begin
                k:=k+1;
  //              writeln(k);
                end;
if (k<=n) and (a[k]>2*d) then
         begin
         sec:=a[k];
//         writeln(k,' ',a[k],' ',sec);
         inc(k);

         if (k<=n) and (a[k]>2*d) then
                begin
                thi:=a[k];
                inc(k);
                end;
         end;
k:=k-1;
if (k=0) or ((k=1) and (sec=0) and (thi=0)) then write(a[1])
else
begin
for j:=1 to k-2 do
        begin
        len:=len+a[j]-2*d;
        end;
//writeln(k);
if sec>0 then
        len:=len+sec-d
else
        len:=len+a[k]-d;
if thi>0 then
        len:=len+thi-d
else
        len:=len+a[k-1]-d;
write(len);
end;
close(input);
close(output);

end.


