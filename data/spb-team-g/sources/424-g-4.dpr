program xxx;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, i, j, x, curr, cnt: integer;
  flag: boolean;
  arr: array of extended;
  sum: int64;
  tmp: extended;  

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

  x:= n;
  curr:= 2;

  flag:= false;

  while arr[1] <> arr[x] do
  begin
    while arr[x] > 0 do
    begin
      if (arr[x] - (arr[curr] - arr[1])*(curr-1) >= 0) then
      begin
        arr[x]:= arr[x] - (arr[curr] - arr[1])*(curr-1);
        if curr = x then
        begin
          flag:= true;
          break;
        end
        else

        for j:= 1 to curr - 1 do
          arr[j]:= arr[curr];

      end else
      begin

        inc(cnt);
        for j:= 1 to curr - 1 do
          arr[j]:= arr[j] + arr[x] / (curr - 1);

        arr[x]:= 0;  
      end;

      inc(curr);

    end;

    if (not flag) then
      dec(x);
    if curr >= x then
      if arr[1] <> arr[x] then
      begin
        inc(cnt);
        break;
      end;
  end;


  writeln(cnt);
end.
 