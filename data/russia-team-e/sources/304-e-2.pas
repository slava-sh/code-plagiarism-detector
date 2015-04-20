Const PROB = 'numbers';
{$OPTIMIZATION ON}
{$ifndef HOME}
    {$Q-}{$R-}
{$else}
    {$Q+}{$R+}
{$endif}

Const MaxN = 10000;
      MaxLen = 11;
Type TCode = Record s, c, r: String; end;
Var a: Array[1..MaxN] of TCode;

procedure Sort(l, r: LongInt);
var i, j: LongInt;
    bar: String;
    tmp: TCode;
begin
  i:= l; j:= r;
  bar:= a[(l+r) div 2].s;
  
  While(i<=j) do begin
     While(a[i].s < bar) do Inc(i);
     While(bar < a[j].s) do Dec(j);
     if(i<=j) then begin
        tmp:= a[i]; a[i]:= a[j]; a[j]:= tmp;
        Inc(i); Dec(j);
     end;  
  end;
    
  if(l<j) then Sort(l, j);
  if(i<r) then Sort(i, r);
end;

function Find(tmp: String; low, high: LongInt): LongInt;
var mid: LongInt;
begin
    While(low<high) do begin
        mid:= (low+high) div 2;
        if(a[mid].s < tmp) then low:= mid+1
                           else high:= mid;    
    end;
    
    if(a[low].s = tmp) then Find:= low
                       else Find:= -1;
end;

function formatnum(s: String): String;
var res: String;
begin
    res:= '';
    Case length(s) of 
        3: res:= s;
        4: res:= s[1] + s[2] + '-' + s[3] + s[4];
        5: res:= s[1] + s[2] + s[3] + '-' + s[4] + s[5];
        6: res:= s[1] + s[2] + '-' + s[3] + s[4] + '-' + s[5] + s[6];
        7: res:= s[1] + s[2] + s[3] + '-' + s[4] + s[5] + '-' + s[6] + s[7]; 
    end;
    formatnum:= res;
end;

Var i, j: LongInt;
    N, K, M: LongInt;
    country, tmp: String;
    code: LongInt;
    Num: LongInt;
    ch: Char;
Begin
    {$ifndef HOME}
    Assign(input, PROB + '.in'); Reset(input);
    Assign(output, PROB + '.out'); Rewrite(output);
    {$endif}
    
    Readln(N);
    M:= 0;
    for i:= 1 to N do begin
        country:= '';
        Read(ch);
        While(ch <> ' ') do begin
            country:= country + ch;
            Read(ch);
        end;
        Readln(K);
        
        for j:= 1 to K do begin
            Inc(M);
            Readln(a[M].r);
            a[M].c:= country;
            a[M].s:= a[M].c + a[M].r;
        end;
    end;
    
    Sort(1, M);
    
    Readln(Num);
    for i:= 1 to Num do begin
        tmp:= '';
        Readln(tmp);
        for j:= 4 to 8 do begin
            code:= -1;
            if(tmp[j+1] = '0') then continue;
            code:= Find(Copy(tmp, 1, j), 1, M);
            if(code>0) then break;        
        end;
        if(code<0) then begin
            Writeln('Incorrect');
            continue;
        end;
                
        Writeln('+', a[code].c, '(', a[code].r, ')', formatnum(Copy(tmp, length(a[code].s)+1, 11)));
    end;
    
    Close(input); Close(output);
End.
