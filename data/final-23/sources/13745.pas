program signchange;

{$APPTYPE CONSOLE}
{$O-}

uses
  SysUtils;
const
  MAXN=1 shl 18;
var
  rsq0,rsq1:array[1..MAXN shl 1] of integer;
  n,m,i,k,l,r:integer;
function GetSumm0(t,l,r,x,y:integer):integer;
begin
  if x<l then x:=l;
  if y>r then y:=r;
  if x>y then begin
    GetSumm0:=0;
    exit;
  end;
  if (x=l) and (y=r) then begin
    GetSumm0:=rsq0[t];
    exit;
  end;
  GetSumm0:=GetSumm0(t*2,l, (l+r) div 2, x,y)+GetSumm0(t*2+1, (l+r) div 2+1, r, x,y);
end;

function GetSumm1(t,l,r,x,y:integer):integer;
begin
  if x<l then x:=l;
  if y>r then y:=r;
  if x>y then begin
    GetSumm1:=0;
    exit;
  end;
  if (x=l) and (y=r) then begin
    GetSumm1:=rsq1[t];
    exit;
  end;
  GetSumm1:=GetSumm1(t*2,l, (l+r) div 2, x,y)+GetSumm1(t*2+1, (l+r) div 2+1, r, x,y);
end;

procedure update0(t,r:integer);
begin
  r:=r+MAXN-1;
  rsq0[r]:=t;
  r:=r div 2;
  while r<>0 do begin
    rsq0[r]:=rsq0[2*r]+rsq0[2*r+1];
    r:=r div 2;
  end;
end;
procedure update1(t,r:integer);
begin
  r:=r+MAXN-1;
  rsq1[r]:=t;
  r:=r div 2;
  while r<>0 do begin
    rsq1[r]:=rsq1[2*r]+rsq1[2*r+1];
    r:=r div 2;
  end;
end;
begin
  reset(input, 'signchange.in');
  rewrite(output, 'signchange.out');
  read(n);
  for i:=1 to n do begin
    read(k);
    if i mod 2=0 then
      rsq0[i+MAXN-1]:=k
    else rsq1[i+MAXN-1]:=k;
  end;
  for i:=MAXN-1 downto 1 do begin
    rsq0[i]:=rsq0[2*i]+rsq0[2*i+1];
    rsq1[i]:=rsq1[2*i]+rsq1[2*i+1];
  end;
  read(m);
  for i:=1 to m do begin
    read(k,l,r);
    if k=0 then
      if l mod 2=0 then
        update0(r,l)
      else
        update1(r,l)
    else
      if l mod 2=0 then
        writeln(GetSumm0(1,1,MAXN,l,r)-GetSumm1(1,1,MAXN,l,r))
      else writeln(GetSumm1(1,1,MAXN,l,r)-GetSumm0(1,1,MAXN,l,r))
  end;
end.
