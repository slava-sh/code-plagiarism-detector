program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var  n,m,a,b,c,d, pr, Petya, Vasya: int64;
      L: array of int64;
      P: array of integer;
      i,j: integer;
begin
  assignfile(input, 'game.in');
  assignfile(output, 'game.out');
  readln (n, m);
  readln (a, b);
  readln (c, d);
  setlength (L, n);
  setlength (P, n);
  for i:= 1 to n do read (L[i]);
  for i:= 1 to m do begin
    if (L[i] >= a) and (L[i] <= b) then P[i]:= P[i] + 1;
    if (L[i] >= c) and (L[i] <= d) then P[i]:= P[i] + 2;
  end;

  for i:= 1 to m div 2 do begin
    for j:= 1 to n do if P[j] = 3 then begin
          P[j] := 0;
          pr:= 1;
          break;
    end;
    if pr = 0 then  begin
          for j:= 1 to n do if P[j] = 1 then begin
                P[j] := 0;
                pr:= 1;
                break;

          end;
    end;
    if pr = 1 then Petya := Petya + 1;
    pr := 0;

    for j:= 1 to n do if P[j] = 3 then begin
          P[j] := 0;
          pr:= 1;
          break;

    end;
    if pr = 0 then  begin
          for j:= 1 to n do if P[j] = 2 then begin
                P[j] := 0;
                pr:= 1;
                break;

          end;
    end;
    if pr = 1 then Vasya := Vasya + 1;
    pr := 0;

  end;
  if m mod 2 = 1 then begin
        for j:= 1 to n do if P[j] = 3 then begin
          P[j] := 0;
          pr:= 1;
          break;

    end;
    if pr = 0 then  begin
          for j:= 1 to n do if P[j] = 1 then begin
                P[j] := 0;
                pr:= 1;
                break;
          end;
    end;
    if pr = 1 then Petya := Petya + 1;
  end;



  if Petya > Vasya then writeln ('Petya')
  else if Vasya > Petya then writeln ('Vasya')
  else writeln ('Draw');

  close (input);
  close (output);

end.
