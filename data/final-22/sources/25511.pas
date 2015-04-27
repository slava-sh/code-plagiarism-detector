program graf_4_3;
  {$o-,H+}
  type int=longint;
       uk=^s;
       s=record
           wh:int;
           w:int;
           next:uk;
         end;
   const con=524288;
         con2=con*2;
         very_big=maxlongint;
         eps=1e-9;
   var
     i,j,n,m,tec,qw,sdvig:int;
     a,b,c:int;
     reb,kon:array[1..500020]of uk;
     d1:array[1..500020]of extended;
     kol,l,r:array[0..4]of int;
     q:array[0..4,1..500020]of int;
     z:uk;

     procedure dob(no,a,b:int);
       var z1:uk;
         begin

           if reb[no]=nil then
             begin
               new(reb[no]);
               reb[no]^.w:=b;
               reb[no]^.wh:=a;
               reb[no]^.next:=nil;
               kon[no]:=reb[no];
               exit;
             end;
           z1:=kon[no];
           new(z1^.next);
           z1:=z1^.next;
           kon[no]:=z1;
           z1^.next:=nil;
           z1^.wh:=a;
           z1^.w:=b;
         end;

     function poisk(q:int):int;
       begin
         if q=0 then poisk:=0 else
         if q=1 then poisk:=4 else
         if q=2 then poisk:=2 else
         if q=3 then poisk:=3 else
         poisk:=1;
       end;


     begin
     assign(input,'graph.in');
     reset(input);
     assign(output,'graph.out');
     rewrite(output);
     read(n,m);
     for i:=1 to m do
       begin
         read(a,b,c);
         dob(a,b,c);
         dob(b,a,c);
       end;
     for i:=1 to n do
       d1[i]:=very_big;  
     q[0,1]:=1;
     kol[0]:=1;
     l[0]:=1;
     r[0]:=0;
     d1[1]:=0.0;
     for i:=1 to 5 do
       l[i]:=1;
     while kol[1]+kol[2]+kol[3]+kol[4]+kol[0]>0 do
       begin
         while kol[sdvig]=0 do
           sdvig:=(sdvig+1)mod 5;
         tec:=q[sdvig,l[sdvig]];
         z:=reb[tec];
         while z<>nil do
           begin
             if d1[tec]+1/z^.w+eps<d1[z^.wh]then
               begin
                 d1[z^.wh]:=d1[tec]+1/z^.w;
                 qw:=(poisk(z^.w)+sdvig)mod 5;
                 inc(kol[qw]);
                 inc(r[qw]);
                 q[qw,r[qw]]:=z^.wh;
               end;
             z:=z^.next;
           end;
         dec(kol[sdvig]);
         inc(l[sdvig]);
         if kol[sdvig]=0 then
           begin
             l[sdvig]:=1;
             r[sdvig]:=0;
           end;  
         if kol[sdvig]=0 then
           sdvig:=(sdvig+1) mod 5;
       end;
    for i:=2 to n do
     writeln(d1[i]:0:8);

     close(input);
     close(output);

  end.
