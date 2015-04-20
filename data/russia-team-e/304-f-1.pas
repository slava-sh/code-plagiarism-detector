Uses math;
Const PROB = 'polygon';
{$OPTIMIZATION ON}
{$ifndef HOME}
    {$Q-}{$R-}
{$else}
    {$Q+}{$R+}
{$endif}

Const MaxN = 2000;
      epsilon = 1.0e-12;
      RTD = 180.0 / pi;
Type TCoors = Record x, y: Extended; end;
     TArray = Array[1..MaxN+1] of TCoors;

function GetVec(A, B: TCoors): TCoors;
begin
    GetVec.x:= B.x - A.x;
    GetVec.y:= B.y - A.y;
end;

function GetLen(v: TCoors): Extended;
begin
    GetLen:= Sqrt( Sqr(v.x) + Sqr(v.y) );
end;

function SqrLen(v: TCoors): Extended;
begin
    SqrLen:= Sqr(v.x) + Sqr(v.y);
end;

function DotMult(u, v: TCoors): Extended;
begin
    DotMult:= u.x * v.x + u.y * v.y;
end;

function Add(A, v: TCoors): TCoors;
begin
    Add.x:= A.x + v.x;
    Add.y:= A.y + v.y;
end;

function Scale(v: TCoors; q: Extended): TCoors;
begin
    Scale.x:= v.x * q;
    Scale.y:= v.y * q;
end;

function GetAngle(v: TCoors): Extended;
var alpha: Extended;
begin
    alpha:= arccos(v.x / GetLen(v)) * RTD;
    if(v.y < -epsilon) then alpha:= alpha + 360.0;
    GetAngle:= alpha;    
end;

function inInterval(a: Extended): Boolean;
begin
    inInterval:= (-epsilon < a) and (a < 1.0+epsilon);    
end;

function GetTime(A, v: TCoors; R2: Extended): Extended;
var aa, kk, cc: Extended;
    D, t: Extended;
begin
    aa:= SqrLen(v);
    kk:= DotMult(A, v);
    cc:= SqrLen(A) - R2;
    
    D:= Sqr(kk) - aa*cc;
    if(D<0.0) then Exit(-1.0);
    D:= Sqrt(D);
    
    t:= (-kk + D) / aa;
    if inInterval(t) then Exit(t);
    t:= (-kk - D) / aa;
    if inInterval(t) then Exit(t);
    
    GetTime:= -1.0;
end;

Var a: TArray;
    N, M: LongInt;
    v, O, G: TCoors;
    minalpha, minbeta, alpha, beta: Extended;
    phi, teta: Extended;
    t: Extended;
    i: LongInt;
Begin
    {$ifndef HOME}
    Assign(input, PROB + '.in'); Reset(input);
    Assign(output, PROB + '.out'); Rewrite(output);
    {$endif}
    
    Readln(N);
    for i:= 1 to N do Readln(a[i].x, a[i].y);
    O:= a[1];
    for i:= 1 to N do a[i]:= GetVec(O, a[i]);
    a[N+1]:= a[1];
    
    Readln(M);
    While(M>0) do begin
        Readln(G.x, G.y);
        G:= GetVec(O, G);
        teta:= GetAngle(G);
        minalpha:= 500; minbeta:= 500;
        
        for i:= 1 to N do begin
            v:= GetVec(a[i], a[i+1]);
            
            t:= GetTime(a[i], v, SqrLen(G));
            if(t<0) then continue;
            
            phi:= GetAngle( Add(a[i], Scale(v, t)) );
            
            While(phi>teta) do phi:= phi - 360;
            
            beta:= teta - phi;
            alpha:= 360.0 - beta;
            
            if(alpha < minalpha) then minalpha:= alpha;
            if(beta < minbeta) then minbeta:= beta;        
        end;
        
        if( (minalpha > 360.0) and (minbeta > 360.0) ) then Writeln('360 360')
                                                       else Writeln(minbeta, ' ', minalpha);
        Dec(M);
    end;
    
    Close(input); Close(output);
End.
