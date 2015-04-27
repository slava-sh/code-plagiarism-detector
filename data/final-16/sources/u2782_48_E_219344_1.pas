program prgE;

{$APPTYPE CONSOLE}
{$O-}

uses
  SysUtils,Math;

type
  sost = record
    h,t: integer;
  end;

var
  hh,ht,th,tt: array[0..1000] of integer;
  n:integer;
  h:integer;
  t:integer;
  i:integer;
  r:integer;
  m:integer;
  bad: integer;
  q: array[0..1000000] of sost;
  j:integer;
  toend: array[0..1000,0..1000] of integer;
  l:integer;
  maxzmey:integer;
  was: array[0..1000,0..1000] of integer;
  draw: boolean;


procedure dfs(h,t,kol: integer);
var i:integer;
begin
  if was[h,t] = 1 then begin
    draw := true;
    exit;
  end;
  if was[h,t] = 2 then
    exit;
  if h + t > bad then begin
    if maxzmey < kol then
      maxzmey := kol;
    exit;
  end;
  was[h,t] := 1;
  for i := 1 to min(n,h) do begin
    dfs(h + hh[i] - i,t + ht[i],kol + 1);
    if toend[h + hh[i] - i,t + ht[i]] + 1 > toend[h,t] then
      toend[h,t] := toend[h + hh[i] - i,t + ht[i]] + 1;
  end;
  for i := 1 to min(t,m) do begin
    dfs(h + th[i],t + tt[i] - i,kol + 1);
    if toend[h + th[i],t + tt[i] - i] + 1 > toend[h,t] then
      toend[h,t] := toend[h + th[i],t + tt[i] - i] + 1;
  end;
  was[h,t] := 2;
end;

procedure add(h,t,kol: integer);
begin
  if was[h,t] <> 0 then
    exit;
  if h + t > bad then begin
    exit;
  end;
  was[h,t] := kol + 1;
  inc(r);
  q[r].h := h;
  q[r].t := t;
end;

begin
  read(h,t,bad,n);
  for i := 1 to n do
    read(hh[i],ht[i]);
  read(m);
  for i := 1 to m do
    read(th[i],tt[i]);
  q[1].h := h;
  q[1].t := t;
  was[h,t] := 1;
  l := 1;
  r := 1;
  while l <= r do begin
    if (q[l].h = 0) and (q[l].t = 0) then begin
      writeln('Ivan');
      write(was[q[l].h,q[l].t] - 1);
      halt(0);
    end;

    for i := 1 to min(n,q[l].h) do
      add(q[l].h + hh[i] - i,q[l].t + ht[i],was[q[l].h,q[l].t]);
    for i := 1 to min(q[l].t,m) do
      add(q[l].h + th[i],q[l].t + tt[i] - i,was[q[l].h,q[l].t]);

    inc(l);
  end;
  for i := 0 to 500 do
    for j := 0 to 500 do
      was[i,j] := 0;
  draw := false;
  dfs(h,t,0);
  if draw then
    write('Draw')
  else begin
    writeln('Zmey');
    write(toend[h,t]);
  end;
end.

