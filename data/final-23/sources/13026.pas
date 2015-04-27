program PROG;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const
  ci = 131072;
  
var
  n, k, m : integer;
  com : integer;
  S1, v1 : array[1..ci*2+1] of integer;
  S2, v2 : array[1..ci*2+1] of integer;

procedure relax1(t : integer);
begin
  S1[t] := S1[2*t] + S1[2*t + 1];
end;

procedure relax2(t : integer);
begin
  S2[t] := S2[2*t] + S2[2*t + 1];
end;

procedure complete1(t, l, r, x : integer);
begin
  v1[t] := x;
  S1[t] := x*(r-l+1);
end;

procedure complete2(t, l, r, x : integer);
begin
  v2[t] := x;
  S2[t] := x*(r-l+1);
end;

procedure change1(t, l, r, ql, qr, x : integer);
var
  m : integer;
begin
  if (ql > r) or (l > qr) then exit; 
  if (ql <= l) and (r <= qr) then begin
    complete1(t, l, r, x);
    exit;
  end;
  {+push}
  if v1[t] <> -1 then begin
    m := (r+l) div 2;
    complete1(2*t, l, m, v1[t]);
    complete1(2*t+1, m+1, r, v1[t]);
    v1[t] := -1;
  end;
  {-push}
  m := (r+l) div 2;
  change1(2*t, l, m, ql, qr, x);
  change1(2*t+1, m+1, r, ql, qr, x);
  relax1(t);
end;

procedure change2(t, l, r, ql, qr, x : integer);
var
  m : integer;
begin
  if (ql > r) or (l > qr) then exit; 
  if (ql <= l) and (r <= qr) then begin
    complete2(t, l, r, x);
    exit;
  end;
  {+push}
  if v2[t] <> -1 then begin
    m := (r+l) div 2;
    complete2(2*t, l, m, v2[t]);
    complete2(2*t+1, m+1, r, v2[t]);
    v2[t] := -1;
  end;
  {-push}
  m := (r+l) div 2;
  change2(2*t, l, m, ql, qr, x);
  change2(2*t+1, m+1, r, ql, qr, x);
  relax2(t);
end;

function GS1(t, l, r, ql, qr: integer) : integer;
var
  m : integer;
begin
  if (ql > r) or (l > qr) then begin
    result := 0;
    exit; 
  end;
  if (ql <= l) and (r <= qr) then begin
    result := S1[t];
    exit;
  end;
  if v1[t] <> -1 then begin
    m := (r+l) div 2;
    complete1(2*t, l, m, v1[t]);
    complete1(2*t+1, m+1, r, v1[t]);
    v1[t] := -1;
  end;
  m := (r+l) div 2;
  result := GS1(2*t, l, m, ql, qr) + GS1(2*t+1, m+1, r, ql, qr);
end;

function GS2(t, l, r, ql, qr: integer) : integer;
var
  m : integer;
begin
  if (ql > r) or (l > qr) then begin
    result := 0;
    exit; 
  end;
  if (ql <= l) and (r <= qr) then begin
    result := S2[t];
    exit;
  end;
  if v2[t] <> -1 then begin
    m := (r+l) div 2;
    complete2(2*t, l, m, v2[t]);
    complete2(2*t+1, m+1, r, v2[t]);
    v2[t] := -1;
  end;
  m := (r+l) div 2;
  result := GS2(2*t, l, m, ql, qr) + GS2(2*t+1, m+1, r, ql, qr);
end;

var
  l, r, x : integer;
  i : integer;

begin
  reset(input, 'signchange.in');
  rewrite(output, 'signchange.out');
  read(n);
  for i := 1 to n do begin
    read(x);
    if i mod 2 <> 0 then 
      change1(1, 1, ci, i, i, x)
    else 
      change2(1, 1, ci, i, i, x);
  end;
  read(m);
  for i := 1 to ci*2 do begin
    v1[i] := -1;
  end;
  for i := 1 to ci*2 do begin
    v2[i] := -1;
  end;
  //writeln('1D : ', GS1(1, 1, ci, 1, n));
  //writeln('2D : ', GS2(1, 1, ci, 1, n));
  for i := 1 to m do begin
    read(com);
    if com = 0 then begin
      read(l, x);
      if l mod 2 <> 0 then 
        change1(1, 1, ci, l, l, x) 
      else 
        change2(1, 1, ci, l, l, x);   
      //writeln('1D : ', GS1(1, 1, ci, 1, n));
      //writeln('2D : ', GS2(1, 1, ci, 1, n));
    end else begin
      readln(l, r);    
      if l mod 2 <> 0 then 
        writeln(GS1(1, 1, ci, l, r) - GS2(1, 1, ci, l, r))
      else 
        writeln(GS2(1, 1, ci, l, r) - GS1(1, 1, ci, l, r));
    end; 
  end;
end.
  
end.
 
