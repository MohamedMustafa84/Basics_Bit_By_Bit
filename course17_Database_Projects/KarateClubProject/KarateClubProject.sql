
create Database KarateClub ;

use KarateClub;


create table Persons (
PersonID int Primary key ,
Name nvarchar(100) not null,
Address nvarchar(100) not null,
ContactInfo nvarchar(100) not null
)

select * from Persons;


create table BeltsRanks(
		BeltRankID int primary key ,
		BletName nvarchar(50) default 'White Belt',
		BeltTestFee money not null
	)

 create table Members(
	MemberID int primary key ,
	PersonID int references Persons(PersonID) not null,
	EmergencyContct nvarchar(100) not null,
	BletRanKID int references BeltsRanks(BeltRankID) not null,
	IsActive  bit not null
	
	)

	

	

	select * from Members;

	select * from BeltsRanks;






	create table Instructors(
		InstructorID int primary key ,
		PersonID int references Persons(PersonID)not null,
		Qualification nvarchar(100) not null
	)

	

	select * from Instructors;



	create table  Mentorships (
		MentorshipID  int primary key ,
		MemberID int references Members(memberID) not null,
		Instructor  int references Instructors(instructorID) not null ,
		SignDate Date not null
	)

	select * from Mentorships;

	create table Payments(
		PaymentID int primary key ,
		 Amount money not null,
		 PaymentDate Date not null,
		 MemberID  int references Members(MemberID)
	)

	create table SubscribtionPeriods(
		PeriodID int primary key ,
		MemberID int references Members(MemberID) not null,
		PeriodStartDate Date not null,
		PeriodEndDate Date not null,
		PaymentID  int references Payments(PaymentID)

	)

	select * from SubscribtionPeriods;

	

	create table BletsRanksTest (
		RankTestID int primary key ,
		MemberID int references Members(MemberID)not null,
		InstructorID int references Instructors(InstructorID) not null,
		TestDate Date not null,
		TestResult bit not null ,
		BletRankID int references BeltsRanks(BeltRankID) not null,
		PaymentsID int references Payments(PaymentID) not null 
	)

	select * from BletsRanksTest;













