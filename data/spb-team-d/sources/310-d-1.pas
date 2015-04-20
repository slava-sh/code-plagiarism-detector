program problemD;

type arr1 = array [1..1000] of integer;
     arr2 = array [1..10000000] of int64;
var i, o : text;
    n, m, j, k : int64;
    x : arr1;
    l, r, d, a : arr2;

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
          clear(l);
          clear(r);
          clear(d);
          clear(a);
          readln(i, n, m);
          for j:=1 to n do
          begin
               readln(i, l[j], r[j], x[j]);
               for k:=l[j] to r[j] do
               begin
                    if ((k-l[j]) mod 2) = 0 then d[k]:=d[k]+x[j]
                                          else d[k]:=d[k]-x[j];
               end;
          end;
          for j:=1 to m do readln(i, a[j]);
          for j:=1 to m do writeln(o, d[a[j]]);
     close(i);
     close(o);
end.