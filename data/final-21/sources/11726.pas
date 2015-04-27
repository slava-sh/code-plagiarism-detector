program invent;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
  MaxN = round(2 * 10E4 + 1);

type
  ar = array[1..MaxN] of char;
  ar1 = array[0..MaxN] of longint;

var
  n, i, j, len: longint;
  a: ar;
  p: ar1;
  h, r: ar1;
  boo: boolean;

procedure get_str(var a: ar; var len: longint);
var
  i: longint;
begin
  i := 0;
  while not(eoln) do
  begin
    inc(i);
    read(a[i]);
  end;
  len := i;
  for i := len + 1 to 2 * len do
    a[i] := a[i - len];
  readln;
end;

procedure get_hash(len: longint);
var
  i: longint;

begin
  for i := 1 to len * 2 do
    h[i] := h[i - 1] *  p[1] + ord(a[i]) - 48;
  for i := len * 2 downto 1 do
    r[i] := r[i + 1] *  p[1] + ord(a[i]) - 48;
end;

begin
  assign(input, 'inventory.in');
  assign(output, 'inventory.out');
  reset(input);
  rewrite(output);

  readln(n);
  p[0] := 1;
  p[1] := 29;
  for i := 2 to MaxN do
    p[i] := p[i - 1] * p[1];
  for i := 1 to n do
  begin
    get_str(a, len);
    get_hash(len);
    boo := false;
    for j := 1 to len do
      if h[j + len - 1] - h[j + len div 2 - 1] * p[len - len div 2] = r[j] - r[j + len - len div 2] * p[len - len div 2] then
      begin
        writeln(j - 1);
        boo := true;
        break;
      end;
    if not boo then
      writeln(-1);
  end;

  close(input);
  close(output);
end.
