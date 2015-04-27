{$A8,B-,C+,D+,E-,F-,G+,H+,I+,J-,K-,L+,M-,N+,O-,P+,Q+,R+,S+,T-,U-,V+,W-,X+,Y+,Z1}
//{$A8,B-,C+,D-,E-,F-,G+,H+,I-,J-,K-,L+,M-,N+,O+,P+,Q-,R-,S-,T-,U-,V+,W-,X+,Y+,Z1}
{$MINSTACKSIZE $00004000}
{$MAXSTACKSIZE $00100000}

program ProblemC;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const
  inname = 'input.txt';
  outname = 'output.txt';
  maxn = 100110;
  maxm = 0;
  inf = maxlongint div 2;
  eps = 0;

type
  int = longint;
  bool = boolean;
  real = extended;
  tv = record
    id, count: int;
  end;

var
  n, m, ans: int;
  a: array[0..maxn] of int;
  b: array[0..maxn] of tv;
  e: array[0..maxn,0..3] of int;   

procedure sort(l, r: int);
var
  i, j, x, t: int;
begin
  x := a[l + random(r - l + 1)];

  i := l;
  j := r;

  repeat
    while a[i] < x do
      inc(i);
    while a[j] > x do
      dec(j);

    if i <= j then begin
      t := a[i];
      a[i] := a[j];
      a[j] := t;

      inc(i);
      dec(j);
    end;
  until i > j;

  if l < j then
    sort(l, j);
  if i < r then
    sort(i, r);
end;

procedure swap(i, j: int);
var
  t: tv;
begin
  t := b[i];
  b[i] := b[j];
  b[j] := t;
end;

procedure down(t: int);
begin
  while ((2*t <= m) and (b[2*t].count > b[t].count)) or
        ((2*t + 1 <= m) and (b[2*t + 1].count > b[t].count)) do begin
    if (2*t + 1 > m) or (b[2*t + 1].count < b[2*t].count) then begin
      swap(t, 2*t);
      t := 2*t;
    end else begin
      swap(t, 2*t + 1);
      t := 2*t + 1;
    end;
  end;
end;

procedure up(t: int);
begin
  while (t div 2 > 0) and (b[t div 2].count < b[t].count) do begin
    swap(t, t div 2);
    t := t div 2;
  end;
end;

procedure bild;
var
  i: int;
begin
  for i := 1 to m do
    up(i);
end;

procedure run;
var
  i, i1, i2, i3, j, t: int;
begin
  randomize;

  read(n);
  for i := 1 to n do begin
    read(a[i]);
  end;
  a[0] := -1;

  sort(1, n);

  m := 0;

  for i := 1 to n do
    if a[i] = a[i - 1] then
      inc(b[m].count)
    else begin
      inc(m);
      b[m].count := 1;
      b[m].id := a[i];
    end;

  if m < 3 then begin
    write(0);
    exit;
  end;

  bild;

  ans := 0;
  while true do begin
    i1 := 1;
    if b[2].count > b[3].count then
      i2 := 2
    else
      i2 := 3;

    i3 := 0;
    for i := 1 to 8 do
      if (i <> i1) and (i <> i2) then
        if (i3 = 0) or (b[i3].count < b[i].count) then
          i3 := i;

    if (i3 = 0) or (b[i3].count = 0) then
      break;

    inc(ans);
    e[ans, 1] := b[i1].id;
    e[ans, 2] := b[i2].id;
    e[ans, 3] := b[i3].id;
    for i := 1 to 3 do
      for j := 1 to 2 do
        if e[ans, j] < e[ans, j + 1] then begin
          t := e[ans, j];
          e[ans, j] := e[ans, j + 1];
          e[ans, j + 1] := t;
        end;

    dec(b[i3].count);
    down(i3);
    dec(b[i2].count);
    down(i2);
    dec(b[i1].count);
    down(i1); 
  end;

  writeln(ans);
  for i := 1 to ans do begin
    for j := 1 to 3 do
      write(e[i, j], ' ');
    writeln;  
  end;
end;

procedure openfiles;
begin
  assign(input, inname);
  assign(output, outname);
  reset(input);
  rewrite(output);
end;

procedure closefiles;
begin
  close(input);
  close(output);
end;

Begin
  //openfiles;
  run;
  //closefiles;
End.

