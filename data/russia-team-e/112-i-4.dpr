program II;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  ans, i, n, d, m, u1, u2, mak, k: longint;
  a: array [0..100000] of longint;
begin
  assign(input, 'sochi.in');
  reset(input);
  assign(output, 'sochi.out');
  rewrite(output);                     
  k := 0;
  read(n, d);
  for i := 1 to n do
    read(a[i]);
  mak := 0;
  for i := 1 to n do
    if a[i] > mak then
      mak := a[i];
  ans := 0;
  a[0] := 0;
  u1 := 0;
  for i := 1 to n do
    if (a[i] < 3 * d) and (a[i] > d) and (a[i] > a[u1]) then
      u1 := i;
  u2 := 0;
  for i := 1 to n do
    if (a[i] < 3 * d) and (a[i] > d) and (a[i] > a[u2]) and (i <> u1) then
      u2 := i;
  for i := 1 to n do
    if (a[i] >= 3 * d) then
    begin
      ans := ans + a[i];
      inc(k);
    end;
  if (u1 <> 0) then
  begin
   ans := ans + a[u1];
   inc(k);
   end;
  if (u2 <> 0) then
  begin
   ans := ans + a[u2];
   inc(k);
  end;
  if (k > 0) then
    ans := ans - (k - 1) * 2 * d
  else
    ans := 0;
  if (mak > ans) then
    ans := mak;
  write(ans);

end.
