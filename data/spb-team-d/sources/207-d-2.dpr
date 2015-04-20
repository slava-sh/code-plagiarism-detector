program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var q:array[1..1000] of int64;
l:array[1..1000] of int64;
r:array[1..1000] of int64;
x:array[1..1000] of smallint;
res:array[1..1000] of integer;
n,m,i,j,xx :integer;
ll,rr,qq :int64;


begin
  assignfile(input, 'dunes.in');
  assignfile(output, 'dunes.out');

  readln(n,m);

  for i:=1 to n do
  readln(l[i],r[i],x[i]);

  for i:=1 to m do
  readln(q[i]);

  for i:=1 to n do
  begin
    ll:=l[i]; rr:=r[i]; xx:=x[i];
    for j:= 1 to m do
    begin
      qq:=q[j];
      if (qq >= ll) and (qq <= rr) then
      begin
        if (qq-ll) mod 2 = 0 then res[j]:=res[j]+xx
        else res[j]:=res[j]-xx;
      end;
    end;
  end;

  for i:=1 to m do writeln(res[i]);

  close (input);
  close (output);
end.
