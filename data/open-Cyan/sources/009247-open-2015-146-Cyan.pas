type
  point = record
    x,y:int64;
  end;

var
 order:longint;
 chain:array[1..300000] of point;
 l:array[1..100000] of longint;
 stpos:array[1..100000] of longint;
 n:longint;
 i,j:longint;
 pos1,pos2:longint;
 ans1:longint;
 ans2:longint;

 function GetInter:boolean;
 var
  y1,y2:int64;
 begin
  y1:=chain[pos1].y*(chain[pos1-1].x-chain[pos1].x);
  y2:=chain[pos2].y*(chain[pos2-1].x-chain[pos2].x);
  If chain[pos1].x>chain[pos2].x Then
  begin
   y1:=(chain[pos2].x-chain[pos1].x)*(chain[pos1-1].y-chain[pos1].y) + chain[pos1].y*(chain[pos1-1].x-chain[pos1].x);
  end
  else
  begin
   y2:=(chain[pos1].x-chain[pos2].x)*(chain[pos2-1].y-chain[pos2].y) + chain[pos2].y*(chain[pos2-1].x-chain[pos2].x);
  end;
  y1:=y1*(chain[pos2-1].x-chain[pos2].x);
  y2:=y2*(chain[pos1-1].x-chain[pos1].x);
  Case order of
   0:begin
      If y1>y2 Then
      begin
       order:=1;
      end;
      If y2>y1 Then
      begin
       order:=2;
      end;
      GetInter:=false;
     end;
   1:begin
      If y2>y1 Then
      begin
       GetInter:=true;
      end
      else
      begin
       GetInter:=false;
      end;
     end;
   2:begin
      If y1>y2 Then
      begin
       GetInter:=true;
      end
      else
      begin
       GetInter:=false;
      end;
     end;
  end;
 end;

begin
 read(i,j);
 read(n);
 stpos[1]:=1;
 For i:=1 to n do
 begin
  read(l[i]);
  For j:=0 to l[i] do
  begin
   read(chain[stpos[i]+j].x,chain[stpos[i]+j].y);
  end;
  stpos[i+1]:=stpos[i]+l[i]+1;
 end;
 For i:=1 to n-1 do
 begin
  For j:=i+1 to n do
  begin
   order:=0;
   If chain[stpos[i]].y>chain[stpos[j]].y Then order:=1;
   If chain[stpos[i]].y<chain[stpos[j]].y Then order:=2;
   pos1:=stpos[i]+1;
   pos2:=stpos[j]+1;
   While (pos1<=stpos[i]+l[i]) and (pos2<=stpos[j]+l[j]) and (ans1=0) do
   begin
    If GetInter Then
    begin
     ans1:=i;
     ans2:=j;
    end;
    If (pos1<stpos[i]+l[i]) and (pos2<stpos[j]+l[j]) Then
    begin
     If chain[pos1+1].x<chain[pos2+1].x Then inc(pos1) else inc(pos2);
    end
    else
    begin
     If (pos1<stpos[i]+l[i]) Then inc(pos1) else inc(pos2);
    end;
   end;
   If ans1>0 Then break;
  end;
  If ans1>0 then break;
 end;
 If ans1>0 Then
 begin
  writeln('No');
  writeln(ans1,' ',ans2);
 end
 else
 begin
  writeln('Yes');
 end;
 readln;
 readln;
end.

