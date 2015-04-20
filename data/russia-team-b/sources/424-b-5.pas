program n1;
var n, r, ans, i, j, ansr:longint;
a: array[1..400000] of longint;

function bin(x, y, sr:longint):longint;
  var i: longint;
  begin
   if x > y then
     begin
      bin := -1;
      exit;
     end;
   i := (y + x) div 2;
   if (a[i] - a[sr] > r) and (a[i - 1] - a[sr] <= r)
    then bin := i
   else if (a[i] - a[sr] > r) and (a[i - 1] - a[sr] > r)
         then bin := bin(x, i, sr)
   else if (a[i] - a[sr] <= r) then bin := bin(i + 1, y, sr);
  end;
begin
{
assign(input, 'input.txt');
assign(output, 'output.txt');
reset(input); rewrite(output);
}
{}
assign(input, 'che.in');
assign(output, 'che.out');
reset(input); rewrite(output);
{}
read(n, r);
for i := 1 to n do read(a[i]);

ans := 0;
for i := 1 to n - 1 do
  begin
   j := bin(i + 1, n, i);
   if j <> -1 then inc(ans, n - j + 1);
  end;

write(ans);
end.