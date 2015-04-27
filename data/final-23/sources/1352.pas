program Project1;

{$APPTYPE CONSOLE}

uses
  Math;

type integer = int64;


var
   b,c : array [0..2*100000-1] of integer;
   a : array [0..100000] of integer;
   n,x,m : integer;

procedure define1(i,d : integer);
begin
   a[i] := d;
   i := i + n - 1;
   b[i] := d;
   while i <> 1 do
      begin
         i := i div 2;
         b[i] := (b[i*2] + b[i*2+1]);
      end;
end;

procedure define2(i,d : integer);
begin
   a[i] := d;
   i := i + n - 1;
   c[i] := d;
   while i <> 1 do
      begin
         i := i div 2;
         c[i] := (c[i*2] + c[i*2+1]);
      end;
end;

function getsum1(l,r : integer) : integer;
var m : integer;
begin
   l := l + n - 1;
   r := r + n - 1;
   m := 0;
   while l <= r do
      begin
         if odd(l) then
            begin
               m := m + b[l];
               inc(l);
            end;
         if not odd(r) then
            begin
               m := m + b[r];
               dec(r);
            end;
         l := l div 2;
         r := r div 2;
      end;
   getsum1 := m;
end;


function getsum2(l,r : integer) : integer;
var m : integer;
begin
   l := l + n - 1;
   r := r + n - 1;
   m := 0;
   while l <= r do
      begin
         if odd(l) then
            begin
               m := m + c[l];
               inc(l);
            end;
         if not odd(r) then
            begin
               m := m + c[r];
               dec(r);
            end;
         l := l div 2;
         r := r div 2;
      end;
   getsum2 := m;
end;

var i,k1,k2,lll,k3 : system.integer;

begin
   reset(input, 'signchange.in');
   rewrite(output, 'signchange.out');
   read(n);
   for i := 1 to n do
      begin
         read(x);
         if odd(i) then b[i-1+n] := x;
         a[i] := x;
         if not odd(i) then c[i-1+n] := x;
      end;
   for i := n - 1 downto 1 do
      b[i] := (b[2*i] + b[2*i+1]);
   for i := n - 1 downto 1 do
      c[i] := (c[2*i] + c[2*i+1]);
   read(m);
   for i := 1 to m do
      begin
         read(k1,k2,k3);
         if k1 = 0 then
            if odd(k2) then define1(k2,k3) else define2(k2,k3) else
               if odd(k2) then writeln(getsum1(k2,k3)-getsum2(k2,k3)) else
                  writeln(getsum2(k2,k3)-getsum1(k2,k3));
      end;
   close(input);
   close(output);
end.
