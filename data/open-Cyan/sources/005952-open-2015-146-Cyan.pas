type
  po = record
   x,y:int64;
  end;

var
 v1,v2:array[1..200000] of po;
 n,l1,l2:longint;
 i,j:longint;
 nv1,nv2,a,b:longint;
 pp:longint;
 ans:longint;

 function GetIm(i,j:longint):boolean;
 var
  ta1:int64;
  ta2:int64;
  tb1:int64;
  tb2:int64;
 begin
  ta1:=v1[i].y*(v1[i+1].x-v1[i].x);
  ta2:=v1[i+1].y*(v1[i+1].x-v1[i].x);
  tb1:=v2[j].y*(v2[j+1].x-v2[j].x);
  tb2:=v2[j+1].y*(v2[j+1].x-v2[j].x);
  If v1[i].x<v2[j].x Then
  begin
   ta1:=(v2[j].x-v1[i].x)*(v1[i+1].y-v1[i].y) + v1[i].y*(v1[i+1].x-v1[i].x);
  end;
  If v1[i].x>v2[j].x Then
  begin
   tb1:=(v1[i].x-v2[j].x)*(v2[j+1].y-v2[j].y) + v2[j].y*(v2[j+1].x-v2[j].x);
  end;
  If v1[i+1].x>v2[j+1].x Then
  begin
   ta2:=(v2[j+1].x-v1[i].x)*(v1[i+1].y-v1[i].y) + v1[i].y*(v1[i+1].x-v1[i].x);
  end;
  If v1[i+1].x<v2[j+1].x Then
  begin
   tb2:=(v1[i+1].x-v2[j].x)*(v2[j+1].y-v2[j].y) + v2[j].y*(v2[j+1].x-v2[j].x);
  end;
  If ((ta1*(v2[j+1].x-v2[j].x)>tb1*(v1[i+1].x-v1[i].x)) and (ta2*(v2[j+1].x-v2[j].x)<tb2*(v1[i+1].x-v1[i].x))) or ((ta1*(v2[j+1].x-v2[j].x)<tb1*(v1[i+1].x-v1[i].x)) and (ta2*(v2[j+1].x-v2[j].x)>tb2*(v1[i+1].x-v1[i].x))) Then
  begin
   GetIm:=true;
  end
  else
  begin
   GetIm:=false;
  end;
 end;

begin
 read(a,b);
 read(n);
 read(l1);
 For i:=1 to l1+1 do
 begin
   read(v1[i].x,v1[i].y);
 end;
 For j:=2 to n do
 begin
  If j mod 2 = 0 then
  begin
   read(l2);
   For i:=1 to l2+1 do
   begin
    read(v2[i].x,v2[i].y);
   end;
  end
  else
  begin
    read(l1);
    For i:=1 to l1+1 do
    begin
      read(v1[i].x,v1[i].y);
    end;
  end;
  nv1:=1;
  nv2:=1;
  While (nv1<=l1) and (nv2<=l2) do
  begin
   If GetIm(nv1,nv2) Then ans:=j-1;
   If (nv1<=l1-1) and (nv2<=l2-1) then
   begin
    If v1[nv1+1].x<v2[nv2+1].x Then inc(nv1) else inc(nv2);
   end
   else
   begin
    If nv1<=l1-1 then inc(nv1) else inc(nv2);
   end;
  end;
  If ans>0 then break;
 end;
 If ans>0 then
 begin
  writeln('No');
  writeln(ans,' ',ans+1);
 end
 else
 begin
  writeln('Yes');
 end;
 readln;
 readln;
end.
