program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type ladia = record
        x: integer;
        y: integer;
      end;

var fin, fout: TextFile;
    N: integer;
    k: integer;
    AnsAr: array of ladia;
    Ar: array of integer;
    flag: Boolean;
    i: integer;

Procedure Openning;
var iopen: integer;
begin
  AssignFile(fin, 'chess.in');
  AssignFile(fout, 'chess.out');
  Reset(fin);
  Rewrite(fout);

  Readln(fin, N);
  SetLength(Ar, N);
  For iopen := 0 to N-1 do
    Read(fin, Ar[iopen]);
end;

Procedure Ending;
begin
  CloseFile(fin);
  CloseFile(fout);
end;

Procedure PrintAnswer;
var iprint: integer;
begin
  Writeln( fout, k + 1 );
  For iprint := 0 to k  do
    Writeln( fout, AnsAr[iprint].x + 1, ' ', AnsAr[iprint].y + 1);
end;

Procedure Cheeck;
var icheeck: integer;
begin
  flag := True;
  For icheeck := 0 to N - 1 do
    If Ar[icheeck] > 0 then
      flag := False;
end;


begin
  Openning;
  flag := false;
  k := -1;

  While ( not flag ) do begin
    Inc( k );
    SetLength( AnsAr, k + 1);
    AnsAr[k].x := k;
    AnsAr[k].y := k;
    Ar[k] := 0;
    For i := k to (N - 1) do
      Dec(Ar[i]);
    Cheeck;
  end;

  PrintAnswer;
  Ending;  
end.
