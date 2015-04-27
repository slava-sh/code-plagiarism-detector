type TQ=record
h,t,turn:Longint;
end;
var i,n,m:LongInt;
incheadhead,incheadtail,inctailhead,inctailtail:array[0..201] of LongInt;
visited:array[0..201,0..201] of boolean;
queue:array[0..200*200+2000] of TQ;
cq:LongInt;
defhead,deftail:LongInt;
attack:LongInt;

procedure add(ch,ct,cturn:LongInt);
begin
  inc(cq);
  queue[cq].h:=ch;
  queue[cq].t:=ct;
  queue[cq].turn:=cturn;
  visited[ch,ct]:=true;
end;

procedure win(turn:LongInt);
begin
  writeln('Ivan');
  writeln(turn);
  halt;
end;

procedure trywin;
var i,dech,dect:LongInt;
begin
  cq:=0;
  fillchar(visited,sizeof(visited),0);
  add(defhead,deftail,0);
  for i:=1 to maxlongint do
  begin
    if i>cq then exit;
    if (queue[i].h=0)and(queue[i].t=0) then Win(queue[i].turn);
    for dech:=1 to n do
      if queue[i].h-dech<0 then continue
      else
      if (queue[i].h+queue[i].t-dech+incheadhead[dech]+incheadtail[dech]>attack) then continue
      else
      if (not visited[queue[i].h-dech+incheadhead[dech],queue[i].t+incheadtail[dech]]) then Add(queue[i].h-dech+incheadhead[dech],queue[i].t+incheadtail[dech],queue[i].turn+1);
      
    for dect:=1 to m do
      if queue[i].t-dect<0 then continue
      else
      if (queue[i].h+queue[i].t-dect+inctailhead[dect]+inctailtail[dect]>attack) then continue
      else
      if (not visited[queue[i].h+inctailhead[dect],queue[i].t-dect+inctailtail[dect]]) then add(queue[i].h+inctailhead[dect],queue[i].t-dect+inctailtail[dect],queue[i].turn+1);
    
  end;
end;

var color:array[0..201,0..201] of LongInt;

procedure dfs(ch,ct:LongInt);
var q:LOngInt;
begin
  color[ch,ct]:=1;
  for q:=1 to n do
   if (ch-q<0)or(ch+ct-q+incheadhead[q]+incheadtail[q]>attack) then continue
   else
   begin
     if color[ch-q+incheadhead[q],ct+incheadtail[q]]=1 then begin writeln('Draw');halt;end;
     if color[ch-q+incheadhead[q],ct+incheadtail[q]]=0 then 
       dfs(ch-q+incheadhead[q],ct+incheadtail[q]);
   end;
   
  for q:=1 to m do
    if (ct-q<0)or(ch+ct-q+inctailhead[q]+inctailtail[q]>attack) then continue
    else
    begin
      if color[ch+inctailhead[q],ct-q+inctailtail[q]]=1 then begin writeln('Draw');halt;end;
      if color[ch+inctailhead[q],ct-q+inctailtail[q]]=0 then
        dfs(ch+inctailhead[q],ct-q+inctailtail[q]);
    end;
  color[ch,ct]:=2;
end;

procedure defendforever;
begin
  fillchar(color,sizeof(color),0);
  dfs(defhead,deftail);
end;

procedure justdefend;
var i,j,k,q:LongInt;
changed:boolean;
a,aprev:array[0..200,0..200] of boolean;
begin
  changed:=false;
  fillchar(a,sizeof(a),false);
  a[defhead,deftail]:=true;
  k:=0;
  while true do
  begin
    changed:=false;
    inc(k);
    aprev:=a;
    fillchar(a,sizeof(a),false);
    for i:=0 to 200 do
      for j:=0 to 200 do
        if aprev[i,j] then
        begin
       //  writeln(k,' ',i,' ',j,' true!',n,m,inctailhead[1],inctailtail[1]);
          for q:=1 to n do
            if (i-q<0)or(i+j-q+incheadhead[q]+incheadtail[q]>attack) then continue
            else
            begin
              a[i-q+incheadhead[q],j+incheadtail[q]]:=true;
              changed:=true;
            end;
            
          for q:=1 to m do
            if (j-q<0)or(i+j-q+inctailhead[q]+inctailtail[q]>attack) then continue
            else
            begin
              a[i+inctailhead[q],j-q+inctailtail[q]]:=true;
              changed:=true;
            end;  
        end;
    if not changed then 
    begin
      writeln('Zmey');
      writeln(k);
      halt;
    end;
  end;
end;

begin
 // assign(input,'/home/megaterik/input.txt');reset(input);
  read(defhead,deftail,attack);
  read(n);
  for i:=1 to n do
    read(incheadhead[i],incheadtail[i]);
  read(m);
  for i:=1 to m do 
    read(inctailhead[i],inctailtail[i]);
  
  TryWin;
  DefendForever;
  JustDefend;
end.
