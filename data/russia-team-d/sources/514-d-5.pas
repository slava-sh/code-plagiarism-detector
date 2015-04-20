{$mode delphi}
var min,n,k,i,max,rem,curx,h:integer;
    c,need,s,oldneed:int64;
    a,pleas:array[0..100001] of integer;
procedure qsorta(l,r:integer);
var
m,t,i,j:integer;
begin
i:=l;
j:=r;
m:=a[l+random(r-l+1)];
while i<j do
        begin
        while a[i]<m do inc(i);
        while a[j]>m do dec(j);
        if i<=j then
                begin
                t:=a[i];
                a[i]:=a[j];
                a[j]:=t;
                inc(i);
                dec(j);
                end;
        end;
if i<r then qsorta(i,r);
if j>l then qsorta(l,j);
end;
begin
assign(input,'fence.in');
assign(output,'fence.out');
reset(input);
rewrite(output);
read(n,k);
s:=0;
for i:=1 to n do begin read(a[i]);    s:=s+a[i];   end;


qsorta(1,n);
if s<=k then write(a[1])
else
begin
min:=a[1];
max:=a[n];
c:=0;
for i:=2 to n do pleas[i]:=a[i]-a[i-1];
for i:=2 to n do
        begin
        c:=c+abs(min-pleas[i]);
//writeln(c);
end;
max:=max+c;
//writeln(max);
max:=max-k;
min:=max;

{max:=max div( n-1);
//writeln(max);
if min mod (n-1)>0 then inc(max);
//writeln(max);
 }
max:=round(max/(n-1));
write(a[1]-max);
   end;

close(input);
close(output);
end.
