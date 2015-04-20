uses
  math;
const
  ll=5000;
  md=1000000007;
var
  a,kind,mas:array[1..ll] of longint;
  used:array[1..ll] of boolean;
  x,y,i,j,n:longint;
  ans,step,size,t:int64;

procedure bad;
begin
  writeln(0);
  close(input);
  close(output);
  halt;
end;

{
function find(x:longint):longint;
begin
  if (f[x]<>x) then f[x]:=find(f[x]);
  exit(f[x]);
end;

procedure union(x,y:longint);
begin
  x:=find(x);
  y:=find(y);
  if (x=y) then exit;
  if (random(2)=0) then f[x]:=y else f[y]:=x;
end;
}

begin
  assign(input,'binary.in');
  reset(input);
  assign(output,'binary.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do 
  begin
    read(a[i]);
    if (a[i]>n-i+1) then bad;
  end;
  if (a[1]>0) then bad;
  kind[1]:=1;
  for i:=2 to n do if (a[i]=0) then kind[i]:=2;
  for i:=2 to n do
  begin
    if (a[i]=-1) then continue;
    for j:=1 to a[i] do
    begin
      x:=j;
      y:=i+j-1;
      if (kind[x]+kind[y]=3) then bad;
      kind[x]:=max(kind[x],kind[y]);
      kind[y]:=max(kind[x],kind[y]);
    end;
    x:=a[i]+1;
    y:=i+a[i];
    if (kind[x]=0) then continue;
    if (kind[x]=kind[y]) then bad;
  end;
  for i:=1 to n do if (kind[i]=0) then mas[i]:=i;
  for i:=2 to n do
  begin
    if (a[i]=-1) then continue;
    for j:=1 to a[i] do
    begin
      x:=j;
      y:=i+j-1;
      if (kind[x]=0) and (kind[y]=0) then 
      begin
        mas[j]:=mas[i];
      end; 
    end;
    x:=a[i]+1;
    y:=i+a[i];
  end;
  for i:=2 to n do 
  begin
    if (a[i]=-1) then continue;
    x:=a[i]+1;
    y:=i+a[i];
    mas[x]:=mas[y];
  end;    
  t:=0;
  for i:=2 to n do 
  begin
    if (kind[i]<>0) then continue;
    if (not used[mas[i]]) then inc(t);
    used[mas[i]]:=true;
  end; 
  step:=2;
  ans:=step;
  for i:=1 to t do ans:=(ans*step) mod md;
  writeln(ans);
  close(input);
  close(output);
end.