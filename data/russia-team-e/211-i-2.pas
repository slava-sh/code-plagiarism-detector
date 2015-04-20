var  n, d, i, max2, max1: longint;
   sum: int64;
   a: array [1..100001] of longint;
begin
        assign(input, 'sochi.in');
        assign(output, 'sochi.out');
        reset(input);
        rewrite(output);
  readln(n, d);
  for i := 1 to n do
    read(a[i]);
  for i := 1 to n do
    a[i] := a[i] - (2 * d);
  sum := 0;
  max1 := -15000;
  max2 := -15000;
  for i := 1 to n do
    if a[i] >= d then
      inc(sum, a[i])
    else
        if a[i] > max1 then
                max1 := a[i]
        else
                if a[i] > max2 then
                        max2 := a[i];
 //   writeln(sum, max1);
  if sum <> 0 then
        begin
  if (max1 + d> 0) and (max1 > -15000) then
        inc(sum, max1 + d)
  else
        inc(sum, d);
  if (max2 + d> 0) and (max2 > -15000) then
        inc(sum, max2 + d)
  else
        inc(sum, d);
  end
  else
        if (max1 + max2) + (2 * d) > 0 then
                sum := max1 + max2 + (2 * d)
                else
        sum := max1 + (2 * d);
  writeln(sum);
  close(input);
  close(output);
end.
