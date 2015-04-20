Uses StrUtils, Math;
Const PROB = 'travel';
Type TDMatrix = Array[0..501, 0..501] of Char;
{$OPTIMIZATION ON}
{$ifndef HOME}
    {$Q-}{$R-}
{$else}
    {$Q+}{$R+}
{$endif}

Function Opp(const a: Char):Char;
Begin
    Case a of
    'r': Exit('l');
    'l': Exit('r');
    'u': Exit('d');
    'd': Exit('u');
    end;
End;

Var maxT: Array[0..501, 0..501] of LongInt;
    prev, special: TDMatrix;
Function Solve(const a: TDMatrix; const w, h, n: LongInt):AnsiString;
Var res: AnsiString;
    i, j, bestAns, bestX, bestY, ansHere: LongInt;
    tmp: Char;
Begin
    FillByte(maxT, sizeof(maxT), 0);
    for i:=0 to max(w, h) do begin
        maxT[i, 0] := -1;
        maxT[0, i] := -1;
    end;
    maxT[1, 1] := 0;
    FillChar(special, sizeof(special), '#');
    for i:=1 to w do begin
        for j:=1 to h do begin
            if (i = 1) and (j = 1) then continue;
            
            if maxT[i - 1, j] >= maxT[i, j - 1] then begin
                maxT[i, j] := maxT[i - 1, j];
                prev[i, j] := 'r';
            end else begin
                maxT[i, j] := maxT[i, j - 1];
                prev[i, j] := 'd';
            end;
            if a[i, j] = 'T' then
                Inc(maxT[i, j]);
            
            if a[i - 1, j] = 'T' then
                special[i, j] := 'l';
            if a[i + 1, j] = 'T' then
                special[i, j] := 'r';
            if a[i, j - 1] = 'T' then
                special[i, j] := 'u';
            if a[i, j + 1] = 'T' then
                special[i, j] := 'd';
        end;
    end;
    
    bestAns := -1;
    bestX := -1;
    bestY := -1;
    for i:=1 to w do begin
        for j:=1 to h do begin
            if a[i, j] <> 'T' then continue;
            if maxT[i, j] > n then continue;
            
            ansHere := i + j - 2;
            if special[i, j] <> '#' then
                Inc(ansHere, n - maxT[i, j])
            else
                Inc(ansHere, (n - maxT[i, j]) * 2);
            
            if (bestAns = -1) or (ansHere < bestAns) then begin
                bestAns := ansHere;
                bestX := i;
                bestY := j;
            end;
        end;
    end;
    
    if bestAns = -1 then Exit('');
    
    res := '';
    i := bestX;
    j := bestY;
    while (i <> 1) or (j <> 1) do begin
        res := res + prev[i, j];
        case prev[i, j] of
        'r': Dec(i);
        'd': Dec(j);
        end;
    end;
    res := AnsiReverseString(res);
    if special[bestX, bestY] = '#' then begin
        for j:=maxT[bestX, bestY] + 1 to n do
            res := res + Opp(prev[bestX, bestY]) + prev[bestX, bestY];
    end else begin
        tmp := special[bestX, bestY];
        for j:=maxT[bestX, bestY] + 1 to n do begin
            res := res + tmp;
            tmp := Opp(tmp);
        end;
    end;
    Exit(res);
End;

Var w, h, n, i, j, startX, startY: LongInt;
    m, tmp: TDMatrix;
    bestSol, hereSol: AnsiString;
Begin
    {$ifndef HOME}
    Assign(input, PROB + '.in'); Reset(input);
    Assign(output, PROB + '.out'); Rewrite(output);
    {$endif}
    
    ReadLn(w, h, n);
    startX := -1;
    startY := -1;
    for i:=1 to h do begin
        for j:=1 to w do begin
            Read(m[j, i]);
            if m[j, i] = 'V' then begin
                startX := j;
                startY := i;
                m[j, i] := 'A';
            end;
        end;
        ReadLn;
    end;
    
    bestSol := '';
    // down right
    FillChar(tmp, sizeof(tmp), '#');
    for i:=startX to w do begin
        for j:=startY to h do begin
            tmp[i - startX + 1, j - startY + 1] := m[i, j];
        end;
    end;
    hereSol := Solve(tmp, w - startX + 1, h - startY + 1, n);
    if (Length(hereSol) > 0) and ((Length(bestSol) = 0) or (Length(hereSol) < Length(bestSol))) then begin
        bestSol := hereSol;
        for i:=1 to Length(bestSol) do begin
            case bestSol[i] of 
            'u': bestSol[i] := 'N';
            'd': bestSol[i] := 'S';
            'l': bestSol[i] := 'W';
            'r': bestSol[i] := 'E';
            end;
        end;
    end;
    
    // up right
    FillChar(tmp, sizeof(tmp), '#');
    for i:=startX to w do begin
        for j:=1 to startY do begin
            tmp[i - startX + 1, startY - j + 1] := m[i, j];
        end;
    end;
    hereSol := Solve(tmp, w - startX + 1, startY, n);
    if (Length(hereSol) > 0) and ((Length(bestSol) = 0) or (Length(hereSol) < Length(bestSol))) then begin
        bestSol := hereSol;
        for i:=1 to Length(bestSol) do begin
            case bestSol[i] of 
            'u': bestSol[i] := 'S';
            'd': bestSol[i] := 'N';
            'l': bestSol[i] := 'W';
            'r': bestSol[i] := 'E';
            end;
        end;
    end;
    
    // down left
    FillChar(tmp, sizeof(tmp), '#');
    for i:=1 to startX do begin
        for j:=startY to H do begin
            tmp[startX - i + 1, j - startY + 1] := m[i, j];
        end;
    end;
    hereSol := Solve(tmp, startX, h - startY + 1, n);
    if (Length(hereSol) > 0) and ((Length(bestSol) = 0) or (Length(hereSol) < Length(bestSol))) then begin
        bestSol := hereSol;
        for i:=1 to Length(bestSol) do begin
            case bestSol[i] of 
            'u': bestSol[i] := 'N';
            'd': bestSol[i] := 'S';
            'l': bestSol[i] := 'E';
            'r': bestSol[i] := 'W';
            end;
        end;
    end;
    
    // up left
    FillChar(tmp, sizeof(tmp), '#');
    for i:=1 to startX do begin
        for j:=1 to startY do begin
            tmp[startX - i + 1, startY - j + 1] := m[i, j];
        end;
    end;
    hereSol := Solve(tmp, startX, startY, n);
    if (Length(hereSol) > 0) and ((Length(bestSol) = 0) or (Length(hereSol) < Length(bestSol))) then begin
        bestSol := hereSol;   
        for i:=1 to Length(bestSol) do begin
            case bestSol[i] of 
            'u': bestSol[i] := 'S';
            'd': bestSol[i] := 'N';
            'l': bestSol[i] := 'E';
            'r': bestSol[i] := 'W';
            end;
        end;
    end;
        
    WriteLn(bestSol);
    
    Close(input); Close(output);
End.
