uses math;
var n, d, max1, max5, max4, max2, i, max3: longint;
a: array [1..100003] of longint;
sum : int64;
fl2, fl1: boolean;
used: array [1..100003] of boolean;
begin
  assign(input, 'sochi.in');
  assign(output, 'sochi.out');
  reset(input);
  rewrite(output);
  readln(n, d);
  for i := 1 to n do
    read(a[i]);
  sum := 0;
  for i := 1 to n do
    if a[i] - (3 * d) >= 0 then
      begin
        inc(sum, a[i] - (2 * d));
        used[i] := true;
      end;
  if sum <> 0 then
    inc(sum, 2 * d);
  max1 := 0;
  max2 := 0;
  for i := 1 to n do
    if (a[i] - (d) > 0) and (not used[i]) then
      if a[i] >= max1 then
        begin
          max2 := max1;
          max1 := a[i];
        end
      else
        if a[i] > max2 then
          begin
            max2 := a[i];
          end;
  max3 := 0;
  for i := 1 to n do
    if a[i] > max3 then
      max3 := a[i];
  if sum <> 0 then
    writeln(max(sum, max(sum + max1 + max2 - 4 * d, sum + max1 - 2 * d)))
  else
    writeln(max(max3, max1 + max2 - 2 * d));
  close(input);
  close(output);
end.
