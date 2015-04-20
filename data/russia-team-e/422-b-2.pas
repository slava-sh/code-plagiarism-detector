const lim = 300300;
  var i , n , d , cc : longint;
      ans : int64;
      a : array[1 .. lim] of longint;

function dix(cis : longint) : int64;
  var l , r , mid : longint;

begin

  l := 1; r := n;
  while r - l > 1 do begin
    mid := (l + r) div 2;
    if cis <= a[mid] then r := mid
      else l := mid;
  end;

  if a[r] <= cis then exit(int64(r))
    else exit(int64(l));

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
