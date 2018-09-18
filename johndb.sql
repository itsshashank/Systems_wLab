create table john_emp(id char(5),did numder(2),name char(15),designation char(15),basicpay number(10,2),sex char(1));

insert into john_emp values('101',1,'Ram','Typist',2000,'M');
insert into john_emp values('101',1,'Ram','Typist',2000,'M');
insert into john_emp values('101',1,'Ram','Typist',2000,'M');
insert into john_emp values('101',1,'Ram','Typist',2000,'M');
insert into john_emp values('101',1,'Ram','Typist',2000,'M');
insert into john_emp values('101',1,'Ram','Typist',2000,'M');
insert into john_emp values('101',1,'Ram','Typist',2000,'M');
insert into john_emp values('101',1,'Ram','Typist',2000,'M');

//male staff

select count(sex) from shashank_emp where sex='M';

select max(basicpay),designatiom from shashank_emp group by(designatiom);

//add coloum
alter table shashank_emp add manager_id char(5);

update values

update shashank_emp set manager_id='102' where id = '123' or id = '114' or id = '115';
select count(distinct(did)) from shashank_emp;
select did,count(id) from shashank_emp group by(did);
select did,avg(basicpay) from shashank_emp group by(did);
select max(basicpay) as max_salary from shashank_emp;
select avg(basicpay) from shashank_emp group by(did);
 select e.name,m.name as manager from emp e,emp m where e.mid like m.id;

//differrnt desig
select distinct designatiom from shashank_emp;
//no of designation
select count(distinct designatiom) from shashank_emp;
//max max_salary of male emp

select max(basicpay) as max_salary from shashank_emp where sex='m' or sex='M';
//display female Typist
select name from shashank_emp where designatiom like '%ypist' and sex='F';
//male clerk sal>3000
select name from shashank_emp where designatiom like 'Cleark' and (sex='m' or sex='M') and basicpay >3000;
//manager and analyst
select * from shashank_emp where designatiom in ('manager','Manager','analyst','Analyst') and did = 2;
//menon
select designatiom,basicpay from shashank_emp where name = 'menon';
//add join_date
alter table shashank_emp add join_date date;
//update join_dates
update shashank_emp set join_date='2-feb-1999' where id=101;
select * from my_emp;
//display according to seniority
select * from my_emp order by joindate desc/asc;
//desc order of sal
select * from my_emp order by basic desc;

//refer dept to emp table;
alter table my_emp add foreign key (did) references my_dept(dept_id);
//display emp name and dept name
select e.name,d.dname from my_emp e,my_dept d where e.dept_id=d.dept_id;
//typist in design dept;
select * from my_emp left join my_dept on my_dept.dept_id=my_emp.dept_id where my_dept.dname='design' and my_emp.designation='typist';
select my_emp.name , my_emp.basic_pay from my_emp,my_dept where my_emp.dept_id = my_dept.dept_id and my_dept.dname = 'research';
select * from my_emp where sex='f';
select * from my_emp where my_emp.id in (select my_emp.id from my_emp,my_dept where my_emp.dept_id = my_dept.dept_id and my_dept.dname not in ('coding','testing'));
select my_dept.dname from my_dept where my_dept.dept_id=(
    select distinct dept_id from my_emp where basic_pay=(
        select max(basic_pay) from my_emp
    )
);
select min(count(*)) as dept_count,my_emp.dept_id from my_emp,my_dept where my_emp.dept_id=my_dept.dept_id group by(my_emp.dept_id);
select dept_id,count(*) from my_emp 
    group by(dept_id)
    having count(*) = (select min(count(*)) from my_emp group by (dept_id));


select my_dept.dname from my_dept,(select dept_id,count(*) from my_emp 
    group by(dept_id)
    having count(*) = (select min(count(*)) from my_emp group by (dept_id))) a where my_dept.dept_id = a.dept_id;
SELECT *
FROM (
  SELECT basic_pay, 
         rank() over (order by basic_pay desc) as row_rank
  FROM my_emp
) t
WHERE row_rank = 1;
select * from  my_emp order by basic_pay desc limit 1,1;
select max(basic_pay) from my_emp where basic_pay not in (select max(basic_pay) from my_emp);
select min(basic_pay) from my_emp where basic_pay not in (select min(basic_pay) from my_emp);
select name from my_emp, (select avg(basic_pay) as bp,dept_id from my_emp group by (dept_id)) a
where my_emp.dept_id =a.dept_id and my_emp.basic_pay >a.bp;
select avg(basic_pay) from my_emp group by (dept_id);
select id from my_emp where name like 'ram';
select name as emp_under_ram from my_emp where manager_id in (select id from my_emp where name like 'ram');
select dept_id,count(*) as no_of_dept_employees from my_emp group by(dept_id)
having count(*) > 3;
select dept_id, min(basic_pay) as lowest_salary from my_emp group by(dept_id) having min(basic_pay) > 2500;
select max(basic_pay) from my_emp group by(dept_id);
select name from my_emp where basic_pay in (select max(basic_pay) from my_emp group by(dept_id));
select e.name from my_emp e,(select dept_id,max(basic_pay) as bp from my_emp group by(dept_id)) a where e.dept_id = a.dept_id and e.basic_pay = a.bp;
select name from my_emp where basic_pay not in (select min(basic_pay) from my_emp);
select name from my_emp where basic_pay not in (select min(basic_pay) from my_emp) or basic_pay not in (select max(basic_pay) from my_emp);
alter table my_emp add city varchar(10);
update my_dept set city='ekm' where dept_id = 1;
update my_dept set city='ktm' where dept_id = 2;
update my_dept set city='tvm' where dept_id = 3;
update my_dept set city='pkd' where dept_id = 4;
update my_emp set city='ekm' where id = 101;
update my_emp set city='ktm' where id = 121;
select e.name from my_emp e,my_dept d where e.dept_id = d.dept_id and e.city = d.city;
select dept_id,min(sum(basic_pay)) from my_emp group by(dept_id);
select dept_id from my_emp group by(dept_id) having sum(basic_pay)=(select min(sum(basic_pay)) from my_emp group by(dept_id));
select dname from my_dept where dept_id = (select dept_id from my_emp group by(dept_id) having sum(basic_pay)=(select min(sum(basic_pay)) from my_emp group by(dept_id)));

select name from my_emp where join_date like '%-%-1990';
select name from my_emp where join_date like '%-AUG-%';
select dept_id,count(*) as no_of_dept_employees from my_emp group by(dept_id);
select * from my_dept where dept_id in(select dept_id from my_emp group by(dept_id) having count(*) = 0);
select * from my_dept where dept_id in(
    select dept_id from my_emp group by(dept_id)having count(*) > 2
);

//19-sep-18
select dept_id,count(dept_id) as no_of_emp_havemorethan_5000 from my_emp  where dept_id in(
        select dept_id from my_emp group by(dept_id) having count(*) > 4) 
    and basic_pay > 5000 group by(dept_id);

