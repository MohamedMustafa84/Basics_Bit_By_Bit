
create Database LibraryProject;



create Table Books(
	BookID int Primary key ,
	Title nvarchar(50) not null,
	Auther nvarchar(50) not null,
	ISBN nvarchar(100) not null,
	PublicationDate date not null,
	genre nvarchar(30) not null,
	AdditinalDetails nvarchar(max)
)

select * from Books;


create table BooksCopies(
	BookCopyID int primary key,
	bookID int references Books(BookID)  not null,
	AvailabilityStatus bit 
)

select * from BooksCopies;

create table Users(
	UserID int primary key ,
	UserName nvarchar(30) not null ,
	LibraryCard nvarchar(50),
	ContactInfo nvarchar(50) not null
)

select * from BooksCopies;


create table BorrowingsRecords (
	BorrowingRecordID int primary key,
	BookCopyID int references BooksCopies(BookCopyID) not null,
	UserID int references Users(UserID) not null,
	BorrowingDate date not null ,
	DueDate date not null,
	ActualReturnDate Date
)

select * from BorrowingsRecords; 


create Table FinesRecords(
	FineRecordID int primary key ,
	UserID int references Users(UserID) not null,
	BorrowingRecordID int references BorrowingsRecords(BorrowingRecordID) not null,
	LateDays int not null,
	FineAmount money not null,
	PaymentStatus bit default 0,
)


	select * from FinesRecords;


create table ReservationRecords(
	ReservationID int primary key ,
	UserID int references Users(UserID) not null,
	BookCopyID int references BooksCopies(BookCopyID) not null ,
	ReservationDate date not null
)


select * from ReservationRecords;
		


create table Settings ( 
DefaultBorrowingDays int not null ,
FinePerDay int not null
)


select * from Settings;














