Program A;
uses crt;
var n : integer;
    ch : char;
    i,j,t1,t:integer;
    s,s1,s2:string;
    f,f1 : TEXT;

Begin

assign(f, 'abcd.in');
reset(f);
assign(f1,'abcd.out');
rewrite(f1);

ReadLn(f, n);

for i:= 1 to n do begin
ReadLn(f, s);

t := (((ord(s[1])-48)*10) + (ord(s[2])-48));
t1:= (((ord(s[3])-48)*10) + (ord(s[4])-48));

if (((t*t) + (t1*t1)) mod 7) = 1 Then begin WriteLn('YES'); end
else WriteLn('NO');








end;


ReadLn(n);

close(f);
close(f1);
END.