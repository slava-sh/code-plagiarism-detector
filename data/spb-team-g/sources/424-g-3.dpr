
program Project2;
 
{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, i, j, n0: integer;
  tmp: integer;
  s: string;
  arr: array of integer;
  count, countsum: int64;

begin
  assignfile(input, 'merlin.in');
  assignfile(output, 'merlin.out');
  readln(n);
  setlength(arr, n + 1);

  for i:= n downto 1 do
  begin
    read (arr[i]);
    for j:= i to n-1 do
    begin
      if (arr[j] > arr[j+1]) then
      begin
        tmp:= arr[j]; arr[j]:= arr[j+1]; arr[j+1]:= tmp;
      end else
        break;
    end;
  end;

  n0:= n;

  count:= 1;
  countsum:= arr[1];

  for i:= 1 to n-1 do
    if (arr[i] = arr[i+1]) then
    begin
      inc(count);
      countsum:= countsum + arr[count]
    end else
      break;

  while (count < n-1) do
  begin
    while (arr[n] > 0) and (count < n-1) do
    begin
      if (arr[n] >= arr[count+1]*count - countsum) then
      begin
        arr[n]:= arr[n] - arr[count+1]*count + countsum;
        inc(count);
        countsum:= countsum+arr[count];
      end else
      begin
        countsum:= countsum + arr[n];
        break;
      end;
    end;
    dec (n);
  end;

  writeln (n0 - count);

end.
