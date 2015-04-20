{$mode delphi}
{$R+}
{$Q+}
{$I+}
{$S+}
{$O+}
var min,n,k,i,max,rem,curx,h:integer;
    need,oldneed:int64;
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
procedure qsortpleas(l,r:integer);
var
m,t,i,j:integer;
begin
i:=l;
j:=r;
m:=pleas[l+random(r-l+1)];
while i<j do
        begin
        while pleas[i]<m do inc(i);
        while pleas[j]>m do dec(j);
        if i<=j then
                begin
                t:=pleas[i];
                pleas[i]:=pleas[j];
                pleas[j]:=t;
                inc(i);
                dec(j);
                end;
        end;
if i<r then qsortpleas(i,r);
if j>l then qsortpleas(l,j);
end;

begin
assign(input,'fence.in');
assign(output,'fence.out');
reset(input);
rewrite(output);
read(n,k);
for i:=1 to n do read(a[i]);
qsorta(1,n);
max:=a[n];
rem:=k-max;
min:=a[1];
pleas[1]:=a[1];
for i:=2 to n do pleas[i]:=a[i]-a[i-1];
qsortpleas(1,n);
need:=0;
h:=1;
for i:=2 to n do begin
    oldneed:=need;
    need:=need+(pleas[i]-pleas[i-1])*(i-1);
    if need>rem then break;
    h:=i;
end;
if h=n then begin
            curx:=min;
            end
else begin
     curx:=pleas[h]+(rem-oldneed) div h;
     if curx>min then curx:=min;
     end;
writeln(curx);
close(input);
close(output);
end.
