program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils, Math, Classes;

var
  Inp, O: TextFile;
  Arr: Array[0..1001] of array[0..2] of String;
  Arr2: Array[0..1001] of array[0..1] of Int64;
  Arr3: Array[0..1001] of array[0..1] of Integer;
  i, j, n: Integer;
  t: String;
  SL: TStringList;

Function HashF(Str: String): Int64;
var
  ii: Integer;
begin
  Result := 0;
  Str := LowerCase(Str);
  For ii := 1 to Length(Str) do
    Result := (Result+Ord(Str[ii])-Ord('a')+1)*37;
end;

begin
  AssignFile(Inp, 'names.in');
  Reset(Inp);
  Readln(Inp, N);
  For i := 0 to N-1 do begin
    Readln(Inp, T);

    Arr[i,0] := Copy(T, 1, pos(' ', T)-1);
    Delete(T, 1, pos(' ', T));

    Arr[i,1] := Copy(T, 1, pos(' ', T)-1);
    Delete(T, 1, pos(' ', T));

    Arr[i,2] := T;
  end;
  CloseFile(Inp);

  For i := 0 to N-1 do begin
    Arr2[i, 0] := HashF(Arr[i, 0]);
    Arr2[i, 1] := HashF(Arr[i, 1]);
    Arr3[i,0] := 0;
    Arr3[i,1] := 0;
  end;

  For i := 0 to N-1 do
    For j := 0 to N-1 do
      if i <> j then begin

        if Arr2[i,0] = arr2[j,0] then
          arr3[i,0] := arr3[i,0] + 1;

        if Arr2[i,0] = arr2[j,1] then
          arr3[i,0] := arr3[i,0] + 1;
      end;

  For i := 0 to N-1 do
    if arr3[i,0] > 0 then begin
      t := arr[i,0];
      arr[i,0] := arr[i,1];
      arr[i,1] := t;

      t := Arr[i,2];
      Arr[i,2] := Arr[i,0];
      Arr[i,0] := t;
    end;

  SL := TStringList.Create;
  For i := 0 to N-1 do
  SL.Add(arr[i,0]+' '+arr[i,1]+' '+arr[i,2]);

  SL.Sort;

  AssignFile(O, 'names.out');
  Rewrite(O);
  For I := 0 to N-1 do
    Writeln(O, SL.Strings[i]);
  CloseFile(O);
  SL.Free;
end.
