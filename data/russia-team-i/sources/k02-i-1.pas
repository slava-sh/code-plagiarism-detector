uses math;
var
  a: array[1..100010] of longint;
  n, d,i , j, ans, ans1: longint;

procedure swap(var a, b: longint);
var
  d: longint;
  begin
    d := a; a := b; b := d;
  end;

procedure qsort(l, r: longint);
var
  s, i, j: longint;
begin
  i := l;
  j := r;
  s := a[l + random(r -l)];

  while i <= j do
  begin
    while a[i] < s do inc(i);
    while a[j] > s do dec(j);

    if i <= j then
    begin
      swap(a[i], a[j]);
      inc(i);  dec(j);
    end;
  end;

  if i < r then qsort(i, r);
  if l < j then qsort(l, j);

end;

begin
	assign(input, 'sochi.in'); reset(input);
	assign(output, 'sochi.out'); rewrite(output);

  read(n, d);

  for i := 1 to n do
    read(a[i]);

  if n = 1 then
  begin
    write(a[1]);
    halt;
  end;

  qsort(1, n);

  for i:= 1 to n do
    if a[i] >= 3 * d then
      break;

  ans := a[n];
  if (n >= 2) and (a[n] > d) and (a[n - 1] > d) then
  ans := max(ans, a[n] + a[n - 1] - 2 * d);

  if a[i] >= 3 * d then
  begin
        for j := i to n do
                ans1 := ans1 + a[j];
        ans := max(ans, ans1 - (n - i) * 2 * d);
        if (i > 1) and (a[i - 1] - d >= d) then
          ans := max(ans, ans1 + a[i - 1] - (n - i + 1) * 2 * d);
        if (i > 2) and (a[i - 2] - d >= d) then
          ans := max(ans, ans1 + a[i - 1] + a[i - 2] - (n - i + 2) * 2 * d);
  end;

  write(ans);
end.