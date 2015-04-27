var
    
    a,b,na,nb : array[1..200000]of longint;
    mk,mn,m,n,i,j,k,x,y,p:longint;

procedure make_1;
begin
    for i := mn to mn+n do
        na[i]:=a[i-mn+1];
    i:=mn+mn-1;
    while i>1 do
    begin
        na[i div 2]:=na[i]+na[i-1];
        dec(i,2);
    end;
end;

procedure make_2;
begin
    for i := mk to mk+k do
        nb[i]:=b[i-mk+1];
    i:=mk+mk-1;
    while i>1 do
    begin
        nb[i div 2]:=nb[i]+nb[i-1];
        dec(i,2);
    end;
end;

procedure update_1(i,x:longint);
begin
    i:=i+mn-1;
    na[i]:=x;
    while i>1 do begin
        i:=i div 2;
        na[i]:=na[2*i]+na[2*i+1]
    end;
end;

procedure update_2(i,x:longint);
begin
    i:=i+mk-1;
    nb[i]:=x;
    while i>1 do begin
        i:=i div 2;
        nb[i]:=nb[2*i]+nb[2*i+1]
    end;
end;

function find_1(l,r:longint):longint;
var 
    s,i,j:longint;
begin
    s:=0;
	l:=l+mn-1;
	r:=r+mn-1;
	while r>l do begin
        if l mod 2 = 1 then  s:=s+na[l];
        if r mod 2 = 0 then  s:=s+na[r];
        r:=(r-1)div 2;
        l:=(l+1)div 2;
   end;
   if l=r then s:=s+na[l];
   find_1:=s;
end;

function find_2(l,r:longint):longint;
var 
    s,i,j:longint;
begin
    s:=0;
	l:=l+mk-1;
	r:=r+mk-1;
	while r>l do begin
        if l mod 2 = 1 then  s:=s+nb[l];
        if r mod 2 = 0 then  s:=s+nb[r];
        r:=(r-1)div 2;
        l:=(l+1)div 2;
    end;
    if l=r then s:=s+nb[l];
    find_2:=s;
end;


begin
    assign(input, 'signchange.in'); reset(input);
    assign(output, 'signchange.out'); rewrite(output);
    read(m);
    for i := 1 to m do
        if i mod 2 = 1 then begin
            inc(n);
            read(a[n]);
        end else begin
            inc(k);
            read(b[k]);
        end;
    mk:=1;
    while k > mk do
        mk:=mk+mk;
    mn:=1;
    while n > mn do
        mn:=mn+mn;
    make_1;
    make_2;
    read(m);
    for i := 1 to m do
        begin
            read(p);
            if p = 0 then begin
                read(x,y);
                if x mod 2 = 1 then
                    update_1((x div 2)+1 ,y)
                else
                    update_2(x div 2, y);
            end
            else begin
                read(x,y);
                if (x mod 2 = 1) and (y mod 2 = 1) then
                    writeln(find_1((x div 2) + 1,(y div 2) + 1)-find_2((x div 2) + 1,y div 2)); 
                if (x mod 2 = 1) and (y mod 2 = 0) then
                    writeln(find_1((x div 2) + 1,(y div 2))-find_2((x div 2) + 1,(y div 2)));
                if (x mod 2 = 0) and (y mod 2 = 1) then
                    writeln(find_2((x div 2) ,(y div 2))-find_1((x div 2) + 1,(y div 2)+1));
                if (x mod 2 = 0) and (y mod 2 = 0) then
                    writeln(find_2((x div 2) ,(y div 2))-find_1((x div 2) + 1,(y div 2)));
            end;
        end;

end.
