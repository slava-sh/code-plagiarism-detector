program JJ_Mybabe;

{$APPTYPE CONSOLE}  {$o-}

uses
  SysUtils,Math;
  const
    maxN=662144;
  var
      i,m,ano,n,k,j,ma,al: integer;
      p:int64;
      a,chet,nech:array[1..maxN] of integer;
function build_chet(p:integer):integer;
  var
      i:integer;
begin
  if p>al then
  begin
    result:=0;
    exit;
  end;
  if p>=ma then
  begin
    if p mod 2=0 then
      result:=(-1*a[p])
    else
      result:=(a[p]);
  end
  else
    result:=build_chet(p*2)+build_chet(p*2+1);
  chet[p]:=result;
end;
function build_nech(p:integer):integer;
  var
      i:integer;
begin
  if p>al then
  begin
    result:=0;
    exit;
  end;
  if p>=ma then
  begin
    if p mod 2=1 then
      result:=(-1*a[p])
    else
      result:=(a[p]);
  end
  else
    result:=build_nech(p*2)+build_nech(p*2+1);
  nech[p]:=result;
end;
procedure change(p,k:integer);
  var
      i:integer;
begin
  a[p]:=k;
  if p mod 2=0 then
  begin
    nech[p]:=a[p];
    chet[p]:=a[p]*-1;
  end
  else
  begin
    nech[p]:=a[p]*-1;
    chet[p]:=a[p];
  end;  
    p:=p div 2;
    while p>0 do
    begin
      nech[p]:=nech[p*2]+nech[p*2+1];
      chet[p]:=chet[p*2]+chet[p*2+1];
      p:=p div 2;
    end;
end;

function get_sum(p,l,r,a,b:integer):integer;
  begin
    if (a<=l) and (b>=r) then
      if a mod 2=0 then
        result:=nech[p]
      else
        result:=chet[p]  
    else
    if (b<l) or (a>r) then
      result:=0
    else
      result:=get_sum(p*2,l,(l+r) div 2,a,b)+get_sum(p*2+1,(l+r)div 2+1,r,a,b);
  end;      
begin
  reset(input,'signchange.in');
  rewrite(output,'signchange.out');
  read(n);
  i:=1;
  while i<n do i:=i*2;
  ma:=i;
  al:=ma*2-1;
  for i:=ma to ma+n-1 do
    read(a[i]);
  build_chet(1); build_nech(1);
  read(m);
  for i:=1 to m do
  begin
    read(p);
    if p=0 then
    begin
      read(j,k);
      change(j+ma-1,k);
    end
    else
    begin
      read(j,k);
      writeln(get_sum(1,ma,al,j+ma-1,k+ma-1));
    end;
  end;
end.





