program n1;
var n, r, ans, i, j, ansr:longint;
a: array[1..400000] of longint;
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
   ansr := ans;
   for j := i + 1 to n do
     if (a[j] - a[i] > r) then
       begin
        inc(ans, n - j + 1);
        break;
       end;
   if ansr = ans then break;
  end;

write(ans);
end.