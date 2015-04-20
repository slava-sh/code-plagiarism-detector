type gorod=record
    c:string;
    k:longint;
    ops:array[1..102] of string;

end;
var a:array[1..102] of gorod;
m,n:integer;
i,j:integer;
s,s1,s2:string;
ct2,ct,t:longint;
f:boolean;
  input1,output1:text;
function give(s:string):string;
var s1:string;
begin
s1:='';
if length(s) = 3 then s1:=s;
if length(s) = 4 then s1:=s[1]+s[2]+'-'+s[3]+s[4];
if length(s) = 5 then s1:=s[1]+s[2]+s[3]+'-'+s[4]+s[5];
if length(s) = 6 then s1:=s[1]+s[2]+'-'+s[3]+s[4]+'-'+s[5]+s[6];
if length(s) = 7 then s1:=s[1]+s[2]+s[3]+'-'+s[4]+s[5]+'-'+s[6]+s[7];
give:=s1;
end;

Begin
assign(input1,'numbers.in');
assign(output1,'numbers.out');
reset(input1); rewrite(output1);

readln(input1,n);
for i:=1 to n do
Begin
//writeln('n=',i);
   read(input1,t,a[i].k);
  // writeln(t);
  // a[i].c:='sadg';
   str(t,a[i].c);

  // writeln(a[i].c,'<');
   readln(input1);
   for j:=1 to a[i].k do
        readln(input1,a[i].ops[j]);
end;
readln(input1,m);
for i:=1 to m do
Begin
   readln(input1,s);
                     f:=false;
                   //  writeln('sravmn ',s);
   for j:=1 to n do
   begin
       //  writeln(a[j].c);
       t:=pos(a[j].c,s);
     //  writeln(t);
       if t=1 then begin f:=true; ct:=j; break; end;
   end;
   if not f then begin writeln(output1,'Incorrect'); continue; end;
   s:=copy(s,length(a[ct].c)+1,length(s)-length(a[ct].c));
   s1:='+'+a[ct].c;
   f:=false;

   for j:=1 to a[ct].k do
   begin

       t:=pos(a[ct].ops[j],s);
     //  writeln(t);
       if t=1 then begin f:=true;  ct2:=j; break;  end;
   end;
    if not f then begin writeln(output1,'Incorrect'); continue; end;
      s:=copy(s,length(a[ct].ops[ct2])+1,length(s)-length(a[ct].ops[ct2]));
   s1:=s1+'('+a[ct].ops[ct2]+')';
   s2:=give(s);
   if pos('0',s2)=1 then begin writeln(output1,'Incorrect'); continue; end;
   s1:=s1+s2;
   writeln(output1,s1);

end;


close(input1);
close(output1);
end.