{$H+}
const
  p=5;
  q=1000000009;
type
  voc = record
    sh:array[1..3] of int64;
    sl:array[1..3] of longint;
    pl:array[1..3] of longint;
    cou:longint;
  end;

  hashar = array[0..20000] of int64;

var
  ans:longint;
  st:string;
  l,i:longint;
  tmp:voc;
  ansv:voc;
  sthash:hashar;
  ppow:array[0..20000] of int64;

procedure getans(pos:longint);
var
  i:longint;
  h:int64;
  gone:boolean;
begin
 If pos=length(st)+1 then
 begin
  If ans>tmp.cou Then
  begin
   ans:=tmp.cou;
   ansv:=tmp;
  end;
 end
 else
 begin
  gone:=false;
  If pos<=length(st) Then
  begin
   For i:=1 to tmp.cou do
   begin
    If (pos+tmp.sl[i]-1<=length(st)) and (ans>tmp.cou) Then
    begin
     h:=(q+sthash[pos+tmp.sl[i]-1]-(sthash[pos-1]*ppow[tmp.sl[i]]) mod q) mod q;
     If h=tmp.sh[i] Then
     begin
      gone:=true;
      getans(pos+tmp.sl[i]);
     end;
    end;
   end;
   For i:=1 to l do
   begin
    If (ans<=tmp.cou+1) or gone Then
    begin
     break;
    end
    else
    begin
     inc(tmp.cou);
     tmp.sl[tmp.cou]:=i;
     tmp.sh[tmp.cou]:=(q+sthash[pos+i-1]-(sthash[pos-1]*ppow[i]) mod q) mod q;
     tmp.pl[tmp.cou]:=pos;
     getans(pos+i);
     dec(tmp.cou);
    end;
   end;
  end;
 end;
end;

begin
 readln(l);
 readln(st);
 sthash[0]:=0;
 ppow[0]:=1;
 For i:=1 to length(st) do
 begin
  sthash[i]:=(sthash[i-1]*p+ord(st[i])-ord('a')+1) mod q;
  ppow[i]:=(ppow[i-1]*p) mod q;
 end;
 ans:=4;
 getans(1);
 writeln(ans);
 For i:=1 to ans do
 begin
  writeln(copy(st,ansv.pl[i],ansv.sl[i]));
 end;
 readln;
 readln;
end.

