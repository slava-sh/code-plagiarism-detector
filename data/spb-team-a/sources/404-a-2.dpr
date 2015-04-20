program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  t: Integer;
  Code: Array[0..10000] of Array[0..1] of byte;
  Str: String;
  Inp, O: TextFile;
  i, Res: Integer;
begin
  AssignFile(Inp, 'abcd.in');
  Reset(Inp);
  Readln(Inp, T);
  For i := 0 to T-1 do begin
    Readln(Inp, Str);
    If Str[1] = '0' then
      Code[i,0] := StrToInt(Str[2])
    else
      Code[i,0] := StrToInt(Str[1]+Str[2]);
    If Str[3] = '0' then
      Code[i,1] := StrToInt(Str[4])
    else
      Code[i,1] := StrToInt(Str[3]+Str[4]);
  end;
  CloseFile(Inp);
  AssignFile(O, 'abcd.out');
  Rewrite(O);
  For I := 0 to T-1 do begin
    Res := (Code[i,0]*Code[i,0] + Code[i,1]*Code[i,1]) mod 7;
    if Res = 1 then
      Writeln(O, 'YES')
    Else
      Writeln(O, 'NO');
  end;
  CloseFile(O);
end.
