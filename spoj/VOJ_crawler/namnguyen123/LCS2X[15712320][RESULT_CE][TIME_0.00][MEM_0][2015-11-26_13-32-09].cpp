uses    math;

const   fi='';//lcs2x.inp';
        fo='';//lcs2x.out';

const   maxn=1500;

var     m,n:longint;
        a,b,d:array[0..maxn]of longint;
        f:array[0..maxn,0..maxn]of longint;
        res:longint;

procedure solve;
var     i,j,t:longint;
begin
        fillchar(d,sizeof(d),0);
        res:=0;
        for i:=1 to m do begin
                t:=0;
                for j:=1 to n do begin
                        if a[i]=b[j] then
                                f[i,j]:=t+1;
                        if a[i]>=2*b[j] then
                                t:=max(t,d[j]);
                        if a[i]=b[j] then begin
                                d[j]:=max(d[j],f[i,j]);
                                res:=max(res,f[i,j]);
                                end;
                        end;
                end;
end;

procedure enter;
var     k,t,i:longint;
begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(output);
        readln(t);
        for k:=1 to t do begin
                readln(m,n);
                for i:=1 to m do
                        read(a[i]);
                for i:=1 to n do
                        read(b[i]);
                solve;
                writeln(res);
                end;
        close(output);
        close(input);
end;

BEGIN
        enter;
END.