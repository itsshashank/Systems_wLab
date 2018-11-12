//salary
DECLARE 
   e_id plemp.id%type; 
   e_name plemp.name%type; 
   e_sal plemp.sal%type; 
   CURSOR emp_sal is 
      SELECT  id, name, sal FROM plemp; 
BEGIN 
   OPEN emp_sal; 
   LOOP 
   FETCH emp_sal into e_id, e_name, e_sal; 
      EXIT WHEN emp_sal%notfound; 
      dbms_output.put_line(e_id || ' ' || e_name || ' ' || e_sal); 
   END LOOP; 
   CLOSE emp_sal; 
END; 
/
//Date of birth
DECLARE 
   e_name plemp.name%type; 
   e_dob plemp.b_date%type; 
   CURSOR emp_dob is 
      SELECT  name, b_date FROM plemp; 
BEGIN 
   OPEN emp_dob;
      dbms_output.put_line('emp_name' || ' ' || 'DateOfBirth'); 
   LOOP 
   FETCH emp_dob into e_name, e_dob; 
      EXIT WHEN emp_dob%notfound; 
      dbms_output.put_line(e_name || ' ' || e_dob); 
   END LOOP; 
   CLOSE emp_dob; 
END; 
/
//DA
DECLARE 
   e_name plemp.name%type; 
   e_sal plemp.sal%type; 
   CURSOR emp_da is 
      SELECT  name, sal FROM plemp;
	e_da number; 
BEGIN 
   OPEN emp_da;
      dbms_output.put_line('emp_name' || ' ' || 'DA'); 
   LOOP 
   FETCH emp_da into e_name, e_sal; 
      EXIT WHEN emp_da%notfound; 
	e_da := 0.1*e_sal;
      dbms_output.put_line(e_name || ' ' || e_da); 
   END LOOP; 
   CLOSE emp_da; 
END; 
/
//update sal by 1000 for a dept
DECLARE 
   e_dno plemp.dno%type;
   e_name plemp.name%type; 
   e_sal plemp.sal%type;
   temp plemp.sal%type; 
   CURSOR emp_update is 
      SELECT  name, sal,dno FROM plemp;
	did number; 
BEGIN 
   OPEN emp_update;
	did := &did;
      dbms_output.put_line('emp_name' || ' ' || 'sal' || 'oldsal'); 
   LOOP 
   FETCH emp_update into e_name, e_sal ,e_dno; 
      EXIT WHEN emp_update%notfound; 
      temp := e_sal;
	if (did = e_dno) then
		e_sal := e_sal +1000;
	update plemp set sal = e_sal where dno = did;
      dbms_output.put_line(e_name || ' ' || e_sal ||' '|| temp);
	end if; 
   END LOOP; 
   CLOSE emp_update; 
END; 
/
//get month
DECLARE 
   e_name plemp.name%type; 
   e_dob varchar(3); 
   CURSOR emp_b_month is 
      SELECT  name, SUBSTR(b_date,4,3) FROM plemp; 
BEGIN 
   OPEN emp_b_month;
      dbms_output.put_line('emp_name' || ' ' || 'Birth Month'); 
   LOOP 
   FETCH emp_b_month into e_name,e_dob; 
      EXIT WHEN emp_b_month%notfound; 
      dbms_output.put_line(e_name || ' ' || e_dob); 
   END LOOP; 
   CLOSE emp_b_month; 
END; 
/
// difference between avg sal of 2 dept
DECLARE 
   e_dno plemp.dno%type; 
   e_sal plemp.sal%type; 
   CURSOR emp_sal_diff is 
      SELECT  dno, avg(sal) FROM plemp group by dno;
      deptone number;
      depttwo plemp.dno%type;   
   sal_d1 number;
   sal_d2 number;
   sal_diff number;
BEGIN 
   OPEN emp_sal_diff;
      deptone := &deptone;
      depttwo := &depttwo;
      dbms_output.put_line('difference in sal'||' '||deptone||','||depttwo); 
   LOOP 
   FETCH emp_sal_diff into e_dno, e_sal; 
      EXIT WHEN emp_sal_diff%notfound; 
	if (e_dno = deptone) then
		sal_d1 := e_sal ;
	elsif (e_dno = depttwo) THEN
            sal_d2 := e_sal;
      end if; 
   END LOOP; 
   sal_diff := sal_d1 - sal_d2;
      dbms_output.put_line(sal_diff);
   CLOSE emp_sal_diff; 
