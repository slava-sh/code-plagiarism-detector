program II;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  ans, i, n, d, m, u1, u2: longint;
  a: array [0..100000] of longint;
begin
  assign(input, 'sochi.in');
  reset(input);
  assign(output, 'sochi.out');
  rewrite(output);        
  read(n, d);
  for i := 1 to n do
    read(a[i]);
  ans := 0;
  a[0] := 0;
  u1 := 0;
  for i := 1 to n do
    if (a[i] < 3 * d) and (a[i] > 2 * d) and (a[i] > a[u1]) then
      u1 := i;
  u2 := 0;
  for i := 1 to n do
    if (a[i] < 3 * d) and (a[i] > 2 * d) and (a[i] > a[u2]) and (i <> u1) then
      u2 := i;
  for i := 1 to n do
    if (a[i] >= 3 * d) then
      ans := ans + a[i] - 2 * d;
  if (u1 <> 0) then
   ans := ans + a[u1] - d
  else
    ans := ans + d;
  if (u2 <> 0) then
   ans := ans + a[u2] - d
  else
    ans := ans + d;

  write(ans);

end.
 