Const PROB = 'binary';
      MODULO = 1000000000 + 7;
      MAXN = 1000;
      UNSURE = 0;
      EQ = 1;
      NEQ = 2;
{$OPTIMIZATION ON}
{$ifndef HOME}
    {$Q-}{$R-}
{$else}
    {$Q+}{$R+}
{$endif}
Var n: LongInt;
    conn: Array[1..MAXN, 1..MAXN] of Byte;
    visited: Array[1..MAXN] of Boolean;
    comp: Array[1..MAXN] of LongInt;
    compC: LongInt;

Procedure Ans0();
Begin
    WriteLn(0);
    Close(input); CLose(output);
    halt(0);
End;

Procedure MarkComps(const v: LongInt);
Var i: LongInt;
Begin
    visited[v] := True;
    comp[v] := compC;
    //writeln('  ', v, ' ', compC);
    for i:=1 to n do if not visited[i] then begin
        if (conn[v, i] <> UNSURE) then
            MarkComps(i);
    end;
End;

Procedure TryMarking(const v, c: LongInt);
Var i: LongInt;
Begin
    visited[v] := True;
    comp[v] := c;
    
    for i:=1 to n do if conn[v, i] <> UNSURE then begin
        if visited[i] then begin
            if ((conn[v, i] = EQ) and (comp[i] <> comp[v])) or 
                ((conn[v, i] = NEQ) and (comp[i] = comp[v])) then
                Ans0();
        end else begin
            if conn[v, i] = EQ then
                TryMarking(i, c)
            else
                TryMarking(i, (c + 1) mod 2);
        end;
    end;
End;

Function Pow(b, e, m: Int64):Int64;
Var res: Int64;
Begin
    res := 1;
    while e > 0 do begin
        if e mod 2 = 1 then
            res := (res * b) mod m;
        e := e div 2;
        b := (b * b) mod m;
    end;
    Pow := res;
End;

Var i, j, tmp: LongInt;
Begin
    {$ifndef HOME}
    Assign(input, PROB + '.in'); Reset(input);
    Assign(output, PROB + '.out'); Rewrite(output);
    {$endif}
    
    ReadLn(n);
    FillByte(conn, sizeof(conn), UNSURE);
    
    for i:=1 to n do begin
        Read(tmp);
        if tmp = -1 then continue;
        if i = 1 then begin
            if (tmp <> 0) then Ans0();
            continue;
        end;
        for j:=1 to tmp do begin
            if i + j - 1 > n then Ans0();
            if conn[j, i + j - 1] = NEQ then Ans0();
            conn[j, i + j - 1] := EQ;
            conn[i + j - 1, j] := EQ;
        end;
        
        if i + tmp <= n then begin
            if conn[i + tmp, tmp + 1] = EQ then Ans0();
            conn[i + tmp, tmp + 1] := NEQ;
            conn[tmp + 1, i + tmp] := NEQ;
        end;
    end;
    
    {for i:=1 to n do begin
        for j:=1 to n do begin
            write(conn[i,j]);
        end;
        writeln;
    end;}
    
    FillByte(visited, sizeof(visited), 0);
    for i:=1 to n do if not visited[i] then begin
        TryMarking(i, 0);
    end;
        
    FillByte(visited, sizeof(visited), 0);
    compC := 0;
    for i:=1 to n do if not visited[i] then begin
        Inc(compC);
        MarkComps(i);
    end;
        
    WriteLn(Pow(2, compC, MODULO));
    
    Close(input); Close(output);
End.
