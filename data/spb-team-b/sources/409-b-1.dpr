program chess;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type vector2 = record
x, y : Integer;
end;

var
  n, i, j, k, numberKl, count : Integer;
  isKl : array [1..1001, 1..1001] of Boolean;
  currentBool : Boolean;
  coord : array [1..1001] of vector2;
  currentCoord : vector2;

begin
  reset(input, 'chess.in');
  rewrite(output, 'chess.out');
  Read(n);

  for i:=1 to n do
  begin
    Read(numberKl);
    for j:=1 to numberKl do
      isKl[i, j]:=true;
  end;
  //currentBool[1,1];
  currentCoord.x:=1;
  currentCoord.y:=1;
  coord[1]:=currentCoord;
  count:=1;

  while isKl[currentCoord.x + 1, currentCoord.y + 1] = true do
  begin
    count:=count+1;
    coord[count].x:=currentCoord.x + 1;
    coord[count].y:=currentCoord.y + 1;
    currentCoord.x:=currentCoord.x + 1;
    currentCoord.y:=currentCoord.y + 1;
  end;

  WriteLn(count);
  for k:=1 to count do
  begin
    Write(coord[k].x, ' ');
    WriteLn(coord[k].y);
  end;




  close(output);
end.
 