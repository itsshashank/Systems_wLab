DECLARE 
a NUMBER := &a;
b NUMBER := &b;
c NUMber :=&c;
l NUMber := -1;
BEGIN
IF( a > b) THEN
    if(a>c) THEN
        l:=a;
    else 
        l:=c;
    end if; 
ELSE
    if(b>c) THEN
        l:=b;
    ELSE
        l:=c;
    end if;    
END IF;
dbms_output.put_line(l ||' is greatest');
END;
/