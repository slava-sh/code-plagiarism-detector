var m,n,ma,k,i,j,d:longint;
    a:array[0..100000]of longint;
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
assign(input,'sochi.in');
reset(input);
assign(output,'sochi.out');
rewrite(output);
read(n,d);
for i:=1 to n do read(a[i]);
sort(1,n);
if n=1 then k:=1
       else
       if (n>1)and(a[n-1]-d<0)then k:=1
       else k:=2;

for i:=n downto 3 do if a[i]-3*d>=0 then inc(k)
                                    else break;
ma:=a[n];
for i:=2 to k do begin
    if a[n-i+1]-2*d>0 then ma:=ma+a[n-i+1]-2*d;
end;
writeln(ma);
end.