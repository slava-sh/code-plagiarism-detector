{$MODE OBJFPC}
program Tasks;
const
  {$IFDEF ONLINE_JUDGE}
  {$R-,Q-,S-,I-}
  {$OPTIMIZATION LEVEL2}
  {$INLINE ON}
  InputFile  = '';
  OutputFile = '';
  {$ELSE}
  {$INLINE OFF}
  InputFile  = 'Input.txt';
  OutputFile = 'Output.txt';
  {$ENDIF}
  maxMN = 500;
var
  fi, fo: TextFile;
  n, m, k, modulo: Integer;
  count: array[1..maxMN] of Integer;
  f: array[0..maxMN, 0..maxMN] of Int64;

procedure Enter;
var
  i, j: Integer;
  ch: Char;
begin
  ReadLn(fi, n, m, modulo);
  FillChar(count, SizeOf(count), 0);
  k := n;
  for i := 1 to m do
    begin
      for j := 1 to n do
        begin
          Read(fi, ch);
          if ch = '1' then
            begin
              if count[j] = 0 then Dec(k);
              Inc(count[j]);
            end;
        end;
      ReadLn(fi);
    end;
  m := n - m;
  FillChar(f, SizeOf(f), $FF); //-1
end;

function GetF(m, k: Integer): Int64;
var
  k1: Integer;
  temp1, temp2, temp3: Int64;
begin
  if (m < 0) or (k < 0) then Exit(0);
  if f[m, k] <> -1 then Exit(f[m, k]);
  if m = 0 then
    begin
      if k = 0 then f[m, k] := 1 mod modulo
      else f[m, k] := 0;
    end
  else
    begin
      k1 := 2 * m - 2 * k;
      if k1 < 2 then
        temp1 := 0
      else
        temp1 := k1 * (k1 - 1) div 2 * GetF(m - 1, k) mod modulo;
      if (k1 < 1) or (k < 1) then
        temp2 := 0
      else
        temp2 := k * k1  * GetF(m - 1, k - 1) mod modulo;
      if k < 2 then
        temp3 := 0
      else
        temp3 := k * (k - 1) div 2 * GetF(m - 1, k - 2) mod modulo;
      f[m, k] := (temp1 + temp2 + temp3) mod modulo;
    end;
  Result := f[m, k];
end;


begin
  AssignFile(fi, InputFile); Reset(fi);
  AssignFile(fo, OutputFile); Rewrite(fo);
  try
    Enter;
    WriteLn(fo, GetF(m, k));
  finally
    CloseFile(fi); CloseFile(fo);
  end;
end.
