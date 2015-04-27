program signchange;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  na:array [1..100000] of integer;
  b:array [0..1,1..1000000] of integer;
  n,i,k,m,x,y,pl,mn:integer;
  function getSum(l,r,f:integer):integer;
  var
    p:integer;
  begin
    p:=0;
    while l<r do begin
      if l mod 2=1 then begin
        p:=p+b[f,l];
        l:=l+1;
      end;
      l:=l div 2;
      if r mod 2=0 then begin
        p:=p+b[f,r];
        r:=r-1;;
      end;
      r:=r div 2;
    end;
    if l=r then
      p:=b[f,l]+p;
    getSum:=p;
  end;
  procedure modify(i,t,f:integer);
  var
    j,d:integer;
  begin
    j:=i+n-1;
    d:=t-b[f,j];
    b[f,j]:=t;
    while j<>0 do begin
      j:=j div 2;
      b[f,j]:=b[f,j]+d;
    end;
  end;
begin
  reset(input, 'signchange.in');
  rewrite(output,'signchange.out');
  read(n);
  for i:=1 to n do
    read(na[i]);
  for i:=1 to n do begin
    k:=i+n-1;
    b[k mod 2,k]:=na[i];
  end;
  for i:= n-1 downto 1 do begin
    b[0,i]:=b[0,i*2]+b[0,i*2+1];
    b[1,i]:=b[1,i*2]+b[1,i*2+1];
  end;
  read(m);
  for i:=1 to m do begin
    read(k,x,y);
    if k=0 then
      modify(x, y, (x+n-1) mod 2)
    else begin
      pl:=getSum(x+n-1,y+n-1,0);
      mn:=getSum(x+n-1,y+n-1,1);
      if (x+n-1) mod 2 =1 then
        writeln(mn-pl)
      else
        writeln(pl-mn);
    end;
  end;
  close(input);
  close(output);
end.