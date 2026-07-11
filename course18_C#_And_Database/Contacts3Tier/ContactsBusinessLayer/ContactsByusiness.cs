using System;
using System.Data;
using System.Net;
using System.Security.Policy;
using System.Xml.Serialization;
using ContactsDataAccessLayer;


namespace ContactsBusinessLayer
{
    public class ClsContact
    {
        public int ID { get; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Email { get; set; }
        public string Address { get; set; }
        public string Phone { get; set; }
        public int CountryID { get; set; }
        public DateTime DateOfBirth { get; set; }
        public string ImagePath { get; set; }

        public enum enMode { AddNew = 1, Update = 2 };
        public  enMode Mode { get; set; }

        public ClsContact()
        {
            this.ID = -1;
            this.FirstName = "";
            this.LastName = "";
            this.Email = "";
            this.Phone = "";
            this.Address = "";
            this.DateOfBirth = DateTime.Now;
            this.CountryID = -1;
            this.ImagePath = "";

            Mode = enMode.Update;

        }

        private ClsContact(int contactID, string firstName, string lastName, string email, string phone, string address, DateTime dateOfBirth, int countryID, string imagePath)
        {
            this.ID = contactID;
            this.FirstName = firstName;
            this.LastName = lastName;
            this.Email = email;
            this.Phone = phone;
            this.Address = address;
            this.DateOfBirth = dateOfBirth;
            this.CountryID = countryID;
            this.ImagePath = imagePath;

        }



        public static ClsContact Find(int ContactID)
        {                                                           

            string FirstName = "", LastName = "", Email = "", Address = "", Phone = "", Imagepath = "";
            int CountryID = -1;
            DateTime DateOfBirth = DateTime.Now;


            if (ContactsDataAccess.FindContact(ContactID, ref FirstName, ref LastName, ref Email, ref Phone, ref Address, ref DateOfBirth, ref CountryID, ref Imagepath))
            {
                return new ClsContact(ContactID, FirstName, LastName, Email, Phone, Address, DateOfBirth, CountryID, Imagepath);

            }
            else
            {
                return null;
            }


        }



        private bool _AddNewContact()
        {
            bool AddStatus = false;

            int ContactID = ContactsDataAccess.AddNewContact( this.FirstName, this.LastName, this.Email, this.Phone, this.Address, this.DateOfBirth, this.CountryID, this.ImagePath);

            if (ContactID != -1)
            {
                AddStatus = true;
            }


            return AddStatus;

        }


        private bool _UpdateContact()
        {

            int ContactID = ContactsDataAccess.UpdateContact(this.ID ,this.FirstName, this.LastName, this.Email, this.Phone, this.Address, this.DateOfBirth, this.CountryID, this.ImagePath);

            


            return (ContactID > 0);

        }



        public  bool Save()
        {
            switch (Mode) {

                case enMode.AddNew:
                    if (_AddNewContact())
                    {
                        Mode = enMode.Update;
                        return true;

                    }
                    else
                    {
                        return false;
                    }
                case enMode.Update:

                    return _UpdateContact();
                default:
                        return false;
                    
                    
            
            
            }

        }

        public static bool DeleteContact(int ContactID)
        {
            return ContactsDataAccess.DeleteContact(ContactID);
        }

        public static bool ISContactExist(int ContactID)
        {
            return ContactsDataAccess.IsExist(ContactID);
        }

        public static DataTable GetContactsList()
        {
            return ContactsDataAccess.GetAllContacts();
        }

    }
}