END; 
/
// display sal in decending order ( FOR LOOP)
DECLARE
      CURSOR decsal is 
            SELECT name,sal from plemp order by sal desc;
BEGIN
      for i in decsal
            LOOP
                  dbms_output.put_line(i.name || ' ' ||i.sal );
            END LOOP;
end;
/
//update sal by 1000 for a dept (Parametrized CURSOR)
DECLARE 
   e_dno plemp.did%type;
   e_name plemp.name%type; 
   e_sal plemp.sal%type;
   temp plemp.sal%type; 
   CURSOR emp_update( c_dno number) is 
      SELECT  name, sal,did FROM plemp where did = c_dno;
	did number; 
BEGIN
      did := &did;
   OPEN emp_update(did);
      dbms_output.put_line('emp_name' || ' ' || 'sal' || 'oldsal'); 
   LOOP 
   FETCH emp_update into e_name, e_sal ,e_dno; 
      EXIT WHEN emp_update%notfound; 
      temp := e_sal+1000;
	update plemp set sal = temp where did = e_dno;
      dbms_output.put_line(e_name || ' ' || e_sal ||' '|| temp); 
   END LOOP; 
   CLOSE emp_update; 
END; 
/
//test
declare
      cursor c_emp is
            select id,name,sal from plemp where dno=&dno;
begin
      for c in c_emp
      loop
            dbms_output.put_line(c.id||'     '||c.name||'      '||c.sal);
      end loop;
end;
/
//test 2
declare
      cursor c2(xdno number) is
            select id,name,sal,dno from plemp where dno=xdno;
      d_no number(4);
      eno number(5);
      nm varchar2(15);
begin
      d_no:=&deptno;
      for c in c2(d_no)
      loop
            dbms_output.put_line(c.id||'     '||c.name||'      '||c.sal);
      end loop;
      OPEN c2(d_no);
      if c2%ROWCOUNT =0 then
                  dbms_output.put_line('deptno '||d_no|| ' does not exist');
            end if;
      CLOSE c2;
end;
/
//dbms_output for 8 and 9
declare
      cursor c2(xdno number) is
            select id,name,sal,dno from plemp where dno=xdno;
      d_no number(4);
      temp number;
begin
      d_no:=&deptno;
      for c in c2(d_no)
      loop
                  temp := c.sal;
                  c.sal := c.sal + 1000;
                  dbms_output.put_line(c.name || ' ' || c.sal ||' '|| temp);
      update plemp set sal = c.sal where dno = d_no;
      end loop;
      OPEN c2(d_no);
      if c2%ROWCOUNT =0 then
                  dbms_output.put_line('deptno '||d_no|| ' does not exist');
            end if;
      CLOSE c2;
end;
/
//PROCEDURE run as EXECUTE greetings
CREATE OR REPLACE PROCEDURE greetings 
AS 
BEGIN 
   dbms_output.put_line('Welcome to plsql'); 
END; 
/
//PROCEDURE to display
DECLARE
      dno plemp.dno%type;
      PROCEDURE display(xdno number)
      is
      BEGIN
       FOR aRow IN (SELECT id, Name,sal fROM plemp WHere dno = xdno)
       LOop
            dbms_output.put_line('ID '|| 'NAME ' || 'sal ');
            dbms_output.put_line(aRow.id || ' ' || aRow.name ||' '|| aRow.sal);
       end loop;
      end;
BEGIN
      dno :=&dno;
      display(dno);
END;
/
//indepenent procedures
create or replace PROCEDURE display(xdno number)
      is
      BEGIN
       FOR aRow IN (SELECT id, Name,sal fROM plemp WHere dno = xdno)
       LOop
            dbms_output.put_line('ID '|| 'NAME ' || 'sal ');
            dbms_output.put_line(aRow.id || ' ' || aRow.name ||' '|| aRow.sal);
       end loop;
      end;

//functions
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