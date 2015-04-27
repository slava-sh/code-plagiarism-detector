program signchange;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const
  maxn = 300000;
  infile = 'signchange.in';
  outfile = 'signchange.out';
type int = longint;
var
  a1,b1,a2,b2 : array[1..maxn] of int;
  n,i,ch,m,x,y,kol1,kol2 : int;
procedure modify(i,j : int);
begin
  if i mod 2 = 0 then begin
    i := i div 2;
    a1[i] := j;
    i := i + kol1 - 1;
    b1[i] := j;
    while i <> 1 do begin
      i := i div 2;
      b1[i] := b1[2 * i] + b1[2 * i + 1];
    end;
  end else begin
    i := i div 2 + 1;
    a2[i] := j;
    i := i + kol2 - 1;
    b2[i] := j;
    while i <> 1 do begin
      i := i div 2;
      b2[i] := b2[2 * i] + b2[2 * i + 1];
    end;
  end;
end;

function getsum2(l,r : int) : int;
var
  sum : int;
begin
  l := l + kol2 - 1;
  r := r + kol2 - 1;
  sum := 0;
  while (l <= r) do begin
    if l mod 2 = 1 then begin
      sum := sum + b2[l];
      inc(l);
    end;

    if r mod 2 = 0 then begin
      sum := sum + b2[r];
      dec(r);
    end;

    l := l div 2;
    r := r div 2;
  end;
  getsum2 := sum;
end;

function getsum1(l,r : int) : int;
var
  sum : int;
begin
  l := l + kol1 - 1;
  r := r + kol1 - 1;
  sum := 0;
  while (l <= r) do begin
    if l mod 2 = 1 then begin
      sum := sum + b1[l];
      inc(l);
    end;

    if r mod 2 = 0 then begin
      sum := sum + b1[r];
      dec(r);
    end;

    l := l div 2;
    r := r div 2;
  end;
  getsum1 := sum;
end;

begin
  assign(input,infile);
  assign(output,outfile);
  reset(input);
  rewrite(output);
  readln(n);
  for i := 1 to n do begin
    read(x);
    if i mod 2 = 0 then begin
      inc(kol1);
      a1[kol1] := x;
    end else begin
      inc(kol2);
      a2[kol2] := x;
    end;
  end;
  for i := 1 to kol1 do
    b1[i + kol1 - 1] := a1[i];
  for i := kol1 - 1 downto 1 do
    b1[i] := b1[2 * i] + b1[2 * i + 1];
  
  for i := 1 to kol2 do
    b2[i + kol2 - 1] := a2[i];
  for i := kol2 - 1 downto 1 do
    b2[i] := b2[2 * i] + b2[2 * i + 1];
  readln(m);
  for i := 1 to m do begin
    readln(ch,x,y);
    if ch = 0 then modify(x,y);
    if ch = 1 then begin
      if (x mod 2 = 0) and (y mod 2 = 0) then
        writeln(getsum1(x div 2,y div 2) - getsum2(x div 2 + 1,y div 2) );
      if (x mod 2 = 1) and (y mod 2 = 1) then
        writeln(getsum2(x div 2 + 1,y div 2 + 1) - getsum1(x div 2 + 1,y div 2));
      if (x mod 2 = 0) and (y mod 2 = 1) then
        writeln(getsum1(x div 2,y div 2) - getsum2(x div 2 + 1,y div 2 + 1));
      if (x mod 2 = 1) and (y mod 2 = 0) then
        writeln(getsum2(x div 2 + 1,y div 2) - getsum1(x div 2 + 1,y div 2));
    end; 

    end;
  close(input);
  close(output);
end.

