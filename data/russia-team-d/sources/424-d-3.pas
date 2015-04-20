program n1;
var n, i, k, ans:longint;
a: array[1..400000] of longint;

procedure swap(var a, b:longint);
  var x: longint;
  begin
   x := a;
   a := b;
   b := x;
  end;

procedure qsort(l, r:longint);
  var x, i, j:longint;
  begin if l >= r then exit else
   begin
   x := a[l + random(r - l + 1)];
   i := l;
   j := r;
   while i <= j do
     begin
     while a[i] < x do inc(i);
     while a[j] > x do j := j - 1;
     if i <= j then
       begin
       swap(a[i], a[j]);
       inc(i);
       dec(j);
       end;
     end; qsort(l, j); qsort(i, r);
   end;
  end;

function max(a, b:longint):longint;
  begin
   if a > b then max := a else max := b;
  end;

function can(x: longint):boolean;
  var i, s: longint;
  begin
  if (x > a[1]) then
    begin
     can := false;
     exit;
    end;
  s := 0;
   for i := 1 to n do
     begin
      if (i = n) then inc(s, x)
      else inc(s, max(a[i] - s, x));
     end;
  if s <= k then can := true else can := false;
  end;

function bin(x, y:longint):longint;
  var i: longint;
  begin
   if (y - x < 1) then
     begin
      bin := 0;
      exit;
     end;

   if (can(x)) and (not can(x + 1)) then
     begin
      bin := x;
      exit;
     end;
   if (can(y)) and (not can(y + 1)) then
     begin
      bin := y;
      exit;
     end;

   i := (y + x) div 2;
   if (can(i)) and (not can(i + 1))
    then bin := i
   else if (not can(i))
         then bin := bin(x, i)
   else if (can(i)) and (can(i+1))
         then bin := bin(i + 1, y);
  end;

begin
{
assign(input, 'input.txt');
assign(output, 'output.txt');
reset(input); rewrite(output);
}
{}
assign(input, 'fence.in');
assign(output, 'fence.out');
reset(input); rewrite(output);
{}
randomize;
read(n, k);
for i := 1 to n do read(a[i]);
qsort(1, n);
if (k < n) then ans := 0 else ans := bin(1, k);
write(ans);
end.
