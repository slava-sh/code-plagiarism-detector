program problemD;

type arr1 = array [1..1000] of integer;
     arr2 = array [1..10000000] of integer;
var i, o : text;
    n, m, j, k : integer;
    l, r, x, a:int64;
    d : arr2;

procedure clear(var a : arr2);
var i : int64;
begin
     for i:=1 to 10000000 do a[i]:=0;
end;

begin
     assign(i,'dunes.in');
     assign(o,'dunes.out');
     reset(i);
     rewrite(o);
          clear(d);
          readln(i, n, m);
          for j:=1 to n do
          begin
               readln(i, l, r, x);
               for k:=l to r do
               begin
                    if ((k-l) mod 2) = 0 then d[k]:=d[k]+x
                                          else d[k]:=d[k]-x;
               end;
          end;
          for j:=1 to m do begin readln(i, a);
          writeln(o, d[a]); end;
     close(i);
     close(o);
end.