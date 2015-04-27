program tree;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var i,st:longint;
    a,b,c:array[0..300000]of longint;

procedure modify(var i,k:longint);
begin
  a[i]:=k;
  i:=i+st-1;
  b[i]:=k;
  c[i]:=-k;
  while i<>1 do
  begin
    i:=i div 2;
    if i<=(st*2-1-(st*3)div 2) then b[i]:=b[2*i]+b[2*i+1] else b[i]:=b[2*i]+c[2*i+1];
    if i<=(st*2-1-(st*3)div 2) then c[i]:=c[2*i]+c[2*i+1] else c[i]:=c[2*i]+b[2*i+1];
  end;
end;

function getsum(l,r,i,zn,le,ri:longint):longint;
var zn1,zn2,r1:longint;
begin

  if (r<le)or(ri<l) then
  begin
    getsum:=0;
    exit;
  end;

  if (l<=le)and(ri<=r) then
  begin
    if (zn=0) then
    begin
      if le mod 2=0 then getsum:=b[i] else getsum:=c[i];
    end else
    begin
      if le mod 2=0 then getsum:=c[i] else getsum:=b[i];
    end;
    exit;
  end;

  r1:=(le+ri)div 2;
  zn1:= getsum(l,r,2*i,zn,le,r1);
  zn2:=getsum(l,r,2*i+1,zn,r1+1,ri);
  getsum:=zn1+zn2;

end;

var q1,q2,n,m,q3:longint;

begin
  reset(input,'signchange.in');
  rewrite(output,'signchange.out');
  readln(n);
  for i:=1 to n do
    read(a[i]);
  st:=1;
  while st<n do
    st:=st*2;
  for i:=1 to st do
  begin
    b[i+st-1]:=a[i];
    c[i+st-1]:=-a[i];
  end;
  for i:=st-1 downto 1 do
  begin
    if i<=(st*2-1-(st*3)div 2) then b[i]:=b[2*i]+b[2*i+1] else b[i]:=b[2*i]+c[2*i+1];
    if i<=(st*2-1-(st*3)div 2) then c[i]:=c[2*i]+c[2*i+1] else c[i]:=c[2*i]+b[2*i+1];
  end;
  readln(m);
  for i:=1 to m do
  begin
    readln(q1,q2,q3);
    if q1=0 then modify(q2,q3) else
    writeln(getsum(q2,q3,1,q2 mod 2,1,st));
  end;

end.
