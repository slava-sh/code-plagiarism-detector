program sol;

uses
  SysUtils,math;
type tNum=record country,oper,n:int64; end;
     tCountry=record Code,no:int64; a:array[1..101] of int64; end;
var t:tNum;
    C:array[1..101] of tCountry;
    nc,n,m:int64;
    i,j:longint;
    s:string;
function fCountry(s:string;var numb:longint):boolean;
var i,x:longint;
begin
  if s[1]='0'
  then begin
         result:=false;
         exit;
       end;
  x:=strtoint(s);
  for i:=1 to n do
  begin
    if c[i].Code=x
    then begin
           result:=true;
           numb:=i;
           exit;
         end;
  end;
  result:=false;
end;
function fOperator(y:int64;s:string):boolean;
var i,x:longint;
begin
  if s[1]='0'
  then begin
         result:=false;
         exit;
       end;
  x:=strtoint(s);
  for i:=1 to c[y].no do
  begin
    if c[y].a[i]=x
    then begin
           result:=true;
           exit;
         end;
  end;
  result:=false;
end;
procedure Writerez(x:tNum);
var s:string;
begin
  write('+',x.country);
  write('(',x.oper,')');
  s:=inttostr(x.n);
  case length(s) of
  3:write(s);
  4:write(s[1]+s[2],'-',s[3]+s[4]);
  5:write(s[1]+s[2]+s[3],'-',s[4]+s[5]);
  6:write(s[1]+s[2],'-',s[3]+s[4],'-',s[5]+s[6]);
  7:write(s[1]+s[2]+s[3],'-',s[4]+s[5],'-',s[6]+s[7]);
  end;
  writeln;
end;
function GetNumber(s:string):tNum;
var i,j,temp:longint;
begin
  for i:=1 to 3 do
  begin
    if fCountry(copy(s,1,i),temp)
    then
    begin
      for j:=3 to 5 do
      begin
        if (fOperator(temp,copy(s,i+1,j)))and(s[i+j+1]<>'0')
        then  begin
                result.oper:=strtoint(copy(s,i+1,j));
                result.country:=c[temp].Code;
                result.n:=strtoint(copy(s,i+1+j,length(s)-i-j));
                writerez(result);
                exit;
              end;
      end;
    end;
  end;
  writeln('Incorrect');
end;
begin
  //assign(input,'input.txt');
  assign(input,'numbers.in');
  reset(input);
  //assign(output,'output.txt');
  assign(output,'numbers.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    readln(c[i].code,c[i].no);
    for j:=1 to c[i].no do
    readln(c[i].a[j]);
  end;
  readln(m);
  for i:=1 to m do
  begin
    readln(s);
    GetNumber(s);
  end;
end.
