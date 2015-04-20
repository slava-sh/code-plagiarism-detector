const lim = 300300;
  var i , n , d , cc , ans : longint;
      a : array[1 .. lim] of longint;

function dix(cis : longint) : longint;
  var l , r , mid : longint;

begin

  l := 1; r := n;
  while r - l > 1 do begin
    mid := (l + r) div 2;
    if cc <= a[mid] then r := mid
      else l := mid;
  end;

  if a[r] <= cc then exit(r)
    else exit(l);

end;


BEGIN

  assign(input , 'che.in'); assign(output , 'che.out');
  reset(input); rewrite(output);
  readln(n , d);
  for i := 1 to n do read(a[i]);
  ans := 0;
  for i := 1 to n do begin
    cc := a[i] - d - 1;
    if cc <= 0 then continue;
    ans := ans + dix(cc);
  end;
  writeln(ans);
  close(input); close(output);

END.
