/functions
DECLARE
      id plemp.id%type;
      sal plemp.sal%type;
      FUNCTION dissal(xid number)RETURN number
      is
      BEGIN
       FOR aRow IN (SELECT id, Name,sal fROM plemp WHere id = xid)
       LOop
            dbms_output.put_line('NAME ' || 'sal ');
            dbms_output.put_line( aRow.name ||' '|| aRow.sal);
            RETURN aRow.sal;
       end loop;
      end;
BEGIN
      id :=&id;
      sal:=dissal(id);
      dbms_output.put_line( 'SAl=' || sal);
END;
/