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
	if (did = e_dno) then
            temp := e_sal;
		e_sal := e_sal +1000;
	update plemp set sal = e_sal where dno = did;
	end if;
      dbms_output.put_line(e_name || ' ' || e_sal ||' '|| temp); 
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


