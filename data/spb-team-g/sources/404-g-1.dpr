program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var fin, fout: TextFile;
    N: integer;
    Answer: integer;
    Ar: array of Real;
    Sum: real;
    flag: Boolean;
    i, j: integer;
    mid: real;

Procedure Openning;
begin
  AssignFile(fin, 'merlin.in');
  AssignFile(fout, 'merlin.out');
  Reset(fin);
  Rewrite(fout);

  Readln(fin, N);
  SetLength(Ar, N);
  sum := 0;
  For i := 0 to N-1 do
    Read(fin, Ar[i]);
end;

Procedure Ending;
begin
  Writeln( fout, Answer );
  CloseFile(fin);
  CloseFile(fout);
end;

Procedure Change(var a, b: real);
var t: real;
begin
  t := a;
  a := b;
  b := t;
end;

Procedure BubbleSort;
begin
  For i := 0 to N - 1 do
    For j := 0 to N - 1 do
      If (Ar[j] < Ar[j+1]) then
        Change(Ar[j], Ar[j+1]);
end;

Procedure Cheeck;
var i: integer;
begin
  flag := True;
  For i := 0 to N - 1 do
    If ( Ar[ i ] <> Ar[ 0 ] ) then begin
      flag := False;
      break;
    end;  
end;


begin
  Openning;
  For i := 0 to N - 1 do
    sum := sum + Ar[i];

  BubbleSort;
  Cheeck;
  Answer := 0;
  j:=2;

  While ( not flag ) do begin
    Inc( Answer );
    mid := sum / (N - 1);

    While ( Ar[N-1] > 0 ) do
      If Ar[N-1] <= mid - Ar[N-j] then begin
        Ar[N-j] := Ar[N-1] + Ar[N-j];
        Ar[N-1] := 0;
      end else begin
        Ar[n-1] := Ar[n-1] - mid + Ar[n-j];
        Ar[n-j] := mid;
        Inc( j );
      end;

    Dec( N );
    SetLength(Ar, N);
    Cheeck;
  end;

  Ending;
end.
