
-- problem 51 : get all employees that have managers along with managers name 
--note : we used inner join on the same table  with different alliace

select Employees.Name,Employees.ManagerID,Employees.Salary ,Managers.Name as managerName
		from Employees inner join Employees as Managers on Employees.ManagerID = Managers.ManagerID;
