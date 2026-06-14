
create database OnlineStore;

use OnlineStore;


 create table ProductsCategory(
	CategoryID int primary key ,
	CategoryName nvarchar(50) not null
)

select * from ProductsCategory;


 create table ProductsCatalog(
	ProductID  int primary key ,
	Name nvarchar(50) not null,
	Description nvarchar(250) not null,
	Price smallmoney not null,
	QuantityInStack int not null,
	 CategoryID int references ProductsCategory(CategoryID) not null,
)

select * from ProductsCatalog;



create table ProductsImages(
	ProductImageID  int primary key ,
	ImageUrl nvarchar(100) not null,
	ProductID int references ProductsCatalog(ProductID),
	ImageOrder int not null
) 

select * from ProductsImages;


create table Customers(
	CustomerID int primary key,
	CustomerName nvarchar(50) not null,
	Email nvarchar(40) not null,
	Phone nvarchar(15) not null,
	UserName nvarchar(30) not null,
	CustomerPassword nvarchar(40) not null
)

select * from Customers;

 create table ReviewsRecords(
	ReviewID int primary key ,
	CustomerID int references Customers(CustomerID) not null,
	ProductID int references ProductsCatalog(ProductID) not null, 
	ReviewComent nvarchar(max) not null,
	Rating int not null,
	ReviewDate Date not null
	)

	select * from ReviewsRecords;



	create table ShippingsInfo(
		ShippingID int primary key ,
		ShippingStatus nvarchar(20) not null,
		TrackingNumber nvarchar(40) not null,
		EstimatedDeliveryDate date not null,
		ActualDelivryDate Date ,
		AdditinalNotes  nvarchar(max)
	)




	create  table  Orders(
		OrderID int primary key ,
		CustomerID int references Customers(CustomerID) not null,
		OrderDateAndTime datetime not null,
		ShippingInfo int references ShippingsInfo(ShippingID) not null,
		TotalAmount smallmoney not null
	)

	select * from ShippingsInfo;
	select * from  Orders ;


	 Create table OrderItems(
		ItemID int primary key ,
		ProductID int references ProductsCatalog (ProductID) not null,
		OrderID int references Orders(OrderID) not null,
		Quantity int not null,
		PricePerItem smallmoney not null,
		TotalPrice  smallmoney not null
	)

	select * from OrderItems;
	
 create table Payments(
	PaymentID int Primary key ,
	OrderID int References Orders(OrderID) not null,
	PaymentDateAndTime datetime not null,
	PaymentMethod  nvarchar(50) not null,
	PaymentAmount smallmoney not null
) 

select * from Payments;













