var min,p:longint;
    a,m:array[0..100000]of longint;
    k,i,ko,j,n,o:longint;
procedure sort(l,r:longint);
var tm,tm1,i,j:longint;
begin
tm:=a[(l+r)div 2];
i:=l;j:=r;
while i<j DO BEGIN
      while a[i]<tm do inc(i);
      while a[j]>tm do dec(j);
      if i<=j then begin
         tm1:=a[i]; a[i]:=a[j]; a[j]:=tm1; inc(i); dec(j);
         end;
end;
if (i<r) then sort(i,r);
if (j>l) then sort(l,j);
end;
begin
assign(input,'fence.in'); reset(input);
assign(output,'fence.out'); rewrite(output);
readln(n,k);
p:=k div n;
read(a[1]); min:=a[1];
for i:=2 to n do begin
    read(a[i]);
    if a[i]<min then min:=a[i];
    end;
sort(1,n);
o:=min;
if p<min then o:=p;
if o=0 then begin  writeln(o);halt;end;
ko:=0;
fillchar(m,sizeof(m),0);
for i:=1 to n do begin
    if a[i]-ko>o then begin ko:=ko+a[i]-ko-o;end;
    if a[i]-ko<o then inc(m[o-a[i]+ko]);
    ko:=ko+o;
end;
for i:=o-1 downto 1 do m[i]:=m[i]+m[i+1];
j:=1;
while ko>k do begin
      ko:=ko-m[j]; dec(o);
      inc(j);
      end;
writeln(o);
end.
