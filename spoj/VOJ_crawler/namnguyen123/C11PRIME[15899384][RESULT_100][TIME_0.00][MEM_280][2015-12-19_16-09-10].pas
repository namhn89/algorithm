const   fi='';
        vc=high(int64);
        du=1000000000000000000;
type    data=longint;
        data1=int64;
var
        N:data1;
        f:text;
 
function KTSNT(n:data1):boolean;
var
        i:data;
begin
        for i:=2 to trunc(sqrt(n)) do
                if n mod i=0 then
                        exit(false);
        exit(true);
end;
 
function tinhcan(a:int64; b:data1):int64;
begin
        tinhcan:=round(exp(ln(a)/b));
end;
 
function amuk(a:int64; k:data):int64;
var     i:data;
        res:int64;
begin
        res:=1;
        for i:=1 to k do
                begin
                        res:=(res*a) mod du;
                end;
        exit(res);
end;
 
procedure xuli;
var     i,j:data;
        so:data1;
begin
        for i:=2 to 60 do
                begin
                        so:=tinhcan(n,i);
 
                        if (amuk(so,i)=n) and ktsnt(so) then
                                begin
                                        writeln(so,' ',i);
                                        exit;
                                end;
                end;
        writeln(0);
end;
 
begin
        assign(f,fi); reset(f);
        readln(f,n);
        close(f);
        xuli;
end.