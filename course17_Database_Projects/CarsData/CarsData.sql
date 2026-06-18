
create database CarsData;

use CarsData;

select * from CarsData;

-- select 10 random rows from the database 

select top 10  * from CarsData where Make ='Ferrari' And Year <1990
order by newID() ;



--count the Ferrari cars in the database

select count(*) from CarsData where make = 'Ferrari';


-- copy makes in different table without Repeattoin

create table Makes(
	MakeID int primary key,
	MakeName nvarchar(50) not null
)



select * from Makes;



insert into Makes
select distinct Make from CarsData order by Make Asc;

select * from Makes;


-- Add MakeID column to CarsData and Fill it with Cars MakeID from the table Makes

-- create the MakeID column  and make it allow null ata first 

-- Update the  makeID with the data from makes table

alter Table CarsData Add foreign key (MakeID) references Makes(makeID);

update CarsData 
 set MakeID = (select MakeID from Makes where Makes.MakeName =CarsData.Make );


 select * from CarsData ;


-- After we add MakeID cloumn w dont nedd make Column anymore so we have to delete it 
	
	Alter table CarsData drop column Make;

select * from CarsData ;



--

insert into DriveTypes
select distinct Drive_Type from CarsData 
Order by Drive_Type Asc;

Select * from DriveTypes;


 select  top 10 * from CarsData;

 update CarsData 
 set DriveTypeID = (Select DriveTypeID from DriveTypes where DriveTypes.DriveTypeName = CarsData.Drive_Type);


 Alter table CarsData drop Column Drive_Type;

 Select * from CarsData;




