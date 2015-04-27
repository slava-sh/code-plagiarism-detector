program zachet02;

{$APPTYPE CONSOLE}
{$R-,Q-,O+}
uses
  SysUtils,Math;
type int=integer;
     ext=extended;
     bool=boolean;
const len=131072;
var n,m:int;
    a,b,sum1,sum2:array[-1..2*len+100]of int;

procedure swap(var a,b:int);
 var c:int;
begin
  c:=a;
  a:=b;
  b:=c
end;

procedure readdata;
 var y,k,i:int;
begin
  readln(k);
  for i:=1 to len do
    a[i]:=0;
  for i:=1 to len do
    b[i]:=0;

  for i:=1 to k do begin
    read(y);
    if i mod 2=0 then a[i]:=y
    else b[i]:=y
  end
end;

procedure built;
 var i:int;
begin
  for i:=1 to 2*len+10 do begin
    sum1[i]:=0;
    sum2[i]:=0
  end;

  for i:=1 to len do begin
    sum1[i+len-1]:=a[i];
    sum2[i+len-1]:=b[i]
  end;

  for i:=len-1 downto 1 do begin
    sum1[i]:=sum1[2*i]+sum1[2*i+1];
    sum2[i]:=sum2[2*i]+sum2[2*i+1]
  end
end;

procedure modify1(i,d:int);
 var j:int;
begin
  a[i]:=d;
  j:=i+len-1;
  sum1[j]:=d;
  while j<>1 do begin
    j:=j div 2;
    sum1[j]:=sum1[2*j]+sum1[2*j+1]
  end
end;

procedure modify2(i,d:int);
 var j:int;
begin
  b[i]:=d;
  j:=i+len-1;
  sum2[j]:=d;
  while j<>1 do begin
    j:=j div 2;
    sum2[j]:=sum2[2*j]+sum2[2*j+1]
  end
end;

function getsum1(l,r,i,lo,ro:int):int;
begin
  if (r<lo)or(ro<l)then begin
    getsum1:=0;
    exit
  end;
  if (l<=lo)and(ro<=r)then begin
    getsum1:=sum1[i];
    exit
  end;
  getsum1:=getsum1(l,r,2*i,lo,(lo+ro)div 2)+getsum1(l,r,2*i+1,((lo+ro)div 2)+1,ro)
end;

function getsum2(l,r,i,lo,ro:int):int;
begin
  if (r<lo)or(ro<l)then begin
    getsum2:=0;
    exit
  end;
  if (l<=lo)and(ro<=r)then begin
    getsum2:=sum2[i];
    exit
  end;
  getsum2:=getsum2(l,r,2*i,lo,(lo+ro)div 2)+getsum2(l,r,2*i+1,((lo+ro)div 2)+1,ro)
end;

procedure solve;
 var u,q,w,e,z,i,l,r:int;
begin
  built;

  readln(u);
  for i:=1 to u do begin
    readln(q,l,r);
    if q=1 then begin
      z:=getsum1(l,r,1,1,len)-getsum2(l,r,1,1,len);
      if l mod 2=0 then writeln(z)
      else writeln(-z)
    end
    else begin
      if l mod 2=0 then modify1(l,r)
      else modify2(l,r)
    end
  end
end;

begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  reset(input,'signchange.in');
  rewrite(output,'signchange.out');
  readdata;
  solve
end.
