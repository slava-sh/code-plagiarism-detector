program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, m, i, j, q: integer;
  ans: int64;
  arr: array of record
    a, b, c: integer;
  end;



begin
  assignfile(input, 'dunes.in');
  assignfile(output, 'dunes.out');

  readln(n, m);
  setlength(arr, n + 1);

  for i:= 1 to n do
    readln(arr[i].a, arr[i].b, arr[i].c);

  for i:= 1 to m do
    begin
      readln(q);
      ans:= 0;

      for j:= 1 to n do
        if (q >= arr[j].a) and (q <= arr[j].b) then
          if ((q - arr[j].a) mod 2 = 0) then
            inc(ans, arr[j].c)
          else
            dec(ans, arr[j].c);
      writeln(ans);        
    end;

end.
