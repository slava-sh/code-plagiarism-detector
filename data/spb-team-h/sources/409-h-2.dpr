program names;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type vector3 = record
x, y, z : String;
end;

var
i, n, j, k : Integer;
data : array[1..1002] of vector3;
current, help, min, max : string;
flag, minMore, maxMore : boolean;
helpV : vector3;

begin
  reset(input, 'names.in');
  rewrite(output, 'names.out');
  ReadLn(n);

  for i:=1 to n do
  begin
    Readln(current);
    for j:=1 to 2 do
    begin
      if j = 1 then
      data[i].x:=Copy(current, 1, Pos(' ', current)-1) else
      data[i].y:=Copy(current, 1, Pos(' ', current)-1);
      Delete(current, 1, Pos(' ', current));
    end;
      data[i].z:=Copy(current, 1, length(current));
  end;

  for i:=1 to n do
  begin
    current:=data[i].x;
    for j:=1 to n do
      if (i <> j) and ((current = data[j].x) or (current = data[j].y)) then
      begin
        help:=data[i].y;
        data[i].y:=data[i].x;
        data[i].x:=help;
        help:=data[i].z;
        data[i].z:=data[i].x;
        data[i].x:=help;
        break;
      end;
  end;

  for i:=1 to n-1 do
    for j:=1 to n - 1 do
    begin
      for k:=1 to length(data[j].x) do
        if (data[j].x[k] > data[j + 1].x[k]) or (data[j+1].x[k] = #0) then
        begin
          helpV:=data[j];
          data[j]:=data[j + 1];
          data[j + 1]:=helpV;
        end else
        if (data[j].x[k] < data[j + 1].x[k]) then
        break;

    end;

  for i:=1 to n do
  begin
    Trim(data[i].x);
    Trim(data[i].y);
    Trim(data[i].z);
    Write(data[i].x, ' ', data[i].y, ' ');
    WriteLn(data[i].z);
  end;
  close(output);
end.
 