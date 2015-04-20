program Game;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  m,n,l1,r1,l2,r2,pet,vas,obsh,i,k,f,x:longint;
begin
  assign(input,'game.in');
  assign(output,'game.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  readln(l1,r1);
  readln(l2,r2);
  pet:=0;
  vas:=0;
  obsh:=0;
  for i:=1 to n do
    begin
    read(x);
    if ((l1<=x)and(x<=r1))and((l2<=x)and(x<=r2)) then
      obsh:=obsh+1 else
      if (l1<=x)and(x<=r1) then
        pet:=pet+1 else
        if (l2<=x)and(x<=r2) then
          vas:=vas+1;
    end;
  if(obsh>=m)then
    if (m mod 2=0) then
      writeln('Draw') else
      writeln('Petya') else
        begin
        k:=m-obsh;
        f:=obsh mod 2;
        if (k>=pet+vas) then
          if (pet+f=vas) then
            writeln('Draw') else
            if(pet+f>vas) then
              writeln('Petya') else
              writeln('Vasya') else
          if (pet<=vas) then
            if (pet>k div 2) then
              if (f=1) then
                writeln('Petya') else
                writeln('Draw') else
              if (pet+f=k-pet) then
                writeln('Draw') else
                if (pet+f>k-pet) then
                  writeln('Petya') else
                  writeln('Vasya') else
            if (vas<k div 2) then
              writeln('Petya') else
              if (vas=k div 2) then
                if (f=0)and(m mod 2=0) then
                  writeln('Draw') else
                  writeln('Petya') else
                if (vas>k div 2) then
                  if (m mod 2=0) then
                    writeln('Draw') else
                    writeln('Petya');
        end;
  close(input);
  close(output);
end.
